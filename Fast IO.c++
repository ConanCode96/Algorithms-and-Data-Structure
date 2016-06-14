#include <bits/stdc++.h>

using namespace std;

//Reading numbers.
inline int readInt(){
	int s = 1, x = 0, c = getc(stdin);
	while (c <= 32){
		c = getc(stdin);
	}
	if (c == '-'){
		s = -1;
		c = getc(stdin);
	}
	while ('0' <= c && c <= '9'){
		x = x * 10 + c - '0';
		c = getc(stdin);
	}
	return x*s;
}

//Writing numbers.
inline void writeLong(long long x){
	if (x < 0){
		putc('-', stdout);
		x = -x;
	}
	char s[40];
	int n = 0;
	while (x || !n){
		s[n++] = '0' + x % 10;
		x /= 10;
	}
	while (n--){
		putc(s[n], stdout);
	}
}

int main(){
    
    return 0;
}
