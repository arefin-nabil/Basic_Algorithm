#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    vector<int> v;
    while (t--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int y;
            cin >> y;
            v.push_back(y);
            sort(v.begin(), v.end());
        }
        if (x == 2)
        {
            cout << v.front() << "\n";
            v.clear();
        }
    }
    if (v.empty())
        cout << "empty" << "\n";

    return 0;
}