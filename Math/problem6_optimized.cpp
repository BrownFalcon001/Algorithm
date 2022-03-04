/*
    find greatest integer x such that 
    x is a factor of p 
    x is not a multiple of q
    p<=1e18
    q<=1e9
*/

// Time Complexity: O(N) approx

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e4 + 2;
bool primes[MAXN];
vector<ll> prime;
void prime_sieve() {
    for(int i=1;i<MAXN;i++) {
        primes[i] = true;
    }
    primes[1] = false;
    for(int i=2;i*i<MAXN;i++) {
        if(primes[i]) {
            for(int j = i*i;j<MAXN;j+=i) {
                primes[j] = false;
            }
        }
    }
    for(int i = 1;i<MAXN;i++) {
        if(primes[i]) prime.push_back(i);
    }
}

vector<ll> factQ(ll q) {
    vector<ll> ans;
    for(auto it: prime) {
        if(q%it == 0) {
            ans.push_back(it);
            while(q%it==0) {  
                q /=it;
            }
        }
    }
    if(q>1) ans.push_back(q);
    return ans;
}

int main() {
    prime_sieve();
    int t;cin>>t; 
    while(t--) {
        ll p, q;cin>>p>>q;
        vector<ll> factorOf_q = factQ(q);
        ll ans = 0;
        for(auto it: factorOf_q) {
            ll x = p;
            while(x%q==0) {
                x /=it;
            }
            ans = max(ans, x);
        }
        cout<<ans<<endl;
    }
    return 0;
}
