//COPY LISTS WITH RANDOM POINTERS
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node* oldTemp = head;
        Node* newHead = new Node(oldTemp->val);
        Node* newTemp = newHead;
        oldTemp = head->next;
        unordered_map<Node*, Node*> m;

        while (oldTemp != NULL) {
            Node* copyNode = new Node(oldTemp->val);
            newTemp->next = copyNode;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        oldTemp = head;
        newTemp = newHead;
        while (oldTemp != NULL) {
            m[oldTemp] = newTemp;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        oldTemp = head;
        newTemp = newHead;
        while (oldTemp != NULL) {
            newTemp->random = m[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};
