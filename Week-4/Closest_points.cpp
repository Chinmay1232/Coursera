#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

struct pt {
    int x, y, id;
};

struct cmp_x {
    bool operator()(const pt & a, const pt & b) const {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
};

struct cmp_y {
    bool operator()(const pt & a, const pt & b) const {
        return a.y < b.y;
    }
};

double mindist;
pair<int, int> best_pair;

void upd_ans(const pt & a, const pt & b) {
    double dist = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    if (dist < mindist) {
        mindist = dist;
        best_pair = {a.id, b.id};
    }
}

int n;

vector<pt> a;
vector<pt> t;

void rec(int l, int r) {
    if (r - l <= 3) {
        for (int i = l; i < r; ++i) {
            for (int j = i + 1; j < r; ++j) {
                upd_ans(a[i], a[j]);
            }
        }
        sort(a.begin() + l, a.begin() + r, cmp_y());
        return;
    }

    int m = (l + r) >> 1;
    int midx = a[m].x;
    rec(l, m);
    rec(m, r);

    merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, t.begin(), cmp_y());
    copy(t.begin(), t.begin() + r - l, a.begin() + l);

    int tsz = 0;
    for (int i = l; i < r; ++i) {
        if (abs(a[i].x - midx) < mindist) {
            for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)
                upd_ans(a[i], t[j]);
            t[tsz++] = a[i];
        }
    }
}

lld distance(const pt & a, const pt & b)
{
    double dist = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    return dist;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    a.resize(n);
    t.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x;
        cin >> a[i].y;
        a[i].id = i;
    }
    
    sort(a.begin(), a.end(), cmp_x());
    mindist = 1E20;
    rec(0, n);
    
    int x = best_pair.first;
    int y = best_pair.second;

    lld x1 = (a[x].x-a[y].x) * (a[x].x-a[y].x);
    lld y1 = (a[x].y-a[y].y) * (a[x].y-a[y].y);
    cout << "\n";
    cout << a[x].x << " " << a[x].y << "\n";
    cout << a[y].x << " " << a[y].y << "\n";

    return 0;
}
// 11 
// 4 4 
// -2 -2
// -3 -4
// -1 3
// 2 3
// -4 0
// 1 1
// -1 -1
// 3 -1
// -4 2
// -2 4
