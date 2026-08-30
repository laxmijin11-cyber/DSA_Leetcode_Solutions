/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n=nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        //find
                        vector<int> triplet={nums[i],nums[j],nums[k]};
                        //sort
                        sort(triplet.begin(),triplet.end());
                        //set mai find kia
                        if(s.find(triplet)==s.end()){
                            s.insert(triplet);
                            ans.push_back(triplet);
                        }
                    }
                }
            }
        } 
        return ans; 
    }
};
*/
