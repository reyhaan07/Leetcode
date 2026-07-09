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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        int count=0,mcount;
        ListNode *temp=head;
        while(temp->next!=NULL)
        {
            count++;
            temp=temp->next;
        }
        if(count%2==0) mcount=count/2;
        else mcount=(count+1)/2;
        count=0;
        temp=head;
        ListNode *ele;
        while(temp->next!=NULL)
        {
            if(count==mcount)
            {
                ele=temp;
                break;
            }
            else
            {
                count++;
                temp=temp->next;
            }
        }
        return ele;
    }
};