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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pointerA=headA;
        ListNode* pointerB=headB;
        while(pointerA!=NULL){
            while(pointerB!=NULL){
                if(pointerA==pointerB)
                    return pointerA;
                pointerB=pointerB->next;
            }
            pointerB=headB;
            pointerA=pointerA->next;
        }
        return NULL;
    }
};