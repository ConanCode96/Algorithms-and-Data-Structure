/*
Submitted With (^^) by -> Hossam ^_^
_____________________
|     ___     ___     |
|    (^_^)   (^_^)    |
|   /( | )\_/( | )\   |
|_____|_|_____|_|_____|
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;

inline void prep()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
};

#define X first
#define Y second
#define endl '\n'
#define ll long long
#define inf (0x7fffffffffffffff)
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << (x) << "\n";
#define ZXC cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;

const int mod = (int)1e9 + 7;
// const int mod = 998244353;
const int MX = (int)4e6 + 10;


int main() {

    prep();

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> dp(n + 1, 0); //dp[i] is the number of DISTINCT subsequences on the string s ending with i.

    dp[0] = 1; // empty string

    for(int i = 0; i < n; ++i){
        for(char nxt_letter = 'a'; nxt_letter <= 'z'; ++nxt_letter){
            int j = i;
            while(j < n && s[j] != nxt_letter) j++;
            if(j < n)
                dp[j + 1] += dp[i];
        }
    }

    int res = 0;
    for(int i : dp) res += i;

    cout << res << endl;

    return 0;
}