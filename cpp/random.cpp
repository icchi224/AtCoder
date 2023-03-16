#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;
void opvec1(vector<int> &vec);
void opvec2(vector<vector<int>> &vec);
void opset(set<int> &S);

// a 以上 b 以下の乱数生成
int randint(int a, int b) {
  return a + rand() % (b - a + 1);
}

// 0.0 以上 1.0 以下のランダムな実数を返す関数
double randdouble() {
  return 1.0 * rand() / RAND_MAX;
}

int main() {
  rep(i, 10) cout << randdouble() << endl;
}

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