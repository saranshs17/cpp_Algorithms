#include <bits/stdc++.h>
#define sped ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ln '\n'
#define int long long
#define f first
#define s second
#define loop(n) for(int i = 0; i < n; ++i)
#define rep(i, begin, end) for(int i = begin; i < end; ++i)

using namespace std;

const long long M = 1e9 + 7;
const int N = 1000000;
vector<bool> isPrime(N + 1, 1);
//<---------------------------code begins--------------------------->

int ring_contribute(int d, int x, int y) {
    if (y == -d) {
        return (d - 1) + (d + x) / 2;
    } else if (y == d) {
        return (d - 1) + 2 * d + (d - x) / 2;
    } else if (x == -d) {
        return (d - y) / 2 - 1;
    } else {
        return 2 * d + (d + y) / 2 - 1;
    }
}

int32_t main() {
    sped
    int n;
    cin >> n;
    int n2 = n * n;
    int N = n - 1;

    for (int y = N; y >= -N; y -= 2) {
        for (int x = -N; x <= N; x += 2) {
            int d = max(abs(x), abs(y));
            int v = (d - 1) * (d - 1);
            v += ring_contribute(d, x, y);
            cout << n2 - v << " ";
        }
        cout << ln;
    }
}
