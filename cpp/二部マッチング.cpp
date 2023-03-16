#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;
#include <atcoder/all>
using namespace atcoder;

/*
二部マッチング O(N^3)
https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bq
*/

int main() {
  int N;
  string c[155];
  cin >> N;
  rep(i, N) cin >> c[i];

  mf_graph<int> G(2*N + 2);
  rep(i, N) {
    G.add_edge(2*N, i, 1);  // 始点2Nから頂点i
    G.add_edge(N + i, 2*N + 1, 1);  // 頂点N+iから終点2N+1

    rep(j, N) {
      if (c[i][j] == '#') {
        G.add_edge(i, N + j, 1);  // iからN+jへ辺を追加
      }
    }
  }
  int ans = G.flow(2*N, 2*N + 1); // 始点2Nから終点2N+1のFlow
  cout << ans << endl;
}