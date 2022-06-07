//BITSWAPS
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
int ranks[300001];
int parent[300001];


bool isKthBitSet(int n, int k)
{
    if (n & (1 << (k)))
        return true;
    return false;
}

int find(int node){
    if(node==parent[node]){
        return node;
    }
    else{
        return find(parent[node]);
    }
}
void union1(int x, int y){
    int i = find(x);
    int j = find(y);
    if(i!=j){
        if(ranks[i]>ranks[j]){
            ranks[i]+=ranks[j];
            parent[j] = i;
        }
        else if(ranks[j]>ranks[i]){
            ranks[j]+=ranks[i];
            parent[i] = j;
        }
        else{
            parent[j] = i;
            ranks[i]++;
        }
        
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    for(int i=0;i<300001;++i){
            ranks[i] = 0;
            parent[i]  = i;
    }
    int t;
    cin>>t;
    
    while(t--){
        
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            ranks[i] = 0;
            parent[i]  = i;
        }
        vector<int>vect(n), temp(n);

        for(int i=0;i<n;++i){
            cin>>vect[i];
            temp[i] = vect[i];
        }

        vector<vector<int>>bits(32);

        for(int i=0;i<32;++i){
            for(int j=0;j<n;++j){
                if(isKthBitSet(vect[j], i))
                {
                    bits[i].push_back(j);
                }
            }
        }

        for(int i=0;i<bits.size();++i){
            
            for(int j=0;j<(int)bits[i].size()-1;++j){
                int x = bits[i][j];
                int y = bits[i][j+1];
                if(find(x)!=find(y)){
                    union1(x, y);

                }
            }
        }

        vector<set<int>>s(n);//s[i] is acting like parent array and not taking in duplicates

        for(int i=0;i<n;++i){
            s[find(i)].insert(i);
            // cout<<find(i)<<" "<<i<<endl;
        }
        sort(temp.begin(), temp.end());
        map<int, int>sortedindex;
        for(int i=0;i<n;++i){
            sortedindex[temp[i]] = i;
        }
        bool flag = true;
        for(int i=0;i<n;++i){
            //won't give tle because all elements will won't exceed n even if there are n parents
            for (auto itr = s[i].begin(); itr != s[i].end(); itr++) {//us index ka sorted usi ka parent mein present hai ya nahi
                if(s[i].find(sortedindex[vect[*itr]])==s[i].end()){
                    flag = false;
                    break;
                }
            }
        }

        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}

