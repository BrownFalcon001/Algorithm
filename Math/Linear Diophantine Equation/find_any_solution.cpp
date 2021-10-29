

//time complexity = O(log(min(a,b)))


#include<bits/stdc++.h>
using namespace std;
#define int long long

int egcd(int a, int b, int &x, int &y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1;
    while(b) {
        int q = a/b;
        tie(x, x1) = make_pair(x1, x-x1*q);
        tie(y, y1) = make_pair(y1, y-y1*q);
        tie(a, b) = make_pair(b, a%b);
    }
    return a;
}

bool find_any_solution(int a, int b, int c, int &x, int &y, int &g) {
    g = egcd(abs(a), abs(b), x, y);
    cout<<g<<endl;
    if(c%g) {
        return false;
    }
    x *=c/g;
    y *=c/g;
    if(a<0) x = -x;
    if(b<0) y = -y;
    return true;
}

signed main(){
    int a,b,c;
    cin>>a>>b>>c;
    int x, y, g;
    if(find_any_solution(a, b, c, x, y, g)) {
        cout<<x<<' '<<y<<' '<<c<<endl;
    }
    else cout<<"No solution\n";
}
