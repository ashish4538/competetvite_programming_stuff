#include <bits/stdc++.h>

using namespace std;

int chil[200010];
priority_queue<int> que;

int main()
{
	int t, n, i, p;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		
		for(i=0; i<=n; i++) chil[i] = 0;
		
		chil[0] = 1;
		for(i=2; i<=n; i++){
			cin >> p;
			chil[p]++;
		}
		
		sort(chil, chil+n+1, greater<int>());
		
		for(i=0; i<n; i++){
			if(chil[i] == 0) break;
			que.push(chil[i]+i);
		}
		for(; i<que.top(); i++){
			que.push(que.top()-1);
			que.pop();
		}
		
		cout << i << '\n';
		
		while(!que.empty()) que.pop();
	}
	
	return 0;
}