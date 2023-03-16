#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// トポロジカルソート O(N+M)
// 有向非巡回グラフを順序付け
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=ja

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    vector<int> deg(N);   // 各頂点の入次数

    rep(i, M) {
        int a, b;
        cin >> a >> b;
        //a--; b--;
        G[a].emplace_back(b);
        deg[b]++;
    }

    vector<int> sorted; // sort後の配列
    queue<int> que;
    rep(i, N) {
        if (!deg[i]) que.push(i);   // 入時数0の頂点をpush
    }

    while (!que.empty()) {
        int pos = que.front();
        que.pop();
        sorted.emplace_back(pos);
        for (auto to: G[pos]) {
            deg[to]--;
            if (!deg[to]) que.push(to); // 入時数0の頂点をpush
        }
    }

    for (auto a: sorted) cout << a << endl;
}
