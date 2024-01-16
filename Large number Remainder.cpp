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
#define sara(x) cout << #x << " = " << x << "\n"
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
#define pi 3.14159265359

// In Interactive problem use :
// endl (flushes buffer automatically)(provide o/p for each query) 
// or use '\n' (provide o/p for all query at once) along with cout.flush();

// n=10010010
//       0010(want till ith)
// extracted no.=(1<<i)-(n%(1<<(i+1))) i.e.0010

// upper bound of factors:cbrt(n)

const long long M = 1000000007;
const int N = 1000000;
vector<bool> isprime(N + 1, true);
vector<int> spf(N + 1, 0);

int lcm(int a, int b){int g=__gcd(a, b); return a/g*b;}
 
int fact(int n){n%=M; if(n<=1) return 1; return n*fact(n-1)%M;}

int binexp(int a, int b , int m) {
  if (b == 0) return 1;
  if (b == 1) return (a) % m;
  int res = binexp(a, b / 2 , m);
  if (b % 2 == 0) return (res * res) % m;
  return ((res * res) % m * (a) % m) % m;
}

int modinv(int a, int p)
{return binexp(a, p - 2, p);}

void SPF(){
  for (int i = 1; i <= N; i++){ spf[i] = i;}spf[1] = -1;
  for (int i = 2; i * i <= N; i++) {if (spf[i] == i) {for (int j = i * i; j <= N; j += i) {if (spf[j] == j) {spf[j] = i;}}}}
}

void sieve() {
    isprime[0]=isprime[1] = false;
for (int i = 2; i * i <= N; i++) {if (isprime[i]) {for (int j = i * i; j <= N; j += i) {if (isprime[j] == true) isprime[j] = false;}}}
}

//<---------------------------code begins--------------------------->

int32_t main(){
    //sieve();
    // SPF();
    sped
    int t;
    t=1;
    while(t--){
    	int mod;
    	string num;cin>>num>>mod;
    	int rem=0;
    	for(int i=0;i<num.size();++i){
    		rem=(rem*10+num[i]-'0')%mod;
    	}
    	cout<<rem<<ln;
    }
}
