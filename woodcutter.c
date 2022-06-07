#include<bits/stdc++.h>
using namespace std;

#define inf INT_MAX





int  main(){
    int n;
    cin>>n;
    vector<int>x(n),h(n);
    for(int i=0;i<n;i++){
        cin>>x[i]>>h[i];
    }
    vector<array<int,3>>dp(n,{{-inf,-inf,-inf}});
    dp[0]={1,0,1};
    //if there are 0 trees we fell the tree either left or right we will get 1 //point
    for(int i=1;i<n;i++){
        dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
        if(x[i]-h[i]>x[i-1]){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+1);
            //if we want fell the tree in the left
            
        }
        if(x[i-1]+h[i-1]<x[i]-h[i]){
            dp[i][0]=max(dp[i][0],dp[i-1][2]+1);
            //if we want to fell the tree in right;
            
        }
        if(x[i-1]+h[i-1]<x[i]){
            dp[i][1]=max(dp[i][1],dp[i-1][2]);
            //if we can't fell the tree
        }
        //dp[i] [right]=dp[i][stay]+1?
        //it increased previous right if it was possible to fell the tree see 
        //above condition
        dp[i][2]=dp[i][1]+1;
    }
    
    int ans=-1;
    for(int i=0;i<3;i++){
        ans=max(dp[n-1][i],ans);
    }
    cout<<ans<<"\n";
    return 0;
    
    
}