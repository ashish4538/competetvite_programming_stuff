//global round 19 D

#include<bits/stdc++.h>
using namespace std;
bool dp[105][10005];
int T,n,a[105],b[105];
int main(){
	for(cin>>T;T;T--){
		cin>>n;int s=0;
//dp[i][j] is defined is sum possible using i elements and swapping a[i] and b[i] or not.
        for(int i=1;i<=n;i++)cin>>a[i],s+=a[i];
        for(int i=1;i<=n;i++)cin>>b[i],s+=b[i];
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=s;j++){
                if(j>=a[i])dp[i][j]|=dp[i-1][j-a[i]];
                if(j>=b[i])dp[i][j]|=dp[i-1][j-b[i]];
               
            }
     
        }

        long long sum=0;
        for(int i=1;i<=n;i++)sum+=a[i]*a[i];
        for(int i=1;i<=n;i++)sum+=b[i]*b[i];
        long long ans=1e18;
         
        for(int i=0;i<=s;i++){
            if(!dp[n][i])continue;
            
           // ans=(n-2)*Σ(a^2 + b^2)+(Σai)^2+(Σbi)^2
            // minimizing the last two terms is our goal
            ans=min(ans,1ll*(n-2)*sum+1ll*i*i+1ll*(s-i)*(s-i));
        }
        cout<<ans<<endl;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=s;j++)dp[i][j]=0;
	}
	return 0;
}