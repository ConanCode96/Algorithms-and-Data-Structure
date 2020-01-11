
const int MX = 2e6 + 10;

//SPARSE TABLE

int ST[22][MX];

void build(const vector<int> &a)
{
  int n = a.size();
  for (int i = 0; i < n; ++i)
    ST[0][i] = a[i];
  for (int lgN = 1; (1 << lgN) <= n; ++lgN)
  {
    for (int i = 0; i + (1 << lgN) <= n; ++i)
    {
      int pv_lgN = 1 << (lgN - 1);
      ST[lgN][i] = max(ST[lgN - 1][i], ST[lgN - 1][i + pv_lgN]);
    }
  }
}

int query(int l, int r)
{
  int sz = r - l + 1;
  int lg = 0;
  while ((1 << (lg + 1)) <= sz)
    lg++;
  return max(ST[lg][l], ST[lg][l + (sz - (1 << lg))]);
}
