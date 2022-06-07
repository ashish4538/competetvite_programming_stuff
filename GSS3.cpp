#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b)      for(int i=(a);i<(b);++i)
using namespace std;
const int inf=1e+9;
const int MAXN=1e5+10;
const int MAXK=0;
//spoj GSS3
int arr[MAXN];


struct data {
    int sum,pref,suff,ans;
};

data combine(data l,data r){
    data res;
    res.sum=l.sum+r.sum;
    res.pref=max(l.pref,l.sum+r.pref);
    res.suff=max(r.suff,r.sum+l.suff);
    res.ans=max(max(l.ans,r.ans),l.suff+r.pref);
    return res;
    
}
data make_data(int val){
    data res;
    res.sum=val;
    res.pref=res.suff=res.ans=val;
    return res;
}
data tree[MAXN<<2];





void buildTree(int low, int high, int pos) {
     int mid =(low+high)>>1;

     if(low == high)
        tree[pos] = make_data(arr[mid]);
    else {
        buildTree(low, mid, 2*pos);
        buildTree(mid+1, high, 2*pos+1);

        tree[pos] = combine(tree[2*pos] , tree[2*pos+1]);
    }
}

data queryTree(int low, int high, int pos, int qLow, int qHigh) {
    int mid = (low+high)>>1;

    if(qLow > high || qHigh < low)
        return make_data(-inf);
    else if(qLow <= low && qHigh >= high)
        return tree[pos];
    else
        return combine(queryTree(low, mid, 2*pos, qLow, qHigh) , queryTree(mid+1, high, 2*pos+1, qLow, qHigh));
}

void updateTree(int low, int high, int pos, int idx, int val) {
    int mid = (low+high)>>1;

    if(idx < low || idx > high)
        return ;
    else if(low == high)
        tree[pos] = make_data(val);
    else {
        updateTree(low, mid, 2*pos, idx, val);
        updateTree(mid+1, high, 2*pos+1, idx, val);

        tree[pos] = combine(tree[2*pos] , tree[2*pos+1]);
    }
}

//Main function
int32_t main() {
  

    int n;
    cin>>n;

    FOR(i, 1, n+1)
        cin>>arr[i];
    buildTree(1, n, 1);

    int q;
    cin>>q;

    while(q--) {
        int x, a, b;
        cin>>x>>a>>b;
        if(x==0){
            updateTree(1,n,1,a,b);
        }
        else{
            data ans=queryTree(1,n,1,a,b);
            cout<<ans.ans<<"\n";
        }

       
    }

    return 0;
}