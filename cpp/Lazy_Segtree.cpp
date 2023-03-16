#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;

#include <atcoder/all>
using namespace atcoder;

// Lazy Segment Tree 
// 更新 O(logn), クエリ処理 O(logn)
// https://atcoder.jp/contests/typical90/tasks/typical90_ac

using S = int; //dataの型
using F = int; // lazyの型
S op(S a, S b) { return max(a, b); }  // 演算
S mapping(F f, S x) { return max(x, f);}    // dataに対する区間操作
F composition(F f, F g) { return max(f, g);}    // lazyに対する区間操作
S e() { return 0;}  // dataの初期値
F id() {return 0;}  // lazyの値を変えない値（加減なら0, 乗除なら1）

int main() {
    int W, N;
    cin >> W >> N;
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(W+1);

    rep(i, N){
        int l, r;
        cin >> l >> r;
        r++;
        S x = seg.prod(l, r);  // [l, r) の op を返す
        cout << x + 1 << endl;

        seg.apply(l, r, x+1);   // [l, r) を x+1 に更新
    }    
}