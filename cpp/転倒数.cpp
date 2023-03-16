#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;

// 転倒数 O(n^2)
int inversion(vector<int> &vec) {
  int inv = 0;
  rep(i, vec.size()) rep(j, i) {
    if (vec[i] < vec[j]) inv++;
  }
  return inv;
}

int main() {
  vector<int> a = {4, 3, 2, 1};

  int inv = inversion(a);
  cout << inv << endl;
}