/*
* author : brownFalcon
*/

#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(n log max(num)) 

int n;
vector<int> num;
vector<int> rem;

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

int invMod(int a, int m) {
    int x, y;
    int g = egcd(a, m, x, y);
    if(g == 1) {
        int res = ((x % m) + m) % m;
        return res;
    }
    else return -1;
}

int findMinX() {
    int P = 1;
    for(int i=0;i<n;i++) P*=num[i];
    int res = 0;
    for(int i=0;i<n;i++) {
        int pp = P / num[i];
        res += (rem[i] * pp * invMod(pp, num[i]));
    }
    return res % P;
}


int main() {
    cin>>n;
    num.resize(n);
    rem.resize(n);
    for(int i = 0; i < n; i++) cin>>num[i];
    for(int i = 0; i < n; i++) cin>>rem[i];
    cout<<findMinX()<<endl;
}
