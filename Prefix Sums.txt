/* When to use prefix Sums?
   - range sum
   - xor,product
   - frequency
   - static(no updates)
  => More Advanced
   - combine with binary search
   - subtree/path sum in a tree
   - 2d prefix sums 
   - SOS(sum over subset)
*/

// Ex-1 : Given array of n integers find sum of values in range [a,b] 
// Link-> https://cses.fi/problemset/task/1646
// Solution:
int n,q; cin>>n>>q;
vector<int> v(n); loop(n){cin>>v[i];};
vector<int> pref(n+1);
for(int i=1;i<=n;++i){pref[i]=pref[i-1]+v[i];};  // precomputation
loop(q){int a,b; cin>>a>>b; cout<<pref[b]-pref[a-1]<<ln;};

// Ex-2 : Given string S of length N,Answer Q queries, Input : L,R ,, find most common character in the substring S[L..R]. 
// Link-> https://www.geeksforgeeks.org/queries-to-print-the-character-that-occurs-the-maximum-number-of-times-in-a-given-range/
// Solution:
string s; cin>>s; int n =s.length();
vector<vector<int>> pref(n+1,vector<int>(26));
// precomputation
loop(n){ pref[i+1] = pref[i]; int char_id=s[i]-'a'; pref[i+1][char_id]++;};
int q; cin>>q;
loop(q){
int L,R; cin>>L>>R;  // 0 based
char best_char='?'; int best_freq = -1;
rep(char_id,0,26){
int freq=pref[R+1][char_id] - pref[L][char_id];
if(freq>best_freq){best_freq = freq; best_char = 'a'+char_id;}} 
cout<<best_char<<ln;
}

// Ex-3 : Need to increase all elements of the array at indices L..R by +x.
// Link(similar)-> https://www.hackerrank.com/challenges/crush/problem
// Solution:
int n; cin >>n; 
vector<int> a(n); loop(n){cin>>a[i];};
vector<int> pref(n+1);
int q; cin>>q;
loop(q){
int L,R,data=0;  // 1-based
cin>>L>>R>>data;
pref[L-1]+=data; 
pref[R]-=data;
}
rep(i,1,n+1){pref[i]+=pref[i-1];}; 
loop(n){cout<<a[i]+pref[i]<<" ";};
