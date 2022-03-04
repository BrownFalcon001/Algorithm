/*
* Author: BrownFalcon
*/

// Time Complexity: O(T*log(mod))
// so it will pass when 1<=T, N<=1e5

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 2;

ll factorial[MAXN];

void precalculate_factorial() {
    factorial[0] = 1LL;
    for(int i=1;i<MAXN; i++) {
        factorial[i] = (factorial[i-1] * i) % mod;
    }
}

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


int main() {
    int t;cin>>t;
    precalculate_factorial();
    while(t--) {
        ll n,r;cin>>n>>r;
        // nCr = n!/(r!(n-r)!)
        ll nfact = factorial[n]; // O(1)
        ll rfact = factorial[r]; // O(1)
        ll nrfact = factorial[n-r]; // O(1)
        ll denom = (rfact * nrfact) % mod; // O(1)
        denom = power(denom, mod-2); // we know a^(-1) % prime= a^(p-2) % prime // O(log MOD)
        ll ans = (nfact * denom) % mod; // O(1)
        cout<<ans<<endl;
    }

    return 0;
}
