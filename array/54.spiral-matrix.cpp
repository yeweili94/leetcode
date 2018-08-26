class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int row = matrix.size();
        if (row <= 0) {
            return ret;
        }
        int col = matrix[0].size();
        int dir_col[4] = {1, 0, -1, 0};
        int dir_row[4] = {0, 1, 0, -1};
        int index = 0;
        int r = 0, c = 0;
        vector<vector<bool>> used(row, vector<bool>(col, false));
        for (int i = 0; i < row*col; i++) {
            ret.push_back(matrix[r][c]);
            used[r][c] = true;
            int r_tmp = r + dir_row[index];
            int c_tmp = c + dir_col[index];
            if (r_tmp < 0 || r_tmp >= row || c_tmp < 0 || c_tmp >= col || used[r_tmp][c_tmp]) {
                index = (index + 1) % 4;
                r = r + dir_row[index];
                c = c + dir_col[index];
            } else {
                r = r_tmp;
                c = c_tmp;
            }
        }
        return ret;
    }
};
