class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(!ans.empty() && ans.back() == nums[i]){
                ans.pop_back();
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
