//there are another implemented algo which done the same stuff iteratively
//you will find that in the same folder

///time complexity = O(log(min(a, b)))

#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

signed main() {
    int a, b;cin>>a>>b;
    cout<<gcd(a,b)<<endl;
}
