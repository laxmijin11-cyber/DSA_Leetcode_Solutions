class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        double maxAvg=INT_MIN;
        int left=0;
        // int n=nums.size();

        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            if(right-left+1==k){
                maxAvg=max(maxAvg,sum/k);
                sum-=nums[left];
                left++;
            }
        }
        return maxAvg!=INT_MIN?maxAvg:0;
    }
};

//TO TRACK THE SLIDING WINDOW SIZE:USE RIGHT-LEFT+1==K
