#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long 
using namespace std ;

const int N = 1501 ;
int dx[] = {1 , -1 ,-1 , 1};
int dy[] = {1, 1 , -1 , -1};
const int inf = 1e15 ;
char grid[N][N];
int vis[N][N][4] , dis[N][N][4];
int n , m ;
bool valid(int i , int j){
    if(i < 0 || i >=  n || j <  0 || j >= m) return 0;
    
    if(grid[i][j] == '#'){
        return  0;
    }
    return 1 ;
}
signed  main(){

	cin >> n ; 
	int sx , sy , ex , ey ;
	cin >> sx >> sy >> ex >> ey ;
	m =  n ;
	sx-- , sy-- , ex-- , ey--;
	
	for(int i =  0 ; i < n ; i++){
		 for(int j =  0 ; j < m ; j++){
		 	   cin >> grid[i][j];
		 }
	}
	
	// { {dis , dir} , {x , y} }
	set<pair<pii , pii>> s ;
	for(int i = 0  ; i <=  n ; i++){
		 for(int j = 0  ; j <=  n ; j++){
		 	  for(int k = 0  ; k <= 3 ; k++) dis[i][j][k] = inf ;
		 }
	}
	
    for(int i = 0  ; i < 4 ; i++){
    	 s.insert({{1, i} , {sx , sy}});
    	 dis[sx][sy][i] = 1 ;
	}	
	
	
	
	while(!s.empty()){
		 auto it = s.begin();
		 auto curr_x = (*it).second.first ;
		 auto curr_y = (*it).second.second ;
		 auto dir = (*it).first.second ;
		 s.erase(it);
		 
		// cout << curr_x << " " << curr_y << endl;
		 for(int i = 0  ; i < 4 ; i++){
		 	  if(i == dir)
			   {
		 	  	 int nx = curr_x + dx[i];
		 	  	 int ny = curr_y + dy[i];
		 	  	 if(valid(nx , ny))
				   {
		 	  	 	  if(dis[nx][ny][dir] > dis[curr_x][curr_y][dir])
		 	  	 	  {
		 	  	 	      s.erase({{dis[nx][ny][dir] , dir} , {nx , ny}});
						  dis[nx][ny][dir] = dis[curr_x][curr_y][dir]	;
						  s.insert({{dis[nx][ny][dir] , dir} , {nx , ny}});
					  }
					}
			   }
			   else
			   {
			   	    int nx = curr_x + dx[i];
		 	  	    int ny = curr_y + dy[i];
			   	  if(valid(nx , ny))
			   	  {
			   	  	 if(dis[nx][ny][i] > dis[curr_x][curr_y][dir]  + 1)
		 	  	 	  {
		 	  	 	      s.erase({{dis[nx][ny][i] , i} , {nx , ny}});
						  dis[nx][ny][i] = dis[curr_x][curr_y][dir]	+ 1;
						  s.insert({{dis[nx][ny][i] , i} , {nx , ny}});
					  }
				  }
			   }
		 }
	}
	
//	
	int ans = inf ;
    
    
   for(int i = 0  ; i < 4 ; i++){
       ans = min(ans , dis[ex][ey][i]);
   }
	
	if(ans == inf) ans = -1 ;
	cout << ans << endl;
}