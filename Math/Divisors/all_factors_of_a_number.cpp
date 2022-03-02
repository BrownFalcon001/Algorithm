/*
* Author: BrownFalcon
*/

// Time Complexity: O(sqrt(n))
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

int NOF = 0;

void print_all_factors(int n) {
    int LIM = sqrt(n);
    for(int i=1;i<=LIM;i++) {
        if(n%i==0) {
            cout<<i<<' ';
            NOF++;
            if(i!=n/i) {
                cout<<n/i<<' ';
                NOF++;
            }
        }
    }
    cout<<endl;
}

int main() {
    int n;cin>>n;
    print_all_factors(n);
    cout<<"Number of Factors: "<<NOF<<endl;
}
