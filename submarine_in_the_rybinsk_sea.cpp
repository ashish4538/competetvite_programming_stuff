#include <bits/stdc++.h>
using namespace std;
 
int main(){
   long long ans=0,x,y,n,b,p=998244353;
   cin >> n ;
   for(int i=0;i<n;i++){
      cin >> x;
      y=0;b=1;
      //every digit having position i appears in pos i*2 and i*2-1 n times
      // we are just incrementing the b by 10^2 to account for that and starting from 1 
      while(x) {
         y+=(x%10)*b; x/=10; b=(b*100)%p;
      }
      ans=(ans%p+(((y+y*10)%p)*n%p)%p)%p;
   }
   cout << ans%p;
   return 0;
}