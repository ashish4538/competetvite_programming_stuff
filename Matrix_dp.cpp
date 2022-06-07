#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define mx INT_MAX
#define mn INT_MIN
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define itr set<int> :: iterator
const int N = 1e5+10;


int main(){

// #ifndef ONLINE_JUDGE
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
// #endif

    // ******* START HERE ******
    
    int n,m;
    cin>>n>>m;

    vector<vector<int> > grid;

    for(int i=0; i<n; i++){
        vector<int> v;
        string str;
        cin>>str;
        for(int j=0; j<m; j++){
            int x = str[j]-'0';
            v.pb(x);
        }
        grid.pb(v);
    }    

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(grid[i][j]==1){
                grid[i][j] = min(grid[i-1][j-1], grid[i-1][j]) + 1;
            }
        }
    }
 
    ll cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            cnt += grid[i][j];
           // cout<<grid[i][j]<<" ";
        }
       // cout<<endl;
    }    

    cout<<cnt<<endl;

    // ***** END HERE ***** 
    return 0;
}
//Problem Code: MATRIX2