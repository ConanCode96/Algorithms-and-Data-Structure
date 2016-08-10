#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;


class SegmentTree{

private: vi A, st; int n;

inline int left (int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }

void build(int p, int L, int R){

	if(L == R) st[p] = L; //index

	else{

	int mid = (L+R)>> 1;

	int l = left(p);
	int r = right(p);

	build(l, L, mid);
	build(r, mid + 1, R);

	int p1 = st[l];
	int p2 = st[r];

	st[p] = (A[p1] <= A[p2])? p1 : p2;

	}
	
}

int rmq(int p, int L, int R, int i, int j){

	if(L > j || R < i) return -1;
	if(L >= i && R <= j) return st[p];

	int mid = (L+R)>> 1;

	int l = left(p);
	int r = right(p);

	int p1 = rmq(l, L, mid, i, j);
	int p2 = rmq(r, mid + 1, R, i, j);

	if(p1 == -1) return p2;
	if(p2 == -1) return p1;

	return (A[p1] <= A[p2]) ? p1 : p2;
}


public :

SegmentTree(const vi &A){
	this->A = A;
	n = (int) A.size();
	st.assign(4*n,0);
	build(1, 0, n - 1);
}

int rmq(int i, int j){ return rmq(1, 0, n - 1, i, j); }

};



int main(int argc, char const *argv[]){

	int arr[] = { 18, 17, 13, 19, 15, 11, 20 };

	vi A(arr, arr + 7);

	SegmentTree st(A);

	cout << A[st.rmq(0, 6)] << endl;

	return 0;
}
