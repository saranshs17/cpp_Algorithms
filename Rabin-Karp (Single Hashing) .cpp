const long long M = 1000000007;
#define ll long long int
class Solution {
public:
    ll hashValue(string str,ll RADIX, ll m){
        ll ans=0,factor=1;
        for( ll i = m-1;i>=0;--i){
            ans+=((str[i]-'a')*factor)%M;
            factor = (factor*RADIX)%M;
        }
        return ans%M;
    }
    int strStr(string haystack, string needle) {
        ll n=haystack.size();
        ll m = needle.size();
        if(n<m)return -1;
        ll RADIX=26, MAX_WEIGHT=1;
        for(ll i =1;i<=m;++i){
            MAX_WEIGHT = (MAX_WEIGHT*RADIX)%M;
        }
        ll hashNeedle=hashValue(needle,RADIX,m);
        ll hashHaystack=0;
        for(ll i=0;i<=n-m;++i){
            if(i==0){
                hashHaystack = hashValue(haystack,RADIX,m);
            }else{
                hashHaystack = ( (hashHaystack*RADIX)%M - ((haystack[i-1]-'a')*MAX_WEIGHT)%M + (haystack[i+m-1]-'a') + M )% M;
            }
            if(hashHaystack == hashNeedle){
                return i;
            }
        }
        return -1;
    }
};
