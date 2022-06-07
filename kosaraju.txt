//Kosaraju's Algorithm for Strongly Connected Components

//Strongly Connected Components(SCC)
//A directed graph is strongly connected if there is a path between all pairs of vertices. A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph.



#include <bits/stdc++.h>

using namespace std;



int s=0;
vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order,components;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
   // component.push_back(v);
 s++;
    for (auto u : adj_rev[v])
        if (!used[u]){
            dfs2(u);
           
        }
}

int main() {
    int n;
    cin>>n;
    int m;
    cin>>m;
//int component=0;
 adj.resize(n);
 adj_rev.resize(n);
 
    while(m--){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    used.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());

    for (auto v : order){
        if (!used[v]) {
            dfs2 (v);
            components.push_back(s);
            s=0;
        }
    }
    
    
    int sumo=0;
    int sume=0;
    for(auto x : components){
        if(x%2){
            sumo+=x;
        }
        else{
            sume+=x;
        }
    }
    
    cout<<-(sume-sumo)<<"\n";
}       
        
        
        
        
        
        
        
        
        
        
        
