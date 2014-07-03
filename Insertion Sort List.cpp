/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /********************/
 /*
 思路：
 插入排序就是不断的将新的元素插入在前面已排好序的链表中
 */
 /********************/
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *begin=new ListNode(-1);//在整个链表的头部添加一个头，因为以后根据链表不断调整，head肯定会随时变化，我们再加入的头部可以定位最开始的节点
        ListNode *tmpbegin=begin;//为当前头部赋临时值
        tmpbegin->next=head;//把新建的链表指向当前链表头部
        ListNode* nextNode=head->next;//nextNode表示下一个节点
        ListNode* preNode=head;//记录nextnode的前一个节点
        while(nextNode){//下一个节点非空
            tmpbegin=begin;//永远从最开始的头节点寻找合适插入的位置
            while(tmpbegin->next != nextNode && tmpbegin->next->val < nextNode->val){//在当前节点以前的节点中寻找合适插入的位置
                tmpbegin=tmpbegin->next;
            }
            if(tmpbegin->next==nextNode){//发现当前节点位置不用交换，直接向后滑动一格
                preNode=nextNode;
                nextNode=nextNode->next;
            }else{//需要交换节点
                ListNode* tmpswap=tmpbegin->next;//将待插入节点的下一个节点保存起来
                tmpbegin->next=nextNode;
                preNode->next=nextNode->next;//注意是要将已排好序的链表的最后一个节点指向nextNode的下一个节点
                nextNode->next=tmpswap;
                nextNode=preNode->next;
            }
        }//已排好序
        ListNode* recbegin=begin;
        begin=begin->next;
        delete recbegin;//删除新加入的头结点 
        return begin;
    }
};