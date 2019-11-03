#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)1e5 + 10;
const int mod = (int)1e9 + 7;

void add_self(int &x, int y){x += y; if(x >= mod) x -= mod;}
void sub_self(int &x, int y){x -= y; if(x < 0) x += mod;}
void mul(int &x, int y){x = x * 1LL * y % mod;}


int dp[32][2][2];

int calc(int idx, int l, int r, int tightL, int tightR){
    if(idx == -1) return 1;

    int &res = dp[idx][tightL][tightR];
    if(~res) return res;

    res = 0;

    int x = (l >> idx) & 1;
    int y = (r >> idx) & 1;

    int mn = tightL ? x : 0;
    int mx = tightR ? y : 1;

    assert(mn <= mx);

    for(int i = mn; i <= mx; ++i){
        res += calc(idx - 1, l, r, tightL && (i == x), tightR && (i == y));
    }

    return res;
}

int main(){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);


    int l, r;
    cin >> l >> r;

    memset(dp, 0xff, sizeof dp);

    //counts the number of numbers between L, R
    cout << calc(30, l, r, 1, 1) << endl;

    
    return 0;
}