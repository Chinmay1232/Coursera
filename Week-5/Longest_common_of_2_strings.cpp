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

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int m;
    cin >> m;

    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = m-1; j >= 0; j--)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = 1+dp[i+1][j+1];
            }
            else
            {
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    
    cout << dp[0][0];
    return 0;
}