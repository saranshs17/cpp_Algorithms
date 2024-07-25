#include <bits/stdc++.h> 
int f(int i,int mask,vector<vector<int>> &dist,vector<vector<int>>& dp){
	if(mask==0)return dist[i][0];
	if(dp[i][mask]!=-1)return dp[i][mask];
	int ans=INT_MAX;
	for(int j=1;j<dist.size();++j){
		if(mask&(1<<j)){
			int submask=mask^(1<<j);
			ans=min(ans,dist[i][j]+f(j,submask,dist,dp));
		}
	}
	return dp[i][mask]=ans;
}
int shortestRoute(vector<vector<int>> &distance)
{
	int ans=-1;
	int n=distance.size();
	vector<vector<int>> dp(n,vector<int>(1<<n,-1));
	ans=f(0,(1<<(n))-2,distance,dp);
	return ans;
}
