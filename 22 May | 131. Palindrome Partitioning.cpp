class Solution {
public:

    bool isPartition(string s, int start, int end) {
        
        while(start < end){
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    void func(int index, string s, vector<string>&temp, vector<vector<string>>&ans) {
        if(index == s.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i = index; i < s.size(); i++) {
            if(isPartition(s, index, i)) {
                temp.push_back(s.substr(index, i - index + 1));
                func(i+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string>temp;
        func(0,s,temp,ans);
        return ans;
    }
};
