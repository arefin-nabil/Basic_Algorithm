#include <bits/stdc++.h>
using namespace std; 

long long int dp[1005];
int tetra(long long int n)
{

    if (n < 2)
        return n;
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = tetra(n - 1) + tetra(n - 2) + tetra(n - 3) + tetra(n - 4);

    return dp[n];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    long long int n;
    cin >> n;
    cout << tetra(n);
    return 0;
}



