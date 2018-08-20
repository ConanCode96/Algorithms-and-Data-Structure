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
const int MX = (int)2e4 + 10;


int pa[MX];
int chain_no = 0;
vector<int> g[MX];
vector<vector<int>> whosHere;
vector<int> chain_head, chain_size; 
int chain_idx[MX], chain_pos[MX], far[MX];

pair<int, int> df(int x, int par = -1){
    pair<int, int> res = {1, x};
    for(auto& y : g[x]){
        if(y == par) continue;
        auto p = df(y, x);
        if(p.X + 1 > res.X){
            res.X = p.X + 1;
            res.Y = p.Y;
        }
    }
    return res;
}

void dfs(int node, int par = -1){
    far[node] = 1;
    pa[node] = par;
	for(auto& v : g[node]){
        if(v == par) continue;
        dfs(v, node);
		far[node] = max(far[node], far[v] + 1);
	}
}


//MUST BE STARTED FROM A LEAF ON THE TREE DIAMETER (EXTREMELY IMPORTANT!)

void lsd(int node, int par = -1){
 
	if((int)chain_head.size() == chain_no){ // new chain
        chain_head.push_back(node); //assigning the head for the current chain
        chain_size.push_back(0); //initilaizing chain size
        whosHere.push_back(vector<int>()); // initiliazing whosHere for the new chain
    }
	chain_idx[node] = chain_no;
	chain_pos[node] = chain_size[chain_no];
    whosHere[chain_no].push_back(node);
	chain_size[chain_no]++;
 
 
	int idx = -1;
	int farthest = -1;
	for(auto& v : g[node]){
        if(v == par) continue;
		if(far[v] > farthest){
			idx = v;
			farthest = far[v];
		}
	}
 
	if(idx != -1) lsd(idx, node); //preferred longest chain
 
	for(auto& v : g[node]){
        if(v == par || v == idx) continue;
        chain_no++;
        lsd(v, node);
	}
}

int main()
{
    prep();


    //TIMUS TREE2
    
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int leaf = df(1).Y;

    dfs(leaf);
    lsd(leaf);

    while(q--){
        int v, d;
        cin >> v >> d;

        while(d && v != -1){
            int ch = chain_idx[v];
            int cz = chain_size[ch];
            int cp = chain_pos[v];
            if(cz - cp - 1 >= d){ //looking down the chain
                v = whosHere[ch][cp + d];
                d = 0;
            }
            else if(cp >= d){ //looking up the chain
                v = whosHere[ch][cp - d];
                d = 0;
            }
            else{ // move up to the next upper chain
                v = pa[chain_head[ch]];
                d -= cp + 1;
            }
        }

        cout << ((!d && ~v)? v : 0) << endl;
    }

    // int i = 1;
    // for(auto &v : whosHere){
    //     cout << "chain " << i++ << endl;
    //     for(auto x : v){
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

    // ZXC
    return 0;
}