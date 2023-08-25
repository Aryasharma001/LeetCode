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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummynode = new ListNode(-1);
        dummynode->next = head;  // Set the next of dummy node to the actual head
        ListNode* p1 = dummynode;
        ListNode* p2 = head;
        
        // Move p2 ahead by n nodes
        for (int i = 0; i < n; ++i) {
            p2 = p2->next;
        }
        
        // Move both p1 and p2 until p2 reaches the end
        while (p2 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        // Remove the nth node from the end
        p1->next = p1->next->next;
        
        return dummynode->next;
    }
};
