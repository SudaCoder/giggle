package tree;

/**
 * Created by 杜文丽 on 2020/1/13 14:22
 * 取左右两个子树中 深度最深的
 **/
public class MinimumDepthOfBinaryTree111 {

    public int minDepth(TreeNode root) {
        if (root==null){
            return 0;
        }
        return depth(root,0);
    }
    boolean leaf(TreeNode root){
        if (root!=null&&root.left==null&&root.right==null){
            return true;
        }
        return false;
    }
    public int depth(TreeNode root,int curr){
        if (root==null){
            return 1000000000;
        }
        if (leaf(root)){
            return curr;
        }
        return Math.min(depth(root.left,curr+1),depth(root.right,curr+1));
    }
}
