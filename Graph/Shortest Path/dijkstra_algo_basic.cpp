/*
 *   author: brownFalcon
 */

// Time Complexity: O(v + e log v) ; here v : vertex; e : edge

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 2;

vector<int> dis;
vector<pair<int, int>> Graph[N]; // first -> node , second -> weight to reach at the node

void dijkstra(int src, int n) {
    vector<int> vis(n+1);
    dis.resize(n+1, INT_MAX); 
    
    dis[src] = 0;
    multiset<pair<int, int>> ms; // first -> dis from src to the node, second -> node
    ms.insert({0, src});

    while(!ms.empty()) {
        int u = ms.begin()->second;
        ms.erase(ms.begin());
        if(vis[u]) continue;
        vis[u] = 1;

        for(auto it: Graph[u]) {
            int v = it.first;
            int w = it.second;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                ms.insert({dis[v], v});
            }
        }
    }

}

int main()
{    
    int n, m;cin>>n>>m;
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin>>u>>v>>w;
        Graph[u].push_back({v, w});
        // Graph[v].push_back({u, w});
    }

    dijkstra(0, n);
    for(int i=0;i<n;i++) {
        cout<<dis[i]<<' ';
    }
    cout<<endl;

    return 0;   
}
