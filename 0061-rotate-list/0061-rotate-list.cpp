class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;

        int N=1;
        ListNode* temp=head;

        while(temp->next!=NULL) {
            N++;
            temp=temp->next;
        }

        k=k%N;
        if(k==0) return head;

        int NT=N-k;
        ListNode* newtail=head;

        for(int i=1;i<NT;i++) {
            newtail=newtail->next;
        }

        ListNode* newhead=newtail->next;
        newtail->next=NULL;
        temp->next=head;

        return newhead;
    }
};