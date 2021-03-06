



/*There are n people and k keys on a straight line. Every person wants to get to the office which is located on the line as well. To do that, he needs to reach some point with a key, take the key and then go to the office. Once a key is taken by somebody, it couldn't be taken by anybody else.

You are to determine the minimum time needed for all n people to get to the office with keys. Assume that people move a unit distance per 1 second. If two people reach a key at the same time, only one of them can take the key. A person can pass through a point with a key without taking it.

Input
The first line contains three integers n, k and p (1 = n = 1 000, n = k = 2 000, 1 = p = 1e9) — the number of people, the number of keys and the office location.

The second line contains n distinct integers a1, a2, ..., an (1 = ai = 1e9) — positions in which people are located initially. The positions are given in arbitrary order.

The third line contains k distinct integers b1, b2, ..., bk (1 = bj = 1e9) — positions of the keys. The positions are given in arbitrary order.

Note that there can't be more than one person or more than one key in the same point. A person and a key can be located in the same point.

Output
Print the minimum time (in seconds) needed for all n to reach the office with keys.




input
2 4 50
20 100
60 10 40 80
output
50

*/




#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    int a[n], b[k];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<k; i++){
        cin >> b[i];
    }
    sort(a, a+n);
    sort(b, b+k);
    int ans = INT_MAX;
	//why k-n?
	//path should not cross (prove it )
	// if path should not cross then if there are 4 people and 6 slots then it
	//------(1234--,-1234-,--1234)should look like this so,we used k-n so that we only have to check till k-n
    for(int i=0; i<=k-n; i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            sum = max(sum, abs(a[j]-b[i+j]) + abs(b[i+j]-p));
            // sum is storing every possible postion k-n times
        }
        ans = min(ans, sum);
    }
    cout << ans;
	return 0;
}