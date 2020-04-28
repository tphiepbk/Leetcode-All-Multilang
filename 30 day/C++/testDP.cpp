#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b, int c)
{
    if (a >= b)
    {
        if (b >= c)
            return c;
        else
            return b;
    }
    else
    {
        if (a >= c)
            return c;
        else
            return a;
    }
}

int minCost(vector<vector<int>> arr)
{
    vector<vector<int>> res(arr.size(), vector<int>(arr[0].size(), 0));
    int m = arr.size();
    int n = arr[0].size();
    m--;
    n--;
    res[0][0] = arr[0][0];
    for (int i = 1; i <= m; i++)
    {
        res[i][0] = res[i - 1][0] + arr[i][0];
    }
    for (int j = 1; j <= n; j++)
    {
        res[0][j] = res[0][j - 1] + arr[0][j];
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            res[i][j] = arr[i][j] + min(res[i][j - 1], res[i - 1][j]);
        }
    }

    return res[m][n];
}

int main()
{
    vector<vector<int>> arr = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minCost(arr);
}