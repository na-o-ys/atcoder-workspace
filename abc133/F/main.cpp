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

using E = tuple<int, int, int>;

const int M = 100010;
const int MLV = 18; 
vector<E> G[M];
int root;
int n,q;
int parent[MLV][M];
int depth[M];
int cols[M] = {};
int cold[M] = {};

void dfs(int v,int p,int d){
	parent[0][v] = p;
	depth[v] = d;
	for(int i = 0;i < G[v].size();i++){
        int w = get<0>(G[v][i]);
		if(w != p) dfs(w,v,d + 1);
	}
}

void init(int V){
	dfs(root,-1,0);
	for(int k = 0;k+1 < MLV;k++){
		for(int v = 1;v <= V;v++){
			if(parent[k][v] < 0) parent[k+1][v] = -1;
			else parent[k+1][v] = parent[k][parent[k][v]];
		}
	}
}

int lca(int u,int v){
	if(depth[u] > depth[v]) swap(u,v);
	for(int k = 0;k < MLV;k++){
		if((depth[v] - depth[u]) >> k & 1){
			v = parent[k][v];
		}
	}
	if(u == v)return u;
	for(int k = MLV-1;k >= 0;k--){
		if(parent[k][u] != parent[k][v]){
			u = parent[k][u];
			v = parent[k][v];
		}
	}
	return parent[0][u];
}

int main() {
    cin >> n >> q;
    loop (n - 1, i) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        G[a].push_back({ b, c, d });
        G[b].push_back({ a, c, d });
    }
    return 0;
}

