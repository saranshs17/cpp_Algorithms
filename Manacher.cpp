#include<bits/stdc++.h>
using namespace std;
string t;
vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^"; 
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}


vector<int> manacher(string &s) {
    for(auto c: s) {
        t += string("#") + c;
    }
    t+='#';
    auto res = manacher_odd(t);
    return vector<int>(begin(res), end(res));
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        string s;cin>>s;
        vector<int>res=manacher(s);
        int id=0,longest=0;
        for(int i=0;i<res.size();i++){
            if(longest<res[i]){
                longest=res[i];
                id=i;
            }
        }
        int leftE=id-longest+1,rightE=id+longest-1;
        string ans="";
        for(int i=leftE;i<=rightE;i++){
            if(t[i]=='#')continue;
            ans.push_back(t[i]);
        }
        cout<<ans;
}
