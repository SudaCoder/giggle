package stack;

import com.sun.source.tree.Tree;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * Created by 杜文丽 on 2019/12/2 22:26
 **/
public class ZigZagLevelOrder103 {
    Stack<TreeNode> mystack = new Stack<>();
    List<List<Integer>> res = new ArrayList<>();
    boolean leftFirst = false;

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) {
            return res;
        }
        List<Integer> tmpRes = new ArrayList<>();
        tmpRes.add(root.val);
        res.add(tmpRes);
        mystack.add(root);
        zigzag();
        return res;
    }

    public void zigzag() {
        if (mystack.empty()) {
            return;
        }
        List<Integer> tmpRes = new ArrayList<>();
        Stack<TreeNode> tmpStack = new Stack<>();
        while (!mystack.empty()) {
            TreeNode node = mystack.peek();
            mystack.pop();
            if (leftFirst) {
                if (node.left != null) {
                    tmpStack.add(node.left);
                    tmpRes.add(node.left.val);
                }

                if (node.right != null) {
                    tmpStack.add(node.right);
                    tmpRes.add(node.right.val);
                }
            } else {
                if (node.right != null) {
                    tmpStack.add(node.right);
                    tmpRes.add(node.right.val);
                }
                if (node.left != null) {
                    tmpStack.add(node.left);
                    tmpRes.add(node.left.val);
                }
            }

        }

        mystack = tmpStack;
        leftFirst = !leftFirst;

        if (!mystack.empty()){
            res.add(tmpRes);
            zigzag();
        }
    }

    public static void main(String[] args) {
        ZigZagLevelOrder103 test = new ZigZagLevelOrder103();
        TreeNode root3 = new TreeNode(3);
        TreeNode root9 = new TreeNode(9);
        TreeNode root20 = new TreeNode(20);
        TreeNode root15 = new TreeNode(15);
        TreeNode root7 = new TreeNode(7);
        root3.left=root9;
        root3.right=root20;
        root20.left=root15;
        root15.right=root7;
        test.zigzagLevelOrder(root3);
    }
}
