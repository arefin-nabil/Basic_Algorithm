#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1000];
bool vis[1000];
int level[1000];
int parent[1000];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        // cout << par << " ";
        for (int child : adj_list[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));
    int src, dst;
    cin >> src >> dst;
    bfs(src);
    // Parent printing---------------
    // for (int i = 0; i < n; i++)
    //     cout << parent[i] << " ";

    // Shortest distance printing--------------
    cout << "Shortest Path " << level[dst] << endl;

    vector<int> v;
    int node = dst;
    while(node!=-1)
    {
        v.push_back(node);
        node = parent[node];
    }
    reverse(v.begin(), v.end());
    for(int x:v)
        cout << x << " ";

        
    return 0;
}