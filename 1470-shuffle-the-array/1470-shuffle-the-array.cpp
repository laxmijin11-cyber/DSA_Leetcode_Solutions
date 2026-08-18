class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        for (int i = 0; i <n; i++) {
            ans.push_back(nums[i]);
            ans.push_back(nums[i + n]);
        }
        return ans;
    }
};
// 2,5,1,3,4,7
//  0,1,2,0,1,2
//  0,1,2,3,4,5
//  2,3,5,4,1,7
//  3--1,4--3,5---5