#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
using P = pair<ll, ll>;


void solve(std::string b){
    if (b == "A") cout << "T" << endl;
    else if (b == "T") cout << "A" << endl;
    else if (b == "G") cout << "C" << endl;
    else if (b == "C") cout << "G" << endl;
}

int main(){
    std::string b;
    std::cin >> b;
    solve(b);
    return 0;
}

