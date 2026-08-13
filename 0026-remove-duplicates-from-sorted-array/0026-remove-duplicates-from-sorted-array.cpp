class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int j=1;
        for(int i=1;i<n;i++){
            if(nums[i] !=nums[j-1]){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};
//inplace array
//i is second pointer and j is first pointer
//i checks other and j mei put kar raha inplace array