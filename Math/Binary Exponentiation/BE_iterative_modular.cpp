//iterative approach
// it is way faster than recursive approach

///complexity = O(logb)

#include<bits/stdc++.h>
using namespace std;

int power(int a, int b, int m) {
    int result = 1;
    while(b) {
        if(b%2) result = (result*a)%m;
        a =(a*a)%m;
        b /=2;
    }
    return result;
}

int main() {
    int a, b, m;cin>>a>>b>>m;
    cout<<power(a,b,m)<<endl;
}
