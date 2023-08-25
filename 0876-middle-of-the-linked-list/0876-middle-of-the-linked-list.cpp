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
        ListNode* testnode=head;
        int count=0;
        while(testnode!=NULL){
            count++;
            testnode=testnode->next;                                                  
        }
        int middle;
        if(count%2==0)
            middle=count/2;
        else
            middle=count/2;
        int i=0;
        while(i<=middle-1){
            head=head->next;
            i++;
        }
        return head;
    }
};