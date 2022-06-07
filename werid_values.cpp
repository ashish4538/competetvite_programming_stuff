/*You are given an array A=[A1,A2,…,AN] containing N integers.

Consider any subarray [AL,AL+1,…,AR] of this subarray (where 1≤L≤R≤N). Ther weirdness of this subarray, denoted w(L,R), is defined to be the number of indices L≤i≤R such that Ai equals the number of occurrences of Ai in this subarray.

Formally, we define w(L,R) for 1≤L≤R≤N as follows:

For every integer x, let fL,R(x) denote the number of indices L≤j≤R such that Aj=x.
w(L,R) then equals the number of L≤i≤R such that Ai=fL,R(Ai)
For example, let A=[1,3,5,2,1,2,9,5]. Then,

w(1,8)=2, which can be computed as follows. We have
f1,8(1)=2
f1,8(2)=2
f1,8(3)=1
f1,8(5)=2
f1,8(9)=1
The only indices which satisfy f1,8(Ai)=Ai are i=4 and i=6, and hence w(1,8)=2.

w(3,5)=1 — the subarray is [5,2,1], and each of 1,2,5 occur exactly once in this subarray. Of these, only 1 equals the number of its occurrences in this subarray.
Given A, your task is to compute the sum of the weirdness of all subarrays of A, i.e, the value
∑L=1N∑R=LNw(L,R)
Input Format
The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains an integer N, the size of the given array.
The second line of each test case contains N space-separated integers A1,A2,…,AN — the elements of A.
Output Format
For each test case, output a single line containing a single integer — the sum of the weirdness of all subarrays of the given array.

Constraints
1≤T≤103
1≤N≤106
1≤Ai≤106
The sum of N across all test cases does not exceed 106.


*/



























#include <bits/stdc++.h>

using namespace std;



int32_t main()
{
    
ios::sync_with_stdio(0);
cin.tie(0);   
    
  
  int tc;
  cin>>tc;
  while(tc--){
    int n;
    cin>>n;
    vector<vector<int>>inds(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x<=n)inds[x].push_back(i);
        //if x>n then it won't we able to contribute to the frequency
    }
    
    long long  ans=0;
    for(int x=1;x<=n;x++){
        vector<int>indsx=inds[x];
        indsx.insert(begin(indsx),0);
        indsx.push_back(n+1);
        //padding on both sides of the array
        for(int i=1;i<int(indsx.size())-x;i++){
            //x is first removing all elements that have  the frequency less its value and also keeping us from overflow.
            ans+=(long long )x*(indsx[i]-indsx[i-1])*(indsx[i+x]-indsx[i+x-1]);
            //[$ 3 $ 3 $ 3 $]
            //ind[i-1]=0   ind[i]=2  ind[i+x]=10 ind[i+x-1]=7;    
        }
    }
    cout<<ans<<"\n";
    
      
  }
   
   return 0;
}