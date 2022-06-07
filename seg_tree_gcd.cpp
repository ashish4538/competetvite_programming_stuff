// CREATED BY    DEVIL'S_NE5T   AKA    HARSH GUPTA

// NOT A PRO CODER XD
// JUST SOMEONE WHO IS INTERESED IN THE WORLD OF CODING
// JUST SO I MENTION THAT ALTHOUGH I LIKE CODING BUT DEBUGGING MAKES ME FEEL SICK


#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll              long long
#define ld              long double
#define ull             unsigned long long
//COMMON DATA STRUCTURES
//----------------------
#define vll             vector<ll>
#define pll             pair<ll,ll>
#define vpairll         vector<pair<ll,ll>>
#define mpll            map<ll,ll>
#define mpcl            map<char,ll>
#define setll           set<ll>
//COMMON OPERATIONS 
//-----------------
#define setbits         __builtin_popcountll //count number of 1 in binary
#define leadzero        __builtin_clz //count leading zeroes in binary
#define tailzero        __builtin_ctz //coutn tail zero
#define pb              push_back
#define pf              push_front
#define lb              lower_bound
#define ub              upper_bound
#define F               first
#define S               second
#define endl            "\n"
#define all(v)          v.begin(),v.end()
#define revall(v)       v.end(),v.begin()
#define MEM(a, b)       memset(a, (b), sizeof(a))    
#define loop(i,a,b)     for(ll i=a;i<b;i++)
#define rev(i,a,b)      for(ll i=b-1;i>=a;i--)
#define loop2d(n,m)   loop(i,0,n){loop(j,0,m)
#define sc(a,n)         vll a(n); loop(i,0,n)cin>>a[i];
#define yes             cout<<"YES"<<endl;
#define no              cout<<"NO"<<endl;
#define dbg(a)          cout<<a<<" ";
#define ln              cout<<endl;


//  DEBUG
// _____________________________________


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


// ______________________________________
//PBDS
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
//     ordered_set;

//find_by_order() return the iterator to the element at xth(0-based) position
//order_of_key() returns number of elements in set which are strictly less than x

#define PI           3.1415926535897932384626433832795
const ll M      =    1e9+7;
const ll i1     =    1e6+5;

//______________________________________

//COMMON FUNCTIONS USED 
//---------------------MATHS---------------------------
ll gcd(ll a,ll b){if(b==0) return a; return gcd(b,a%b);}
ll lcm(ll a,ll b){return ((a*b)/gcd(a,b));}
ll modexp(ll a,ll b){
    int res = 1;
    while (b){if(b%2==1)res= (res*a)%M; b>>=1; a=(a*a)%M;}
    return res%M;
}
vll pw;
void power(){
    ll x = 1;while(x<1e18){pw.pb(x);x*=2ll;}
}
// ll fact[i1];
// void factorial(){
//     fact[0] = 1;
//     loop(i,1,i1){
//         fact[i] = fact[i-1]*i;fact[i]%=M;
//     }
// }

// ll ncr(ll n, ll r){
//     ll x = fact[n]*(modexp(fact[r],M-2)%M*modexp(fact[n-r],M-2)%M)%M;
//     return x%M;
// }

// ll prime[i1]={};
// vll prm;
// void seive(){
//     prime[0]=prime[1]=1;
//     for(ll i=2;i*i<i1;i++){
//         if(prime[i]==0){
//             for(ll j=i*i;j<i1;j+=i){
//                 prime[j]=1;
//             }
//         }
//     }
//     for(ll i=1;i<i1;i++){
//         if(prime[i]==0)prm.pb(i);
//     }
// }

// -----------------DSU------------------

// ll n,d;
// ll parent[i1];
// ll rk[i1];

// void makeset(){
//     loop(i,1,n+1){
//         parent[i] = i;
//         rk[i] = 0;
//     }
// }
// ll findPar(ll node){
//     if(node==parent[node])return node;
//     return parent[node] = findPar(parent[node]);
// }
// void uni(ll u, ll v){
//     u = findPar(u);
//     v = findPar(v);
//     if(rk[u]<rk[v]) parent[u] = v;
//     else if(rk[v]<rk[u]) parent[v] = u;
//     else{
//         parent[v] = u;
//         rk[u]++;
//     }
// }

// ------------COMPARATOR-----------------

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){
    return (a.second < b.second);
}



// ______________________________________
// ______________________________________
//CODE HERE........

vll tree;
vll op;

ll cnt = 0, gd = 0;
bool found = false;

void build(vll& a, ll st, ll en, ll node){

    if(st==en){
        tree[node] = a[st];
        return;
    }
    ll mid = (en+st)/2;
    build(a,st,mid,2*node);
    build(a,mid+1,en,2*node+1);

    tree[node] = gcd(tree[2*node],tree[2*node+1]);

}

void query(ll l, ll r, ll st, ll en, ll node = 1){
    if(st>r or en<l or st-l>cnt or found ) return;
    if(st>=l and en<=r and gcd(gd,tree[node])>cnt+en-st+1){
        gd = gcd(gd,tree[node]);
        cnt += en-st+1; //len of the segment
        return;
    }
    if(st==en){
        if(gcd(gd,tree[node])>cnt+1){
            cnt++;
            gd = gcd(gd,tree[node]);
        }
        else{       // ye basically wo wala condition h jisme gcd mko lower mil jaa rha h
                    // to apan yaha tk ka length store krke break krenge
            cnt++;
            found = true;
        }
        return;
    }
    ll mid = (st+en)/2;
    query(l,r,st,mid,2*node);
    query(l,r,mid+1,en,2*node+1);
}

ll gcd_query(ll l,ll r,ll st,ll en,ll node = 1ll){
    if(st>r or en<l)return 0;
    if(st>=l and en<=r) return tree[node];
    ll mid = (st+en)/2;
    return gcd(gcd_query(l,r,st,mid,2*node),gcd_query(l,r,mid+1,en,2*node+1));

}

void harsh_op(ll test_case){

    ll n; cin>>n;

    op.resize(n);

    sc(a,n);

    tree.resize(4*n+1);

    build(a,0,n-1,1);

    ll i = 0;
    while(i<n){
    // for(ll i=0;i<n;){
        cnt = gd = 0;
        found = false;
        query(i,n-1,0,n-1);
        // dbg(i)
        // here we get the count of the numbers from index i upto where the 
        // equation gcd(ai , ai+1, ... acnt ) >= (r-l+1) satisfies
        // coz if u visualize in this way that if gcd of three adjacent number is 
        // 5 then the gcd of any two adjacent number in that range is always gonna be
        // higher than or equal to 5 
        if(gcd_query(i,i+cnt-1,0,n-1)==cnt){ // here we are checking ki jaha pe gcd !> cnt mila h 
                                             // wha tk me jo segment h uska gcd == cnt h ki nhi
            op[i+cnt-1]++;
            i+=cnt; // curr_i + len_of_segment = to_i + 1
        }
        else{ // agar uss location pe gcd < cnt tha to chalega agar wo equal to len nhi h to
            i++;
        }
        // dbg(cnt)
        // return;
    }

    ll ans = 0;
    loop(i,0,n){
        ans+=op[i];
        dbg(ans)
    }



} 

int main(){
    fast;
    // seive();
    // factorial();
    // solve();
    power();

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);

    #endif
    
    ll ttcc = 1;
    // cin>>ttcc;
    ll test_case=1;
    while(ttcc--){
        harsh_op(test_case);
        test_case++;
    }

}

//C:\Users\harsh gupta\.vscode\helloWorld\cp