//max value of a segment and the number of occurrence of that max value on that segment

//time complexity = O(logn) for each function call(not build which needs O(n))


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mx 100001
struct node
{
    int max, cnt;
} tree[mx * 4];
int arr[mx];

void build(int v, int l, int r)
{
    if (l == r)
    {
        tree[v].max = arr[l];
        tree[v].cnt = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    if (tree[2 * v].max > tree[2 * v + 1].max)
        tree[v] = tree[2 * v];
    else if (tree[2 * v].max < tree[2 * v + 1].max)
        tree[v] = tree[2 * v + 1];
    else
        tree[v].max = tree[2 * v].max, tree[v].cnt = tree[2 * v].cnt + tree[2 * v + 1].cnt;
}
node maximum(int v, int l, int r, int i, int j)
{
    if (r < i || l > j)
        return {0, 0};
    if (l >= i && r <= j)
        return tree[v];
    int mid = (l + r) / 2;
    node m1 = maximum(2 * v, l, mid, i, j);
    node m2 = maximum(2 * v + 1, mid + 1, r, i, j);
    if (m1.max > m2.max)
        return m1;
    else if (m1.max < m2.max)
        return m2;
    else
    {
        return {m1.max, m1.cnt + m2.cnt};
    }
}

void update(int v, int l, int r, int i, int newVal)
{
    if (l == r)
    {
        tree[v].max = newVal;
        tree[v].cnt = 1;
        return;
    }
    int mid = (l + r) / 2;
    if (i <= mid)
        update(2 * v, l, mid, i, newVal);
    else
        update(2 * v + 1, mid + 1, r, i, newVal);
    if (tree[2 * v].max > tree[2 * v + 1].max)
        tree[v] = tree[2 * v];
    else if (tree[2 * v].max < tree[2 * v + 1].max)
        tree[v] = tree[2 * v + 1];
    else
        tree[v] = {tree[2 * v].max, tree[2 * v].cnt + tree[2 * v + 1].cnt};
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int i, j;
            cin >> i >> j;
            node ans = maximum(1, 1, n, i, j);
            cout << ans.max << ' ' << ans.cnt << endl;
        }
        else
        {
            int i, val;
            cin >> i >> val;
            update(1, 1, n, i, val);
        }
        for (int i = 1; i <= 4 * n; i++)
            cout << tree[i].max << ' ' << tree[i].cnt << endl;
    }
}
