/*
* Author: BrownFalcon
*/

// Time Complexity : O(log (min(a, b)))
// Space Complexity : O(1)

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
    while(b) {
        a = a%b;
        swap(a, b);
    }
    cout<<a<<endl;
}
