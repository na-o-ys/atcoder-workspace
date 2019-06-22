#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define loop1(n, i) for(int i=1;i<=n;i++)
#define rloop(n, i) for(int i=n;i;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    a--;
    ll lcm = c * d / gcd(c, d);
    ll g = lcm / c + lcm / d - 1;

    ll bb = b - ((b / lcm) * g + (b % lcm) / c + (b % lcm) / d);
    ll aa = a - ((a / lcm) * g + (a % lcm) / c + (a % lcm) / d);
    cout << bb - aa << endl;
    return 0;
}

