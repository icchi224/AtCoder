#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;
#include <atcoder/all>
using namespace atcoder;

/*
 最大フロー問題 O(FM) ?, 総流量F,辺の数M
 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bp

*/

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> A(M), B(M), C(M);
  rep(i, M) cin >> A[i] >> B[i] >> C[i];

  mf_graph<int> G(N+1); // グラフ

  rep(i, M) {
    G.add_edge(A[i], B[i], C[i]); // aからbへ容量cの辺を追加
  }

  int ans = G.flow(1, N); // 頂点1から頂点Nまでのmax_flow
  cout << ans << endl;
}