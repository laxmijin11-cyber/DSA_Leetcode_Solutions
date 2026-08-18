class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        int left = 0;
        while (left < nums.size()) {
            int currCount = 0;
            for (int right = 0; right < nums.size(); right++) {
                if (nums[right] < nums[left]) {
                    currCount++;
                }
            }
            ans.push_back(currCount);
            left++;
        }
        return ans;
    }
};