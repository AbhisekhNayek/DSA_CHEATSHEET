#include <iostream>
#include <vector>

using namespace std;

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);

    for (int col = 1; col < row; col++) {
        ans *= (row - col);
        ans /= col;
        ansRow.push_back(ans);
    }

    return ansRow;
}

vector<vector<int>> pascalTriangle(int N) {
    vector<vector<int>> ans;

    for (int i = 1; i <= N; i++) {
        ans.push_back(generateRow(i));
    }

    return ans;
}

int main() {
    // Example usage
    int n = 5; // Change the value of n as needed
    vector<vector<int>> result = pascalTriangle(n);

    // Print the result
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
