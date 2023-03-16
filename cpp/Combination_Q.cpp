#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int mod = 1000000007;

int N = 1001001;    // 二項定理の上限
vector<ll> fanc(N, 1), inv(N, 1), finv(N, 1); // 保存用

// 前処理 O(n) nまでの二項定理の値を用意
int Com_init() {
  for (int i = 2; i < N; i++) {
    fanc[i] = (fanc[i-1] * i) % mod; // 分子
    inv[i] = mod - inv[mod % i] * (mod / i) % mod;  // 逆元
    finv[i] = (finv[i-1] * inv[i]) % mod; // 分母
  }
  return 0;
}

// 二項定理の計算 nCr O(1) 
ll Combination_Q(ll n, ll r) {
  return (fanc[n] * (finv[r]*finv[n-r]%mod)) %mod;
}

int main() {
  ll n, r;
  cin >> n >> r;
  Com_init();
  cout << Combination_Q(n, r) << endl;
}