// getting the sum of distances over a cycle from both directions

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
