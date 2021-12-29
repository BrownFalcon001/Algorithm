/*
 *   author: brownFalcon
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define fastio()                        \
    ios_base::sync_with_stdio(false);   \
    cin.tie(NULL);                      \
    cout.tie(0)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define endl '\n'
#define lb lower_bound
#define ub upper_bound
#define sp ' '
#define no cout << "no" << endl
#define NO cout << "NO" << endl
#define No cout<<"No"<<endl
#define yes cout << "yes" << endl
#define YES cout << "YES" << endl
#define Yes cout<<"Yes"<<endl
#define INIT(a, b) memset(a, b, sizeof(a))
#define preci(x, y) fixed << setprecision(y) << x
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define INFI 1e18

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define F0R(i, a) for (int i = 0; i < a; i++)
#define FORd(i, a, b) for (int i = b - 1; i >= a; i--)
#define F0Rd(i, a) for (int i = a-1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
    int n;cin>>n;
    int arr[n];
    F0R(i, n) {
        cin>>arr[i];
    }
    int q;cin>>q;
    while(q--) {
        int x;cin>>x;
        int dp[x+1];
        dp[0] = 1;
        FOR(i, 1, x) {
            int ans = 0;
            F0R(j, n) {
                if(i-arr[j]>=0) {
                    ans += dp[i-arr[j]];
                }
            }
            dp[i] = ans;
        }
        cout<<dp[x]<<endl;
    }

}
