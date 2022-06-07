#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b)      for(int i=(a);i<(b);++i)
using namespace std;
const int inf=1e18;
const int MAXN=1e5+10;
const int MAXK=0;

int arr[MAXN], tree[MAXN<<2];



struct data {
     int l,mx,mi;
    data(){};
    data(int v){
        mx=mi=v;
		l=0;
		
    }
};












data combine(data left,data right){
	data res;
	if(x.l==0 && y.l==0 && x.mx<=y.mi ){
		res.l=0;
		
	}
	else{
		if( left.mx>right.mi){
			int posk=(x.mx+y.mx)/2;
			 res.l=posk;
			 
		}
		else if(y.l<x.l && (abs(x.l-y.mi)<x.mx || abs(y.mx-x.l)<x.mx) ){
			res.l=-1;
		}
		else if(y.l>=x.l && 
		

}










void buildTree(int low, int high, int pos) {
     int mid =(low+high)>>1;

     if(low == high)
        tree[pos] = arr[mid];
    else {
        buildTree(low, mid, 2*pos);
        buildTree(mid+1, high, 2*pos+1);

        tree[pos] = combine(tree[2*pos] , tree[2*pos+1]);
    }
}

int queryTree(int low, int high, int pos, int qLow, int qHigh) {
    int mid = (low+high)>>1;

    if(qLow > high || qHigh < low)
        return 0;
    else if(qLow <= low && qHigh >= high)
        return tree[pos];
    else
        return queryTree(low, mid, 2*pos, qLow, qHigh) + queryTree(mid+1, high, 2*pos+1, qLow, qHigh);
}

void updateTree(int low, int high, int pos, int idx, int val) {
    int mid = (low+high)>>1;

    if(idx < low || idx > high)
        return ;
    else if(low == high)
        tree[pos] = val&1;
    else {
        updateTree(low, mid, 2*pos, idx, val);
        updateTree(mid+1, high, 2*pos+1, idx, val);

        tree[pos] = tree[2*pos] + tree[2*pos+1];
    }
}

//Main function
int_32t main() {
  

    int n;
    cin>>n;

    FOR(i, 1, n+1)
        cin>>arr[i], arr[i] &= 1;
    buildTree(1, n, 1);

    int q;
    cin>>q;

    while(q--) {
        int q, a, b;
        cin>>q>>a>>b;

        if(!q)
            updateTree(1, n, 1, a, b);
        else {
            int ans = queryTree(1, n, 1, a, b);

            if(q&1)
                ans = (b-a+1) - ans;
            cout<<ans<<endl;
        }
    }

    return 0;
}