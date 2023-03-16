#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

// nCr O(r)
mint combination(ll n, ll r) {
    mint res = 1;
    for (int i = (n-r+1); i <= n; i++) res *= i; // 分子
    for (int i = 1; i <= r; i++) res /= i; // 分母
    return res;
}

int main() {
    ll n, r;
    cin >> n >> r;
    mint ans = combination(n, r);
    cout << ans.val() << endl;
}