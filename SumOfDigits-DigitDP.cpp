#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define ll long long
#define inf (ll)1e18
#define all(x) x.begin(), x.end()

const int MX = 200020;
const int N = 1000060;
const int mod = ((int)1e9 + 7);

int len;
string s;
ll dp[18][200][2];

int op = 0;

// THIS SUMS THE DIGITS OF NUMBERS LESS THAN SOME NUMBER

ll calc(int idx, int sum, bool tight){

	if(idx == len){
		op++;
		return sum;
	}

	if(dp[idx][sum][tight] != -1)
		return dp[idx][sum][tight];

	int mx = tight ? s[idx] - '0' : 9;

	ll res = 0;
	for(int i = 0; i <= mx; ++i){
		res += calc(idx + 1, sum + i, tight & (i == s[idx] - '0'));
	}

	return dp[idx][sum][tight] = res;
}

int main(){
/*
    Hossam ^_^
     ___     ___
    (^_^)   (^_^)
   /( | )\ /( | )\
     | |     | |
*/
    cin.tie(0);
    cin.sync_with_stdio(0);

    #ifdef Cyborg101
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> s;

    len = (int)s.size();

    memset(dp, 0xff, sizeof dp);

    cout << calc(0, 0, true) << endl;

    // cout << op << endl;

	memset(dp, 0x00, sizeof dp);

	for(int i = 0; i < 180; ++i) dp[len][i][0] = dp[len][i][1] = i;

	// this implementation is working right to left from least significant to most significant(same as top down)
    for(int idx = len - 1; idx >= 0; --idx){
    	for(int sum = 0; sum < 180; ++sum){
    		for(int tight = 0; tight < 2; ++tight){
    			int mx = tight ? s[idx] - '0' : 9;
    			for(int i = 0; i <= mx; ++i){
    				dp[idx][sum][tight] += dp[idx + 1][sum + i][tight && i == (s[idx] - '0')];
    			}
    		}
    	}
    }

    cout << dp[0][0][1] << endl;

 	return 0;
}
