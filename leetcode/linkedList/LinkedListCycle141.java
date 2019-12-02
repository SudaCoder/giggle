package linkedList;

/**
 * Created by 杜文丽 on 8/16/2019 6:53 PM
 **/
public class LinkedListCycle141 {
    public static void main(String[] args) {

    }
}


class ListNode141 {
    int val;
    ListNode141 next;

    ListNode141(int x) {
        val = x;
        next = null;
    }
}

class Solution141 {
    public boolean hasCycle(ListNode141 head) {
        if (head==null)
            return false;
        ListNode141 fast=head.next;
        ListNode141 slow=head;
        if (slow==null||fast==null){
            return false;
        }
        while (slow!=null&&fast!=null&&slow!=fast&&fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        if (slow==fast&&slow!=null){
            return true;
        }else if (slow==null||fast==null||fast.next==null||slow.next==null){
            return false;
        }
        return false;
    }
}