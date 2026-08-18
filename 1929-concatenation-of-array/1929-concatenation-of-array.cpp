class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(2*n,0);
        for(int i=0;i<=2*n-1;i++){
            ans[i]=i>=n ?nums[i%n] :nums[i];
        }
        return ans;
    }
};
//0 to 9---10 elements
