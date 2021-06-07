bool isPalindrome(ListNode *head)
{
    if (!head->next || !head)
        return true;
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reversE(slow->next);
    slow = slow->next;

    while (slow)
    {
        if (head->val != slow->val)
            return false;
        slow = slow->next;
        head = head->next;
    }
    return true;
}

ListNode *reversE(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *next = NULL;
    ListNode *current = head;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}