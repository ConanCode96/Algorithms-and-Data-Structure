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
ll dp[18][180][2];

int op = 0;

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
    
    cout << op << endl;

 	return 0;
}
