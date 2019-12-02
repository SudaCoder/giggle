package dfs;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by 杜文丽 on 8/14/2019 3:27 PM
 **/
public class PathSumII113 {
    public static void main(String[] args) {
        TreeNode n1=new TreeNode(5);
        TreeNode n2=new TreeNode(4);
        TreeNode n3=new TreeNode(8);
        TreeNode n4=new TreeNode(11);
        TreeNode n5=new TreeNode(13);
        TreeNode n6=new TreeNode(4);
        TreeNode n7=new TreeNode(7);
        TreeNode n8=new TreeNode(2);
        TreeNode n9=new TreeNode(5);
        TreeNode n10=new TreeNode(1);

        n1.left=n2;
        n1.right=n3;
        n2.left=n4;
        n3.left=n5;
        n3.right=n6;
        n4.left=n7;
        n4.right=n8;
        n6.left=n9;
        n6.right=n10;
        Solution113 s=new Solution113();
        List<List<Integer>> res=s.pathSum(n1,22);
    }
}

class TreeNode113 {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode113(int x) {
        val = x;
    }
}

class Solution113 {
    public void sub(int currSum,int target,List<List<Integer>> res,List<Integer> currRes,TreeNode root){
        if (root==null){
            return;
        }
        currSum+=root.val;
        currRes.add(root.val);
        if (currSum==target&&root.right==null&&root.left==null){
            res.add(currRes);
            return;
        }
        List<Integer> curr1=new ArrayList<>(currRes);
        List<Integer> curr2=new ArrayList<>(currRes);
        sub(currSum,target,res,curr1,root.left);
        sub(currSum,target,res,curr2,root.right);

    }
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res=new ArrayList<List<Integer>>();
        sub(0,sum,res,new ArrayList<>(),root);
        return res;
    }
}
