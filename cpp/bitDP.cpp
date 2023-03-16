#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
void opvec2(vector<vector<int>> &vec);

// bit DP O(N^2 * 2^N)
int inf = 1e9;
int main() {
  int N = 4;
  vector dp(1<<N, vector<int>(N, inf));
  dp[1][0] = 0; // 初期位置

  rep(bits, 1<<N) rep(pos, N) {
    // 訪れていないならcotinue
    if (dp[bits][pos] == inf) continue;
    rep(to, N) {
      // 次に行く場所がすでに訪れた場所ならcontinue
      if ((bits >> to) & 1) continue;

      int next = bits | (1 << to);
      dp[next][to] = min(dp[next][to], dp[bits][pos] + 1);
    }
  }
  output_vec2(dp);
}

int output_vec2(vector<vector<int>> &vec) {
    rep(i, vec.size()) {
      rep(j, vec[0].size()) {
        cout << vec[i][j] << " ";
      } 
    cout << endl;
    }
    return 0;
}