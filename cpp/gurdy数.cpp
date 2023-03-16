#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

// grudy数 O(N)
vector<int> grudy(100);

int CalcGrudy(int X, int Y) {
  rep(i, grudy.size()) {
    vector<bool> transit(3);  // Grudy数が0,1,2となる遷移があるかどうか
    if (i >= X) transit[grudy[i-X]] = true;
    if (i >= Y) transit[grudy[i-Y]] = true;

    // grudy数更新
    if (!(transit[0])) grudy[i] = 0;
    else if (!(transit[1])) grudy[i] = 1;
    else grudy[i] = 2;
  }
  return 0;
}

int main() {
  int X = 2, Y = 8;

  CalcGrudy(X, Y);
  rep (i, 50) cout << grudy[i] << " ";
}