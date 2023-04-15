#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, ans = 0;
    cin >> n;
    multiset<int> st;
    rep(i, n) {
        int a;
        cin >> a;
        if (st.count(a)) {
            ans++;
            st.erase(st.find(a));
        }
        else {
            st.insert(a);
        }
    }
    cout << ans << endl;
    return 0;
}