#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll binpower(ll a, ll b) {
	ll ans = 1;
	while (b != 0) {
		if (b % 2 == 1) {
			ans = ans*a;
		}
		a = (a)*a;
		b /= 2;
	}
	return ans;
}

int main() {
    ll a = 2, b = 6;
    ll ans = binpower(a, b);
    cout << ans << endl;
}
