int maxSumIS(int arr[], int n)  
	{  
	    int msis[n];
	    for(int i=0;i<n;++i){
	        msis[i]=arr[i];
	    }
	    for(int i=1;i<n;++i){
	        for(int j=i-1;j>=0;--j){
	            if(arr[j]<arr[i] && msis[i]<msis[j]+arr[i]){
	                 msis[i]=msis[j]+arr[i];
	            }
	        }
	    }
	    int ans=0;
	    for(int i=0;i<n;++i)ans=max(ans,msis[i]);
	    return ans;
	}  
