#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

// 約数列挙 (O√n)
set<ll> yakusu(ll n) {
    set<ll> S;
    ll i = 1;
    while (i*i <= n) {
        if (n%i == 0) {
            S.insert(i);
            S.insert(n/i);
        }
        i++;
    }
    return S;
}

// 素数判定 O(√N)
// Nが素数かどうかを判定
bool is_prime(ll N) {
    if (N == 2) return true;
    for (ll i = 2; i <= ll(sqrt(N)); i++) {
        if (!(N % i)) return false;
    }
    return true;
}

int main() {
    set<ll> S = yakusu(100);
    for (auto s: S) cout << s << endl;
}