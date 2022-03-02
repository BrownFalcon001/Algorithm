/*
* Author: BrownFalcon
*/

// Time Complexity O(log n)
// Space Complexity O(log n)

#include<bits/stdc++.h>
using namespace std;

long long power(long long a, long long n) {
    if(n==0) return 1;
    long long temp = power(a, n/2);
    if(n%2==0)  return temp * temp;
    return temp *temp * a;
}

int main() {
    long long a, n;cin>>a>>n;
    // determine power(a,n)
    long long ans = power(a, n);
    cout<<ans<<endl;
}
