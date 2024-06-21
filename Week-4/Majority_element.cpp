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
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    
    bool ans = false;
    for(auto ele : mp)
    {
        if(ele.second > n/2)
        {
            ans = true;
        }
    }

    cout << ans;
    
    return 0;
}