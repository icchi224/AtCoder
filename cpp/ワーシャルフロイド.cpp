#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// ワーシャルシャルフロイド法 O(N^3)
// 全頂点から全頂点までのコストを計算
int main() {
    int N, M;
    cin >> N >> M;
    ll inf = 1e18;  // コストの初期値
    vector cost(N, vector<ll>(N, inf));    // コストの2次元配列
    rep(i, N) cost[i][i] = 0;   // 同じ頂点に行く場合はコスト0

    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        cost[a][b] = c; // aからbへのコストはc
    }
    
    // ワーシャルシャルフロイド
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                // 頂点kを経由して頂点iから頂点jに行く最小コスト
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    rep(i, N) {
        rep(j, N) cout << cost[i][j] << " ";
        cout << endl;
    }
}
