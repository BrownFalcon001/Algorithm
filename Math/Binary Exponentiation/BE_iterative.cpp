//iterative approach
// it is way faster than recursive approach

//time complexity = O(logb)

#include<bits/stdc++.h>
using namespace std;

int power(int a, int b) {
    int result = 1;
    while(b) {
        if(b%2) result *=a;
        a *=a;
        b /=2;
    }
    return result;
}

int main() {
    int a, b;cin>>a>>b;
    cout<<power(a,b)<<endl;
}
