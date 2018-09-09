/*
    Submitted With (^^) by -> Hossam ^_^
     ___     ___
    (^_^)   (^_^)
   /( | )\ /( | )\
     | |     | |
*/

#include <bits/stdc++.h>

using namespace std;

inline void prep(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	#ifdef Cyborg101
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

#define X first
#define Y second
#define ll long long
#define inf (0x7f7f7f7f7f7f7f7f)
#define all(x) x.begin(), x.end()

const int MX = 1e6 + 10;
const int mood = ((int)1e9 + 7);

/////////////////////////////////////

struct node{
	node* lf;
	node* rg;
	int cnt = 0;
};

void insert(int x, node* cur){

	for(int i = 30; i >= 0; --i){
		int val = (1 << i) & x;
		if(val == 0){
			if(cur->lf == 0)
				cur->lf = new node();
			cur = cur->lf;
			cur->cnt++;
		}else{
			if(cur->rg == 0)
				cur->rg = new node();
			cur = cur->rg;
			cur->cnt++;
		}
	}

}

void remove(int x, node* cur){
	
	for(int i = 30; i >= 0; --i){
		int val = (1 << i) & x;
		if(val == 0){
			if(cur->lf == 0)
				return;
			cur = cur->lf;
			cur->cnt--;
		}else{
			if(cur->rg == 0)
				return;
			cur = cur->rg;
			cur->cnt--;
		}
	}
}

int query(int x, node* cur){

	for(int i = 30; i >= 0; --i){
		int val = (1 << i) & x;
		if(val == 0){
			if(cur -> lf == 0)
				return 0;
			cur = cur -> lf;
		}
		else{
			if(cur -> rg == 0)
				return 0;
			cur = cur -> rg;
		}
	}

	return cur -> cnt;
}

int main(){

	prep();
	
	node* root = new node();

	int q;
	cin >> q;
	for(int i = 0; i < q; ++i){
		char t; int x;
		cin >> t >> x;
		if(t == '+')
			insert(x, root);
		else if(t == '-')
			remove(x, root);
		else
			cout << query(x, root) << '\n';
	}
	
    return 0;
}	
