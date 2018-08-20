class fenwick{

public:

int a[N], n;
map<int, int>mp;
int tree[N];

void upd(int idx){
    idx++;
    
    for(; idx <= n; idx += idx & -idx)
        tree[idx]++;
    
    
}
int qry(int idx){
    
    idx++;
    int ret = 0;
    for( ;idx > 0; idx -= idx & -idx)
        ret += tree[idx];
        
    return ret;
    
}

};

///////////////////////////////////////
// Segment Tree

int n, m;
std::vector<int> a;

struct segmentTree{

  int lgn;
  std::vector<int> tree, lazy;

  segmentTree(){
    lgn = 31 - __builtin_clz(n) + 2;
    tree.assign(1 << lgn, 0);
    lazy.assign(1 << lgn, 0);
  }

  void build(int l = 0, int r = n - 1, int pos = 0){
      
      if(l == r){
          tree[pos] = a[l];
          return;
      }
      else{
          int mid = (l + r) / 2;
          build(l, mid, 2 * pos + 1);
          build(mid + 1, r, 2 * pos + 2);
      }
  }
  
  inline void propagate_lazy(int pos, int l, int r){

      if(lazy[pos] != 0){ //get_prev_lazy_updates
      
          tree[pos] += lazy[pos];
          
          if(l != r){ // not a leaf
              lazy[2 * pos + 1] += lazy[pos];
              lazy[2 * pos + 2] += lazy[pos];
          }
          
          lazy[pos] = 0;
      }  
  }

  void update(int lx, int rx, int val, int l = 0, int r = n - 1, int pos = 0){
      
      propagate_lazy(pos, l, r);

      if(l > r || l > rx || r < lx) return;
    
      if(l >= lx && r <= rx){ //lazy_update

          tree[pos] += val;
          
          if(l != r){
              lazy[2 * pos + 1] += val;
              lazy[2 * pos + 2] += val;
          }
          
          return;
      }

      int mid = (l + r) / 2;
      update(lx, rx, val, l, mid, 2 * pos + 1);
      update(lx, rx, val, mid + 1, r, 2 * pos + 2);
    
      tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
  }
  
  int query(int lx, int rx, int l = 0, int r = n - 1, int pos = 0){
          
      propagate_lazy(pos, l, r);
     
      if(l > r || l > rx || r < lx) return -1; //outside
 
      if(l >= lx && r <= rx){
          return tree[pos];
      }

      int mid = (l + r) / 2;
      int lll = query(lx, rx, l, mid, 2 * pos + 1);
      int rrr = query(lx, rx, mid + 1, r, 2 * pos + 2);
    
      return max(lll, rrr);
  }
      
};
/////////////////////////////////////

//ONLINE SQRT-DECOMPOSITION

struct SQRT{

	int n, sq, blk_cnt;

	std::vector<ll> bst;
	std::vector<ll> lazy;

	SQRT(const vector<ll>& a){
		n = (int)a.size();
		sq = int(sqrt(n)) + 1;
		blk_cnt = (n + sq - 1) / sq;
		bst.assign(blk_cnt, inf);
		lazy.assign(blk_cnt, 0);

		for(int i = 0; i < n; ++i)
			bst[i / sq] = min(bst[i / sq], a[i]);
	}

	auto up = [&](int blk, int l, int r, int v = 0){

		int L = blk * sq;
		int R = min(L + sq - 1, n - 1); 

		ll res = (ll)1e18;
		bst[blk] = (ll)1e18;

		for(int i = L; i <= R; ++i){
			a[i] += lazy[blk];
			if(i >= l && i <= r){
				a[i] += v;
				res = min(res, a[i]);
			}
			bst[blk] = min(bst[blk], a[i]);
		}

		lazy[blk] = 0;

		return res;
	};

    auto update = [&](int l, int r, int v){

    	int lf = l / sq;
    	int rg = r / sq;

    	up(lf, l, r, v);

    	if(lf != rg)
    		up(rg, l, r, v);

		for(int blk = lf + 1; blk < rg; ++blk)
			lazy[blk] += v;

		return;
    };

    auto query = [&] (int l, int r){

    	int lf = l / sq;
    	int rg = r / sq;

    	ll res = up(lf, l, r);

    	if(lf != rg)
    		res = min(res, up(rg, l, r));

    	for(int blk = lf + 1; blk < rg; ++blk)
    		res = min(res, bst[blk] + lazy[blk]);

    	return res;
    };
};
////////////////////////////////////////////////////////

//KMP

    string s;
    cin >> s;

    int n = int(s.size());
    std::vector<int> lcp(n);

    for(int i = 1, j = 0; i < n; ++i, ++j){
      while(j && s[j] != s[i]) j = lcp[j - 1];
      lcp[i] = j + (s[i] == s[j]);
    }
///////////////////////////////////////////////////////    

    
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        
        int n = nums.size();
        long long dp[2][n + 1];
        for(int i = 0; i < n; ++i)
          dp[0][i] = dp[1][i] = 0;

        dp[nums[0] < 0][0] = nums[0];
        long long ans = nums[0];
        
        for(int i = 1; i < n; ++i){
            int type = nums[i] < 0; //0 for pos, 1 for neg
            
            dp[type][i] = max((long long)nums[i] * (type ? -1 : 1), nums[i] * dp[0][i - 1] * (type ? -1 : 1)) * (type ? -1 : 1);
            dp[type ^ 1][i] = nums[i] * dp[1][i - 1];
        
            ans = max(ans, max(dp[0][i], dp[1][i]));

            //cout << dp[0][i] << " " << dp[1][i] << endl;
        }
        
        return ans;
        
    }
};

////////////////////////////////////////////


struct node{
  int x;

  node(int xx) : x(xx) {};

  bool operator <(const node& o2) const{
    return x < o2.x;
  }
};


////////////////////////////////////////////

//UNION-Find


int find(int x, std::vector<int>& ds){
  return ds[x] < 0 ? x : ds[x] = find(ds[x], ds);
}

void unite(int x, int y, std::vector<int>& ds){
  int xx = find(x, ds);
  int yy = find(y, ds);
  if(xx != yy){
    if(ds[xx] > ds[yy]) swap(xx, yy);
    ds[xx] += ds[yy];
    ds[yy] = xx;
  }
}
//////////////////////////////////////////


//TARJAN for SCCs on Digraphs

std::vector<vector<int>> g;
int pre[MX];
int low[MX];
int id[MX];
stack<int> stk;
int cntr, scc;

void tarjan(int x){

  stk.push(x);
  pre[x] = cntr++;
  low[x] = pre[x];

  for(auto y : g[x]){
    if(pre[y] == -1)
      tarjan(y);
    low[x] = min(low[x], low[y]); 
  }

  if(pre[x] == low[x]){ //component root
    while(true){
      int y = stk.top();
      stk.pop();
      low[y] = MX; //inf
      id[y] = scc;
      if(y == x) break;
    }
    scc++;
  }
}

///////////////////////////////////////////////

//RETURNS MX DIAMETER, HEIGHT OF A TREE

pair<int, int> dia(int x, int par = -1)
{

    int mxHeight[3] = {-1, -1, -1};

    pair<int, int> mine = {0, 0};

    for (auto &y : g[x])
    {
        if (y == par)
            continue;
        auto res = dia(y, x);
        mine.X = max(mine.X, res.X);
        mxHeight[0] = mine.Y + 1;
        sort(mxHeight, mxHeight + 3);
    }

    for (auto &v : mxHeight)
        if (v == -1)
            v = 0;

    mine.X = max(mine.X, mxHeight[1] + mxHeight[2]);
    return {mine.X, mxHeight[2]}; // MX (diameter, height)
}

////////////////////////////////////////////////////////////////////
