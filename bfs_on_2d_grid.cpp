#include <bits/stdc++.h>
using namespace std;


bool vis[8][8];
int dist[8][8];
int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

 
bool isValid(int x , int y)
{
	if(x > 7 || x < 0 || y > 7 || y < 0) return false;
	
	if(vis[x][y]) return false;
	
	return true;
}
 
void bfs(int srcX , int srcY)
{
	queue< pair<int,int> > q;
	q.push( {srcX , srcY} );
	dist[srcX][srcY] = 0;
	vis[srcX][srcY] = 1;
	
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int d = dist[x][y];
		q.pop();
		
		for(int i=0;i<8;i++)
		{
			int newX = x + X[i];
			int newY = y + Y[i];
			
			if(isValid(newX , newY))
			{
				dist[newX][newY] = d + 1;
				vis[newX][newY] = 1;
				q.push( {newX , newY} );
			}
		}
	}
	
}
 