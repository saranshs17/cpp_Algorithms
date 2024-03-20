#include <bits/stdc++.h>
using namespace std;
vector<int> kmp(string s) 
{
    int n = s.size();
    vector<int> pie(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pie[i - 1];
        while (s[i] != s[j] && j > 0){
            j = pie[j - 1];
        }
        if (s[i] == s[j])
            j++;
        pie[i] = j;
    }
    return pie;
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    string newS = t + "#" + s;
    vector<int> ans = kmp(newS);
    int m = t.size(), cnt = 0;
    for (int i = m + 1; i < newS.size(); i++){
        if (ans[i] == m)
            cnt++;
    }
    cout << cnt;
}
