#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define db double
#define el "\n"
#define ld long double
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n;i>=0;i--)
#define rep_a(i,a,n) for(int i=a;i<n;i++)


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T=1;
    cin >> T;
    while(T--){
    
        int n;
        cin>>n;

        int a[n];
        rep(i,n){
            cin>>a[i];
        }

        vector<vector<int> > dp(n+1, vector<int>(n+1,0));
        //dp[i][j] represents maximum ans if the two sequences end at i and j
        int ans = 0;
        rep(i,n+1){
            rep_a(j,i+1,n){
                dp[i][j+1] = max(dp[i][j+1],dp[i][j]+abs(a[j]-a[j-1]));
                dp[j][j+1] = max(dp[j][j+1],dp[i][j]+(i==0?0:abs(a[j]-a[i-1])));
                ans = max(ans, max(dp[i][j+1], dp[j][j+1]));
            }
        }

        cout<<ans<<'\n';
    }
    return 0;
}