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


    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        cin >> a[i].second;
    }
    
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    
    sort(b.begin(),b.end());

    for (int i = 0; i < n; i++)
    {
        int idx = lower_bound(b.begin(),b.end(), a[i].first)-b.begin();
        int jdx = upper_bound(b.begin(),b.end(), a[i].second)-b.begin();

        if(jdx != b.size() && b[jdx] > a[i].second)
        {
            jdx-=1;
        }

        cout << max(0, jdx-idx+1) << " ";
    }
    
    return 0;
}