#include <iostream>
#include <vector>
#include <queue>
//use priority queue for lexigraphically smallest topological sort
using namespace std;
int indeg[10005];
int topo[10005];
vector <int> g[10005];
int main(){
        int n,m;
        int cur= 0;
        cin >> n >> m;
        for (int i = 0; i < m; i++){
                int x,y;
                scanf("%d %d" ,&x, &y);
                indeg[y]++;
                g[x].push_back(y);
        }
        priority_queue <int> q;
        for(int i = 1; i <= n; i++)
                if (!indeg[i]) q.push(-1*i);
			// if there are no independecies we push the element in the queue
        while(!q.empty()){
                int nd = -1 * q.top();
                q.pop();
                for(int i = 0; i < g[nd].size(); i++){
                        indeg[g[nd][i]]--;
						//we reduce the indegrees of all the neighbour that are adjacent to it
                        if (!indeg[g[nd][i]])
                                q.push(-1*g[nd][i]);
                }
                topo[cur++] = nd;
        }
        if (cur!= n){
                cout << "Sandro fails." << endl;
				//also detects cycle
                return 0;
        }

        for(int i = 0; i < n-1; i++)
                printf("%d ", topo[i]);
        printf("%d\n", topo[n-1]);


        return 0;
}
