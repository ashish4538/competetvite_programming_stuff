/*The only difference with E1 is the question of the problem.

Vlad built a maze out of n rooms and n−1 bidirectional corridors. From any room u any other room v can be reached through a sequence of corridors. Thus, the room system forms an undirected tree.

Vlad invited k friends to play a game with them.

Vlad starts the game in the room 1 and wins if he reaches a room other than 1, into which exactly one corridor leads. Friends are placed in the maze: the friend with number i is in the room xi, and no two friends are in the same room (that is, xi≠xj for all i≠j). Friends win if one of them meets Vlad in any room or corridor before he wins.

For one unit of time, each participant of the game can go through one corridor. All participants move at the same time. Participants may not move. Each room can fit all participants at the same time.

Friends know the plan of a maze and intend to win. They don't want to waste too much energy. They ask you to determine if they can win and if they can, what minimum number of friends must remain in the maze so that they can always catch Vlad.

In other words, you need to determine the size of the minimum (by the number of elements) subset of friends who can catch Vlad or say that such a subset does not exist.

Input
The first line of the input contains an integer t (1≤t≤104) — the number of test cases in the input. The input contains an empty string before each test case.

The first line of the test case contains two numbers n and k (1≤k<n≤2⋅105) — the number of rooms and friends, respectively.

The next line of the test case contains k integers x1,x2,…,xk (2≤xi≤n) — numbers of rooms with friends. All xi are different.

The next n−1 lines contain descriptions of the corridors, two numbers per line vj and uj (1≤uj,vj≤n) — numbers of rooms that connect the j corridor. All corridors are bidirectional. From any room, you can go to any other by moving along the corridors.

It is guaranteed that the sum of the values n over all test cases in the test is not greater than 2⋅105.

Output
Print t lines, each line containing the answer to the corresponding test case. The answer to a test case should be −1 if Vlad wins anyway and a minimal number of friends otherwise.


*/


















#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int                long long // __int128 FOR BIG INTEGERS WITH C++ 17 (64) (UPTO 10^35 OR SOMETHING)
#define double             long double
#define FAST               ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>ordered_multiset;
//FIND_BY_ORDER(K)  --> VALUE AT KTH INDEX (ITERATOR)
//ORDER_OF_KEY(K)   --> INDEX OF VALUE K

void dbg_out(){cerr << endl;}
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

const double pi = 3.14159265359;
const int mod = 1000000007;
const int modc = 998244353;
const int inf = LLONG_MAX;
const int neg_inf = LLONG_MIN;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //USE rng() INSTEAD OF rand() //shuffle(all(a),rng)

//FOR unordered_map<int,int,custom_hash> TO AVOID FALTU TLE'S COZ OF ANTIHASHES.
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//BINARY EXPONENTIATION(I HOPE SPELLING IS CORRECT)
int inline power(int a, int b, int p){
    a %= p;
    int ans = 1;
    while(b>0){
        if(b & 1)
            ans = (ans*a)%p;
        a = (a*a)%p;
        b >>= 1;
    }
    return ans;
}

//MOD INVERSE (ONLY WORKS WHEN P IS PRIME)
int mod_inv(int n, int p){
    return power(n,p-2, p);
}

int dx[] = {1,0,-1,0,1,-1,1,-1};  //FOR BFS IN MATRIX
int dy[] = {0,1,0,-1,1,1,-1,-1};  //YEAH! SAME

const int M = 2e5 + 5;

//SIEVE IN O(N) TIME (FOR N UPTO 1e7 OTHERWISE YOU'LL FACE MEMORY ISSUES)
/*
vector<int>lp(M);
vector<int>pr;
void sieve()
{
	lp[0] = 1; //AISE HI RANDOM , KUCHH BHI.

	for(int i = 2 ; i < M ; i++)
	{
		if(lp[i] == 0)
		{
			//this is a prime
			lp[i] = i;
			pr.push_back(i);
		}
		for(int j = 0 ; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < M; j++)
			lp[i * pr[j]] = pr[j];
	}
}
*/

//FOR NCR CALCULATIONS
/*
int fact[M];
int ncr(int n, int r)
{
	int ans = fact[n];
	int denom = (fact[r]*fact[n-r])%mod;
	ans = (ans * mod_inv(denom,mod))%mod;
	return ans;
}
*/

vector<int>v[M];
vector<int>dist(M);
vector<int>friends(M);
vector<int>vis(M);

void dfs(int node , int par)
{
	for(auto x : v[node])
	{
		if(x == par)
			continue;
		dfs(x , node);
		dist[node] = min(dist[node] , dist[x] + 1);
	}
	if(friends[node])
		dist[node] = 0;
}

void dfs1(int node , int par , int d)
{
	vis[node] = 1;
	for(auto x : v[node])
	{
		if(x == par)
			continue;

		if(dist[x] > d + 1)
			dfs1(x , node , d + 1);
	}
}

int ans;

void dfs3(int node , int par , int d)
{
	for(auto x : v[node])
	{
		if(x == par)
			continue;

		if(dist[x] <= d + 1)
			ans++;
		else
			dfs3(x , node , d + 1);
	}
}

void solve()
{
	int n , k;
	cin >> n >> k;

	for(int i = 0 ; i <= n  ; i++)
	{
		v[i].clear();
		dist[i] = 1e9;
		friends[i] = 0;
		vis[i] = 0;
	}

	vector<int>x(k);

	for(int i = 0 ; i < k ; i++)
	{
		cin >> x[i];
		friends[x[i]] = 1;
	}

	for(int i = 0 ; i < n - 1 ; i++)
	{
		int a , b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1 , 0);

	dfs1(1 , 0 , 0);

	for(int i = 2 ; i <= n ; i++)
	{
		if(vis[i] && (int)v[i].size() == 1)
		{
			cout << -1 << endl;
			return;
		}
	}
	ans = 0;
	dfs3(1 , 0 , 0);
	cout << ans << endl;
}
int32_t main()
{
	FAST;
	int t = 1;
	cin >> t;
	/*
	fact[0] = 1;
	for(int i = 1;i<M;i++)
		fact[i] = (i * fact[i-1])%mod;
		*/
	int test = 1;
	while(t--)
	{
	//	cout << "Case #" << test << ": ";
		solve();
		test++;
	}
} 