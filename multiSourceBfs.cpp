/*The only difference with E1 is the question of the problem.

Vlad built a maze out of n rooms and n−1 bidirectional corridors. From any room u any other room v can be reached through a sequence of corridors. Thus, the room system forms an undirected tree.

Vlad invited k friends to play a game with them.

Vlad starts the game in the room 1 and wins if he reaches a room other than 1, into which exactly one corridor leads. Friends are placed in the maze: the friend with number i is in the room xi, and no two friends are in the same room (that is, xi≠xj for all i≠j). Friends win if one of them meets Vlad in any room or corridor before he wins.

For one unit of time, each participant of the game can go through one corridor. All participants move at the same time. Participants may not move. Each room can fit all participants at the same time.

Friends know the plan of a maze and intend to win. They don't want to waste too much energy. They ask you to determine if they can win and if they can, what minimum number of friends must remain in the maze so that they can always catch Vlad.

In other words, you need to determine the size of the minimum (by the number of elements) subset of friends who can catch Vlad or say that such a subset does not exist.

Input
The first line of the input contains an integer t (1≤t≤104) — the number of test cases in the input. The input contains an empty string before each test case.

The first line of the test case contains two numbers n and k (1≤k<n≤2⋅105) — the number of rooms and friends, respectively.

The next line of the test case contains k integers x1,x2,…,xk (2≤xi≤n) — numbers of rooms with friends. All xi are different.

The next n−1 lines contain descriptions of the corridors, two numbers per line vj and uj (1≤uj,vj≤n) — numbers of rooms that connect the j corridor. All corridors are bidirectional. From any room, you can go to any other by moving along the corridors.

It is guaranteed that the sum of the values n over all test cases in the test is not greater than 2⋅105.

Output
Print t lines, each line containing the answer to the corresponding test case. The answer to a test case should be −1 if Vlad wins anyway and a minimal number of friends otherwise.

*/

















#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
int mod = 1e9 + 7;
ll inf = 1e18;
int mx = -1;
ll mn = 1e18;

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






















//multisource BFS

void solve(){

int n,k;
cin>>n>>k;
vector<int>color(n,-1);
queue<int>q;
for(int i=0;i<k;i++){
    int x;
    cin>>x;
    color[--x]=0;
    q.push(x);
}

color[0]=1;
q.push(0);
vector<vector<int>>g(n);
for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    g[--u].push_back(--v);
    g[v].push_back(u);
}


while(!q.empty()){
    int v=q.front();
    q.pop();
    for(int u:g[v]){
        if(color[u] ==-1){
            color[u]=color[v];
            q.push(u);
        }

    }
}

for(int v=1;v<n;v++){
    if(g[v].size()==1 && color[v]==1){
        cout<<"YES"<<"\n";
        return;
    }
}

cout<<"NO"<<"\n";




}

 



  

    







int main(){

init_code();
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;

while(t--){

solve();

}
   
return 0;

}




















//https://www.ideone.com/YV2Zo1
//https://www.ideone.com/1FOyoQ
//https://www.ideone.com/oHbz79