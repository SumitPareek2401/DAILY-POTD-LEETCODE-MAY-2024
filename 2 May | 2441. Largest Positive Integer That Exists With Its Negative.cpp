class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0)
                mp[nums[i]] = nums[i];
        }
        sort(nums.rbegin(), nums.rend());
        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                if(mp.find(-nums[i]) != mp.end()) {
                    ans = nums[i];
                    break;
                }
            }
        }
        return ans;
    }
};
