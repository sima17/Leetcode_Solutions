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
    // Function to reverse the linked list (recursive method)
    ListNode* reverseLL(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Find the middle of the list
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode* reversed = reverseLL(slow);

        // Step 3: Compare the first and second halves
        ListNode* first = head;
        ListNode* second = reversed;
        while (second) {  // Compare until the end of the reversed part
            if (first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};