#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<string> s(105);  // vector to store n words
vector<int> adj[26];    // adjacency list
vector<int> order;  // vector to store sorted vertex after toposort
bool flag = false;  // for cycle detection
bool leflag=false;
bool visited[105];
bool recurstack[105];
void dfs(int x, int parent) {
  if (visited[x] == false) {  // if vertex x is not visited we mark it true
    visited[x] = true;
    recurstack[x] = true;  // mark recursion stack foor x as true
    for (int u = 0; u < adj[x].size(); u++) {
      int v = adj[x][u];  //  v as adjacent  vertex  of x
      if (visited[v] == true && recurstack[v] == true)
        flag = true;    // cycle found
      if (!visited[v])  // if not visited start dfs here
        dfs(v, x);      // mark x as parent of v
    }
      recurstack[x] = false;
       order.push_back(x);
  }
  // cout<<" x is "<<x<<endl
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    s[i] = x;
  }
  for (int i = 0; i < 105; i++) {  // visited  and recur vector marked false
    visited[i] = false;
    recurstack[i] = false;
  }
  for (int i = 0; i < n - 1; i++) {  // total n strings
    string x = s[i];
    string y = s[i + 1];  // the two adjacent words i string s vector
    int co=0;

    for (int j = 0; j < min(x.length(), y.length()); j++) {
           if(x[i]==y[i])
            co++;
       if (x[j] != y[j])  // mismatch occurs at  this index here
      {
        int p = x[j] - 'a';
        int q = y[j] - 'a';  // a-a=0 b-a=1 c-a=2
        adj[p].push_back(q);
        // cout<<char(p+'a')<< " "<<char(q+'a')<<endl;
        break;  // move out of loop after first mismatch
      }
      if(x.length()>y.length()&& co==min(x.length(),y.length()))
        leflag=true;

    }
  }
  for (int i = 0; i <= 25; i++)  // z-'a'==25
    dfs(i, -1);  // call dfs on all vertices
  // since sorted vector is pushed in vector order in dfs so i call it on all
  // vertices ,this checks cycle and inserts ordered vertices
   if(flag==true || leflag==true)
    cout << "Impossible" << endl;
   // if flag is false  means cycle  not found
   else{
    for (int i = order.size() - 1; i >= 0; i--) cout << char(order[i] + 'a');
    cout << " " << endl;
  }


  return 0;
}