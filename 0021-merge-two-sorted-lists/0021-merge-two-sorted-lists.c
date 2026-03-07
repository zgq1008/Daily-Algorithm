/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode p={};//返回的头结点
    struct ListNode* cur = &p;
    while (list1&&list2)
    {
        if (list1->val>list2->val)
        {
            cur->next=list2;//cur的下一个为当前list2列表的第一个
            list2=list2->next;//list2指向当前位置的下一个
        }
        else
        {
            cur->next=list1;
            list1=list1->next;
        }
        cur=cur->next;
    }
    if (list1)
    {
        cur->next=list1;
    }
    if (list2)
    {
        cur->next=list2;
    }
    return p.next;
}