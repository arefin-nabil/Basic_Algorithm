#include <bits/stdc++.h>
using namespace std;

int dp[100005];
bool rec(int n)
{
    if (1 == n)
    {
        return true;
    }
    else if (0 >= n)
    {
        return false;
    }
    bool l = false, r = false;
    if (n >= 3)
        l = rec(n - 3);
    else if (n % 2 == 0)
        r = rec(n / 2);

    dp[n] = l || r;
    return dp[n];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        int n;
        cin >> n;
        if (rec(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}