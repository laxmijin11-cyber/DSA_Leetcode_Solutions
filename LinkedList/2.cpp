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
};
//fast ho aur fast ha next ho tabhi toh loop aage jayega  varna agar NULL aa rahe 
/* Yeh Standard "Fast & Slow" logic hai:

Loop tab tak chalta hai jab tak dono pointers valid hain.

Agar fast NULL hai, loop ruk jata hai (kyunki fast!=NULL FALSE hai).

Agar fast->next NULL hai, loop ruk jata hai (kyunki fast->next!=NULL FALSE hai).
*/
