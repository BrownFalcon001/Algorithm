// it is the iterative approach


//time complexity = O(log(min(a,b)))

#include<bits/stdc++.h>
using namespace std;

int egcd(int a, int b, int &x, int &y) {
    x =1, y=0;
    int x1 = 0, y1 = 1;
    while(b) {
        int q = a/b;
        tie(x, x1) = make_tuple(x1, x-q*x1);
        tie(y, y1) = make_tuple(y1, y-q*y1);
        tie(a, b) = make_tuple(b, a%b);
    }
    return a;
}

int main() {
    int a,b;cin>>a>>b;
    int x, y;
    int gcd = egcd(a, b, x, y);
    cout<<x<<' '<<y<<"  "<<gcd<<endl;
}
