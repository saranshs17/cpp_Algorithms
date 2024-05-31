const long long M_1 = 1000000007;
const long long M_2 = 1000000033;
#define ll long long int
class Solution {
public:
    pair<ll,ll> hashValue(string str,ll RADIX_1,ll RADIX_2, ll m){
        ll ans_1=0,factor_1=1;
        ll ans_2=0,factor_2=1;
        for( ll i = m-1;i>=0;--i){
            ans_1+=((str[i]-'a')*factor_1)%M_1;
            factor_1 = (factor_1*RADIX_1)%M_1;
            ans_2+=((str[i]-'a')*factor_2)%M_2;
            factor_2 = (factor_2*RADIX_2)%M_2;
        }
        return {ans_1 % M_1,ans_2 % M_2};
    }
    int strStr(string haystack, string needle) {
        ll n=haystack.size();
        ll m = needle.size();
        if(n<m)return -1;
        ll RADIX_1=26, MAX_WEIGHT_1=1;
        for(ll i =1;i<=m;++i){
            MAX_WEIGHT_1 = (MAX_WEIGHT_1*RADIX_1)%M_1;
        }
        ll RADIX_2=27, MAX_WEIGHT_2=1;
        for(ll i =1;i<=m;++i){
            MAX_WEIGHT_2 = (MAX_WEIGHT_2*RADIX_2)%M_2;
        }
        pair<ll,ll> hashNeedle=hashValue(needle,RADIX_1,RADIX_2,m);
        pair<ll,ll> hashHaystack;
        hashHaystack.first=0;
        hashHaystack.second=0;
        for(ll i=0;i<=n-m;++i){
            if(i==0){
                hashHaystack = hashValue(haystack,RADIX_1,RADIX_2,m);
            }else{
                hashHaystack.first = ( (hashHaystack.first*RADIX_1)%M_1 - ((haystack[i-1]-'a')*MAX_WEIGHT_1)%M_1 + (haystack[i+m-1]-'a') + M_1 )% M_1;
                hashHaystack.second = ( (hashHaystack.second*RADIX_2)%M_2 - ((haystack[i-1]-'a')*MAX_WEIGHT_2)%M_2 + (haystack[i+m-1]-'a') + M_2 )% M_2;
            }
            if((hashHaystack.first == hashNeedle.first) || (hashHaystack.second == hashNeedle.second)){
                return i;
            }
        }
        return -1;
    }
};
