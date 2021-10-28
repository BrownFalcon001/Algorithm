//there are another implemented algo which done the same stuff iteratively
//you will find that in the same folder

#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b) {
    if(a==0) return b;
    return gcd(b%a, a);
}

signed main() {
    int a, b;cin>>a>>b;
    cout<<gcd(a,b)<<endl;
}
