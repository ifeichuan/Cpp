/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
       if(list1==NULL&& list2==NULL){
        return NULL;
    }
    struct ListNode prev = ListNode(-1);
    struct ListNode prehead = prev;
    while(list1!=NULL&&list2!=NULL){
        if(list1->val>=list2->val){
            prehead->next = list2;
            list2=list2->next;
        }
        else{
            prehead->next=list1;
            list1=list1->next;
        }
        prehead=prehead->next;
    }
    prehead->next=list1==NULL?list2:list1;
    return prev->next
}
// @lc code=end

