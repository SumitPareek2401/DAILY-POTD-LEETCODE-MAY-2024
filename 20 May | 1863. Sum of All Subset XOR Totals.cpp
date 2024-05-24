class Solution {
public:
    void calcSubset(vector<int>& A, vector<vector<int> >& res,
                    vector<int>& subset, int index)
    {
        // Add the current subset to the result list
        res.push_back(subset);

        // Generate subsets by recursively including and
        // excluding elements
        for (int i = index; i < A.size(); i++) {
            // Include the current element in the subset
            subset.push_back(A[i]);

            // Recursively generate subsets with the current
            // element included
            calcSubset(A, res, subset, i + 1);

            // Exclude the current element from the subset
            // (backtracking)
            subset.pop_back();
        }
    }

    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans){

        //base case
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }

        //exclude
        solve(nums, output, index+1, ans);

        //include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1, ans);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int> > res;
        int index = 0;
        // calcSubset(nums, res, subset, index);
        solve(nums, subset, index, res);
        // return res;
        int ans = 0;
        for(int i = 0; i < res.size(); i++) {
            int temp = 0;
            for(int j = 0; j < res[i].size(); j++) {
                temp = temp ^ res[i][j];
            }
            ans += temp;
        }
        return ans;
    }
};
