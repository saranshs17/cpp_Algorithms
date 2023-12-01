long long max_sum=arr[0];
    	long long max_till_now=0;
    	for(int i=0;i<n;++i){
    		max_till_now+=arr[i];
    		if(max_sum<max_till_now){
    			max_sum=max_till_now;
    		}
    		if(max_till_now<0){
    			max_till_now=0;
    		}
    	}
