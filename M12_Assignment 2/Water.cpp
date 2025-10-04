#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        int mx = 0;
        int idxl = 0, idxr = 0;

        int i = 0, j = n - 1;

        while (i < j)
        {
            if (v[i] + v[j] > mx)
            {
                mx = v[i] + v[j];
                idxl = i;
                idxr = j;
            }
            if (v[i] < v[j])
                i++;
            else
                j--;
        }
        cout << idxl << " " << idxr << endl;
    }

    return 0;
}