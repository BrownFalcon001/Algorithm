/*
* Author: BrownFalcon
*/

// Time Complexity: O(log n)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7; 

ll power(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b%2) {
            ans= (a*ans) % mod;
        }
        b = b >> 1;
        a = (a*a) % mod;
    }
    return ans;
}

int main() {
    ll a, b;cin>>a>>b;
    cout<<power(a%mod, b%mod)<<endl;

    return 0;
}
