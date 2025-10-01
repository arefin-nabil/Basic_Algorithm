#include <bits/stdc++.h>
using namespace std;
// vector<int> adj_list[1005];
bool vis[1005][1005];
char grid[1005][1005];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
int cnt = 0;
vector<int> vcnt;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj)
{
    // cout << si << " " << sj << endl;
    vis[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            dfs(ci, cj);
    }
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    memset(vis, false, sizeof(vis));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == false && grid[i][j] == '.')
            {
                dfs(i, j);

                // cout << endl;
            } // cout << grid[i][j];
            if (cnt > 0)
                vcnt.push_back(cnt);
            cnt = 0;
        } // cout << endl;
    }
    sort(vcnt.begin(), vcnt.end());
    if (!vcnt.empty())
    {
        cout << vcnt.front();
    }
    else
        cout << "-1";
    // cout << cnt;
    return 0;
}