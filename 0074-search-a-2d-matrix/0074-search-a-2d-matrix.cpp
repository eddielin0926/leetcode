class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Solution
        // Binary search row => O(logm)
        // Binary search column => O(logn)
        // All => O(logm + logn) = O(log(m*n))
        int m = matrix.size(); // m row
        if (m == 0) {
            return false;
        }
        int n = matrix[0].size(); // n column
        if (n == 0) {
            return false;
        }

        int startRow = 0;
        int endRow = m - 1;
        while (startRow <= endRow) {
            int middleRow = startRow + ((endRow - startRow) / 2);
            if (matrix[middleRow][0] <= target && matrix[middleRow][n-1] >= target) {
                int startColumn = 0;
                int endColumn = n-1;
                while (startColumn <= endColumn) {
                    int middleColumn = startColumn + ((endColumn - startColumn) / 2);
                    if (matrix[middleRow][middleColumn] == target) {
                        return true;
                    } else if (matrix[middleRow][middleColumn] > target) {
                        endColumn = middleColumn - 1;
                    } else {
                        startColumn = middleColumn + 1;
                    }
                }
                return false;
            } else if (matrix[middleRow][0] > target) {
                endRow = middleRow - 1;
            } else { // matrix[middleRow][n-1] < target
                startRow = middleRow + 1;
            }
        }

        return false;
    }
};