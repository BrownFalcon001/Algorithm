//recursive approach
//we can do the same function using iterative approach.
//As we know that iterative approach is always faster than recursive I will suggest to use iterative approach
#include<bits/stdc++.h>
using namespace std;

int power(int a, int b) {
    if(b==0) return 1;
    int temp= power(a, b/2);
    int result = temp*temp;
    if(b%2==1) result*=a;
    return result; 
}

int main() {
    int a, b;cin>>a>>b;
    cout<<power(a,b)<<endl;
}
