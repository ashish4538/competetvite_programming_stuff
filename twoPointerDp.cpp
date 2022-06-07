#include <bits/stdc++.h>
using namespace std;
int a[5001];
int f(int l,int r,int h){
    if (r < l) return 0;
    int m = min_element(a + l, a + r + 1) - a;
    return min(r-l+1,f(l, m-1, a[m])+f(m+1, r, a[m])+a[m]-h);
}
int main(){
    int n; cin>>n;
    for (int i = 0; i < n; i++) cin>>a[i];
    cout<<f(0,n-1,0);
}