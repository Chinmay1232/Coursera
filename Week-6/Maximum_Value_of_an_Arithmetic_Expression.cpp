
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

ll calc(ll a, ll b, char op)
{
    if (op == '+')
    {
        return a + b;
    }
    else if (op == '-')
    {
        return a - b;
    }
    else
    {
        return a * b;
    }
}

pair<ll, ll> MinAndMax(vector<vector<ll>> &dp1, vector<vector<ll>> &dp2, ll i, ll j, vector<char> &op)
{
    ll min_value = INT_MAX;;
    ll max_value = INT_MIN;
	
    for (ll k = i; k < j; k++)
    {
        ll a = calc(dp1[i][k], dp1[k + 1][j], op[k]);
        ll b = calc(dp1[i][k], dp2[k + 1][j], op[k]);
        ll c = calc(dp2[i][k], dp1[k + 1][j], op[k]);
        ll d = calc(dp2[i][k], dp2[k + 1][j], op[k]);
        min_value = min({min_value, a, b, c, d});
        max_value = max({max_value, a, b, c, d});
    }
    return make_pair(min_value, max_value);
}

ll okay(vector<ll> &a, vector<char> &op)
{
    ll n = a.size();
    vector<vector<ll>> dp2(n, vector<ll>(n, 0));
    vector<vector<ll>> dp1(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++)
    {
        dp2[i][i] = a[i];
        dp1[i][i] = a[i];
    }
    for (ll s = 1; s < n; s++)
    {
        for (ll i = 0; i < n - s; i++)
        {
            ll j = i + s;
            pair<ll, ll> result = MinAndMax(dp1, dp2, i, j, op);
            dp2[i][j] = result.first;
            dp1[i][j] = result.second;
        }
    }
    return dp1[0][n - 1];
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    vector<char> op;
    vector<ll> a;
    for (char c : s)
    {
        if (c == '+' || c == '-' || c == '*')
        {
            op.push_back(c);
        }
        else
        {
            a.push_back(stoi(string(1, c)));
        }
    }

    cout << okay(a, op) << endl; 
    return 0;
}