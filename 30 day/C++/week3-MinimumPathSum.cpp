#include <vector>
#include <iostream>

using namespace std;

void DFS(int i, int j, vector<vector<char>> &grid)
{
    int width = grid[0].size();
    int height = grid.size();

    if (i < 0 || j < 0 || i >= height || j >= width || grid[i][j] == '0')
        return;

    grid[i][j] = '0';

    int changeX[4] = {-1, 0, 1, 0};
    int changeY[4] = {0, 1, 0, -1};
    for (int k = 0; k < 4; k++)
    {
        DFS(i + changeX[k], j + changeY[k], grid);
    }
}

void findPathUtil(int i, int j, int targetI, int targetJ, vector<vector<int>> &grid, vector<int> &path, int &pathIndex, int &min)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1)
        return;

    path[pathIndex] = grid[i][j];
    pathIndex++;
    int preValue = grid[i][j];
    grid[i][j] = -1;

    if (i == targetI && j == targetJ)
    {
        int len = 0;
        for (int i = 0; i < pathIndex; i++)
        {
            len += path[i];
        }
        if (len < min)
            min = len;
    }

    int changeX[2] = {0, 1};
    int changeY[2] = {1, 0};
    for (int k = 0; k < 2; k++)
    {
        findPathUtil(i + changeX[k], j + changeY[k], targetI, targetJ, grid, path, pathIndex, min);
    }

    grid[i][j] = preValue;
    pathIndex--;
}

int minPathSum(vector<vector<int>> &grid)
{
    if (grid.empty())
        return 0;
    vector<int> path(10000);
    int pathIndex = 0;
    int min = INT_MAX;

    findPathUtil(0, 0, grid.size() - 1, grid[0].size() - 1, grid, path, pathIndex, min);

    return min;
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minPathSum(grid);
}