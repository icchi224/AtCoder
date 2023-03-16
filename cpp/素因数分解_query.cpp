#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
#define ll long long
void opvec1(vector<int> &vec);
void opset(set<int> &S);

// 高速な素因数分解 前処理 O(NloglogN) + 素因数分解 O(logx)

const int MAX_N = 1e5;  // 素因数分解する最大値
vector<int> is_prime(MAX_N + 1);

// エラトステネスのふるい O(N loglogN)
void get_prime() {
    rep(i, MAX_N+1) is_prime[i] = i;  // 初期化

    for (int i = 2; i*i <= MAX_N; i++) {
        if (is_prime[i] == i) {  // iが素数なら
            for (int j = i * 2; j <= MAX_N; j += i) {
                is_prime[j] = i;  // iの倍数をiで記録
            }
        }
    }
}

// 素因数分解 vectorで返す
vector<int> fastprimefact(int x) {
    vector<int> pfact;
    //pfact.emplace_back(1) // 1を含める場合
    while (x > 1) {
        pfact.emplace_back(is_prime[x]);
        x /= is_prime[x];
    }
    return pfact;
}

int main() {

    get_prime();  // 前処理
    vector<int> pfact = fastprimefact(100); // 素因数分解
    
    set<int> S(all(pfact));

    opvec1(pfact);
    opset(S);

}

//
void opvec1(vector<int> &vec) {
    rep(i, vec.size()) cout << vec[i] << " ";
    cout << endl;
}
void opset(set<int> &S) {
    for (auto s: S) cout << s << " ";
    cout << endl;
}