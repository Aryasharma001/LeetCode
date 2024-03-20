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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* aend=NULL;
        ListNode* copy=list1;
        ListNode * head=copy;
        int count=0;
        while(count<a){
            count++;
            copy=list1;
            // cout<<copy->val<<" ";
            list1=list1->next;
        }
        copy->next=list2;
        while(list2!=NULL){
            copy=list2;
            list2=list2->next;
        }
        while(count<b+1){
            count++;
            list1=list1->next;
        }
        copy->next=list1;
        //cout<<copy->val<<" ";
        
        return head;
    }
};