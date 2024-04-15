#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int dfs(int node, vector<vector<pair<int, int>>> adj, vector<int> &ans, int par, int tol, int root)
{

    if (adj[node].size() == 1 && node != root)
    {
        return 0;
    }
    // vector<int>v;
    int mx = -1;
    for (auto it : adj[node])
    {
        if (it.ff != par)
        {
            int x = it.ss + dfs(it.ff, adj, ans, node, tol, root);
            mx = max(mx, it.ss);
            //    v.pb(it.ss);
            if (x > tol)
            {

                ans.push_back(it.ff);
            }
            else
            {
                mx = max(x, mx);
            }
        }
    }
    if (mx == -1)
    {
        return 0;
    }
    else
    {
        return mx;
    }
}

int main()
{
    cout << "enter number of nodes:" << endl;
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> adj(n + 1);
    cout << "enter edges:" << endl;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << "enter root node:" << endl;
    int root;
    cin >> root;
    int tol;
    cout << "tolerance limit? ";
    cin >> tol;
    vector<int> ans;
    dfs(root, adj, ans, root, tol, root);

    for (auto it : ans)
    {
        cout << it << " ";
    }
}
