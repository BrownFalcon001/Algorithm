//memory complexity = O(mk)
   //-> m = sum of length of original n strings
   //-> k = # of characters in character list
//Time Complexity = O(L) per each search
   //-> L = maximum length of the strings

/*
    it is a bit faster code as we do not have any memory allocation
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

class Node {
    public:
        int string_ends;
        vector<int> next;
        Node(int k) {
            string_ends = 0;
            next.resize(k, -1);
        }
};

class Trie {
    public:
        int K;
        vector<Node> nodes;
        Trie(int k) {
            K = k;
            nodes.push_back(Node(k));
        }
        void add(string s) {
            int cur = 0;
            for(auto c: s) {
                if(nodes[cur].next[c-'a'] ==-1) {
                    nodes[cur].next[c-'a'] = nodes.size();
                    nodes.push_back(Node(K));
                }
                cur = nodes[cur].next[c-'a'];
            }
            nodes[cur].string_ends++;
        }
        bool search(string s) {
            int cur = 0;
            for(auto c: s) {
                if(nodes[cur].next[c-'a'] ==-1) {
                    return false;
                }
                cur = nodes[cur].next[c-'a'];
            }
            return nodes[cur].string_ends;
        }
};

signed main() {

} 
