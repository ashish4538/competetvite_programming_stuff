#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=404,M = 404;
int n,m;
int ar[N][M];
int maze[N][M];
int row[N][M],col[N][M];

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		for(int j=1;j<=m;j++){
			maze[i][j] = s[j-1] - '0';
			row[i][j] = row[i][j-1] + maze[i][j];
			//will store number of ones in the given input
			col[i][j] = col[i-1][j] + maze[i][j];
			//will store number of ones of in the col of given output
			maze[i][j] += maze[i-1][j] + maze[i][j-1] - maze[i-1][j-1];
		}
	}
	
	int res = 0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int di = i+4;di <= n;di ++){
				for(int dj = j+3;dj <= m;dj++){
					int temp = maze[di-1][dj-1] + maze[i][j] - maze[i][dj-1] - maze[di-1][j];
					if(temp >= res) break;
					temp += ((dj - j - 1) * 2) - (row[di][dj-1] - row[di][j] + row[i][dj-1] - row[i][j] );
					if(temp >= res) break;
					temp += ((di - i - 1) * 2) - (col[di-1][j] - col[i][j] + col[di-1][dj] - col[i][dj]);
					res = min(res,temp);
				}
			}
		}
	}
	
	cout<<res<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
//	freopen("a.in","w",stdin);
	int T;cin>>T;
	while(T--){
		solve();
	}
	
	
	return 0;
}