  #include <bits/stdc++h>
  
  int a[] = {4, 4, 5, 2, 2, 7, 9, 0, 1, 5, 0, 0, 5, 9, 3, 2, 30, 6};
  const int N = sizeof(a) / sizeof(a[0]);
  int aux[N];


  inline void ShellSort(int *a){

    int h = 1;
    	
    while(h < N/3 ) h = h*3 + 1;

    while(h){

     for (int i = h; i < N; ++i)
     {
     	int j = i;
     	int tmp = a[j];
     	
     	while(j >= h && tmp < a[j - h]){
     		a[j] = a[j - h];
     		j -= h;
     	}

     	a[j] = tmp;

    	}
  
     h/=3;

 	  }

  }

  /////////////////////////////////Main Code//////////////////////////////////////

    int main(){
        
     assert(N == 18);

     //SHELL SORT
     ShellSort(a);

    for(auto x : a)  cout << x <<" ";

    puts("");

    return 0;

    }
