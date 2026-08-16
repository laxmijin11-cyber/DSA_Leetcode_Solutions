class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        stack<int>s;
        //map mai store next greater
        for(int i=nums2.size()-1;i>=0;i--){
            while(s.size()>0 && s.top()<=nums2[i]){
                s.pop();
            }
            if(s.size()==0){
                m[nums2[i]]=-1;
            }
            else{
                m[nums2[i]]=s.top();
            }
            s.push(nums2[i]);
        }

        // vector<int> ans(nums1.size(),0);
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            // ans[i]=m[nums1[i]];
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};
//assign karne ke liye value honi chahiye in ans[i]=m[nums1[i]];