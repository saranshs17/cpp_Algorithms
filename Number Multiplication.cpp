#include<bits/stdc++.h>
using namespace std;
#define sped ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define ln '\n'
#define int long long
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mii map<int, int>
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define vvi vector<vi>
#define pb push_back
#define setbitsll(n)  __builtin_popcountll(n) //counts all set bits in (int)num, setbitsll(num)==1 i.e no. is power of 2
#define setbits(n)  __builtin_popcount(n) 
#define msb(x) __builtin_clzll(x) // to count leading 0 , to find index = 64-msb(n)-1
#define lsb(x) __builtin_ctzll(x) // to count trailing 0 , to find index = lsb(n)
#define yesno(f) f?cout<<"YES\n":cout<<"NO\n"
#define mx(v) *max_element(v.begin(),v.end())
#define mn(v) *min_element(v.begin(),v.end())
#define loop(n) for(int i=0; i<n; ++i)
#define alone(v) v.erase(unique(v.begin(),v.end()),v.end())
#define inf LLONG_MAX

const long long M=1000000007;
const int N = 1000000;
vector<bool> isPrime(N+1,1);

int lcm(int a, int b){int g=__gcd(a, b); return a/g*b;}
 
int fact(int n){n%=M; if(n<=1) return 1; return n*fact(n-1)%M;}
 
int powm(int x,int n){
    x%=M;
    if(n==0)return 1; if(n==1)return x;
    int p= powm(x*x,n/2);
    if(n%2) return p*x%M; return p;
}

void sieve(){isPrime[0]=isPrime[1]=false;for(int i=2;i<N;++i){if(isPrime[i]==true){for(int j=2*i;j<N;j+=i){isPrime[j]=false;}}}}

//<---------------------------code begins--------------------------->

int32_t main(){
    sped
    int t;
    t=1;
    while(t--){
    	int n; // n is the number of digits 
    	cin>>n;
    	int base; // base is the no. in which Base you want to represent you number...
    	cin>>base;
    	vi v(n);
    	loop(n)cin>>v[i];
    	int m; // multiplier
    	cin>>m;
    	vi number; // stores the result
    	int carry =0; // initially no carry
    	for(int i=n-1;i>=0;--i){
    		int bit = ( v[i]*m +carry ) % base;
    		number.pb(bit);
    		carry= (v[i] * m + carry) / base;
    	}
    	while(carry){
    		int bit=carry % base;
    		number.pb(bit);
    		carry = carry/base;
    	}
    	reverse(all(number));
    	for(auto x:number)cout<<x<<" ";
    	cout<<ln;
    }
}
