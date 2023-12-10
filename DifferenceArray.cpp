#include <bits/stdc++.h>
using namespace std;
int main() {

	int n,queries,add;
  cin>>n>>queries>>add;
  int arr[n];
  int diff[n]={0};
  for(int i=0;i<n;++i){
    cin>> arr[i];
  }
  for(int i=0;i<queries;++i){
    int l,r;
    cin>>l>>r;
    if(r>=n){
      diff[l]+=add;
    }else{
      diff[l]+=add;
      diff[r+1]-=add;
    }
  }
  arr[0]+=diff[0];
  for(int i=1;i<n;++i){
    diff[i]+=diff[i-1];
    arr[i]+=diff[i];
  }
  for(auto x:arr)cout<<x<<" ";
	return 0;
}
