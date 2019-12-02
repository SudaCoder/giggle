//package recursion;
//import java.lang.Math;
///**
// * Created by 杜文丽 on 7/23/2019 8:16 PM
// **/
//public class LongestUnivaluePath687 {
//    public boolean compare(TreeNode node1,TreeNode node2){
//        if(node1==null||node2==null){
//            return false;
//        }else if(node1.val==node2.val){
//            return true;
//        }else{
//            return false;
//        }
//    }
//    public int subfind(TreeNode root,int num,int val){
//        if(root==null){
//            return num;
//        }else if(root.val!=val){
//
//        }
//    }
//    public int longestUnivaluePath(TreeNode root) {
//        if (root==null){
//            return 0;
//        }else{
//            return subfind(root,0,0);
//        }
//    }
//}
//class TreeNode {
//    int val;
//    TreeNode left;
//    TreeNode right;
//    TreeNode(int x) { val = x;
//    }
//}