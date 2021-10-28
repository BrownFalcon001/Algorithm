//faster than first implementation
//because it is iterative and first one was recursive

///time complexity = O(log(min(a, b)))

#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b) {
    while(b) {
        a=a%b;
        swap(a, b);
    }
    return a;
}

signed main() {
    int a, b;cin>>a>>b;
    cout<<gcd(a, b)<<endl;
}
