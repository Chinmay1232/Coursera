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

    int o;
    cin >> o;

    vector<int> c(o);
    for (int i = 0; i < o; i++)
    {
        cin >> c[i];
    }

    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(m+1, vector<int>(o+1)));

    for (int i = n-1; i >= 0 ; i--)
    {
        for (int j = m-1; j >= 0; j--)
        {
            for (int k = o-1; k >= 0; k--)
            {
                if(a[i] == b[j] && a[i] == c[k])
                {
                    dp[i][j][k] = 1+dp[i+1][j+1][k+1];
                }
                else
                {
                    dp[i][j][k] = max({dp[i+1][j][k], dp[i][j+1][k], dp[i][j][k+1]});
                }
            }   
        } 
    }
    
    cout << dp[0][0][0];  
    return 0;
}