#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;cin>>s>>t;
    int n=s.size();
    int m=t.size();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                if(dp[i-1][j]>=dp[i][j-1]){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
    }
    int l=n,r=m;
    string ans;
    while(l>0 && r>0){
        if(s[l-1]==t[r-1]){
            ans+=s[l-1];
            l--;
            r--;
        }else if(dp[l-1][r]>=dp[l][r-1]){
            l--;
        }else{
            r--;
        }
    } 
    reverse(ans.begin(),ans.end());
    cout<<ans<<'\n';
}
