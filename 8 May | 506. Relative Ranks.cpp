class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> q;
        for(int i = 0; i < score.size(); i++) {
            q.push(make_pair(score[i], i));
        }
        int n = score.size();
        vector<string> ans(n);
        int i = 1;
        while(!q.empty()) {
            if(i == 1) {
                ans[q.top().second] = "Gold Medal";
            } else if(i == 2) {
                ans[q.top().second] = "Silver Medal"; 
            } else if(i == 3) {
                ans[q.top().second] = "Bronze Medal";
            } else {
                ans[q.top().second] = to_string(i);
            }
            i++;
            q.pop();
        }
        return ans;
    }
};
