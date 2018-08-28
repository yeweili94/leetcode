class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row <= 0) {
            return false;
        }
        int col = matrix[0].size();
        if (col <= 0) {
            return false;
        }
        int low = 0, high = row * col - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            int r = mid / col;
            int c = mid % col;
            if (matrix[r][c] > target) {
                high = mid - 1;
            } else if (matrix[r][c] == target) {
                return true;
            } else {
                low = mid + 1;
            }
        }
        return matrix[low/col][low%col] == target;
    }
};
