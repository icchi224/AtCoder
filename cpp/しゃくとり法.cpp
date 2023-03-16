#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long


// しゃくとり法
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cl
// 総和がM以下になる連続な長さの通り数

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<ll> rui(N+1);   // 累積和
    rep(i, N) rui[i+1] = rui[i] + A[i];

    int ans = 0;
    int right = 0;

    rep(left, N) {
        // 増やす条件
        while (right+1 <= N && rui[right+1] - rui[left] <= M) {
            right++;
        }

        ans += right - left;
        cout << right - left << endl;
    }
    
    cout << ans << endl;
}
