package linkedList;

/**
 * Created by 杜文丽 on 8/16/2019 7:22 PM
 **/
public class ReverseLinkedList206 {
    public static void main(String[] args) {

    }
}

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class Solution {
    public ListNode reverseList(ListNode head) {
        if (head==null||head.next==null){
            return head;
        }
        if (head.next.next==null){
            ListNode tmp=head.next;
            tmp.next=head;
            head.next=null;
            return tmp;
        }
        ListNode A=head;
        ListNode curr=head.next;
        ListNode B=head.next.next;
        A.next=null;
        while (B!=null){
            curr.next=A;
            A=curr;
            curr=B;
            B=B.next;
        }
        curr.next=A;
        return curr;


    }
}