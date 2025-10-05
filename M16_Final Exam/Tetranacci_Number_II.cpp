#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    long long int tetra[n + 4];
    tetra[0] = 0;
    tetra[1] = 1;
    tetra[2] = 1;
    tetra[3] = 2;

    for (int i = 4; i <= n; i++)
    {
        tetra[i] = tetra[i - 1] + tetra[i - 2] + tetra[i - 3] + tetra[i - 4];
    }
    cout << tetra[n] << endl;
    return 0;
}


    // // Handle base cases directly
    // if (n == 0)
    // {
    //     cout << 0 << endl;
    //     return 0;
    // }
    // if (n == 1 || n == 2)
    // {
    //     cout << 1 << endl;
    //     return 0;
    // }
    // if (n == 3)
    // {
    //     cout << 2 << endl;
    //     return 0;
    // }
