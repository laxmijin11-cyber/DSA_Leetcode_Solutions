class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
    long long currSum=0;
    long long maxSum=0;
    unordered_set<int> window;
    int left=0;

    for(int right=0;right<nums.size();right++){
        while(window.find(nums[right])!=window.end()){
            //found a duplicate
            window.erase(nums[left]);
            currSum-=nums[left];
            left++;
        }

        window.insert(nums[right]);
        currSum+=nums[right];
        if(window.size()==k){
            maxSum=max(maxSum,currSum);
            //aage badha rahe pointer ko
            window.erase(nums[left]);
            currSum-=nums[left];
            left++;
        }
    }
    return maxSum;
    }
};
    


// fixed size+NO DUPLICATES

// sliding window problem
//size of window or subarray-->target sum
//size of the window given 

/**
`while (window.find(nums[right]) != window.end())` in one line means:

**"As long as the current number already exists in the set, keep removing elements from the left of the window."**

### 🧠 Breakdown
| **Part** | **Meaning** |
|----------|-------------|
| `window.find(nums[right])` | Tries to find the current number in the set. |
| `!= window.end()` | If it is **found** (i.e., not equal to the end iterator), the condition is `true`. |
| `while (... )` | Keeps running as long as the number is a duplicate. |

### ✅ In Simple Words
This line ensures that **if the current number is already in the set, we shrink the window from the left until the duplicate is removed**, so the window always contains only unique elements. 😊🚀

# Exactly Right — The Window Can Only Hold 3 Numbers at a Time (when k=3)

---

## 🎯 The Core Idea

> **The window should ALWAYS have size ≤ k.**

When the window size becomes exactly `k`, we:
1. Record the sum
2. **Slide** the window → remove the **leftmost** element
3. This makes room for the next element

---

## 📊 Visual Example (`k = 3`)

| **Step** | **Action** | **Window (Set)** | **Size** |
|----------|------------|------------------|----------|
| 1 | Add 1 | `{1}` | 1 |
| 2 | Add 5 | `{1,5}` | 2 |
| 3 | Add 4 | `{1,5,4}` | 3 ✅ **Record sum** |
| 4 | **Slide** → remove 1, then add 2 | `{5,4,2}` | 3 ✅ **Record sum** |
| 5 | **Slide** → remove 5, then add 9 | `{4,2,9}` | 3 ✅ **Record sum** |

---

## 🧠 Why Remove the Leftmost?

| **Reason** | **Explanation** |
|------------|-----------------|
| **Fixed window size** | We always need exactly `k` elements. To add a new element, we must remove one. |
| **Sliding window technique** | The window moves forward one step at a time. The leftmost element is no longer part of the current window. |
| **Avoid duplicates** | Removing the leftmost ensures the set size stays manageable and distinct. |

---

## ✅ Code Explanation

```cpp
if (window.size() == k) {
    maxSum = max(maxSum, curSum);
    
    // Remove leftmost element to slide the window
    window.erase(nums[left]);  // Remove from set
    curSum -= nums[left];      // Remove from sum
    left++;                    // Move left pointer forward
}
```

**Why remove from set?**  
Because the set must only contain elements **currently in the window**. When the window slides, the leftmost element is no longer in the window — so it must be removed from the set.

---

## 🚀 One-Line Summary

> **"Window size is fixed at k — after recording sum, slide forward by removing the leftmost element."** 😊🚀

**Haan, right badh raha hai, par set khali isliye ho raha hai kyunki hum `while` loop mein left se elements hata rahe hain.**  

Jab duplicate `9` aata hai, tab hum left se tab tak hataate hain jab tak duplicate set se nahi hat jaata. Isliye set mein sirf ek `9` bachta hai.  

Phir agla `right` (doosra `9`) aane par firse duplicate milta hai, aur hum left se `9` hata dete hain, jisse set khali ho jaata hai, aur phir naya `9` add hota hai.  

**Set khali isliye hota hai kyunki hume duplicate hatana padta hai, balki right badhne se nahi.** 😊🚀*/