#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define ll long long
#define inf (ll)1e18
#define all(x) x.begin(), x.end()

const int MX = 500020;
const int N = 1000060;
const int mood = ((int)1e9 + 7);


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

  	string s;
  	cin >> s;

  	int n = (int)s.size();

  	unordered_map<int, int> mp;
  	mp[0] = -1;
  	int mask = 0;
  	int res = 0;

  	for(int i = 0; i < n; ++i){
  		mask ^= (1 << (s[i] - 'a'));

  		//all even
  		{
	  		if(mp.find(mask) != mp.end()){
	  			res = max(res, i - mp[mask]);
	  		}
	  		else{
	  			mp[mask] = i;
	  		}
  		}

  		//all even - one odd
  		{
  			for(int j = 0; j < 26; ++j){
  				int edited_mask = mask ^ (1 << j);
  				if(mp.find(edited_mask) != mp.end()){
  					res = max(res, i - mp[edited_mask]);
  				}
  			}
  		}

  	}

  	cout << res << endl;

    return 0;
}
