/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (left == right)
        return head;

    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* leftTail = &dummy;
    struct ListNode* leftNode = head;

    for (int i = 1; i < left; i++) {
        leftTail = leftTail->next;
        leftNode = leftNode->next;
    }

    struct ListNode* current = leftNode;
    struct ListNode* prev = NULL;

    for (int i = 0; i <= right - left; i++) {
        struct ListNode* forw = current->next;
        current->next = prev;
        prev = current;
        current = forw;
    }

    leftTail->next = prev;
    leftNode->next = current;
    return dummy.next;
}