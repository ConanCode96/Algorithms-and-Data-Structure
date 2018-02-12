/*
    Submitted With (^^) by -> Hossam ^_^
     ___     ___
    (^_^)   (^_^)
   /( | )\ /( | )\
     | |     | |
*/

#include <bits/stdc++.h>

using namespace std;

inline void prep(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	#ifdef Cyborg101
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

#define X first
#define Y second
#define ll long long
#define inf (0x7f7f7f7f7f7f7f7f)
#define all(x) x.begin(), x.end()

const int MX = 1e6 + 10;
const int mood = ((int)1e9 + 7);


int main(){

	prep();

	int n;
	cin >> n;

	////////////////////////////////////////

	//Number of divisors calculation O(NLOGN)

	std::vector<int> cnt(MX, 2);
	cnt[0] = 0, cnt[1]--;

	for(int i = 2; i < MX; ++i){
		for(int j = i + i; j < MX; j += i){
			cnt[j]++;
		}
	}

	for(int i = 0; i <= n; ++i){
		cout << cnt[i] << " \n"[i == n];
	}

	///////////////////////////////////////////////////////////

	// Minimum prime calculation for fast factorization
	
	std::vector<int> mp(MX);
	for(int i = 2; i < MX; ++i){
		if(mp[i] == 0){
			for(int j = i; j < MX; j += i){
				if(mp[j] == 0) mp[j] = i; // remove this condition to maximize on the prime for this number
			}
		}
	}

	///////////////////////////////////////////////////////////

	// Number of divisors O(NLOGN), maybe a little faster?

	std::vector<int> cnt2(MX, 1); cnt2[0] = 0;
	for(int i = 2; i < MX; ++i){
		int div_cnt = 1;
		int tmp = i;
		while(tmp > 1){
			int c = 0;
			int prv_prime = mp[tmp];
			while(tmp > 1 && mp[tmp] == prv_prime){
				tmp /= mp[tmp];
				c++;
			}
			div_cnt *= c + 1;
		}
		cnt2[i] = div_cnt;
	}

	for(int i = 0; i <= n; ++i){
		cout << cnt2[i] << " \n"[i == n];
	}

	//////////////////////////////////////////////////
    return 0;
}	
