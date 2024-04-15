// kth smallest element using quick select
#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &v, int beg, int end)
{
  int pivot = v[end];
  int i = beg;
  for (int j = beg; j < end; j++)
  {
    if (v[j] <= pivot)
    {
      swap(v[i], v[j]);
      i++;
    }
  }
  swap(v[i], v[end]);
  return i;
}
int quickselect(vector<int> &v, int beg, int end, int i)
{
  int r = partition(v, beg, end);
  int k = r - beg + 1;
  if (i == k)
    return v[r];
  if (i < k)
    return quickselect(v, beg, r - 1, i);
  return quickselect(v, r + 1, end, i - k);
}
int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i];
  cout << quickselect(v, 0, n - 1, k);
}
