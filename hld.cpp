const int MX = (int)2e5 + 20;
 
int chain_no = 0;
vector<int> g[MX];
int chain_head[MX], chain_size[MX], chain_idx[MX], chain_pos[MX], sz[MX];
 
void dfs(int node, int par){
	sz[node] = 1;
	for(auto v : g[node]){
        if(v == par) continue;
		dfs(v, node);
		sz[node] += sz[v];
	}
}


// TO-DO memset chain_head 0xff
 
void hld(int node, int par){
 
	if(chain_head[chain_no] == -1) chain_head[chain_no] = node; //assigning the head
	chain_idx[node] = chain_no;
	chain_pos[node] = chain_size[chain_no];
	chain_size[chain_no]++;
 
 
	int idx = -1;
	int sub_sz = -1;
	for(auto v : g[node]){
        if(v == par) continue;
		if(sz[v] > sub_sz){
			idx = v;
			sub_sz = sz[v];
		}
	}
 
	if(idx != -1) hld(idx, node);
 
	for(auto v : g[node]){
        if(v == par) continue;
		if(v != idx){
			chain_no++;
			hld(v, node);
		}
	}
}