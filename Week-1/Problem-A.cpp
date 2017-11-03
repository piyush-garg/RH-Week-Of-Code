/*Author:@abs51295*/
#include <bits/stdc++.h>
#include<fstream>
#define fr freopen("input.in","r",stdin)
#define fw freopen("output.out","w",stdout)
#define iOs ios_base::sync_with_stdio(false);
#define INF 1000000009
#define MOD 1000000007
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

/**
* A program to find minimum number of steps to reach from x to t if possible using given operations.
* Time Complexity: O(t)
* Space Complexity: O(t)
*
*/

int main() {
    iOs;

    //We have to reach from x to t in minimal steps if possible.
    ll x,t;
    cin >> x >> t;

    int dp[t+1];

    for(int i=0; i<=t; i++) { //Marking all nodes as unreachable.
        dp[i] = INT_MAX;
    }

    //As we are already at source node.
    dp[x] = 0;

    for(int i=x; i<=t; i++) {
        if(dp[i] != INT_MAX) { //We only want to compute paths for those nodes which are reachable from start node x.
            if(i*4+1 <= t) {
                //Either we have already reached the node previously,
                //OR we are reaching it the first time.
                //Hence it has to be the min of both.
                dp[i*4+1] = min(dp[i*4+1],dp[i]+1);
                // cout << i*4+1 << ' ' << dp[i*4+1] << ' ' << dp[i+1] << endl;
            }
            if(i*5+1 <= t) { //Explore both the possibilities from current node.
                dp[i*5+1] = min(dp[i*5+1],dp[i]+1);
                // cout << i*5+1 << ' ' << dp[i*5+1] << ' ' << dp[i+1] << endl;
            }
        } else {
            continue;
        }
    }
    if(dp[t] == INT_MAX) { //We cannot reach the node.
        cout << -1 << endl;
    } else {
        cout << dp[t] << endl;
    }
    return 0;
}
