package stack;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by 杜文丽 on 2019/12/2 22:19
 **/
public class PreorderTraversalOfBinaryTree144 {
    private List<Integer> traverse = new ArrayList<>();
    public List<Integer> preorderTraversal(TreeNode root) {
        if (root == null) {
            return traverse;
        }
        preorder(root);
        return traverse;
    }

    public void preorder(TreeNode root) {
        if (root==null) {
            return;
        }
        traverse.add(root.val);
        preorder(root.left);
        preorder(root.right);
    }

    public static void main(String[] args) {

    }
}
