#include <bits/stdc++.h>
using namespace std;
int par[1000005];
int grp_size[1000005];

int find(int node)
{
    if (par[node] == -1)
        return node;
    int ldr = find(par[node]);
    par[node] = ldr;
    return ldr;
}

void dsu_union(int node1, int node2)
{
    int ldr1 = find(node1);
    int ldr2 = find(node2);
    if (grp_size[ldr1] >= grp_size[ldr2])
    {
        par[ldr2] = ldr1;
        grp_size[ldr1] += grp_size[ldr2];
    }
    else
    {
        par[ldr1] = ldr2;
        grp_size[ldr2] += grp_size[ldr1];
    }
}

int main()
{
    memset(par, -1, sizeof(par));
    memset(grp_size, 1, sizeof(grp_size));

    int n, e;
    cin >> n >> e;
    int cycle = 0;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int ldrA = find(a);
        int ldrB = find(b);

        if (ldrA == ldrB)
            cycle++;
        else
            dsu_union(a, b);
    }
    cout << cycle;
    return 0;
}