/*
    find greatest integer x such that 
    x is a factor of p 
    x is not a multiple of q
    p<=1e18
    q<=1e9
*/

// Time Complexity: O(sqrt p) ; not enough

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll compute_ans(ll p, ll q) {
    ll ans = 0;
    for(ll i = 1;i*i<=p;i++) {
        if(p%i == 0) {
            if(i%q) {
                ans = max(ans, i);
            }
            if((p/i)%q) {
                ans = max(ans, p/i);
            }
        }
    }
    return ans;
}


int main() {
    ll p, q;cin>>p>>q;
    cout<<compute_ans(p, q)<<endl;

    return 0;
}
