#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

    void DFS(int i, int j, vector<vector<char>>& grid) {
        int width = grid[0].size();
        int height = grid.size();       

        if (i < 0 || j < 0 || i >= height || j >= width || grid[i][j] == '0') return;

        grid[i][j] = '0';

        int changeX[4] = {-1,0,1,0};
        int changeY[4] = {0,1,0,-1};
        for (int k = 0 ; k < 4 ; k++) {
            DFS(i+changeX[k], j+changeY[k], grid);
        }
    }

    void BFS(int i, int j, vector<vector<char>>& grid) {
        int width = grid[0].size();
        int height = grid.size();       

        if (i < 0 || j < 0 || i >= height || j >= width || grid[i][j] == '0') return;


        queue<pair<int, int>> q;
        pair<int, int> p(i,j);
        q.push(p);

        while (!q.empty()) {

            i = q.front().first;
            j = q.front().second;
            q.pop();

            if (i < 0 || j < 0 || i >= height || j >= width || grid[i][j] == '0') continue;

            grid[i][j] = '0';
            
            int changeX[4] = {-1,0,1,0};
            int changeY[4] = {0,1,0,-1};
            for (int k = 0 ; k < 4 ; k++) {
                int i1 = i+changeX[k];
                int j1 = j+changeY[k];
                if (i1 >= 0 && j1 >= 0 && i1 < height && j1 < width && grid[i1][j1] == '1') {
                    pair<int, int> temp(i1, j1);
                    q.push(temp);
                } 
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int width = grid[0].size();
        int height = grid.size();
        int totalIslands = 0;

        for (int i = 0 ; i < height ; i++) {
            for (int j = 0 ; j < width ; j++) {
                if (grid[i][j] == '1') {
                    totalIslands++;
                    BFS(i, j, grid);
                }
            }
        }
        return totalIslands;
    }

int main() {
    vector<vector<char>> grid;
    int row, column;
    cin >> row >> column;
    for (int i = 0 ; i < row ; i++) {
        vector<char> line;
        for (int j = 0 ;j < column ; j++) {
            char temp;
            cin >> temp;
            line.push_back(temp);
        }
        grid.push_back(line);
    }
    cout << numIslands(grid);
}