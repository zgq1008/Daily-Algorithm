/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void addval(struct ListNode* head)
{
    while (head!=NULL)
    {
        if (head->val>9)
        {
            head->val=head->val%10;
            if (head->next==NULL)
            {
                head->next=(struct ListNode *)malloc(sizeof(struct ListNode));
                head->next->next=NULL;
                head->next->val=1;
            }
            else{
                head->next->val+=1;
            }
        }
        head=head->next;
    }
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head1=l1,*head2=l2;
    while (head1!=NULL)
    {
        if (head2!=NULL)
        {
            head1->val+=head2->val;
            head2=head2->next;
        }
        if (head1->next==NULL && (head2!=NULL))
        {
            head1->next=head2;
            head2=NULL;
        }
        head1=head1->next;
    }
    addval(l1);
    return l1;
}