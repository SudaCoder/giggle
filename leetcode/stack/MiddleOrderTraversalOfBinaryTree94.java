package stack;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by 杜文丽 on 2019/12/2 21:53
 **/
public class MiddleOrderTraversalOfBinaryTree94 {
    private List<Integer> traverse = new ArrayList<>();

    public List<Integer> inorderTraversal(TreeNode root) {
        if (root == null) {
            return traverse;
        }
        inorder(root);
        return traverse;
    }

    public void inorder(TreeNode root) {
        if (root==null) {
            return;
        }
        inorder(root.left);
        traverse.add(root.val);
        inorder(root.right);
    }

    public static void main(String[] args) {

    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}