#include <iostream>
#include <vector>

using namespace std;

class BinaryMatrix {
private:
    int C;
    int R;
    vector<vector<int>> data;
public:
    BinaryMatrix(int r, int c, vector<int> dataIn);
    int get(int x, int y);
    vector<int> dimensions();
};

BinaryMatrix::BinaryMatrix(int r, int c, vector<int> dataIn) {
    this->R = r;
    this->C = c;
    int k = 0;
    for (int i = 0 ; i < r ; i++) {
        vector<int> line;
        for (int j = 0 ; j < c ; j++) {
            line.push_back(dataIn[k]);
            k++;
        }
        data.push_back(line);
    }
}

int BinaryMatrix::get(int x, int y) {
    return this->data[x][y];
}

vector<int> BinaryMatrix::dimensions() {
    vector<int> res;
    res.push_back(this->R);
    res.push_back(this->C);
    return res;
}

    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int i = 0, j = dim[1]-1;// Start from top right corner
        int row = dim[0]; // Number of row
        vector<int> colWithOne; // Array to save index of columns which have "1" value 
        while (j >= 0 && i < row) {
            int currentCell = binaryMatrix.get(i,j);
            if (currentCell == 1) { // Move left
                colWithOne.insert(colWithOne.begin(), j);
                j--;
            }
            else if (currentCell == 0) { // Move down
                i++;
            }
        }
        if (colWithOne.empty()) return -1;
        else return colWithOne.front();
    }

int main() {
    vector<int> data = {0,0,0,1,0,0,1,1,0,1,1,1};
    BinaryMatrix bm(2,2,data);
    cout << leftMostColumnWithOne(bm);
}