#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximalSquare(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    // DP table to store the size of the largest square sub-matrix with all 1s
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int maxSide = 0;  // To keep track of the largest square found
    
    // Iterate through each cell in the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 1) {  // If the current cell is 1
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;  // First row and first column can only form a square of size 1
                } else {
                    // Take the minimum of the three neighboring squares and add 1
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                // Update the maximum side length found
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }
    
    // Return the area of the largest square sub-matrix
    return maxSide * maxSide;
}

int main() {
    vector<vector<int>> mat = {
        {1,1,0,1,0},
        {0,1,1,1,0},
        {1,1,1,1,0},
        {1,1,1,1,1},
        {0,0,0,0,1}

    };
    
    int result = maximalSquare(mat);
    cout << "Maximum size of square sub-matrix with all 1's: " << result << endl;
    
    return 0;
}
