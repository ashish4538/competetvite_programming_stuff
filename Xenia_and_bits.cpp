#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b)      for(int i=(a);i<(b);++i)
using namespace std;
const int inf=1e+9;
const int MAXN=((1<<17)+10);
const int MAXK=0;
//Xenia and bits 
int arr[MAXN];






struct node{
    int level;
    int value;
};

node  tree[MAXN*4];
 
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
 



void buildTree(int low, int high, int pos) {
     int mid =(low+high)>>1;

     if(low == high){
        tree[pos].value =arr[mid];
        tree[pos].level=1;
        return;
      }
    else {
        buildTree(low, mid, 2*pos);
        buildTree(mid+1, high, 2*pos+1);
        tree[pos].level=tree[2*pos].level+1;
        int f=tree[pos].level;
        if(f&1) tree[pos].value = tree[2*pos].value ^ tree[2*pos+1].value;
        else tree[pos].value = tree[2*pos].value | tree[2*pos+1].value;
    }
}


void updateTree(int low, int high, int pos, int idx, int val) {
    int mid = (low+high)>>1;

    if(idx < low || idx > high){
        return ;
    }
    else if(low == high){
        tree[pos].value = val;
        return;
    }
    else{ 
        updateTree(low, mid, 2*pos, idx, val);
        updateTree(mid+1, high, 2*pos+1, idx, val);
         int f=tree[pos].level;
        if(f&1) tree[pos].value = tree[2*pos].value ^ tree[2*pos+1].value;
        else tree[pos].value = tree[2*pos].value | tree[2*pos+1].value;
    }
    
}

//Main function
int32_t main() {
  

    int n;
    cin>>n;
    int q;
    cin>>q;
    int sz=binpow(2,n);

    FOR(i, 1, sz+1)
        cin>>arr[i];
    buildTree(1, sz, 1);
   

    

    while(q--) {
        int  a, b;
        cin>>a>>b;
       updateTree(1,sz,1,a,b);
       cout<<tree[1].value<<"\n";

       
    }

    return 0;
}