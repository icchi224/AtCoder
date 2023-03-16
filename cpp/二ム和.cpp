#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

// A個の石が積まれたN個の山がある
// 1つの山から1個以上石を取る操作を交互に行う
// 最後の石を取ったらWIN とすると
// AのXORが0でないなら先手勝利、AのXORが0なら後手勝利(二ム和)
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  
  int x = 0;
  rep(i, N) x ^= A[i];
  if (x) cout << "First" << endl;
  else cout << "Second" << endl;
}