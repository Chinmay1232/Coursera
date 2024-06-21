#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

signed main()
{
    ll n;
    cin >> n;

    vector<ll> a = {1,3,4};
    vector<ll> dp(n+1, n+3);

    dp[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < 3; j++)
        {
            dp[i] = min(dp[i], ((i-a[j] >= 0)?1+dp[i-a[j]]:INT_MAX));  
        }
    }
    
    cout << dp[n];
    return 0;
}