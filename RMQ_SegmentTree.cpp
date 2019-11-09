#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class SegmentTree{

inline int left (int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }

public:

vector<int> A, st; int n;

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

	st[p] = (A[p1] >= A[p2])? p2 : p1;

	}
	
}

void update(int p, int L, int R, int index){

    if(index < L || index > R) return;

	if(L == R && L == index) st[p] = index; //index

	else{

        int mid = (L+R)>> 1;

        int l = left(p);
        int r = right(p);

        update(l, L, mid, index);
        update(r, mid + 1, R, index);

        int p1 = st[l];
        int p2 = st[r];

        // if(p1 == -1) st[p] = p2;
        // else if(p2 == -1) st[p] = p1;
        // else
        st[p] = (A[p1] <= A[p2]) ? p1 : p2;
    }
	
}

//returns minimum number index (right-preferred)
int rmq(int p, int L, int R, int i, int j){
 
	if(L > j || R < i) return -1; // non-existent
	if(L >= i && R <= j) return st[p];

	int mid = (L+R)>> 1;

	int l = left(p);
	int r = right(p);

	int p1 = rmq(l, L, mid, i, j);
	int p2 = rmq(r, mid + 1, R, i, j);

    if(p1 == -1) return p2;
	if(p2 == -1) return p1;

	return (A[p2] <= A[p1]) ? p2 : p1;
}

SegmentTree(const vector<int> &A){
    this->A = A;
    this->n = A.size();
	st.assign(4*n, -1);
    build(1, 0, n - 1);
}

int rmq(int i, int j){ return i <= j ? rmq(1, 0, n - 1, i, j) : -1; }

};



int main(int argc, char const *argv[]){

	int arr[] = { 18, 17, 13, 19, 15, 11, 20 };

	vi A(arr, arr + 7);

	SegmentTree st(A);

	cout << A[st.rmq(0, 6)] << endl;

	return 0;
}
