class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create an unordered_map to store the number and its index
        unordered_map<int, int> numMap;

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // Calculate the complement needed to reach the target
            int complement = target - nums[i];

            // Check if the complement exists in the map
            if (numMap.find(complement) != numMap.end()) {
                // If found, return the indices of the complement and the current number
                return {numMap[complement], i};
            }

            // Otherwise, store the current number and its index in the map
            numMap[nums[i]] = i;
        }

        // The problem guarantees a solution, but we return an empty vector just in case
        return {};
    }
};