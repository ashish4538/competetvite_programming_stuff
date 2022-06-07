#include<bits/stdc++.h>
#define N 511
using namespace std;
int n,m,k;
int a[N],f[N],dp[N][N];
int main(){
	cin>>n>>m>>k;
	memset(dp,0x3f,sizeof dp);
	dp[1][1]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>f[i];
	a[n+1]=m;
	for(int i=2;i<=n+1;i++)
		for(int j=1;j<=i;j++)
			for(int k=1;k<i;k++)
				dp[i][j]=min(dp[i][j],dp[k][j-1]+(a[i]-a[k])*f[k]);
	int ans=1e9;
	for(int i=n-k+1;i<=n+1;i++) ans=min(ans,dp[n+1][i]);
	cout<<ans<<endl;
	return 0;
}
//road optimization #764c