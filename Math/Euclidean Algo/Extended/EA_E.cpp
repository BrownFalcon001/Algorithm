//it is a recursive solution so definitely it is slower than iterative solution
//you will also find a iterative solution of the problem in same folder

//time complexity = O(log(min(a, b)))

#include<bits/stdc++.h>
using namespace std;

int egcd(int a, int b, int *x, int *y) {
    if(b==0) {
        *x = 1,*y = 0;
        return a;
    }
    int x1,y1;
    int gcd = egcd(b, a%b, &x1, &y1);
    *x = y1;
    *y = x1 - (a/b)*y1;
    return gcd;
}/*
* Author: BrownFalcon
*/

// Time Complexity: O(log(min(a,b))) 
// Space Complexity: O(log(min(a,b)))

// We have: ax + by = c
// Calculate integer value of x and y which satisfy the equation 

#include<bits/stdc++.h>
using namespace std;

int egcd(int a, int b, int &x, int &y) {
    if(b==0) {
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    int gcd = egcd(b, a%b, x1, y1);

    x = y1;
    y = x1 - (a/b)*y1;
    return gcd;
}

int main() {
    int a, b, c;
    cin>>a>>b>>c;
    int x, y;

    int gcd = egcd(a, b, x, y);
    if(c%gcd==0) {
        c = c/gcd;
        cout<< "x is "<< c*x<< " and y is "<<c*y<<endl;
    }
    else {
        cout<<"No solution\n";
    }
}

int main() {
    int a,b;cin>>a>>b;
    int x, y;
    int gcd = egcd(a, b, &x, &y);
    cout<<x<<' '<<y<<"  "<<gcd<<endl;
}
