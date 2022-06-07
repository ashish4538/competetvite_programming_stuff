#include <bits/stdc++.h>
using namespace std;


int n;
vector<vector<int>> adj;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void find_cycle() {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs(v))
            break;
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout <<cycle.size()<<"\n";
        for (int v : cycle)
            cout << v+1 << " ";
        cout << endl;
    }
}

int main(){
	cin>>n;
	adj.resize(n+1);
	color.resize(n+1);
	parent.resize(n+1);
	int m;
	cin>>m;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		--x;
		--y;
		adj[x].push_back(y);
	}
	find_cycle();
	return 0;
		
}
