  // swaps elements in given ORDER to a fixed POSITIONS, simulates swapping in the process
  int n = vec.size();
  vector<int> pos(n, -1);
  int ops = 0;
  for(int i = 0; i < n; ++i){
      int req_pos = n - 1 - i;
      ops += abs(req_pos - pos[i]);
      for(int idx = pos[i] + 1; idx <= req_pos; ++idx){
              pos[vec[idx]]--; // bcz I'm swapping myself with them
              vec[idx - 1] = vec[idx]; // swapping values
      }
      pos[i] = req_pos;
      vec[pos[i]] = i;
  }
//////////////////////////////////////////////////////////////////////////

// bubble sort vec to nearest possible satisfying match (min cost / swaps)
  int res = 0;
  for(int i = 0; i < n; ++i){
      int req = n - 1 - i;
      int j = i;
      while(j < n && vec[j] < req) j++; // skips un-qualified candidates
      if(j == n) return -1;
      // else I found a possible match for the current index
      while(i < j) swap(vec[j], vec[j - 1]), res++, j--;
      assert(vec[i] >= req);
  }
