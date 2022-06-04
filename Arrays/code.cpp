#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        vector<int> pre(n + 1, 0);
        pre[0] = 0;
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + v[i - 1];
        }

        if (k < n) {
            int ans = 0;
            for (int i = 0; i <= n - k; i++) {
                ans = max(ans, pre[i + k] - pre[i] + k * (k - 1) / 2);
            }
            cout << ans << "\n";
        } else {
            int ans = (k - n) * n;
            ans += pre[n];
            ans += n * (n - 1) / 2;

            cout << ans << "\n";
        }
    }

    return 0;
}