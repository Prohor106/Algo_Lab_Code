#include<bits/stdc++.h>
using namespace std;

const int M = 1e5+7;

vector<int> adj[M];
bool vis[M];

void dfs(int st){
    stack<int> s;
    s.push(st);
    vis[st] = true;
    while(!s.empty()){
        int n = s.top();
        cout << n << " ";
        s.pop();
        for(auto child:adj[n]){
            if(!vis[child]){
                s.push(child);
                vis[child] = true;
            }
        }
    }
    cout << endl;
}

int main() {

    int node, edge;
    cout << "Enter Number of Node and Endge : " << endl;
    cin >> node >> edge;
    cout << "Enter Endges : " << endl;
    for(int i=0; i<edge; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int st;
    cout << "Enter Starting Node : " << endl;
    cin >> st;
    cout << "DFS : " << endl;
    dfs(st);

    return 0;
}
