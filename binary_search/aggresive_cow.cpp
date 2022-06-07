/*

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?


*/






#include <bits/stdc++.h>

using namespace std;

#define int long long int

 vector<int>pos;




bool check(int d,int n,int m){
   int last=-1e9;
   int cnt=0;
   for(int i=0;i<n;i++){
       if(pos[i]-last>=d){
           cnt++;
           last=pos[i];
       }
   }
   if(cnt>=m){
       return true;
   }
   else{
       return false;
   }
   
}


 


int32_t main()
{
    
int tc;
cin>>tc;
while(tc--){
    int n,m;
    cin>>n>>m;
    pos.resize(n);
    for(int i=0;i<n;i++){
        cin>>pos[i];
    }
    sort(pos.begin(),pos.end());
  
    int r=pos[n-1];
    
    int l=0;
    int mid=(l+r)/2;
    int ans=-1;
    while(l<=r){
       int mid=(l+r)/2;
       if(check(mid,n,m)){
           ans=mid;
           
            l=mid+1;
          
       }
       else{
            r=mid-1;
          
       }
    }
    
    
    cout<<ans<<"\n";
}

  
    
    
    
    
    
    
    
    
    
    
    
    
   
   return 0;
}
