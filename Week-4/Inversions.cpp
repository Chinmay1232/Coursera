#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

int Merge(vector<int> &a, int l, int mid, int r)
{
    int s = l;
    int e = mid+1;

    int ans = 0;

    vector<int> temp;
    while (s <= mid && e <= r)
    {
        if(a[s] <= a[e])
        {
            temp.push_back(a[s]);
            s++;
        }
        else
        {
            ans+=mid-s+1;
            temp.push_back(a[e]);
            e++;
        }
    }


    while (s <= mid)
    {
        temp.push_back(a[s]);
        s++;
    }
    while (e <= r)
    {
        temp.push_back(a[e]);
        e++;
    }
    
    for(int i = l; i <= r; i++)
    {
        a[i] = temp[i-l];
    }
    
    return ans;
}


int MergeSort(vector<int> &a, int l, int r)
{
    if(l >= r)
    {
        return 0;
    }
    int mid = (l+r)/2;
    int ans = 0;
    ans+=MergeSort(a,l,mid);
    ans+=MergeSort(a,mid+1,r);
    ans+=Merge(a,l,mid,r);

    return ans;
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int s = 0; s < n; s++)
    {
        cin >> a[s];
    }
    
    cout << MergeSort(a,0,n-1) << "\n";
    return 0;
}