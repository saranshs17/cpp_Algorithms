#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int a[n];
    for( int i = 0 ; i < n ; i++ ) cin >> a[i];
    vector<int> dp(n); // longest increasing subsequence ending at index i
    for( int i = 0 ; i < n ; i++ ){
        int mx = 0;
        for( int j = 0 ; j < i ; j++ ){
            if( a[j] < a[i] ) mx = max( mx , dp[j] );
        }
        dp[i] = 1 + mx;
    }
    // our ans = max of all dp[i] elements
    // it is not necessary that lcs end at the last element
    int Lislength = *max_element(dp.begin(),dp.end()); 


    // how to find the lis


    vector<int> lis; // contains the index of the lis
    int ptr;
    for( int i = n-1 ; i >= 0 ; i-- ){
        if( dp[i] == Lislength ){
            ptr = i; // index at which the lis is ending
            break;
        }
    }    
    while(dp[ptr]!=1){ // last number of the lis
        lis.push_back(ptr);
        for( int j = ptr-1 ; j >= 0 ; j-- ){
            if( dp[j] == dp[ptr]-1 ){
                ptr = j;
                break;
            }
        }
    }
    lis.push_back(ptr);
    reverse(lis.begin(),lis.end());
    for( auto i : lis ) cout << a[i] << " ";
}
