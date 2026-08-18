class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // int ans = 0;
        int maxans = 0;
        int n = nums.size();
        // int left = 0;
        int right = 0;
        while (right < n) {
            int ans=0;
            while (right < n && nums[right] == 1) {
                ans++;
                right++;
            }
            maxans = max(maxans, ans);
            right++;
        }

        return maxans;
    }
};