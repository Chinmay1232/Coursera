#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

bool ok(vector<ll> &a, ll mask, ll x, ll y, ll z, ll i, ll need)
{
    if(__builtin_popcount(mask) == a.size())
    {
        return ((x == y)&&(y == z));   
    }

    if(x > need || y > need || z > need)
    {
        return false;
    }

    ll one =  ok(a,(mask|(1<<i)), x+a[i], y, z, i+1,need);
    ll two =  ok(a,(mask|(1<<i)), x, y+a[i], z, i+1,need);
    ll three =  ok(a,(mask|(1<<i)),x, y, z+a[i], i+1,need);

    return (one|two|three);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());
    ll tot = accumulate(a.begin(),a.end(),0LL);

    if(tot%3 != 0)
    {
        cout << "0";
    }
    else
    {
        cout << ok(a,0,0,0,0,0,tot/3);
    }
    
    return 0;
}