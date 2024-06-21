#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll k, n;
    cin >> k >> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 0));
    
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j <= k; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j-a[i-1] >= 0)
            {
                dp[i][j] = max(dp[i][j],a[i-1]+dp[i-1][j-a[i-1]]);
            }
        }    
    }
    
    cout << dp[n][k];

    
    return 0;
}