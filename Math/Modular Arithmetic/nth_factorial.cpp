/*
* Author: BrownFalcon
*/

//Time Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9+7;

ll factorial(ll n) {
    ll ans = 1;
    while(n>1) {
        ans = (ans*n)%mod;
        n--;
    }
    return ans;
}


int main() {
    ll n;
    cin>>n;
    cout<<factorial(n)<<endl;
    return 0;
}
