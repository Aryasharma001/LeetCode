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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) {
            return head;
        }

        vector<int> arr;
        ListNode* current = head;
        while (current != NULL) {
            arr.push_back(current->val);
            current = current->next;
        }

        int n = arr.size();
        k = k % n; // Handle cases where k is larger than the length of the list

        vector<int> arr2(n);
        for (int i = 0; i < n; i++) {
            arr2[(i + k) % n] = arr[i];
        }

        current = head;
        for (int i = 0; i < n; i++) {
            current->val = arr2[i];
            current = current->next;
        }

        return head;
    }
};
