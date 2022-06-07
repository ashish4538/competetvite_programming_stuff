#include <bits/stdc++.h>
using namespace std;
#define int long long int
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


int lis(vector<int> const& a) {
    vector<int>y;
    for(auto x : a){
        auto it=upper_bound(y.begin(),y.end(),x);//returns the value greater than the current element
        if(it==y.end()){
            y.push_back(x);//if not found we will add it lis
        }
        else{
            *it=x;//else we got something greater remove it
        }
    }
    return (int)y.size();
}



//ll mul(ll a,ll b,ll m){return (((a%m)*(b%m))%m+m)%m;}
//ll add(ll a,ll b,ll m){return ((a%m)+(b%m))%m;}




void solve(){

int n,m;
cin>>n>>m;
vector<int>a(n);
vector<int>b(m);
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<m;i++){
    cin>>b[i];
}
cout<<lis(a)+lis(b)<<"\n";







}


















 



  

    







int32_t main(){

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


















