//This is some practices for linkedlist
public class ListNode {
	int val;
	ListNode next;
    ListNode(int x) { val = x; }
}

//Given a linked list, remove the n-th node from the end of list and return its head.
class RemoveNthNode {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode pre = head, pro = head;
        while(pre != null && n-- != 0) {
            pre = pre.next;
        }
        if(pre == null && n == 0) return head.next;
        while(pre.next != null) {
            pre = pre.next;
            pro = pro.next;
        }
        pro.next = pro.next.next;
        return head;
        
    }
}

//Given a linked list, rotate the list to the right by k places, where k is non-negative.
//Input: 1->2->3->4->5->NULL, k = 2
//Output: 4->5->1->2->3->NULL

class RotateAList {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!k) return head;
        ListNode* pre=head,* end=head;
        while(pre&&k-->0){
            pre=pre->next;
        }
        if(!pre) return head;
        while(pre->next){
            pre=pre->next;
            end=end->next;
        }
        ListNode* res=end->next;
        end->next=NULL;
        pre->next=head;
        return res;
    }
};

//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//Input: 1->2->3->3->4->4->5
//Output: 1->2->5
class DeleteDuplicateNodes {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        if(head->next&&head->val==head->next->val){
            while(head->next&&head->val==head->next->val){
                head=head->next;
            }
            head=head->next;
            //if(!head) return head;
            //else{
                return deleteDuplicates(head);
            //}
        }
        else{
            head->next=deleteDuplicates(head->next);
            return head;
        }
    }
};

//Sort a linked list in O(n log n) time using constant space complexity.
class SortLinkedList {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        vector<int> temp;
        ListNode* cur = head;
        while(cur){
            temp.push_back(cur->val);
            cur = cur->next;
        }
        sort(temp.begin(),temp.end());
        cur = head;
        //ListNode* dummy = new ListNode(0);
        for(int i = 0;i<temp.size();i++){
            cur->val = temp[i];
            cur = cur->next;
        }
        return head;
    }
};

//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
class PartitionLinkedList {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode node1(0),node2(0);
        ListNode *p1=&node1,*p2=&node2;
        while(head){
            if(head->val<x){
                p1->next=head;
                p1=p1->next;
            }
            else{
                p2->next=head;
                p2=p2->next;
            }
            head=head->next;
        }
        p1->next=node2.next;
        p2->next=NULL;
        return node1.next;
        
    }
};

//Given a singly linked list, group all odd nodes together followed by the even nodes. 
//Please note here we are talking about the node number and not the value in the nodes.
//Input: 1->2->3->4->5->NULL
//Output: 1->3->5->2->4->NULL

class OddEvenOrder {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode *odd_end = head, *even_first = head->next, *even_end = head->next;
        ListNode *p = even_first->next;
        int i = 3;
        while(p){
            if(i % 2){
                even_end->next = p->next;
                p->next = even_first;
                odd_end->next = p;
                odd_end = odd_end->next;
                even_end = even_end->next;
                p = even_end;
            }
            else{
                p = p->next;
            }
            i++;
        }
        return head;
        
    }
};
//Reverse a singly linked list.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pro = head, *pre = head -> next;
        while(pre->next != NULL){
            if(pre->val == 6){
                pro->next = pre->next;
                return head;
            }
            pre = pre->next;
            pro = pro->next;
        }
        return head;
    }
};







