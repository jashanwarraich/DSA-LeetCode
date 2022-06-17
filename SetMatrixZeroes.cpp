// https://leetcode.com/problems/set-matrix-zeroes/

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        // int res[m][n];
        vector<vector<int>> in;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // res[i][j]=matrix[i][j];
                if (matrix[i][j] == 0)
                {
                    vector<int> p = {i, j};
                    in.push_back(p);
                }
            }
        }
        for (int a = 0; a < in.size(); a++)
        {
            int r = in[a][0];
            int c = in[a][1];
            for (int i = 0; i < n; i++)
            {
                matrix[r][i] = 0;
            }
            for (int j = 0; j < m; j++)
            {
                matrix[j][c] = 0;
            }
        }
        return;
    }
};