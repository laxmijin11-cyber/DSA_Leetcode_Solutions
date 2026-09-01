/*
142. Linked List Cycle II
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.
tail return karna h*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        bool isCycle=false;

        //check if cycle is there or not
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                isCycle=true;
                break;
            }
        }

        if(!isCycle){
            return NULL;
        }
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        // return slow;
        return fast;
        
    }
};

/*
Floyd’s Cycle Detection

### 🚨 The Bug:
Look at your first loop:
```cpp
while(fast!=NULL && fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
        isCycle=true;
    }
}
```
**The Problem:** You set `isCycle = true` when they meet, but **you don't break the loop!** 

Since they are inside a cycle, `slow` and `fast` will keep meeting over and over again, and the loop will **never terminate**. This causes a **TLE (Time Limit Exceeded)**.
*/
