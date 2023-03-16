#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int output_vec(vector<int> &vec) {
    rep(i, vec.size()) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}

// 調和級数 O(N logN)
int main() {
    int N = 10;

    for (int i = 1; i <= N; i++) {
        vector<int> x = {0};    //0 を含むなら
        for (int j = i; j <= N; j += i) {
            x.push_back(j);
        }
        output_vec(x);
    }

}