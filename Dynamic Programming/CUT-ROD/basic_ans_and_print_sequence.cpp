/*
 *   author: brownFalcon
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, a) for (int i = 0; i < a; i++)
#define FORd(i, a, b) for (int i = b - 1; i >= a; i--)
#define F0Rd(i, a) for (int i = a; i >= 0; i--)
#define trav(a, x) for (auto &a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pd push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ins insert
#define endl '\n'
#define sp ' '
#define no cout << "no" << endl
#define NO cout << "NO" << endl
#define yes cout << "yes" << endl
#define YES cout << "YES" << endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define print(a) cout<<a<<endl
#define printt(a, b) cout<<a<<sp<<b<<endl
#define printtt(a, b, c) cout<<a<<sp<<b<<sp<<c<<endl
#define INIT(a, b) memset(a, b, sizeof(a))

#define preci(x, y) fixed << setprecision(y) << x

#define FAST                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)

int save[10000];



int cutRod(int a[], int n) {
    int dp[n+1];
    dp[0] = 0;
    FOR(i, 1, n+1) {
        int q = -1;
        FOR(j, 1, i+1) {
            if(q<a[i]+dp[i-j]) {
                save[i] = j;
                q = a[j]+dp[i-j];
            }
        }
        dp[i] = q;
    }
    return dp[n];
}

void printAns(int n) {
    while(n>0) {
        cout<<save[n]<< sp;
        n = n-save[n];
    }
    cout<<endl;
}
signed main()
{
    FAST;
    int n;cin>>n;
    int a[n+1];
    FOR(i, 1, n+1) {
        cin>>a[i];
    }
    int ans = cutRod(a, n);
    print(ans);
    printAns(n);
}
