/*NAME: MIRZA IMRAN BIN BAHARIN
ID: 22005917
LAB: 2
QUESTION: A Boolean Matrix Question*/

#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 4;

void booleanMatrix(int mat[ROWS][COLS]) {
    bool rowMarker[ROWS] = { false };
    bool colMarker[COLS] = { false };

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (mat[i][j] == 1) {
                rowMarker[i] = true;
                colMarker[j] = true;
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (rowMarker[i] || colMarker[j]) {
                mat[i][j] = 1;
            }
        }
    }
}

int main() {
    int mat[ROWS][COLS] = {
        {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };

    booleanMatrix(mat);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
