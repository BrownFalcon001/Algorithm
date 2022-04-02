#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(log m)
// Space Complexity: O(log m) [due to internal recursion stack]

int egcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = egcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return g;
}

void modInverse(int a, int m) {
    int x ,y;
    int g = egcd(a, m, x, y);
    if(g == 1) {
        int res = (x % m + m) % m;
        cout<<"mulviplicative inverse is "<<res<<endl;
    }
    else {
        cout<<"solution doesn't exist :(\n";
    }
}

int main() {
    int a, m;cin>>a>>m;
    modInverse(a, m);
}
