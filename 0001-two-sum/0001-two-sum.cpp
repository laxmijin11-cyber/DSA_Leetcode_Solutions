class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            int second = target - nums[i];
            if (m.find(second) != m.end()) {
                // found if end iterator not coming
                ans.push_back(i);
                ans.push_back(m[second]);
                break;
            }
            m[first] = i;
        }
        return ans;
        
    }
};

/*
sort(nums.begin(), nums.end());
        int first = 0;
        int second = nums.size() - 1;
        while (first < second) {
            int sum = nums[first] + nums[second];
            if (sum == target) {
                return [first, second ];
            } else if (sum > target) {
                second--;
            } else {
                first++;
            }
        }
        return [];


        THIS IS WRONG AS:
        But here, you are sorting the array first, which changes the order of elements. After sorting, the indices first and second refer to positions in the sorted array, not the original array.

        vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int, int>> v;  // {value, original_index}
    
    for (int i = 0; i < nums.size(); i++) {
        v.push_back({nums[i], i});
    }
    
    sort(v.begin(), v.end());  // Sort by value
    
    int first = 0;
    int second = v.size() - 1;
    
    while (first < second) {
        int sum = v[first].first + v[second].first;
        if (sum == target) {
            return {v[first].second, v[second].second};
        } else if (sum > target) {
            second--;
        } else {
            first++;
        }
    }
    
    return {};
}
*/