#include<bits/stdc++.h>
using namespace std;

const int M = 1e5+7;

vector<int> adj[M];
bool vis[M];

void bfs(int st){
    queue<int> q;
    q.push(st);
    vis[st] = true;
    while(!q.empty()){
        int n = q.front();
        cout << n << " ";
        q.pop();
        for(auto child:adj[n]){
            if(!vis[child]){
                q.push(child);
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
    cout << "BFS : " << endl;
    bfs(st);

    return 0;
}
