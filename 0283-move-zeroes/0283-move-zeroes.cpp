class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;  // Points to where the next non-zero should go
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};