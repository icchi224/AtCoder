#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;
void opvec1(vector<int> &vec);
void opvec2(vector<vector<int>> &vec);
void opset(set<int> &S);

// 深さ優先探索 O(N + M)
//https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_am

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    vector<bool> vis(N);  // 頂点に訪れたかどうか

    // dfs
    auto dfs = [&](auto dfs, int pos) -> void {
        vis[pos] = true;
        for (auto to: G[pos]) {
            if (!vis[to]) {
                dfs(dfs, to);
            }
        }
    };

    dfs(dfs, 0);

    // answer
    for (int i = 0; i < N; i++) {
        if (!(vis[i])) {
            cout << "The graph is not connected." << endl;
            return 0;
        }
    }
    cout << "The graph is connected." << endl;
}


//
void opvec1(vector<int> &vec) {
    rep(i, vec.size()) cout << vec[i] << " ";
    cout << endl;
}
void opvec2(vector<vector<int>> &vec) {
    rep(i, vec.size()) {
        rep(j, vec[0].size()) cout << vec[i][j] << " ";
        cout << endl;
    }
}
void opset(set<int> &S) {
    for (auto s: S) cout << s << " ";
    cout << endl;
}