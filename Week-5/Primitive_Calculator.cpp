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

    vector<pair<int,int>> dp(n+1);

    for (int i = 2; i <= n; i++)
    {
        vector<int> op(3);
        op[0] = (i%3 == 0)?dp[i/3].first:INT_MAX-3;
        op[1] = (i%2 == 0)?dp[i/2].first:INT_MAX-3;
        op[2] = dp[i-1].first;
        
        int mn = min_element(op.begin(),op.end())-op.begin();
        dp[i].first = 1+op[mn];
        dp[i].second = mn;
    }

    int idx = n;
    vector<int> ans;
    ans.push_back(n);

    while(idx != 1)
    {
        if(dp[idx].second == 0)
        {
            ans.push_back(idx/3);
            idx/=3;
        }
        else if(dp[idx].second == 1)
        {
            ans.push_back(idx/2);
            idx/=2;
        }
        else
        {
            ans.push_back(idx-1);
            idx-=1;
        }
    }

    cout << dp[n].first << "\n";

    reverse(ans.begin(),ans.end());

    for(auto ele : ans)
    {
        cout << ele << " ";
    }
    
    return 0;
}