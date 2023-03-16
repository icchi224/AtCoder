#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

// 素因数分解 O(√n)
// 出てくる数はlogn個程度
vector<ll> primefact(ll n) {
    // 素因数分解した結果を保存する配列
    vector<ll> pfact = {1};  // 1を含めるか
    for (ll i = 2; i*i <= n; i++) {
        while (n % i == 0) {  // 割り切れなくなるまで割り続ける
            n /= i;
            pfact.emplace_back(i);
        }
    }
    if (n != 1) pfact.emplace_back(n);
    return pfact;
}

int main() {
    vector<ll> pfact = primefact(49);  // 素因数分解
    
    for (auto p: pfact) cout << p << " ";
}