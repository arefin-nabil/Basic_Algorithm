#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> v(t);
    for (int i = 0; i < t; i++)
    {
        cin >> v[i];
    }

    int z;
    cin >> z;

    bool found = false;
    for (int i = 0; i < v.size(); i++)
    {
        if (z == v[i])
        {
            cout << i;
            found = true;
            break;
        }
    }

    if (found == false)
        cout << -1;

    return 0;
}
