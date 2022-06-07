#include <bits/stdc++.h>

using namespace std;

int main()
{
   
   
   int n;
   cin>>n;
   vector<array<int,2>>v(n);
   
 for(int j=0;j<2;j++){
   for(int i=0;i<n;i++){
     cin>>v[i][j];
   }
 }  
 
 
 
 int ans=0;
 int r=-1;
 int l=0;
 for(int i=0;i<n-1;i++){
     if(r==-1){
         if(v[i][0]+v[i+1][1]>v[i][1]+v[i+1][0]){
             ans+=v[i][0];
             r=1;
         }
         else{
             r=0;
             ans+v[i][1];
         }
     }
     
     else if(r==1){
         
          
         if(l==1){
             if(v[i][1]+v[i+1][0]>v[i+1][1]){
                 ans+=v[i][1];
             }
             
             else{
                 
                 
                 
                 
             }
             
             
             
             
         }
        else if(v[i][1]+v[i+1][0]>v[i+1][1]){
             ans+=v[i][1];
             r=0;
         }
         else{
             r=1;
             l=1;
             continue;
         }
         
     }
     else if(r==0){
         
    if(v[i][0]+v[i+1][1]>v[i+1][1]){
             ans+=v[i][1];
             r=0;
         }
         else{
             r=1;
             continue;
         }
         
         
     }
 }
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   return 0;
}