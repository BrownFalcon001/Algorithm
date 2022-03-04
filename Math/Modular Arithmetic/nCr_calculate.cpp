/*
* Author: BrownFalcon
*/

// Time Complexity: O(T*N)
// so it will not pass when 1<=T, N<=1e5

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

ll fact(ll n) {
    ll ans = 1;
    while(n) {
        ans = (ans*n) % mod;
        n--;
    }
    return ans;
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
    while(t--) {
        ll n,r;cin>>n>>r;
        // nCr = n!/(r!(n-r)!)
        ll nfact = fact(n);
        ll rfact = fact(r);
        ll nrfact = fact(n-r);
        ll denom = (rfact * nrfact) % mod;
        denom = power(denom, mod-2); // we know a^(-1) % prime= a^(p-2) % prime
        ll ans = (nfact * denom) % mod;
        cout<<ans<<endl;
    }

    return 0;
}
