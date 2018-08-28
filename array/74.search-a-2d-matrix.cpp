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
        int r = row - 1;
        while (r >= 0 && matrix[r][0] > target) {
            r--;
        }
        if (r < 0) {
            return false;
        }
        int low = 0, high = col;
        while (low < high) {
            int mid = (low + high) / 2;
            if (matrix[r][mid] > target) {
                high = mid - 1;
            } else if (matrix[r][mid] == target) {
                return true;
            } else {
                low = mid + 1;
            }
        }
        return matrix[r][low] == target;
    }
};
