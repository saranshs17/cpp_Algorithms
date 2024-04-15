// Merge sort Algo using Divide and Conquer technique
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &v,int beg,int mid,int end){
    vector<int> left,right;
    for(int i=beg;i<=mid;++i){
        left.push_back(v[i]);
    }
    for(int i=mid+1;i<=end;++i){
        right.push_back(v[i]);
    }
    int i=0,j=0;
    int k=beg;
    while(i<left.size() && j<right.size()){
        if(left[i]<right[j]){
            v[k]=left[i];
            i++;
        }else{
            v[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<left.size()){
        v[k]=left[i];
        i++;k++;
    }
    while(j<right.size()){
        v[k]=right[j];
        j++;k++;
    }
}
void MergeSort(vector<int> &v,int beg, int end){
    if(beg<end){
        int mid=(beg+end)/2;
        MergeSort(v,beg,mid);
        MergeSort(v,mid+1,end);
        merge(v,beg,mid,end);
    }
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    cout<<"Enter array \n";
    for(int i=0;i<n;++i)cin>>v[i];
    MergeSort(v,0,n-1);
    cout<<"Sorted array:";
    for(int i=0;i<n;++i)cout<<v[i]<<" ";
}
