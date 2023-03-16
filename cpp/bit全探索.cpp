#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// ビット全探索 O(N*2^N)
int main() {
    int N = 3;

    const int MXbit = 5;
    rep(i, (1 << N)) {
        bitset<MXbit> bits(i);   //bits
        rep(j, N) { // 小さい桁からbitをチェック
            if (bits.test(j)) { //bitのj番目が1なら
                cout << "True ";
            }
            else {
                cout << "False ";
            }
        }
        cout << endl;
    }
}