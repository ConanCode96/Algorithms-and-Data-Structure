
const int MX = 2e6 + 10;
//SPARSE TABLE

struct SparseTable{

	int ST[20][MX];
	int TYPE;

	void build(const vector<int> &a, int T){
		this->TYPE = T;
		int n = a.size();
		for (int i = 0; i < n; ++i)
			ST[0][i] = a[i];
		for (int lgN = 1; (1 << lgN) <= n; ++lgN){
			for (int i = 0; i + (1 << lgN) <= n; ++i){
				int pv_lgN = 1 << (lgN - 1);
				if(TYPE)
					ST[lgN][i] = max(ST[lgN - 1][i], ST[lgN - 1][i + pv_lgN]);
				else
					ST[lgN][i] = min(ST[lgN - 1][i], ST[lgN - 1][i + pv_lgN]);
			}
		}
	}

	int query(int l, int r)
	{
		l--, r--;
		int sz = r - l + 1;
		int lg = 0;
		while ((1 << (lg + 1)) <= sz)
			lg++;
		if(TYPE)
			return max(ST[lg][l], ST[lg][l + (sz - (1 << lg))]);
		else
			return min(ST[lg][l], ST[lg][l + (sz - (1 << lg))]);
	}

};