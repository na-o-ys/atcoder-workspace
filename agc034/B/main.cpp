#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define loop1(n, i) for(int i=1;i<=n;i++)
#define rloop(n, i) for(int i=n-1;i;i--)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;

void solve(string s){
    int n = s.length();
    s.push_back('.');
    V<ll> A;
    loop (n, i) {
        if (s[i] == 'A') {
            A.push_back(0);
            continue;
        }
        if (s[i] == 'B' && s[i + 1] == 'C') {
            A.push_back(1);
            i++;
            continue;
        }
        A.push_back(-1);
    }
    int m = A.size();
    V<ll> B = A;
    rloop (m, i) {
        if (i && B[i - 1] != -1 && B[i] != -1) {
            B[i - 1] += B[i];
        }
    }
    ll ans = 0;
    loop (m, i) {
        if (A[i] == 0) {
            ans += B[i];
        }
    }
    cout << ans << endl;
}

int main(){
    string s;
    cin >> s;
    solve(s);
    return 0;
}

