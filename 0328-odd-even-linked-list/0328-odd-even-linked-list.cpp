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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* odd;
        ListNode* even;
        odd=head;
        even=head->next;
     ListNode* startEven=head->next;
     while(even!=NULL && even->next!=NULL){
        odd->next=even->next;
        even->next=even->next->next;

        odd=odd->next;
        even=even->next;

     }
      odd->next=startEven;
      return head;
    }
};