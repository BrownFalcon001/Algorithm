//memory complexity = O(mk)
   //-> m = sum of length of original n strings
   //-> k = # of characters in character list
//Time Complexity = O(L) per each search
   //-> L = maximum length of the strings

/*
      Yes it is right as we have O(L) time complexity, it is a very efficient algorithm
      but keep one think on mind, we are allocating memory for all nodes here
      allocation memory takes some extra time
      which possibly cause a TLE, if the number of nodes is large
      we can reduce the time using vector.
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Node{
    Node *a[26];//for a to z in characterlist
    bool end = false;
};
Node *root;

void add(string s) {
    Node *cur = root;
    for(auto c:s) {
        if(cur->a[c-'a']==NULL) {
            cur->a[c-'a'] = new Node;
            for(int i=0;i<26;i++) cur->a[c-'a']->a[i] = NULL;
        }
        cur = cur->a[c-'a'];
    }
    cur->end = true;
}

bool search(string s) {
    Node *cur = root;
    for(auto c:s) {
        if(cur->a[c-'a']==NULL) {
            return false;
        }
        cur = cur->a[c-'a'];
    }
    return cur->end;
}
void printTrie(Node *u = root, string s = "") {
    if(u->end==1) cout<<s<<endl;
    for(int i=0;i<26;i++) {
        if(u->a[i]!=NULL) {
            char c = i+'a';
            printTrie(u->a[i], s+c);
        }
    }
}
bool isEmpty(Node *cur) {
    for(int i=0;i<26;i++) {
        if(cur->a[i]==NULL) return false;
    }
    return true;
}
Node* remove(Node *v, string key, int depth=0) {
    if(v==0) return 0;
    if(key.size()== depth) {
        if(v->end) v->end = false;
        if(isEmpty(v)) {
            delete v;
            v = 0;
        }
        return v;
    }
    int index = key[depth]-'a';
    v->a[index] = remove(v->a[index], key, depth+1);
    if(isEmpty(v)&&v->end == false) {
        delete v;
        v = NULL;
    }
    return v;
}
signed main() {
    int n;cin>>n;
    root = new Node;
    for(int i=0;i<26;i++) root->a[i] = NULL;
    for(int i=0;i<n;i++) {
        string str;cin>>str;
        add(str);
    }
    printTrie();
    int q;cin>>q;
    while(q--) {
        string str;
        cin>>str;
        cout<<search(str)<<endl;
    }
}
