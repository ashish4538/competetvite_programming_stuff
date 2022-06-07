#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
    return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define endl "\n"

#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

// -------------------------<RNG>-------------------------
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define SHUF(v) shuffle(all(v), RNG);
// Use mt19937_64 for 64 bit random numbers.

int solve(vector<int> &arr, int n, int sum, vector<vector<int>> &dp)
{
    if (n == 0)
        return sum == 0;

    if (dp[n][sum] != -1)
        return dp[n][sum];

    int ans = 0;
// how to solve equation of the format 
//x1+x2+x3.....xn=sum
// we can choose for x1 0 to arr[1] times
    for (int k = 0; k <= min(arr[n - 1], sum); k++)
        ans = (ans + solve(arr, n - 1, sum - k, dp)) % MOD;

    return dp[n][sum] = ans;
}

void solve()
{
    // Add your solution here
    int n;
    cin >> n;

    int k;
    cin >> k;

    map<int, int> mp;

    for (int i = 0; i < 2 * n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    int sum = 0;

    vector<int> arr;
    for (auto &itr : mp)
    {
        if (itr.first % 2 == 0)
            continue;

        sum += (itr.first * itr.second);
        arr.push_back(itr.second);
    }

    int extra = k - sum;

    if (extra < 0 or extra > n)
    {
        printf("0\n");
        return;
    }

    n = arr.size();

    vector<vector<int>> dp(n + 10, vector<int>(extra + 1, -1));

    int ans = solve(arr, n, extra, dp);

    printf("%lld\n", ans);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}

 //couarr codechef
