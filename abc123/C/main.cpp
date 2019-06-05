#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define loop1(n, i) for(int i=1;i<=n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;


void solve(long long N, long long A, long long B, long long C, long long D, long long E){
    ll c = A;
    ll ans = (N + (c - 1)) / c;
    c = min(c, B);
    ans += (N + (c - 1)) / c;
    c = min(c, C);
    ans += (N + (c - 1)) / c;
    c = min(c, D);
    ans += (N + (c - 1)) / c;
    c = min(c, D);
    ans += (N + (c - 1)) / c;
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long C;
    scanf("%lld",&C);
    long long D;
    scanf("%lld",&D);
    long long E;
    scanf("%lld",&E);
    solve(N, A, B, C, D, E);
    return 0;
}

