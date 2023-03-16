#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define all(x) std::begin(x), std::end(x)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

// Binary Search O(logN)

// x以上の最小の値の位置
int search_pos(ll x, vector<ll> &A) {
    int pos = lower_bound(all(A), x) - A.begin();
    return pos;
}

// x以上の最小の値
ll search_num(ll x, vector<ll> &A) {
    ll num = *lower_bound(all(A), x);
    return num;
}

// x未満の最大の数の位置
//判定 wjがac側ならtrue
bool is_ac(ll x, ll wj, vector<ll> &A) {
    if (A[wj] < x) return true;
    return false;
}

// Binary Search
// 出力の型を確認すること
ll search_ac(ll x, vector<ll> &A) {
    ll ac = 0, wa = A.size();
    ll wj;
    while (wa - ac > 1) {
        //cout << ac << " " << wa << endl;
        wj = (ac + wa) / 2;
        if (is_ac(x, wj, A)) ac = wj;   // wjがac側
        else wa = wj;
    }
    return ac;
}


int main() {
    ll X = 100;
    vector<ll> A = {1,3,5,7,10};

    ll ans, test = 3;

    if (test == 0) {
        ans = search_pos(X, A); // x以上の最小の値の位置
    }
    else if (test == 1) { 
        ans = search_num(X, A);  // x以上の最小の値
    }
    else {
        ans = search_ac(X, A);  // x未満の最大の数の位置
    }
    cout << ans << endl; 
}