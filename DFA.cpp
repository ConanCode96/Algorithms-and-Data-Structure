//string size * alpha size
int dfa[505][26];

void build(string s){
    int j=0;
    for (int i=0;i<s.size();i++){
        for(int f=0;f<26;f++){
            dfa[i][f]=dfa[j][f];
        }
        j=dfa[i][s[i]-'a'];
        dfa[i][s[i]-'a']=i+1;
    }
}
 
