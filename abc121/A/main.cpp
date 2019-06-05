#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
using P = pair<ll, ll>;


void solve(long long H, long long W, long long h, long long w){
    cout << (H - h) * (W - w) << endl;
}

int main(){
    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    long long h;
    scanf("%lld",&h);
    long long w;
    scanf("%lld",&w);
    solve(H, W, h, w);
    return 0;
}

