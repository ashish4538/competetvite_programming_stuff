#include <bits/stdc++.h>
#define int long long int 
//GSS1 - Can you answer these queries I
using namespace std;

const int inf=1000000;

struct data {
    int sum, pref, suff, ans;
    data(){};
    data(int val){
        sum=ans=pref=suff=val;
    }
};

data combine(data l, data r) {
    data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}


const int MX=4*50000 ;
vector<data>t(MX+16);
void build (int a[],int v,int tl,int tr){
	if(tl==tr){
		t[v]=data(a[tl]);
	}
	else{
		int tm=(tl+tr)/2;
		build(a,v*2,tl,tm);
		build(a,v*2+1,tm+1,tr);
		t[v]=combine(t[v*2],t[v*2+1]);
	}
}

data query(int v,int tl,int tr,int l,int r){
	if(l>r){
		return data(-inf);
	}
	if(l==tl && r==tr){
		return t[v];
	}
	int tm=(tl+tr)/2;
	return combine(query(v*2,tl,tm,l,min(r,tm)),query(v*2+1,tm+1,tr,max(l,tm+1),r));
}

int a[MX+16];


void solve(){
    
 int n;
 cin>>n;

 for(int i=0;i<n;i++){
	 cin>>a[i];
 }
 build(a,1,0,n-1);
 
 int m;
 cin>>m;
 while(m--){
	 int l,r;
	 cin>>l>>r;
	 l--,r--;
	 data ans=query(1,0,n-1,l,r);
	 cout<<ans.ans<<"\n";
	 

   
 
}




}









int32_t main()
{

ios::sync_with_stdio(0);
cin.tie(0);
int t;
t=1;
while(t--){

solve();

}
   
   return 0;
   
}