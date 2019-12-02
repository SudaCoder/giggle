package stack;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by 杜文丽 on 2019/12/2 22:23
 **/
public class PostOrderTraversalOfBinaryTree145 {
    private List<Integer> traverse = new ArrayList<>();
    public List<Integer> postorderTraversal(TreeNode root) {
        if (root == null) {
            return traverse;
        }
        postorder(root);
        return traverse;
    }

    public void postorder(TreeNode root) {
        if (root==null) {
            return;
        }

        postorder(root.left);
        postorder(root.right);
        traverse.add(root.val);
    }

}
