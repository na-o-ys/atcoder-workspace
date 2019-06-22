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

int main() {
    int n, l; cin >> n >> l;
    int s = 0, m = 1<<29;
    loop (n, i) {
        s += l + i;
        if (abs(m) > abs(l + i)) {
            m = l + i;
        }
    }

    cout << s - m << endl;
    return 0;
}

