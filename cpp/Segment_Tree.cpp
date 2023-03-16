#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;

#include <atcoder/all>
using namespace atcoder;

// Segment Tree 
// 更新 O(logn), クエリ処理 O(logn)

int op(int a, int b) { return a + b; }  // 演算
int e() { return 0; } // 初期値


int main() {
    int N = 10;
    segtree<int, op, e> seg(N);  // 長さNのセグ木を生成
    seg.set(0, 1);  // ノード0を1に更新
    seg.set(3, 10);
    int l, r;
    cin >> l >> r;
    int x = seg.prod(l, r);  // l から r-1 までの op を返す
    cout << x << endl;
}