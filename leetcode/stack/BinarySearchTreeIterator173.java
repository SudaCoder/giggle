package stack;

import com.sun.source.tree.Tree;

import java.util.PriorityQueue;
import java.util.Queue;

/**
 * Created by 杜文丽 on 2019/12/2 23:04
 **/
public class BinarySearchTreeIterator173 {
    //此题要用栈实现的话 需要用两个栈
    private Queue<Integer> queue=new PriorityQueue<>();

    public BinarySearchTreeIterator173(TreeNode root) {
        inorder(root);
    }

    public void inorder(TreeNode root){
        if (root==null){
            return;
        }
        inorder(root.left);
        queue.add(root.val);
        inorder(root.right);
    }
    /** @return the next smallest number */
    public int next() {
        if(!queue.isEmpty()){
            return queue.remove();
        }
        return 0;
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        if (queue.isEmpty()){
            return false;
        }
        return true;
    }
}
