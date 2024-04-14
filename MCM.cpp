#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
void print(vector<vector<int>> &s, int i, int j, int n, char &mat)
{
    if (i == j)
    {
        cout << mat++;
        return;
    }
    cout << "(";
    print(s, i, s[i][j], n, mat);
    print(s, s[i][j] + 1, j, n, mat);
    cout << ")";
}
int main()
{
    int n;
    cin >> n;
    vector<int> order;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        order.push_back(x);
    }
    int m[n][n];
    vector<vector<int>> s(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        m[i][i] = 0;
    }
    for (int l = 2; l < n; ++l)
    {
        for (int i = 1; i < n - l + 1; ++i)
        {
            int j = i + l - 1;
            m[i][j] = inf;
            for (int k = i; k <= j - 1; ++k)
            {
                int q = m[i][k] + m[k + 1][j] + order[i - 1] * order[k] * order[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << m[1][n - 1] << '\n';
    char mat = 'A';
    print(s, 1, n - 1, n, mat);
}
