#include <bits/stdc++.h>

using namespace std;

int main()
{
   
   int t;
   cin>>t;
   while(t--){
       int n,m;
       cin>>n>>m;
       int part=m+1;
       int zeros=n-m;
       int length =zeros/part;
       int remZeros=zeros-length*part;
       int x=length*(length+1);
       x/=2;
       int y=(length+1)*(length+2);
       y/=2;
       //extra zeros for all the remZeros part and normal zero for all the parts that are not zero
       long long int ans=(remZeros)*y+(part-remZeros)*x;
       cout<<ans<<"\n";
   }
   
   
   
   
   return 0;
}