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


    for (int i = 0; i < m; i++)
    {
        int idx = lower_bound(a.begin(),a.end(), b[i])-a.begin();
        (idx == n || a[idx]!=b[i])?cout << "-1 ":cout << idx << " ";
    }
    
    return 0;
}