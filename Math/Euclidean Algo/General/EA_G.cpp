/*
* Author: BrownFalcon
*/

// Time Complexity : O(log b)
// Space Complexity : O(log b)

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b, a%b);
}
// lcm = a*b/gcd(a, b) 
int main() {
    int a, b;
    cin>>a>>b;
    cout<<gcd(a, b)<<endl;
}
