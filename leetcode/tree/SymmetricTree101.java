package tree;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by 杜文丽 on 2019/12/25 16:50
 **/
public class SymmetricTree101 {
    public boolean isSymmetric(TreeNode root) {
        if (root==null){
            return true;
        }
        return judge(root.left,root.right);
    }
    public boolean judge(TreeNode left,TreeNode right){
        if (left==null||right==null){
            if (left==null&&right==null){
                return true;
            }else {
                return false;
            }
        }
        if (left.val==right.val){
            return judge(left.left,right.right)&&judge(left.right,right.left);
        }else {
            return false;
        }
    }
}
