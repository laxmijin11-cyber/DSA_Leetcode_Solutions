// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int left=0;
//         int right=0;
//         while(right<nums.size()){
//             if(nums[right]!=0){
//                 // nums[left]=nums[right];
//                 // left++;
//                 swap(nums[left],nums[right]);
//                 left++;
//                 right++;
//             }
//             else{
//                 right++;
//             }
//         }
//     }
// };
//right se check and left pe dalwa rahi hun.
//nums = [0,1,0,3,12]

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

