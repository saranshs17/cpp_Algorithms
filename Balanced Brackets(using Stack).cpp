#include<bits/stdc++.h>
#define tstart auto start = high_resolution_clock::now();
#define tstop auto stop = high_resolution_clock::now();
#define tduration auto duration = duration_cast<microseconds>(stop - start);
#define tprint cout << "Time taken by function: "<< duration.count()<< " microseconds" << endl;
#define sped ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define ln '\n'
#define ll long long
#define f first
#define s second
#define loop(n) for(int i=0;i<n;++i)
using namespace std;
using namespace std::chrono;
const long long M=1e9+7;

//<---------------------------code begins--------------------------->
unordered_map<char,int> symbols={{'[',-1},{'{',-2},{'(',-3},{']',1},{'}',2},{')',3}};
string isBalanced(string str){
    stack<int>s;
    for(char bracket:str){
        if(symbols[bracket]<0) s.push(bracket);
        else{
            if(s.empty()) return "NO";
            char top=s.top();
            s.pop();
            if(symbols[top]+symbols[bracket]!=0){
                return "NO";
            }
        }
    }
    if(s.empty()) return "YES";
    else return "NO";
}
int32_t main(){    
    sped
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        cout<<isBalanced(str)<<ln;
    }
}
