//time complexity = O(logn) of both update and sum;


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mx 100001

int arr[mx];
int tree[4*mx];

void build(int v, int l, int r)
{
    if (l == r)
    {
        tree[v] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
}

int sum(int v, int l, int r, int i, int j)
{
    if (l >= i && r <= j)
        return tree[v];
    if (r < i || l > j)
        return 0;
    int mid = (l + r) / 2;
    int p1 = sum(2 * v, l, mid, i, j);
    int p2 = sum(2 * v + 1, mid + 1, r, i, j);
    return p1 + p2;
}

void update(int v, int l, int r, int i, int newVal)
{
    if (l == r)
    {
        tree[v] = newVal;
        return;
    }
    int mid = (l + r) / 2;
    if (mid >= i)
    {
        update(2 * v, l, mid, i, newVal);
    }
    else
    {
        update(2 * v + 1, mid + 1, r, i, newVal);
    }
    tree[v] = tree[v * 2] + tree[v * 2 + 1];
}

signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n);
    for(int i=1;i<=4*n;i++) cout<<tree[i]<<' ';
    cout<<endl;
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
            cout << sum(1, 1, n, i, j) << endl;
        }
        else if (x == 2)
        {
            int i, val;
            cin >> i >> val;
            update(1, 1, n, i, val);
        }
        else
        {
            cout << "invalid choice" << endl;
        }
    }
}
