#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
using P = pair<ll, ll>;

const string YES = "YES";
const string NO = "NO";

int ans[1 << 18] = {};

int bitswap(int a, int s, int t) {
    int s_mask = 1 << s;
    int t_mask = 1 << t;
    int sb = (a & s_mask) >> s;
    int tb = (a & t_mask) >> t;
    int mask = s_mask | t_mask;
    return (a & ~mask) | (sb << t) | (tb << s);
}

int solve(int s, int n, int A, int B) {
    if (n < 0) return 0;
    int last = B ^ A;
    if (last == 0) return 0;
    if (n == 1) {
        ans[s] = A;
        ans[s + 1] = A ^ 1;
        return 1;
    }
    int p;
    loop (n, i) if ((last >> i) & 1 == 1) {
        p = i;
        break;
    }
    int next_last = bitswap(last, p, n - 1) & ((1 << (n - 1)) - 1);
    int ok = 1;
    ok &= solve(s, n - 1, 0, next_last ^ 1);
    ok &= solve(s + (1 << (n - 1)), n - 1, next_last ^ 1, next_last);
    if (!ok) return 0;
    for (int i = s; i < (s + (1 << n)); i++) {
        int msb = (i - s < (1 << (n - 1))) ? 0 : 1;
        ans[i] = ans[i] | (msb << (n - 1));
        ans[i] = bitswap(ans[i], p, n - 1);
        ans[i] = A ^ ans[i];
    }
    return 1;
}

int main(){
    int N, A, B; cin >> N >> A >> B;
    int result = solve(0, N, A, B);
    if (!result) {
        cout << NO << endl;
        return 0;
    }
    cout << YES << endl;
    for (int i = 0; i < (1 << N); i++) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}

