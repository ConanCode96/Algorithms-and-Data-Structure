/*
Submitted With (^^) by -> Hossam ^_^
_____________________
|     ___     ___     |
|    (^_^)   (^_^)    |
|   /( | )\_/( | )\   |
|_____|_|_____|_|_____|
*/

#include <bits/stdc++.h>

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
const int MX = (int)3e5 + 10;

int main()
{     
    prep();

    int n;
    cin >> n;

    int a[n];
    ll sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }   

    ll each = sum / 3;
    if(sum % 3) return puts("0"), 0;

    /*
        counts all possible triplets of subsets of indices [1, 2, ..., n] (p, q, r) that are:
        1)non-intersecting
        2)has the same sum
        3)their union is [1, 2, ..., n] (i.e. all array indices should be included)
    */

    int U = (1 << n) - 1;
    vector<int> masks;
    vector<ll> cost(U + 1, 0);
    for(int msk = 1; msk <= U; ++msk){ //O(2^n) instead of O(n*(2^n))
        int lsb = 0;
        while(!((1 << lsb) & msk)) lsb++;
        cost[msk] = cost[msk ^ (1 << lsb)] + a[lsb]; //mask dp
        if(cost[msk] == each) masks.push_back(msk);
    }

    int res = 0;
    for(auto &p : masks){
        int qr = U ^ p;
        //iterating all possible non-empty submasks of qr (subtle piece of code ^_^)
        int q = qr & (qr - 1);
        while(q){
            int r = qr ^ q;
            if(cost[q] == each and cost[r] == each) res++;
            q = qr & (q - 1);
        }
    }

    cout << res << endl;
   
    // ZXC
    return 0;
}