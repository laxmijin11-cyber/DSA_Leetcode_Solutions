class Solution {
public:
    int maxArea(vector<int>& height) {
            int left=0;
            int right=height.size()-1;
            int maxArea=0;

            while(left<right){
                int currArea= min(height[left],height[right])*(right-left);
                maxArea=max(currArea,maxArea);
                if(height[left]<height[right]){
                    left++;
                }
                else{
                    right--;
                }
            }
            return maxArea;
    }
};
//1.CALCULATING THE AREA
//2.MOVING POINTERS(HEIGHT KAM HAI JISKI) TO GET MAX AREA
//3.FIND LARGEST AREA

/*

# The Issue: You Re-Declared `maxArea` Inside the Loop

---

## 🔴 The Error

```cpp
int maxArea=0;              // ✅ Outer variable declared

while(left<right){
    int currArea= min(height[left],height[right])*(right-left);
    int maxArea=max(currArea,maxArea);  // ❌ You created a NEW variable here!
    //   ^^^^^ This is a NEW local variable, not the outer one.
}
return maxArea;  // ❌ Returns the OUTER maxArea (still 0!)
```

---

## ✅ The Fix: Remove `int` Inside the Loop

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int currArea = min(height[left], height[right]) * (right - left);
            maxArea = max(currArea, maxArea);   // ✅ No 'int' here!
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};
```

---

## 🔍 What Was Happening

| **Line** | **What You Wrote** | **What Actually Happened** |
|----------|-------------------|---------------------------|
| `int maxArea = 0;` | ✅ Outer variable | `maxArea` = 0 |
| `int maxArea = max(currArea, maxArea);` | ❌ Re-declared inside loop | Created a **NEW** `maxArea` (local to the loop) |
| `return maxArea;` | ❌ Returns outer variable | Returns 0 (never updated) |

---

*/
