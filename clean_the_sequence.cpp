#include <bits/stdc++.h>


using namespace std;

int main()
{
   
  int tc;
  cin>>tc;
  while(tc--){
    
  
int n, k; cin>>n>>k;  
std::vector<int> v;  

for(int i = 0;i<n;i++){  
    int x; cin>>x;  
    if(i == 0) v.push_back(x);  
    else if(x != v.back()) v.push_back(x);  
}  

n = v.size();  

int totalUgliness = 0;  
for(int i = 0;i<n - 1;i++){  
    if(v[i] != v[i + 1]) totalUgliness++;  
}  

//cout<<totalUgliness<<" ";
  
vector<int>ans(k + 1, totalUgliness);  
for(int i = 0;i<n;i++){  
    if(i + 1 < n){  
        ans[v[i]]--;  
        //since all are different we can just subtract one and it will 
        //work
    }  
    if(i - 1 >= 0){  
        ans[v[i]]--;  
    }  
    if(i - 1 >= 0 && i + 1 < n && v[i + 1] != v[i - 1]) ans[v[i]]++; 
    //if the preceeding and suceeding digit are not the same it won't 
    //work becaue erasing it will create one more ugliness
}  

for(int i = 1;i<=k;i++) cout<<ans[i]<<" ";  
cout<<"\n";  
      
      
      
      
      
  }
   
   
   
   
   
   
   
   
   return 0;
}