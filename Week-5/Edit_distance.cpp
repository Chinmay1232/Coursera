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
 
    string s,t;
    cin >> s >> t;
 
    int n = s.size();
    int m = t.size();
 
    vector<vector<int>> dp(n+1, vector<int>(m+1));
 
    for (int i = 0; i <= m; i++)
    {
        dp[n][i] = m-i;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][m] = n-i;
    }
 
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = m-1; j >= 0; j--)
        {
            if (s[i] == t[j])
            {
                dp[i][j] = dp[i+1][j+1];
            }
            else
            {
                dp[i][j] = 1+min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]});
            }
        }
    }
 
    cout << dp[0][0];
 
    return 0;
}