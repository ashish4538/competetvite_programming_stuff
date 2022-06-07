//F. Consecutive Subsequence
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pr pair<int,int>
#define ff first
#define ss second
#define vect vector
#define pb push_back
#define wgr vector<pair<int, int>>
#define lowestbit(x) __builtin_ffs(x)  //returns 1+index of(lowest bit)
#define highestbit(x) __builtin_clz(x) //returns number of 0's to left of MST
#define is(x) cerr << #x << " is " << x << endl;
#define sortv sort(v1.begin(), v1.end());
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define inputarr loop(i, 0, n) cin >> ar[i];
int m = 1e9+7;
int inf = 1e18;

void init_code(){
     #ifndef ONLINE_JUDGE
     freopen("input1.txt","r",stdin);
     freopen("output1.txt","w",stdout);
     #endif
}
 
 
 
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
long long binpow1(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
 











 
 
//ll mul(ll a,ll b,ll m){return (((a%m)*(b%m))%m+m)%m;}
int add(int a,int b,int m){return ((a%m)+(b%m))%m;}











void calc(int n,int m){
        int dif1=n-m;
    int ans=2*(m-1);
    if(dif1%2){
        ans+=(2*dif1);
        ans--;

    }
    else{
        ans+=(2*dif1);
    }
    cout<<ans<<"\n";

}











int cost(vector<int>&a,int p){
    int n=a.size();
    //vector<int>b(n,0);
    int prev=0;
    int cost=0;

   for(int i=p-1;i>=0;i--){
    int curr=a[i];
       cost++;
            if(curr<=prev){
              
          int val = (prev + curr - 1) / curr;
          curr*=val;

          if(curr>prev){
            cost+=(val-1);
          }
          else{
            
            curr+=a[i];
            cost+=val;
          }
         

    }

           //cout<<cost<<"\n";
            prev=curr;
 
    
   }

//cout<<cost<<"\n";
prev=INT_MIN;




    for(int i=p+1;i<n;i++){
        int curr=a[i];
   
            cost++;
    if(curr<=prev){
              
          int val = (prev + curr - 1) / curr;
          curr*=val;
            //cout<<curr<<" "<<val<<" ";
          if(curr>prev){
            cost+=(val-1);
            //cout<<"fuck";
          }
          else{
           // val++;
            curr+=a[i];
            cost+=val;
          }



    }
             // cout<<cost<<"\n";
            prev=curr;
    }


    return cost;

}











void solve(){
int n;
cin>>n;

vector<int>a(n);
rep(i,0,n){
    cin>>a[i];
}
map<int,int>dp;
int mx=0;
int start=0;
for(int i=0;i<n;i++){
    int x=a[i];
    //dp[x]=1;
    dp[x]=dp[x-1]+1;
    if(dp[x]>mx){
        mx=dp[x];
        start=x-dp[x]+1;
    }
}
vector<int>ans;
for(int i=0;i<n;i++){
    if(a[i]==start){
        ans.push_back(i+1);
        start++;
    }
}

cout<<ans.size()<<"\n";
for(auto x : ans){
    cout<<x<<" ";
}




    
}

























































 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int32_t main(){
 
init_code();
ios::sync_with_stdio(0);
cin.tie(0);
int t;
//cin>>t;
t=1;
//SieveOfEratosthenes();
//BFS();

while(t--){
 
solve();
 
}
   
return 0;
 
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 








 






// void solve(){
// int n,x;
// cin>>n>>x;
// vector<int>a(n);
// rep(i,0,n){
//     cin>>a[i];

// }
// set<int>s;
// rep(i,1,x+1){
//     s.insert(i);
// }

// int ans=0;
// map<int,pair<int,int>>mp;
// for(int i=0;i<n-1;i++){
//     int dif=abs(a[i]-a[i+1]);
//     mp[dif]={a[i],a[i+1]};
// }


// for(auto it=mp.rbegin();it!=mp.rend();it++){
//     if(s.size()>0){
//         int l=*s.begin();
//         auto it1=s.end();
//         it1--;
//         int r=*it1;
//         int sum=(*it).ss.ff+(*it).ss.ss;
//         int mx=max((*it).ss.ff,(*it).ss.ss);
//         int mi=min((*it).ss.ff,(*it).ss.ss);
//         if(l<mi || r>mx){
//             int op1,op2;
//             op1=op2=INT_MAX;
//             if(l<mi){
//                 op1=abs(sum-2*l);
//             }
//             if(r>mx){
//                 op2=abs(sum-2*r);
//             }
//             int add;
//             if(op1>op2){
//                s.erase(r);
//                add=op2;
//             }
//             else{
//                 s.erase(l);
//                 add=op1;
//             }

//             ans+=add;
//         }
//         else{
//           ans+=((*it).first);
//         }
//     }
//     else{
//         ans+=((*it).first);
//     } 
// }

// if(s.size()==1){
//     int op1=abs(a[0]-(*s.begin()));
//     int op2=abs(a[n-1]-(*s.begin()));
//     int add=min(op1,op2);
//     ans+=add;
// }
// if(s.size()>1){
//     int f=*s.begin();
//     auto it=s.end();
//     it--;
//     int l=*it;
//     int add=INT_MAX;
//     for(int i=0;i<2;i++){
//         if(i==0){
//             add=min(add,abs(a[i]-f));
//             add=min(add,abs(a[i]-l));
//         }
//         else{
//             add=min(add,abs(a[n-i]-f));
//             add=min(add,abs(a[n-i]-l));
//         }
//     }
//     ans+=add;
//     ans+=(s.size()-1);

// }
// cout<<ans<<"\n";




    
// }

























































 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
// int32_t main(){
 
// init_code();
// ios::sync_with_stdio(0);
// cin.tie(0);
// int t;
// cin>>t;
// //t=1;
// //SieveOfEratosthenes();
// //BFS();

// while(t--){
 
// solve();
 
// }
   
// return 0;
 
// }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 