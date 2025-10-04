#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int left = 0;
        int right = n - 1;

        int maxWater = 0;
        int leftIdx = 0;
        int rightIdx = n - 1;

        while (left < right)
        {
            // Find minimum height
            int water = arr[left];
            if (arr[right] < water)
            {
                water = arr[right];
            }

            // Update maximum
            if (water > maxWater)
            {
                maxWater = water;
                leftIdx = left;
                rightIdx = right;
            }

            // Move pointer with smaller height
            if (arr[left] < arr[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        cout << leftIdx << " " << rightIdx << endl;
    }

    return 0;
}