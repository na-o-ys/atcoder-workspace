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

int n;
ll k;
V<int> A;
V<int> idx[200010];

int head_idx(int i) {
    while (1) {
        if (i >= n) return -1;

        auto itr = upper_bound(idx[A[i]].begin(), idx[A[i]].end(), i);
        if (itr == idx[A[i]].end()) {
            return i;
        }
        i = (*itr) + 1;
    };
}

// int head(int st_c) {
//     int i = idx[st_c][0];
// 
//     while (1) {
//         if (i >= n) return -1;
// 
//         auto itr = upper_bound(idx[A[i]].begin(), idx[A[i]].end(), i);
//         if (itr == idx[A[i]].end()) {
//             if (i + 1 >= n) return -1;
//             return A[i + 1];
//         }
//         i = (*itr) + 1;
//     };
// }

V<int> ans;

void solve(int i) {
    while (1) {
        if (i >= n) return;

        auto itr = upper_bound(idx[A[i]].begin(), idx[A[i]].end(), i);
        if (itr == idx[A[i]].end()) {
            ans.push_back(A[i]);
            i++;
        } else {
            i = (*itr) + 1;
        }
    }
}

int main() {
    cin >> n >> k;
    k--;
    A.resize(n);
    loop (n, i) cin >> A[i];
    loop (n, i) {
        idx[A[i]].push_back(i);
    }

    // int vis[200010] = {};

    V<int> I;
    int nxt = 0;
    while (1) {
        int crr = head_idx(nxt);
        I.push_back(crr);
        if (crr == -1) break;

        nxt = idx[A[crr]][0] + 1;
    }

    // for (int v : I) {
    //     cout << v << " ";
    // }
    // cout << endl;

    k = k % I.size();

    int st = I[k];
    if (st == -1) {
        cout << endl;
        return 0;
    }

    // cout << st << endl;
    solve(st);

    if (ans.size() == 0) {
        cout << endl;
        return 0;
    }

    cout << ans[0];
    for (int i = 1; i < ans.size(); i++) {
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}

