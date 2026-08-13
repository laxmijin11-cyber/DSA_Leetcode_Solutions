class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int k=nums.size();
        vector<int> arr(k);
        for(int i=0;i<k;i++){
            arr[i]=nums[i]*nums[i];
        }
        sort(arr.begin(),arr.end());
        return arr;

    }
};