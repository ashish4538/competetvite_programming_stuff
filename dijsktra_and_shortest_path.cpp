#include <bits/stdc++.h>
using namespace std;
//#define ll long long int
#define pr pair<int, int>
#define ff first
#define ss second
#define vect vector
#define pb push_back
#define wgr vector<pair<int, int>>
#define lowestbit(x) __builtin_ffs(x)  //re}turns 1+index of(lowest bit)
#define highestbit(x) __builtin_clz(x) //returns number of 0's to left of MST
#define is(x) cerr << #x << " is " << x << endl;
#define sortv sort(v1.begin(), v1.end());
#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define inputarr loop(i, 0, n) cin >> ar[i];
/*int mod = 1e9 + 7;
ll inf = 1e18;
int mx = -1;
ll mn = 1e18;
*/
#define int long long int
void init_code(){
     #ifndef ONLINE_JUDGE
     freopen("input1.txt","r",stdin);
     freopen("output1.txt","w",stdout);
     #endif
}




long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

vector<vector<pr>>g;





const int INF = 1e18;


void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = (int)g.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    multiset<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : g[v]) {
            int to = edge.first;
            int len = edge.second;
            //if curr edge + lenght < prev dist of child update it and remove the previous ones

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}



vector<int>restore_path(int s,int t,vector<int>const&p){
    vector<int>path;
    for(int v=t;v!=s;v=p[v]){
        path.push_back(v);
    }
    path.push_back(s);
    reverse(path.begin(),path.end());
    return path;
}









void solve(){


int n,m;
cin>>n>>m;

g.resize(n+1);

for(int i=0;i<m;i++){
    int x,y,wt;
    cin>>x>>y>>wt;
    g[x].push_back({y,wt});
    g[y].push_back({x,wt});
}

vector<int>dist(n+1);
vector<int>par(n+1);

dijkstra(1,dist,par);

if(dist[n]==INF){
   // cout<<dist[n]<<"\n";
    cout<<-1<<"\n";
    return;
}


vector<int>ans=restore_path(1,n,par);
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}

































}

 



  

    







int32_t main(){

init_code();
ios::sync_with_stdio(0);
cin.tie(0);
int t;
t=1;

while(t--){

solve();

}
   
return 0;

}




















//https://www.ideone.com/YV2Zo1
//https://www.ideone.com/1FOyoQ
//https://www.ideone.com/oHbz79