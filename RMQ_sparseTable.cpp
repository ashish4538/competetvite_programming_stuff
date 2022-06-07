#include<bits/stdc++.h>
using namespace std;


const int MAX_N=1e5+5;
const int LOG=17;
int a[MAX_N];
int m[MAX_N][LOG];//m[i][j] is minimum among a[i...i+2^j-1];
int bin_log[MAX_N];



int query(int L,int R){
int length =R-L+1;
int k=bin_log[length];//or k=31-__builtin_clz(x);//count leading zeros
return min(m[L][k],m[R-(1<<k)+1][k]);
}

//min , max , gcd

int main(){
int n;
cin>>n;

bin_log[1]=0;
for(int i=2;i<=n;i++){//extra for log2;
	bin_log[i]=bin_log[i/2]+1;
}



//read input

for(int i=0;i<n;i++){
cin>>a[i];
m[i][0]=a[i];
}
//preprocessing
for(int k=1;k<LOG;k++){
   for(int i=0;i+(1<<k)-1<n;i++){//constructing 2^k from all the 2^(k-1) in a loop
      m[i][k]=min(m[i][k-1],m[i+(1<<(k-1))][k-1]);
	  }

}


int q;
cin>>q;
for(int i=0;i<q;i++){
int L,R;
cin>>L>>R;
cout<<query(L,R)<<"\n";
}
}

