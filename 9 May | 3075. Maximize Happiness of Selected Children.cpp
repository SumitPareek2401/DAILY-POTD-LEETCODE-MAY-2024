class Solution {
public:
    
    void func(vector<int>& arr, long long int n){
        for(int i = 0; i < n; i++) {
            arr[i] -= 1;
        }
    }
    
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long int n = happiness.size();
        long long int i = n-1;
        long long int sum = 0;
        sort(happiness.begin(), happiness.end());
        int cnter = 0;
        while(i >= 0) {
            sum += max(0, happiness[i]- cnter);
            cnter++;
            i--;
            if(cnter >= k) break;
        }
        return sum;
    }
};
