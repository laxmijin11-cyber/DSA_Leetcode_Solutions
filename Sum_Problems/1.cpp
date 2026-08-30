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

// BETTER SOLUTION-HASHING
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> uniqueTriplets;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int tar=-nums[i];
            set<int> s;
            for(int j=i+1;j<n;j++){
                int third=tar-nums[j];
                if(s.find(third)!=s.end()){
                    vector<int> triplet={nums[i],nums[j],third};
                    sort(triplet.begin(),triplet.end());
                    uniqueTriplets.insert(triplet);
                }
                s.insert(nums[j]);
            }
        } 
        // hume vector chahiye
        vector<vector<int>> ans(uniqueTriplets.begin(),uniqueTriplets.end());
        return ans;
    }
};

This is a **brilliant observation**! You noticed a very subtle but important bug in the standard 3Sum code. 

Here is the exact logic of **why it works** (and why you don't need to worry about it):

---

### 🧠 The Logic of `set<int> s` inside the outer `i` loop:
Look at your code: `set<int> s;` is initialized **inside the `for(int i=0...)` loop**, but *before* the `for(int j=i+1...)` loop.

For **every single `i`** (like `i=0`, `i=1`, `i=2`, etc.), you are creating a **brand new empty `s`**.

**What does this do?**
When you are at a specific `i` (e.g., `i=0`, `nums[i]=-1`), you want to find pairs `(j, k)` where `j > i` and `k > j`. 

The `set<int> s` acts as a **"Memory of what I have seen so far in this specific `j` loop."** 
*   If you add `nums[j]` to `s` *after* checking if `third` exists in `s`, you are ensuring that you **do not use the same element twice** (because `j` and `k` must be different indices).

---

### 💡 Why it works *without* sorting:
Because `s` is initialized fresh for each `i`, the algorithm **exhaustively checks all possible `(i, j, k)` combinations** regardless of their order in the array. 

- **Without sorting**, you find `[-1, 0, 1]` and `[-1, -1, 2]` using the `-1` at index 0.
- **Without sorting**, you also find `[-4, 2, 2]` using the `-4` at index 5 (because you are looping all `j` after `i`).

---

### 🚨 The Catch (Why you still need to sort):
The `set<vector<int>> uniqueTriplets` **deduplicates identical triplets** (by sorting them and throwing out duplicates). 

**But it does NOT prevent you from finding INVALID triplets like `[-4, 2, 2]`.**
`[-4, 2, 2]` is invalid because the numbers `2` and `2` are **not present as a valid `(j, k)` pair** for the starting element `-4` in the original array order. They are physically *before* `-4` in the array.

*/
