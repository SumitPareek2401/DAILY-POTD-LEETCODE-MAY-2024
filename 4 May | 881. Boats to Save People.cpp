class Solution {
public:
    void helper(int x, map<int, int>& M, int limit){
        for(int i=x; i>=1; i--){
            if(M[i]){
                M[i]--;
            return;
            }
        }
        return;
    }
    int numRescueBoats(vector<int>& people, int limit) {
        int a = 0;
        int n = people.size();
        int cnt = 0;
        map<int,int> mp;
        for(int i = 0; i < n; i++) {
            mp[people[i]]++;
        }
        for(int i = 0; i < n; i++) {
            int curr = people[i];
            if(mp[curr] <= 0) continue;
            mp[curr]--;
            if(curr == limit) {
                cnt++;
                continue;
            } else {
                helper(limit-curr,mp,limit);
                cnt++;
            }
        }
        return cnt;
    }
};
