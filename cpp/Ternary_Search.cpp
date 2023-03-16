#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;
using P = pair<int, int>;
void opvec1(vector<int> &vec);
void opvec2(vector<vector<int>> &vec);
void opset(set<int> &S);

// 三分探索 下に凸のグラフで極値を探す

//判定
ll f(ll x) {
  return (x - 3)*(x - 3);
}
// 三分探索
ll search() {
  ll L = 0, R = 1e9;
  while (R - L > 2) {
    cout << L << " " << R << endl;
    ll m1 = (L * 2 + R) / 3;  // 左側
    ll m2 = (L + R * 2) / 3;  // 右側
    if (f(m1) > f(m2)) L = m1;
    else R = m2;
  }
  
  // 改めてLLからRRまでの最小値を求める
  ll LL = max(0LL, L - 100);  // 0以下にならないように
  ll RR = R + 100;
  ll res = LL;
  for (ll i = LL; i <= RR; i++) {
    if (f(i) < f(res)) {
      res = i;
    }
  }
  return res;
}

int main() {
  ll ans = search();
  cout << ans << endl;
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