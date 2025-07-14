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
    int getDecimalValue(ListNode* head) {
        int count = 1;
        int num = 0;
        ListNode* cur = head;

      
        while (cur != nullptr) {
            cur = cur->next;
            count *= 2;
        }

        count /= 2; 
        cur = head;

        while (cur != nullptr) {
            num += cur->val * count;
            count /= 2;
            cur = cur->next;
        }

        return num;
    }
};