package linkedList;

/**
 * Created by 杜文丽 on 8/16/2019 7:01 PM
 **/
public class LinkedListCycleII142 {
    public static void main(String[] args) {

    }
}

class ListNode142 {
    int val;
    ListNode142 next;

    ListNode142(int x) {
        val = x;
        next = null;
    }
}

class Solution142 {
    public ListNode142 detectCycle(ListNode142 head) {
        //先走到他们相遇的地方
        ListNode142 fast=head;
        ListNode142 slow=head;
        if (head==null||head.next==null){
            return null;
        }
        do {
            fast=fast.next.next;
            slow=slow.next;
        }while (fast!=null&&slow!=null&&fast.next!=null&&slow.next!=null&&fast!=slow);
        if (fast==null||slow==null||fast.next==null||slow.next==null){
            return null;
        }
        fast=head;
        while (fast!=slow){
            fast=fast.next;
            slow=slow.next;
        }
        return fast;
    }
}