#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;

// 2次元累積和の前処理
void csum2_init(vector<vector<int>> &vec2) {
    int h = vec2.size();
    int w = vec2[0].size();
    rep(i, h) rep(j, w - 1) vec2[i][j + 1] += vec2[i][j]; // 横
    rep(i, h - 1) rep(j, w) vec2[i + 1][j] += vec2[i][j]; // 縦
}

int csum2_get(vector<vector<int>> &vec2, int a, int b, int c, int d) {
    // a ~ c, b ~ d 間の値の和
    return vec2[c][d] - vec2[c][b-1] - vec2[a-1][d] + vec2[a-1][b-1];
}

int main() {
    int h = 4, w = 3;
    vector csum2(h+1, vector<int>(w+1));

    
    for (int i = 1; i < w+1; i++) {
        csum2[i][i] += i+1; //適当に足す
    }

    csum2_init(csum2);  // 前処理


    int ans = csum2_get(csum2, 2, 2, h, w);
    cout << ans << endl;
}
