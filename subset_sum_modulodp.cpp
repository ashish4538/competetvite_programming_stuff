#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void setIO()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
int main()
{
    setIO();
    int n,m;
    cin>>n>>m;
    vi a(n + 1);
    for (int i = 1;i<=n;i++){
        cin>>a[i];
        a[i] %= m;
    }
    if (n >= m){
        cout<<"YES";
        return 0;
    }
    vvb dp(n + 1,vb(m + 1));
    for (int i = 1;i<=n;i++){
        dp[i][a[i]] = 1;
    }
    for (int i = 2;i<=n;i++){
        for (int j = 0;j<m;j++){
            if (dp[i][j])continue;//when j == a[i](mod m)
            if (dp[i - 1][j]){dp[i][j] = dp[i - 1][j];continue;}//subcase 1
            //subcase 2
            dp[i][j] = dp[i - 1][(j - a[i] + m)%m];//do (j - a[i] + m) (mod m) to make sure the value is +ve
        }
    }
    cout<<(dp[n][0] ? "YES" : "NO");
    return 0;
}