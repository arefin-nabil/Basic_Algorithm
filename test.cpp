#include <bits/stdc++.h>
using namespace std;

int dp[100005];

bool rec(long long n)
{
    // base case
    if (n == 1)
    {
        return true;
    }
    if (n <= 0)
    {
        return false;
    }

    // check dp only if n is within array bounds
    if (n < 100005 && dp[n] != -1)
    {
        return dp[n];
    }

    bool l = false, r = false;

    // Try subtracting 3
    if (n >= 3)
    {
        l = rec(n - 3);
    }

    // Try dividing by 2 (only if even)
    if (n % 2 == 0)
    {
        r = rec(n / 2);
    }

    bool result = l || r;

    // store in dp only if n is within array bounds
    if (n < 100005)
    {
        dp[n] = result;
    }

    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        long long n;
        cin >> n;

        if (rec(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}