package dfs;

import java.util.ArrayList;

/**
 * Created by 杜文丽 on 8/14/2019 3:11 PM
 **/
public class ConvertSortedListtoBinarySearchTree109 {
    public static void main(String[] args) {
        //[-10,-3,0,5,9]
        ListNode n1=new ListNode(-10);
        ListNode n2=new ListNode(-3);
        ListNode n3=new ListNode(0);
        ListNode n4=new ListNode(5);
        ListNode n5=new ListNode(9);

        n1.next=n2;
        n2.next=n3;
        n3.next=n4;
        n4.next=n5;
        Solution109 s=new Solution109();
        TreeNode root=s.sortedListToBST(n1);
    }
}


class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
    }
}


class TreeNode109 {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode109(int x) {
        val = x;
    }
}

class Solution109 {
    public TreeNode sub(ArrayList<Integer> arr,int begin,int end){
        if (begin>end){
            return null;
        }else if (begin==end){
            return new TreeNode(arr.get(begin));
        }
        int mid=(begin+end+1)/2;
        TreeNode root=new TreeNode(arr.get(mid));
        root.left=sub(arr,begin,mid-1);
        root.right=sub(arr,mid+1,end);
        return root;
    }
    public TreeNode sortedListToBST(ListNode head) {
        ArrayList<Integer> arrayList=new ArrayList<>();
        while (head!=null){
            arrayList.add(head.val);
            head=head.next;
        }
        return sub(arrayList,0,arrayList.size()-1);
    }
}
