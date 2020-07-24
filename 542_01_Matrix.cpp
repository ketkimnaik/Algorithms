class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != 0) {
                    int top = i > 0 ? matrix[i - 1][j] : MAX_SIZE;
                    int left = j > 0 ? matrix[i][j - 1] : MAX_SIZE;
                    matrix[i][j] = min(top, left) + 1;
                }
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] != 0) {
                    int bottom = i < m - 1 ? matrix[i + 1][j] : MAX_SIZE;
                    int right = j < n - 1 ? matrix[i][j + 1] : MAX_SIZE;
                    matrix[i][j] = min(matrix[i][j], min(bottom, right) + 1);
                }
            }
        }
        return matrix;
    }
private:
    const int MAX_SIZE = 10000;
};