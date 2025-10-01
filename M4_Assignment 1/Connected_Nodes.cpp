#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj_list[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        sort(adj_list[x].begin(), adj_list[x].end(), greater<int>());
        if (!adj_list[x].empty())
            for (int x : adj_list[x])
                cout << x << " ";
        else
            cout << -1;
        cout << endl;
    }
}