package tree;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by 杜文丽 on 2019/12/27 15:30
 * 日妈这道题的边界值太恶心了
 * 恶心死了
 * 决定换用方法 中序遍历为升序！！！
 **/
public class ValidateBinarySearchTree98 {
    List<Integer> res=new ArrayList<>();
    public boolean isValidBST(TreeNode root) {
        if (root==null){
            return true;
        }
        inorder(root);
        if (res.size()<=1){
            return true;
        }
        for (int i = 1; i <res.size() ; i++) {
            if (res.get(i-1)>=res.get(i)){
                return false;
            }
        }
        return true;
    }
    public void inorder(TreeNode treeNode){
        if (treeNode==null){
            return;
        }
        inorder(treeNode.left);
        res.add(treeNode.val);
        inorder(treeNode.right);
    }

//    public boolean isValidBST(TreeNode root) {
//        if (root==null){
//            return true;
//        }
//        if (left(root.left,-2147483648,root.val,root.val)&&right(root.right,root.val,2147483647,root.val)){
//            return true;
//        }
//        return false;
//    }
//    public boolean left(TreeNode leftNode,long min,long max,Integer nodeVal){
//        if (leftNode==null){
//            return true;
//        }
//        if (leftNode.val<nodeVal){
//            if (leftNode.val<max&&leftNode.val>min){
//                return left(leftNode.left,min,leftNode.val,leftNode.val)&&right(leftNode.right,leftNode.val,max,leftNode.val);
//            }else {
//                if (leftNode.val==2147483647&&max==2147483647||leftNode.val==-2147483648&&min==-2147483648){
//                    return true;
//                }
//                return false;
//            }
//        }else {
//            return false;
//        }
//    }
//    public boolean right(TreeNode rightNode,long min,long max,int nodeVal){
//        if (rightNode==null){
//            return true;
//        }
//        if (rightNode.val>nodeVal){
//            if (rightNode.val<max&&rightNode.val>min){
//                return left(rightNode.left,min,rightNode.val,rightNode.val)&&right(rightNode.right,rightNode.val,max,rightNode.val);
//            }else {
//                if (rightNode.val==2147483647&&max==2147483647||rightNode.val==-2147483648&&min==-2147483648){
//                    return true;
//                }
//                return false;
//            }
//        }else {
//            return false;
//        }
//    }
}
