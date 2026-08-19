class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        /*
        unordered_set<int>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(s.find(nums[i])!=s.end()){
                //found
                return nums[i];
            }
        }
        return -1;
        */
        int slow=arr[0];
        int fast=arr[0];
        do{
            slow=arr[slow];
            fast=arr[arr[fast]];
        }while(slow!=fast);

        slow=arr[0];
        while(slow!=fast){
            slow=arr[slow];
            fast=arr[fast];
        }
        return slow;
    }
};