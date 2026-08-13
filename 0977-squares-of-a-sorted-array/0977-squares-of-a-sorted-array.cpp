class Solution {
public:
    // vector<int> sortedSquares(vector<int>& nums) {
    //     int k=nums.size();
    //     vector<int> arr(k);
    //     for(int i=0;i<k;i++){
    //         arr[i]=nums[i]*nums[i];
    //     }
    //     sort(arr.begin(),arr.end());
    //     return arr;
// O(nlogn)
    // }
     vector<int> sortedSquares(vector<int>& nums) {
        int right=nums.size()-1;
        int left=0;
        int pos=nums.size()-1;
        vector<int> result(pos+1);

        while(left<=right){
            if(abs(nums[left])>abs(nums[right])){
                result[pos]=nums[left]*nums[left];
                pos--;
                left++;
            }
            else{
                result[pos]=nums[right]*nums[right];
                pos--;
                right--;
            }
        }
        return result;

    }
};
