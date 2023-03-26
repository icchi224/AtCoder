#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main() {
    int h, w;
    cin >> h >> w;
    vector a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];

    vector<int> road;
    int ans = 0;

    auto dfs = [&](auto dfs, int i, int j) -> void {
        road.emplace_back(a[i][j]);
        if (i == h-1 && j == w-1) {
            set<int> st(all(road));
            if (st.size() == h + w - 1) ans++;
            road.pop_back();
            return;
        }
        if (i < h - 1) dfs(dfs, i+1, j);
        if (j < w - 1) dfs(dfs, i, j+1);
        road.pop_back();
    };

    dfs(dfs, 0, 0);
    cout << ans << endl;
}