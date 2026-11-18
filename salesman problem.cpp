
#include <iostream>
using namespace std;

#define INF 999999

int n;
int cost[10][10];
int dp[10][1024];

int tsp(int city, int mask)
{
    // If all cities are visited, return to start
    if (mask == (1 << n) - 1)
        return cost[city][0];

    if (dp[city][mask] != -1)
        return dp[city][mask];

    int ans = INF;

    for (int i = 0; i < n; i++)
    {
        if ((mask & (1 << i)) == 0)
        {
            int newCost = cost[city][i] +
                          tsp(i, mask | (1 << i));

            if (newCost < ans)
                ans = newCost;
        }
    }

    return dp[city][mask] = ans;
}

int main()
{
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << "Minimum travelling cost: "
         << tsp(0, 1) << endl;

    return 0;
}
