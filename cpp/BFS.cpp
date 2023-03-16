#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

// BFS O(N + M-)
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

    vector<int> dist(N, -1);

    dist[0] = 0;
    deque<int> que;
    que.emplace_back(0);

    while (!(que.empty())) {
        int pos = que.front();
        que.pop_front();

        for (auto to: G[pos]) { // 遷移
            if (dist[to] == -1) {
                que.emplace_back(to);
                dist[to] = dist[pos] + 1;
            }
        }
    }

    rep(i, N) {
        cout << dist[i] << endl;
    }
}