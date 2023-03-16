#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int output_vec2(vector<vector<int>> &vec) {
    rep(i, vec.size()) {
      rep(r, vec[0].size()) {
        cout << vec[i][r] << " ";
      } 
    cout << endl;
    }
    return 0;
}

// 区画dp[l][r]
// lからrまで残っている時点での最善手
int main() {
  int N;
  cin >> N;
  vector<int> P(N), A(N);
  rep(i, N) cin >> P[i] >> A[i];
  rep(i, N) P[i]--;
  vector<vector<int>> dp(N, vector<int>(N));

  rep(l, N-1) {
    for (int r = N-1; r > l; r--) {
      // left を取る場合
      if (P[l] >= l && P[l] <= r) {
        dp[l+1][r] = max(dp[l+1][r], dp[l][r] + A[l]);
      }
      else {
        dp[l+1][r] = max(dp[l+1][r], dp[l][r]);
      }
      // right を取る場合
      if (P[r] >= l && P[r] <= r) {
        dp[l][r-1] = max(dp[l][r-1], dp[l][r] + A[r]);
      }
      else {
        dp[l][r-1] = max(dp[l][r-1], dp[l][r]);
      }
    }
  }
  int ans = 0;
  rep(i, N) {
    ans = max(ans, dp[i][i]);
  }
  cout << ans << endl;
  //output_vec2(dp);
}