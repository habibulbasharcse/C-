class Solution {
public:
    void inset_tail(ListNode* &head, ListNode* &tail, int val) {
        ListNode* newNode = new ListNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void rev(ListNode* &head, ListNode* tmp) {
        if (tmp->next == NULL) {
            head = tmp;
            return;
        }
        rev(head, tmp->next);
        tmp->next->next = tmp;
        tmp->next = NULL;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true; // Single node or empty list is always a palindrome
        }

        ListNode* newHead = NULL;
        ListNode* newTail = NULL;

        // Copy the original list
        ListNode* tmp = head;
        while (tmp != NULL) {
            inset_tail(newHead, newTail, tmp->val); // Use tmp->val instead of head->val
            tmp = tmp->next;
        }

        // Reverse the copied list
        rev(newHead, newHead);

        // Compare the original list and the reversed list
        tmp = head;
        ListNode* tmp1 = newHead;
        while (tmp != NULL) {
            if (tmp->val != tmp1->val) {
                return false;
            }
            tmp = tmp->next;
            tmp1 = tmp1->next;
        }

        return true;
    }
};
