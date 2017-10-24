#include<bits/stdc++.h>

using namespace std;

const int MAX_NODES = 1000;

struct Trie{
  
	int sz;
	int t[MAX_NODES][26], cnt[MAX_NODES][26];

	Trie(){
		memset(t, 0xff, sizeof t);
		memset(cnt, 0, sizeof cnt);
		sz = 0;
	}

	void insert(string s){
		int node = 0;
		for(int i = 0; i < s.size(); ++i){
			if(t[node][s[i] - 'a'] == -1)
				t[node][s[i] - 'a'] = ++sz;
			++cnt[node][s[i] - 'a'];
			node = t[node][s[i] - 'a'];
		}
	}

	int find(string s){
		int node = 0;
		int res = 0;
		for(int i = 0; i < s.size(); ++i){
			res = cnt[node][s[i] - 'a'];
			node = t[node][s[i] - 'a'];
		}
		return res;	
	}

}trie;

int main(){

    cin.tie(0);
    cin.sync_with_stdio(0);

    #ifdef Cyborg101
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
    	string s;
    	cin >> s;
    	trie.insert(s);
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; ++i){
    	string s;
    	cin >> s;
    	cout << trie.find(s) << endl;
    }

    return 0;
}
