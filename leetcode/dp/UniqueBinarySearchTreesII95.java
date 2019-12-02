package dp;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * Created by 杜文丽 on 8/14/2019 11:00 PM
 **/
public class UniqueBinarySearchTreesII95 {
    public static void main(String[] args) {
        Solution95 s=new Solution95();
        List<TreeNode> res=s.generateTrees(3);
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

class Solution95 {
    public void sub(int nodei,int n,List<TreeNode> res){
        Set<Integer> tmplist=new HashSet<>();
        for (int i = 1; i <=n ; i++) {
            if (i!=nodei){
                tmplist.add(i);
            }
        }
        sub2(res,new TreeNode(nodei),tmplist,n);
    }
    public void sub2(List<TreeNode> res,TreeNode root,Set<Integer> tmplist,int n){
        if (tmplist.isEmpty()){
            res.add(root);
            return;
        }
        for (int i = 1; i <=n ; i++) {
            if (tmplist.contains(i)){
                tmplist.remove(i);
                //做出操作
                add(root,i);
                sub2(res,root,tmplist,n);
                //回溯
                //remove(new TreeNode(root),i);
                tmplist.add(i);
            }

        }
    }
    public TreeNode remove(TreeNode root,int i){
        if (root==null){
            return null;
        }else if (root.val==i){
            return null;
        }else {
            if (root.val<i){
                root.right=remove(root.right,i);
            }else{
                root.left=remove(root.left,i);
            }
        }
        return root;
    }
    public TreeNode add(TreeNode root,int i){
        if (root==null){
            return new TreeNode(i);
        }else if (root.right==null&&root.right==null){
            if (root.val<i){
                root.right=add(root.right,i);
            }else{
                root.left=add(root.right,i);
            }
            return root;
        }
        if (root.val>i){
            return add(root.left,i);
        }else if (root.val<i){
            return add(root.right,i);
        }
        return root;
    }
    public List<TreeNode> generateTrees(int n) {
        List<TreeNode> res=new ArrayList<>();
        for (int i = 1; i <=n ; i++) {
            sub(i,n,res);
        }
        return res;
    }
}
