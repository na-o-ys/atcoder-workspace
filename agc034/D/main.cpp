#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define loop1(n, i) for(int i=1;i<=n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;


void solve(long long N, std::vector<long long> RX, std::vector<long long> RY, std::vector<long long> RC, std::vector<long long> BX, std::vector<long long> BY, std::vector<long long> BC){

}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> RX(N);
    std::vector<long long> RY(N);
    std::vector<long long> RC(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&RX[i]);
        scanf("%lld",&RY[i]);
        scanf("%lld",&RC[i]);
    }
    std::vector<long long> BX(N);
    std::vector<long long> BY(N);
    std::vector<long long> BC(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&BX[i]);
        scanf("%lld",&BY[i]);
        scanf("%lld",&BC[i]);
    }
    solve(N, std::move(RX), std::move(RY), std::move(RC), std::move(BX), std::move(BY), std::move(BC));
    return 0;
}

