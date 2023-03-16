#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

// ダブリング
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_be
// N頂点の円環グラフでK回いった先がどの頂点か求める
// 前処理O(N*M) 位置を求めるO(M)

int main() {
    ll N = 5, K = 2;
    
    const int M = 60; // 2^60 > 10^18先まで見れる
    vector dp(M, vector<int>(N));

    rep(i, N) {
        dp[0][i] = (i+1)%N; // 適当に行先を設定
    }

    // 前処理
    for (int i = 1; i < M; i++) {
        rep(j, N) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }

    // pos から K 行った先の位置 
    auto find = [&](int pos, ll K) -> int {
        rep(i, M) {
            if ((K >> i) & 1) {
                pos = dp[i][pos];
            }
        }
        return pos;
    };

    int num = 0;
    int pos = find(0, K);   // num から K 行った先の場所
    cout << "num から K 行った先は " << pos << endl;
}