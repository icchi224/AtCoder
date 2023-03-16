#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#include <atcoder/all>
using namespace atcoder;

// 最小全域木 
//　クラスカル法 O(MlogM + N)
int main() {
  int N, M;
  cin >> N >> M;
  
  vector<int> A(M), B(M), C(M);
  rep(i, M) {
    cin >> A[i] >> B[i] >> C[i];
    A[i]--; B[i]--;
  }
  
  vector<P> E;
  rep(i, M) E.emplace_back(make_pair(C[i], i));
  sort(all(E)); // costが小さい順にsort
  
  dsu d(N); // union-find

  int ans = 0;  // 最小全域木のコストの合計
  for (auto e: E) {
    int cost = e.first;
    int idx = e.second;
    if (!d.same(A[idx], B[idx])) {  // 全域木に含まれるかどうか
      d.merge(A[idx], B[idx]);  // 全域木に追加
      ans += cost;
    }
  }
  cout << ans << endl;
}