#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

long long dis[1000005];
vector<Edge> edge_list;
int n, e, d;
int x = 0;

void bellman_ford()
{
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;
            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
                dis[b] = dis[a] + c;
        }
    }

    for (auto ed : edge_list)
    {
        int a, b, c;
        a = ed.a;
        b = ed.b;
        c = ed.c;
        if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
        {
            cout << "Negative Cycle Detected\n";
            x = 1;
            break;
        }
    }
}

int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    int src;
    cin >> src;

    for (int i = 1; i <= n; i++)
        dis[i] = LLONG_MAX;
    dis[src] = 0;

    bellman_ford();

    if (x == 0)
    {
        int q;
        cin >> q;
        while (q--)
        {
            cin >> d;
            if (dis[d] == LLONG_MAX)
                cout << "Not Possible" << endl;
            else
                cout << dis[d] << endl;
        }
    }

    return 0;
}
