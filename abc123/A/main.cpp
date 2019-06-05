#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define loop1(n, i) for(int i=1;i<=n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;


int main(){
    V<int> a;
    loop (5, i) {
        int v; cin >> v;
        a.push_back(v);
    }
    int k; cin >> k;
    int ok = 1;
    loop (5, i) loop (5, j) {
        if (abs(a[i] - a[j]) > k) ok = 0;
    }
    if (ok) cout << "Yay!" << endl;
    else cout << ":(" << endl;
    return 0;
}

