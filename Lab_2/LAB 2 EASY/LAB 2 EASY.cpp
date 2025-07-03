/* NAME: MIRZA IMRAN BIN BAHARIN
STUDENT ID: 22005917
LAB: 2
QUESTION: Sort the given matrix
*/

#include <iostream>
using namespace std;

void sortMatrix(int mat[3][3]) {
    int temp[9];
    int k = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            temp[k++] = mat[i][j];
        }
    }

    for (int i = 0; i < 9 - 1; ++i) {
        for (int j = 0; j < 9 - i - 1; ++j) {
            if (temp[j] > temp[j + 1]) {
                int tempSwap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = tempSwap;
            }
        }
    }

    k = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat[i][j] = temp[k++];
        }
    }
}

int main() {
    int mat[3][3] = { {5, 4, 7}, {1, 3, 8}, {2, 9, 6} };

    sortMatrix(mat);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}