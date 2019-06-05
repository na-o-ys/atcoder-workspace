#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define loop1(n, i) for(int i=1;i<=n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;

const string YES = "YES";
const string NO = "NO";

void solve(long long H, long long W, long long N, long long s_r, long long s_c, std::string S, std::string T){
    int l = 0, r = W - 1;
    loop (N, i) {
        char s = S[N - 1 - i];
        if (s == 'L') l++;
        if (s == 'R') r--;
        if (l < 0 || l > r || r > W - 1) {
            cout << NO << endl;
            return;
        }

        if (i == N - 1) continue;
        char t = T[N - 2 - i];
        if (t == 'R') l = max(0, l - 1);
        if (t == 'L') r = min((int)W - 1, r + 1);

        // cout << "i:" << i << endl;
        // cout << "(l, r): (" << l << "," << r << ")" << endl;
    }
    if (s_c - 1 < l || s_c - 1 > r) {
        cout << NO << endl;
        return;
    }


    l = 0, r = H - 1;
    loop (N, i) {
        char s = S[N - 1 - i];
        if (s == 'U') l++;
        if (s == 'D') r--;
        if (l < 0 || l > r || r > H - 1) {
            cout << NO << endl;
            return;
        }

        if (i == N - 1) continue;
        char t = T[N - 2 - i];
        if (t == 'D') l = max(0, l - 1);
        if (t == 'U') r = min((int)H - 1, r + 1);
    }
    if (s_r - 1 < l || s_r - 1 > r) {
        cout << NO << endl;
        return;
    }

    cout << YES << endl;
}

int main(){
    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    long long N;
    scanf("%lld",&N);
    long long s_r;
    scanf("%lld",&s_r);
    long long s_c;
    scanf("%lld",&s_c);
    std::string S;
    std::cin >> S;
    std::string T;
    std::cin >> T;
    solve(H, W, N, s_r, s_c, S, T);
    return 0;
}

