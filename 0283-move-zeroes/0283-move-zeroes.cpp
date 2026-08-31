class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonzeroindex=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[nonzeroindex]);
                nonzeroindex++;
            }
        }
    }
};

/*
nums = [0,1,0,3,12]
0=j,
*/