//Codeforces Round #616 (Div. 1) Mind Control
#include <bits/stdc++.h>
using namespace std;
int a[100000];
int c=1e9+1;
int main(){
	int t;
	cin>>t;
	while(t--){
		int ans=0;
		int n,m,k;
		cin>>n>>m>>k;
		k=min(k,m-1);
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<=k;i++){
			c=1e9+1;
			for(int j=0;j<m-k;j++){
				 c=min(c,max(a[i+j],a[i+j+n-m]));//I will check every subarray(n-m+1) but i only have control over certain ones
				 //if the subarray is determined by opponent choice i have to take min among them
				 //if the subarray is determined by me that is what iteration of i is for then i will take maximum among them
				 //of course the max among first and last element of my turn subarray.
			}
			ans=max(ans,c);
		}
		cout<<ans<<'\n';
		ans=0;
	}
}

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    k = min(k, m - 1);
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;
    vector<int> b;
    for(int i = 0; i < m; i++)
        b.push_back(max(a[i], a[i + n - m]));
    int sz = m - k;
    int ans = 0;
    deque<int> q;
    for(int i = 0, j = 0; i + sz - 1 < m; i++) {
        while(q.size() && q.front() < i)
            q.pop_front();
        while(j < i + sz) {
            while(q.size() && b[q.back()] >= b[j])
                q.pop_back();
            q.push_back(j++);
        }
        ans = max(ans, b[q.front()]);
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--)
        solve();
}

