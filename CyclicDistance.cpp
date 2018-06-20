// getting the sum of distances over a cycle from both directions
//Arrays fw, bw are 0-indexed also indices are 0-indexed

inline int getRight(int at, int r){
    int res = fw[(r - 1 + n) % n];
    if(at == 0) return res;
    if(at < r || r == 0) res -= fw[(at - 1 + n) % n];
    else if(at > r) res += bw[at];
    return res;
}

inline int getLeft(int at, int l){
    int res = bw[l];
    if(at == 0) return res;
    if(at > l) res -= bw[at];
    else if(at < l) res += fw[(at - 1 + n) % n];
    return res;
}

/////////////////////////////////////////////////////////////////////////////

//Another optimal way
// 1-indexed array, 0-indexed positions
//only calculate cw direction and its reverse

ll dist(int a, int b) {
    bool swapped = false;
	if (a > b){
		swap(a, b);
        swapped = true;
    }
	ll d = x[b] - x[a];
// 	return min(d, x[n] - d);
    return swapped? x[n] - d : d;
}
///////////////////////////////////////////////////////////////////
