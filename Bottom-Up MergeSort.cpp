 #include<bits/stdc++.h>

 using namespace std;

  int a[] = {4, 4, 5, 2, 2, 7, 9, 0, 1, 5, 0, 0, 5, 9, 3, 2, 30, 6};
  const int N = sizeof(a) / sizeof(a[0]);
  int aux[N];

	inline void merge(int lo, int mid, int high){

    	int sz = high - lo + 1;

    	//cout << sz << endl;

    	for(int i = lo, j = mid + 1, k = 0; k < sz; k++){

    		if(i > mid) aux[k] = a[j++];
    		else if(j > high) aux[k] = a[i++];
    		else if(a[i] < a[j]) aux[k] = a[i++];
    		else
    			aux[k] = a[j++];
    	}


    	for (int i = 0; i < sz; ++i) 
    		a[lo + i] = aux[i];
    	

    }


    inline void BU_MergeSort(int *a){

   	for (int i = 1; i <= N; i*= 2)
		for(int j = 0; j < N; j += 2*i)
			merge(j, j + i - 1, min(j + 2*i - 1, N - 1));

    }

    

  /////////////////////////////////Main Code//////////////////////////////////////

    int main(){
        
     assert(N == 18);

     //Bottom-Up MergeSort
     BU_MergeSort(a);

   	for(auto x : a)  cout << x <<" ";

    puts("");

    return 0;

}
