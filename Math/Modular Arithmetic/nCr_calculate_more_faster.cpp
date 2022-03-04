/*
* Author: BrownFalcon
*/

// Time Complexity: O(MAXN)
// so it will pass when 1<=T, N<=1e5

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 2;



ll power(ll a, ll n) {
    ll ans = 1;
    while(n) {
        if(n%2) {
            ans = (ans*a)% mod;
        }
        n = n >> 1;
        a = (a*a) % mod;
    }
    return ans;
}

ll factorial[MAXN];
ll inverse_factorial[MAXN];
void precalculate_factorial() {
    factorial[0] = 1LL;
    for(int i=1;i<MAXN; i++) {
        factorial[i] = (factorial[i-1] * i) % mod;
    }
    inverse_factorial[MAXN-1] = power(factorial[MAXN-1], mod-2);
    for(int i=MAXN-2;i>=0;i--) {
        inverse_factorial[i] = (inverse_factorial[i+1]*(i+1)) % mod;
    }
}

int main() {
    int t;cin>>t;
    precalculate_factorial(); // O(MAXN)
    while(t--) {
        ll n,r;cin>>n>>r;
        // nCr = n!/(r!(n-r)!)
        ll nfact = factorial[n]; // O(1)
        ll rfact = inverse_factorial[r]; // O(1)
        ll nrfact = inverse_factorial[n-r]; // O(1)
        ll denom = (rfact * nrfact) % mod; // O(1)
        ll ans = (nfact * denom) % mod; // O(1)
        cout<<ans<<endl;
    }

    return 0;
}
