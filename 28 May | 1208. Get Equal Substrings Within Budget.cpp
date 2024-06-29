class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int maxLength = 0;
        int currentCost = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            currentCost += abs(s[right] - t[right]);

            // Shrink the window until the cost is within maxCost
            while (currentCost > maxCost) {
                currentCost -= abs(s[left] - t[left]);
                ++left;
            }

            // Update the maximum length
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
        // int cnt = 0;
        // int n = s.size();
        // int ans = 0;
        // for(int i = 0; i < n; i++) {
        //     // cnt = 0;
            
        //     int cnt = abs(s[i] - t[i]);
        //     maxCost -= cnt;
        //     if(maxCost >= 0)
        //         ans++;
        //     if(maxCost <= 0) break;
        // }
        // // return abs(s[0] - t[0]);
        // return ans;
    }
};
