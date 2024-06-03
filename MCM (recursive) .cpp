int dp[101][101];
    int f(int i,int j,int arr[],int n){
        if (i==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j-1;++k){
            int pro=f(i,k,arr,n)+f(k+1,j,arr,n)+arr[i-1]*arr[k]*arr[j];
            ans=min(ans,pro);
        }
        return dp[i][j]=ans;
    }
    int matrixMultiplication(int N, int arr[])
    {   
        for(int i=0;i<101;++i)for(int j=0;j<101;++j)dp[i][j]=-1;
        return f(1,N-1,arr,N);
    }
