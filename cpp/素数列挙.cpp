#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

// エラトステネスのふるい O(N loglogn)
// n以下の素数を列挙
set<int> get_prime(int n) {
    set<int> primes;  // n以下の素数を列挙するset
    vector<bool> is_prime(n+1, true); // 素数ならtrueにする配列

    for (int i = 2; i*i <= n; i++) {
        if (is_prime[i]) {  // iが素数なら
            for (int j = i * 2; j <= n; j += i) {
                is_prime[j] = false;  // iの倍数は素数ではない
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.insert(i); // setに格納
        }
    }
    return primes;
}

int main() {
    set<int> primes;
    primes = get_prime(100);  // 素数を列挙したset
    for (auto p: primes) cout << p << " ";
}