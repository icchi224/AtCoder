#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;
using P = pair<int, int>;
void output_vec2(auto &vec2);

// 強連結成分分解 O(N+M)
// 有効グラフを強連結成分(SCC)に分解する
// https://atcoder.jp/contests/typical90/tasks/typical90_u

int main() {
    int N, M;
    cin >> N >> M;
    // G1 は有向グラフ　G2 は G1 の逆有効グラフ
    vector<vector<int>> G1(N), G2(N), SCC;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G1[a].emplace_back(b);
        G2[b].emplace_back(a);
    }

    vector<bool> vis(N);
    vector<int> memo, group;

    // dfs1 G1で行ける頂点を帰りがけ順に記録
    auto dfs1 = [&](auto dfs1, int pos) -> void {
        vis[pos] = true;
        for (auto to: G1[pos]) {
            if (!vis[to]) {
                dfs1(dfs1, to);
            }
        }
        memo.emplace_back(pos);
    };

    // dfs2 G2で行先の頂点を同じgroupに追加
    auto dfs2 = [&](auto dfs2, int pos) -> void {
        vis[pos] = true;
        group.emplace_back(pos);
        for (auto to: G2[pos]) {
            if (!vis[to]) {
                dfs2(dfs2, to);
            }
        }
    };

    // 1回目のdfs
    rep(i, N) {
        if (vis[i]) continue;
        dfs1(dfs1, i);  // 頂点からdfs1
    }
    reverse(all(memo));

    // 2回目のdfs
    rep(i, N) vis[i] = false;
    for (int i: memo) {
        if (vis[i]) continue;
        group = {};
        dfs2(dfs2, i);
        SCC.emplace_back(group);    // 強連結成分に分解したgroupをSCCに追加
    }

    //output_vec2(SCC);

    // Answer
    ll ans = 0;
    for (auto vec: SCC) {
        ll x = vec.size();
        ans += x * (x-1) / 2;
    }
    cout << ans << endl;
}

void output_vec2(auto &vec2) {
    for (auto vec1: vec2) {
        for (auto i: vec1) {
        cout << i << " ";
        } 
    cout << endl;
    }
}