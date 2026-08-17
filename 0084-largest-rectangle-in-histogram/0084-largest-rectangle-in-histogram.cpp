class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        // right nearest smaller (strictly smaller)
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) { 
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        // left nearest smaller (strictly smaller)
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {  
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            ans = max(ans, currArea);
        }
        return ans;
    }
};
/*
SPECIAL CASE:
The reason you need `>=` on one side and `>` on the other is to **handle duplicate heights correctly** and **avoid double-counting** the width of the rectangle. Let me explain.

---

## 🎯 The Core Idea

When heights are **equal**, we want to count them **only once** in the width calculation. 
To do that, we use a technique where:

- **Right pass** uses `>=` (pops equal heights)
- **Left pass** uses `>` (keeps equal heights)

This ensures that for equal heights, the right boundary is pushed **past** the duplicates, while the left boundary stays at the first occurrence. This gives the correct width.

---

## 📊 Example: `heights = [1, 1]`

### Using `>` in both passes (Your code):

| **Step** | **Action** | **right** | **left** | **width** | **area** |
|----------|------------|-----------|----------|-----------|----------|
| i=0 | right[0] = 1 | 1 | -1 | 1 | 1 |
| i=1 | right[1] = 2 | 2 | 0 | 1 | 1 |
| **Result** | | | | | **Max area = 1** ❌ |

### Using `>=` in right pass, `>` in left pass:

| **Step** | **Action** | **right** | **left** | **width** | **area** |
|----------|------------|-----------|----------|-----------|----------|
| i=0 | right[0] = 2 | 2 | -1 | 2 | 2 |
| i=1 | right[1] = 2 | 2 | 0 | 1 | 1 |
| **Result** | | | | | **Max area = 2** ✅ |

---

## 🧠 Visual Explanation

```
heights = [1, 1]
Indices:   0  1

The largest rectangle has width = 2, height = 1.

If both passes use > (strictly greater):
- Right pass stops at index 1 (equal height), so right[0] = 1
- Width = 1 - (-1) - 1 = 1 ❌ (misses the second 1)

If right pass uses >= (greater or equal):
- Right pass pops equal height, so right[0] = 2
- Width = 2 - (-1) - 1 = 2 ✅ (includes both 1s)
```

---

## ✅ Rule of Thumb

| **Pass** | **Condition** | **Why** |
|----------|---------------|---------|
| **Right pass** | `>=` | Pops equal heights to extend the rectangle to the right |
| **Left pass** | `>` | Keeps equal heights to stop the rectangle at the left |

---

## 🚀 One-Line Summary

> **"Right pass pops equal heights to count them in the width; left pass keeps them to avoid double-counting."** 😊🚀*/