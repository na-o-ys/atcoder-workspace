#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define loop1(n, i) for(int i=1;i<=n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;

void solve(ll N, ll A, ll B, ll C, ll D, string S){
    A--; B--; C--; D--;
    for (int i = A; i <= max(C, D); i++) {
        if (S[i] == '#' && S[i + 1] == '#') {
            cout << "No" << endl;
            return;
        }
    }
    if (C > D) {
        // A < B < D < C
        int mbd = 0;
        int j = 0;
        for (int i = B - 1; i <= min(D + 1, N - 1); i++) {
            if (S[i] == '.') j++;
            else j = 0;
            mbd = max(mbd, j);
        }
        if (mbd < 3) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main(){
    ll N, A, B, C, D;
    string S;
    cin >> N >> A >> B >> C >> D >> S;
    solve(N, A, B, C, D, S);
    return 0;
}

