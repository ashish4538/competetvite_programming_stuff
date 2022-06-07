#include <bits/stdc++.h>
#define ll long long int

using namespace std;
const ll MAX=4e18;

int main()
{
    
    int tc;
    cin>>tc;
while(tc--){
    
   string s;
   cin>>s;
  
   int n=s.size();
   vector<bool>dp(n);
   bool sign=true;
   stack<int>sc;
   for(int i=0;i<n;i++){
       if(s[i]==')'){
           dp[i]=dp[sc.top()];
           sc.pop();
           sign=dp[i];
           continue;
       }
       dp[i]=sign;
       if(s[i]=='(')sc.push(i);
       if(s[i]=='-')sign^=true;
   }
    vector<array<int,2>>pre(n);
    pre[0][0]=pre[0][1]=0;
    for(int i=1;i<n;i++){
        pre[i][0]+=pre[i-1][0];
        pre[i][1]+=pre[i-1][1];
        if(s[i]=='?')pre[i][dp[i]]++;
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        if(l==r){cout<<"1 "; continue;}
        
        cout<<pre[r][dp[r]]-pre[l][dp[l]]<<" ";
    }
    cout<<"\n";
    
   
   
   
   }
   
   
   return 0;
}
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    
