#include <bits/stdc++.h>
using namespace std;
#define ar array
#define nl '\n'
#define ll long long
#define int long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define mm(a, p) memset(a, p, sizeof(a))
#define bp(a) __builtin_popcountll(a)
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e12;
const ld EPS = 1e-9;

const int MAXN=10*1e5+1;
vector<pair<int,int>>t(4*MAXN,{0,INF});
pair<int,int> sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return {0,INF};
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    auto a=sum(v*2, tl, tm, l, min(r, tm));
    auto b=sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    return {max(a.first,b.first),min(a.second,b.second)};//{l,r} where l is equal to the k asked in problem and r is range of max possible k 
}
void update(int v, int tl, int tr, int pos, pair<int,int> new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v].first =max(t[v*2].first , t[v*2+1].first);
        t[v].second =min(t[v*2].second , t[v*2+1].second);
    }
}

void solve()
{
   int n,q;
   cin>>n>>q;
   int a[n+2]={0};
   a[n+1]=INF;
   for (int i = 1; i <=n; i++)
   {
       cin>>a[i];
       pair<int,int>p;
       if(a[i]<a[i-1]){
           p={(a[i]+a[i-1]+1)/2,INF};
       }
       else if(a[i]>a[i-1]){
           p={0,(a[i]+a[i-1])/2};
       }
       else{
           p={0,INF};
       }
       update(1,1,n+1,i,p);
   }
   update(1,1,n+1,n+1,{0,(a[n]+a[n+1])/2});
//    cout<<"H\n";
   int x,y,z;
   while (q--)
   {
       cin>>x>>y>>z;
       if(x==1){
         a[y]=z;
        pair<int,int>p;
       if(a[y]<a[y-1]){
           p={(a[y]+a[y-1]+1)/2,INF};
       }
       else if(a[y]>a[y-1]){
           p={0,(a[y]+a[y-1])/2};
       }
       else{
           p={0,INF};
       }
       update(1,1,n+1,y,p);
       if(a[y]>a[y+1]){//why upadating again , we don't need that , look while constructing we upadated the according to previous one now , we need to do that only 
	   //because construction method only required us to do that 
	   
           p={(a[y]+a[y+1]+1)/2,INF};
       }
        else if(a[y]<a[y+1]){
           p={0,(a[y]+a[y+1])/2};
       }
       else{
           p={0,INF};
       }
       update(1,1,n+1,y+1,p);
       }
       else{
        pair<int,int>p=sum(1,1,n+1,y+1,z);
        // cout<<p.first<<' '<<p.second<<nl;
        if(p.first>p.second){
            cout<<-1<<nl;
        }
        else{
            cout<<p.first<<nl;
        }
          
       }
   }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin>>tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}