#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    fast;
    int n;
    cin>>n;
    vi a(n);
    for (int i = 0;i<n;i++)cin>>a[i];
    vvi dp(n,vi(n + 1));
    for (int i = 0;i<n;i++)dp[i][0] = 1;
    dp[0][1] = 1;
    for (int i = 1;i<n;i++){
        for (int j = 1;j<=i + 1;j++)
            dp[i][j] = dp[i - 1][j] + (a[i] % j == 0 ? dp[i - 1][j - 1] : 0);
    }
    ll ans = 0;
    for (int j = n;j>=1;j--)ans = (ans + (ll)dp[n - 1][j])%mod;
    cout<<ans;
    return 0;
}