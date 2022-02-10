class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> lists) {

        //找到一半，前半跟後半併
        //併完，update n(list size), k(half of list size)
        int n=lists.size();

        //edge case
        if(n==0) return NULL;

        while(n>1){
            int k=(n+1)/2;
            for(int i=0; i<n/2; i++){
                //if (k+i>n){
                //    break;
                //}
                lists[i]=mergetwoLists(lists[i], lists[i+k]);
            }
            n=k;
            }
        return lists[0];
    }

    ListNode* mergetwoLists(ListNode* l1, ListNode* l2){
        ListNode *dummy=new ListNode(NULL);
        ListNode *cur = dummy;
        //一個在list 1的pointer, 1個在list 2的pointer
        //兩者比大小
        //小的, cur變過去，ptr++
        while(l1 && l2){
            if (l1->val>=l2->val){
                cur->next=l2;
                l2=l2->next;
                cur=cur->next;
            }
            else{
                cur->next=l1;
                l1=l1->next;
                cur=cur->next;
            }
        }

        if (l1) cur->next = l1;
        if (l2) cur->next = l2;

        return dummy->next;
        //不用edge case因為萬一l1, l2不存在，自然會返回NULL
    }
};
