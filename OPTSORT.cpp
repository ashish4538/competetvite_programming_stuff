#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main()
{
    
    int tc;
    cin>>tc;
    map<int,int>mp;
while(tc--){
   int n,l,r;
   cin>>n;
   int a[n],temp[n];
   for(int i=0;i<n;i++){
       cin>>a[i];
       temp[i]=a[i];
   }
   sort(temp,temp+n);
   //temp[i] stores the sorted  values
   int sum=0;
   mp.clear();
   l=r=-1;
   for(int i=0;i<n;i++){
       if(a[i]!=temp[i]){
           l=i;
           // at least do once to intialize the map;
           do{
               mp[temp[i]]--;
               mp[a[i]]++;
               if(mp[temp[i]]==0){
                   mp.erase(mp.find(temp[i]));
                   //this means that element has ocuured in the loop 
                   //before
               }
               if(mp[a[i]]==0){
                   mp.erase(mp.find(a[i]));
                   //same as above
               }
               
              ++i;
           }
           while(!mp.empty());//continues till the map is empty meaning find the whole l..r that has been unsorted
           int mini=1e18,maxi=-1e18;
           for(int j=i;j<l;j++){
               maxi=max(maxi,a[j]);
               mini=min(mini,a[j]);
           }
           --i;
           sum+=maxi-mini;
           
       }
   }
   
   cout<<sum<<"\n";
   

}
   
   return 0;
}