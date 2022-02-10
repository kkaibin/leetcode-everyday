class Solution {
public:
    void reorderList(ListNode* head) {
        //edge case，很重要 因為待會快慢指針會尋找head->next & head->next->next
        if(!head || !head->next || !head->next->next) return;

        //找中點
        ListNode* fast=head;
        ListNode* slow=head;

        //條件很重要
        //如果 fast->next->next沒寫 [1,2,3,4,NULL]就會出錯；如果fast->next沒寫[1,2,3,4,5,NULL]就會出錯
        while(fast->next &&　fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* mid=slow->next;
        slow->next=NULL;

        //反轉後半
        ListNode* cur=mid;
        ListNode* pre=NULL;
        ListNode* temp;
        while(cur){
            temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }

        //交替指前半後半
        while(head && pre){
            temp=head->next;
            head->next=pre;
            pre=pre->next;  //順序很重要
            head->next->next=temp;



            head=temp;


        }

    }
};
