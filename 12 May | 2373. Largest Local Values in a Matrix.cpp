class Solution {
public:
    int returnmax(vector<vector<int>>& g, int s, int e) {
        int maxi = INT_MIN;
        for(int i = s; i < s + 3; i++) {
            for(int j = e; j < e + 3; j++) {
                maxi = max(maxi, g[i][j]);
            }
        }
        return maxi;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));

        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < n - 2; j++) {
                ans[i][j] = returnmax(grid, i, j);
            }
        }
        return ans;
    }
};
