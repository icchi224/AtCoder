#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;
using P = pair<int, int>;
void opvec1(vector<int> &vec);

// ダイクストラ法 O(MlogN)
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bl

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<P>> G(N);
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }

    int inf = 1e9;

    // ダイクストラ法
    auto dijkstra = [&](int s) -> vector<int> {
        vector<int> dist(N, inf);
        vector<bool> visited(N);
        // ヒープキュー
        priority_queue<P, vector<P>, greater<P>> hq;

        dist[s] = 0;
        hq.emplace(0, s);  // (cost，node)

        while (!hq.empty()) {
            int pos = hq.top().second;
            hq.pop();

            if (visited[pos]) continue; // 既に訪れていたらcontinue
            visited[pos] = true;

            // 遷移
            for (auto [next, cost]: G[pos]) {
                if (dist[pos] + cost < dist[next]) {
                    dist[next] = dist[pos] + cost; // 更新
                    hq.emplace(dist[next], next);
                }
            }
        }
        return dist;
    };
    
    vector<int> dist = dijkstra(0);

    opvec1(dist);
}


//
void opvec1(vector<int> &vec) {
    rep(i, vec.size()) cout << vec[i] << " ";
    cout << endl;
}