/*
* Author: BrownFalcon
*/

// Time Complexity O(log n)
// Space Complexity O(1)

#include<bits/stdc++.h>
using namespace std;

int main() {
    long long a, n;cin>>a>>n;
    // determine power(a,n)
    long long ans = 1;
    while(n) {
        if(n%2) ans*=a;
        n = n >> 1;
        a = a*a;
    }
    cout<<ans<<endl;
}
