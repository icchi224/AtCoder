#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

// String Hash 前処理　O(N) hash値計算 O(1)
// N 文字のうち、l文字目からr文字目のhash値を算出
struct StringHash {
  ll mod;
  ll num[100100]; // 文字から数字
  ll H[100200];  // 累積のハッシュ値
  ll Pow100[100100];  // 100の累乗
  string S;
  int N;

  StringHash(string str): mod(2147483647), S(str) {
    N = S.size();
    rep(i, N) num[i+1] = S[i] - 'a' + 1; // 1文字ごとに数値に変換

    Pow100[0] = 1; // 100^0
    rep(i, N) Pow100[i+1] = 100 * Pow100[i] % mod;

    H[0] = 0;
    rep(i, N) H[i+1] = (100 * H[i] + num[i+1]) % mod;
  }

  // l文字目からr文字目のハッシュ値 O (1)
  ll hash_calc(int l, int r) {
    ll val = H[r] - (H[l - 1] * Pow100[r - l + 1]) % mod;
    if (val < 0) val += mod;
    return val;
  }

};

int main() {
  string S = "zbcab"; 
  StringHash sh(S);
  ll hash = sh.hash_calc(1, 2); // 1文字目から2文字目のハッシュ値
  rep(i, S.size()) {
    cout << i << " 文字目までのハッシュ値 " << sh.H[i] << endl;
  }
  cout << hash << endl;
}