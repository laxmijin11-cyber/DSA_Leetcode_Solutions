class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size()==1){
            return nums[0];
        }
        int start=0; int end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(mid==0 && nums[0]!=nums[1]){ return nums[0];}
            if(mid==nums.size()-1 && nums[mid]!=nums[mid-1]){ return nums[mid];}
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){ return nums[mid];}
            if(mid%2==0){
                //even left and right
                if(nums[mid]==nums[mid-1]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            else{//odd index of mid
                if(nums[mid]==nums[mid-1]){
                    //right mai dekho
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};