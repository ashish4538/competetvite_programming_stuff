#include <iostream>

using namespace std;


   int r,c;


int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
//four direction available


void floodFill(char mat[][50],int i,int j,char ch,char color){
    
    
    //base case;
    if(i<0 || j<0 || i>=r || j>=c){
        return ;
    }
    
    if(mat[i][j]!=ch){
        return;
    }
    
    //Recursive call
    mat[i][j]=color
    
    for(int k=0;k<4;k++){
        floodFill(mat,i+dx[k],j+dy[k],ch,color)
    }
    
    
    
    
    
}
















int main()
{
   

   cin>>r>>c;
   char inp[15][50];
   
   for(int i=0;i<r;i++){
       for(int j=0;j<c;j++){
           cin>>inp[i][j];
       }
   }
   
   
   
   
   
   
   
   return 0;
}