#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;
using P = pair<int, int>;
void output_vec1(auto &vec1);

// 最長増加部分列LIS O(N)
// 先頭から各要素までのLISの長さ
int main() {

    vector<int> A = {2, 3, 1, 6, 4};

    auto LIS = [&](vector<int> A) -> vector<int> {
        int N = A.size();
        vector<int> LIS_len(N), vec;
        rep(i, N) {
            int p = lower_bound(all(vec), A[i]) - vec.begin();
            LIS_len[i] = p+1;
            if (p == (int)vec.size()) {
                vec.emplace_back(A[i]); // A[i]が最後の数より大きければ追加
            }
            else {
                vec[p] = A[i]; // A[i]以上の最小の数がある位に上書き
            }
        }
        return LIS_len;
    };
    
    vector<int> LIS_len = LIS(A);
    output_vec1(LIS_len);
}

void output_vec1(auto &vec1) {
    for (auto i: vec1) {
        cout << i << " ";
    }
    cout << endl;
}