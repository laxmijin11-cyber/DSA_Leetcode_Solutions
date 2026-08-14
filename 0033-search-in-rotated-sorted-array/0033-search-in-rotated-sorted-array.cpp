class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[start] <= nums[mid]) {
                // left side sorted
                //  check in left
                if (nums[start] <= target && target <= nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                // right sorted array
                // check in right
                if (nums[mid] <= target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    // check in left
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};
    // check which side is sorted
    //  then find your element