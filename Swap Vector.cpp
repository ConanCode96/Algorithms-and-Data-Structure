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
