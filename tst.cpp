#include <bits/stdc++.h>
using namespace std;

#define int long long
#define LL_MIN LLONG_MIN
#define LL_MAX LLONG_MAX

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        for (int i = 0; i < n; i++) {
            int x = 0, y = 0;
            for (int j = i + 1; j < n; j++) {
                if (a[i] > a[j])
                    x++;
                else if (a[i] < a[j])
                    y++;
            }
            cout << max(x, y) << " ";
        }
        cout << "\n";
    }
    return 0;
}
