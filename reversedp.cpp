#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &it : a) cin >> it;
		vector<vector<long long>> dp(n + 1, vector<long long>(3));
		for (int i = 0; i < n; ++i) {
			dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + (i & 1 ? 0 : a[i]));//if we don't reverse till i
			if (i + 2 <= n) dp[i + 2][1] = max(dp[i + 2][1], max(dp[i][0], dp[i][1]) + (i & 1 ? a[i] : a[i + 1]));//if we reverse and don't end till i
			dp[i + 1][2] = max(dp[i + 1][2], max({dp[i][0], dp[i][1], dp[i][2]}) + (i & 1 ? 0 : a[i]));//if we reverse and end till i
		}
		cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
	}
	
	return 0;
}
//1373D - Maximum Sum on Even Positions'
int n;
cin>>n;
vector<int>a(n);
vector<int>e,o;
if(n%2){
    e.resize(n/2+2,0);
    o.resize(n/2+1,0);
}
else{
    e.resize(n/2+1,0);
    o.resize(n/2+1,0);
}
int ei,oi;
ei=oi=1;
rep(i,0,n){
    cin>>a[i];
    if(i%2){
      o[oi]=o[oi-1]+a[i];
        oi++;
    }
    else{
       
           e[ei]=e[ei-1]+a[i];
        ei++;
    }
}
int ans=INT_MIN;
if(n%2){
int el=n/2+1;
int ol=n/2;
for(int i=1;i<=n/2;i++){
    int op1=o[i]+(e[el]-e[i]);
    int op2=e[i]+(o[ol]-o[i]);
    int curr=max(op1,op2);
    ans=max(curr,ans);
}
ans=max(ans,max(e[el],o[ol]));

}
else{

int el=n/2;
int ol=n/2;
for(int i=1;i<=n/2;i++){
    int op1=o[i]+(e[el]-e[i]);
    int op2=e[i]+(o[ol]-o[i]);
    int curr=max(op1,op2);
    ans=max(curr,ans);
    cout<<e[i]<<" "<<o[i]<<"\n";
}
ans=max(ans,max(e[el],o[ol]));


}
cout<<ans<<"\n";


