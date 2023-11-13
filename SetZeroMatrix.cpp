#include <vector>

using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
    // int col[m] (0); -> matrix[0][..]
    // int row[m] (0); matrix[..][0]

    int col0 = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark the i-th row
                matrix[i][0] = 0;
                // mark the j-th column
                if (j != 0) {
                    matrix[0][j] = 0;
                } else {
                    col0 = 0;
                }
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

int main() {
    // Example usage
    int n = 3, m = 4;
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 0, 7, 8},
                                  {9, 10, 11, 12}};

    vector<vector<int>> result = zeroMatrix(matrix, n, m);

    // Print the result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
