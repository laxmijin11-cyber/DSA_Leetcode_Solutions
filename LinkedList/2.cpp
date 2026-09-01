//MIDDLE OF LINKED LIST
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL &&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    // ListNode* temp=head;
    // int count=0;
    // while(temp!=NULL){
    //     temp=temp->next;
    //     count++;
    // }
    // int mid=count/2;
    // temp=head;
    // while(mid--){
    //     temp=temp->next;
    // }
    // return temp;
    // }
};
//fast ho aur fast ha next ho tabhi toh loop aage jayega  varna agar NULL aa rahe 
/* Yeh Standard "Fast & Slow" logic hai:

Loop tab tak chalta hai jab tak dono pointers valid hain.

Agar fast NULL hai, loop ruk jata hai (kyunki fast!=NULL FALSE hai).

Agar fast->next NULL hai, loop ruk jata hai (kyunki fast->next!=NULL FALSE hai).
*/

/*

**OH! I see the massive confusion now. You are 100% right to ask, and I apologize for the confusing explanation.**

Let's clear this up in **10 seconds**:

---

### Why did I say "6"? (And why it's actually wrong)
You wrote: `count = 1` in your code.

If you start with `count = 1`:
1. `temp = 1` (Node 1) -> `count = 2`
2. `temp = 2` (Node 2) -> `count = 3`
3. `temp = 3` (Node 3) -> `count = 4`
4. `temp = 4` (Node 4) -> `count = 5`
5. `temp = 5` (Node 5) -> `count = 6`
6. `temp = NULL` (End) -> **Loop stops.**

You counted **6** nodes. But there are only **5** nodes! **That is the bug.**

---

### 🚨 The "Real" Fix (Start at 0, not 1)
If you start at `count = 0`:
1. `temp = 1` -> `count = 1`
2. `temp = 2` -> `count = 2`
3. `temp = 3` -> `count = 3`
4. `temp = 4` -> `count = 4`
5. `temp = 5` -> `count = 5`
6. `temp = NULL` -> **Loop stops.** (Count is exactly 5)

---

### ✅ The Final, 100% Correct Code (Just change 1 to 0)
```cpp
ListNode* temp = head;
int count = 0;      // <---- CHANGE THIS TO 0
while(temp != NULL){
    temp = temp->next;
    count++;
}
int mid = count / 2;   // 5 / 2 = 2
temp = head;
while(mid--){
    temp = temp->next;  // Move 2 steps: 1->2->3
}
return temp;
```

**If you start at 1, you count the NULL as a node, which makes you move too far. Start at 0 and you are perfect.** 🚀

This is a **brilliant question**! It is one of the most confusing parts of C++ syntax for beginners.

Here is the exact breakdown of `while(mid--)`:

---

### 🧠 The Logic:
You have a variable `mid` (e.g., `mid = 2` for a list of 5 nodes). You want to move your pointer `temp` **2 steps** forward (from `head` to the middle node).

The `while(mid--)` does **two things** in every single iteration:
1. It **checks** if `mid` is non-zero (truthy). 
2. It **decrements** `mid` by 1 (using the `--` operator).

---

### 👣 Step-by-Step Trace (For `mid = 2`):

**Loop 1:**
- `while(2--)`: Checks if `2` is true (yes).
- It **post-decrements** `mid` to `1`.
- Body runs: `temp = temp->next` (moves 1 step).

**Loop 2:**
- `while(1--)`: Checks if `1` is true (yes).
- It **post-decrements** `mid` to `0`.
- Body runs: `temp = temp->next` (moves 1 step).

**Loop 3:**
- `while(0--)`: Checks if `0` is false (no, stops).
- It decrements `mid` to `-1`. (But it doesn't matter because we exit the loop).

---

### 💡 The "Post-Decrement" Trap (Why it's confusing):
The `--` **after** the variable is called **"post-decrement."** 
This means: **"First use the value, THEN subtract 1."** 

So, when it evaluates `while(mid--)`:
*   It **looks at the current value** of `mid` (e.g., `2`).
*   If it's not `0`, the condition is `TRUE`.
*   **After** checking, it subtracts `1` (making it `1`, then `0`, then `-1`).
*/
