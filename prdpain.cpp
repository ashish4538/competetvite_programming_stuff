#include <bits/stdc++.h>

using namespace std;

#define int long long int





int32_t main()
{
   int tc;
   cin>>tc;
   while(tc--){
       int n;
       cin>>n;
       vector<int>inp(n);
       for(int i=0;i<n;i++){
           cin>>inp[i];
       }
       
       int ans=0;
       
for(int l=0;l<n;l++){
    for(int r=l+2;r<n;r++){
        int a=inp[l];
        int c=inp[r];
        auto b=upper_bound(inp.begin()+l+1,inp.begin()+r,(a+c)/2);
        // we ran binary search on the array find the closest value to a+c/2
        //we decrement the counter so to check for all possibilities
        int best=INT_MIN;
        if(b != inp.begin()+r) best = max(best, 1LL*(c-*b)*1LL*(*b-a));
        if(--b != inp.begin()+l) best =  max(best, 1LL*(c-*b)*1LL*(*b-a));
        ans+=best;
    }
}


cout<<ans<<"\n";

}
  
	
   
   return 0;
}