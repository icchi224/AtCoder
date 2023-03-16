#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;

// 順列全探索 O (N!)
int main() {
    int N = 10;
    vector<int> vec(N);
    rep(i, N) vec[i] = i;
    
    sort(all(vec));
    do {
        for (int x : vec) {
            cout << x << " ";
        }
        cout << endl;
    } while (next_permutation(all(vec)));
    
    // 辞書順でvより小さい最大の配列に並び替える
    // prev_permutation(all(v));
    rep(i, 4) cout << vec[i] << " ";
}