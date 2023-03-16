#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using ll = long long;
void output_vec1(auto &vec1);
void output_vec2(auto &vec2);

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, -1, 0, 1};

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
//mint::set_mod(MOD);


int main() {
  vector<int> vec = {1, 4, 6, 2};
  sort(all(vec), greater<int>()); // 降順

  // number to string
  int number = 100;
  string s = to_string(number);

  // string to number
  string ss = "100";
  int n = stoi(ss);

  // char to number
  char c = '9';
  int n1 = int(c - '0');

  if (false) {
    // 集合set
    set<int> S(all(vec)); // vector -> set
    auto itr = S.lower_bound(100); // x以上の最小の数

    // もしitr が最大値よりも大きいとき
    if (itr == S.end()) {
      cout << -1 << endl;
    }
    // もしitr が S の最小値じゃないとき
    if (itr != S.begin()) {
      itr--;  // S の 1つ小さい値に移動可能
    }
    cout << *itr << endl; // 値
    cout << *begin(S) << " " << *rbegin(S) << endl; //最小と最大
  }

  if (false) {
    // priority_queue 最も大きいものを取りだす
    priority_queue<int> pq;
    // 小さい順に取り出される優先度付きキュー
    priority_queue<int, vector<int>, greater<int>> pq2;
  }

  if(false) {
    // lower_bound / upper_bound
    vector<int> bo = {0,10,20,30,40};
    // 20以上の最小の数
    cout << *lower_bound(all(bo), 20) << endl;  // 値
    cout << lower_bound(all(bo), 20) - bo.begin() << endl;  // 位置
    // 20より大きいの最小の数
    cout << *upper_bound(all(bo), 20) << endl;
  }
  if (true) {
    double ans = (double) 1/3;
    // 小数点以下10桁で出力
    cout << fixed << setprecision(10) << ans << endl;
  }
}

//
void output_vec1(auto &vec1) {
    for (auto i: vec1) {
        cout << i << " ";
    }
    cout << endl;
}
void output_vec2(auto &vec2) {
    for (auto vec1: vec2) {
        for (auto i: vec1) {
            cout << i << " ";
        } 
    cout << endl;
    }
}