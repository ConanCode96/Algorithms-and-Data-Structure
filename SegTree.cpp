struct SegmentTree{
	vector<ll> tree;
	int N;
	SegmentTree(int sz){
		this->N = sz;
		tree.resize(4 * N);
		fill(all(tree), (ll)1e18);
	}

	void update(int idx, ll val){
		assert(0 <= idx && idx <= N - 1);
		upd(idx, val, 0, 0, N - 1);
	}
	ll query(int ql, int qr){
		assert(ql <= qr);
		assert(0 <= ql && qr <= N - 1);
		return qry(ql, qr, 0, 0, N - 1);
	}

	void upd(int idx, ll val, int node, int L, int R){
		if(L == R){
			if(idx == L)
				tree[node] = min(val, tree[node]);
			return;
		}
		int md = (L + R) / 2;
		if(idx <= md) upd(idx, val, node * 2 + 1, L, md);
		else upd(idx, val, node * 2 + 2, md + 1, R);

		tree[node] = min(tree[node * 2 + 1], tree[node * 2 + 2]);
	}

	ll qry(int ql, int qr, int node, int L, int R){
		if(ql <= L && R <= qr) return tree[node]; // within search range
		if(L > qr || R < ql || L > R) return 1e18; // not within range
		int md = (L + R) / 2;
		return min(qry(ql, qr, node * 2 + 1, L, md), qry(ql, qr, node * 2 + 2, md + 1, R));
	}
};