package dfs;

/**
 * Created by 杜文丽 on 8/14/2019 1:59 PM
 **/
public class ConstructBinaryTreefromInorderandPostorderTraversal106 {
    public static void main(String[] args) {
        /*
        [-4,-10,3,-1,7,11,-8,2]
        [-4,-1,3,-10,11,-8,2,7]
         */
        Solution106 s=new Solution106();
        int[] inorder=new int[]{-4,-10,3,-1,7,11,-8,2};
        int[] postorder=new int[]{-4,-1,3,-10,11,-8,2,7};
        TreeNode treeNode=s.buildTree(inorder,postorder);
        print(treeNode);
    }
    public static void print(TreeNode node){
        if (node!=null){
            System.out.println(node.val+" ");
            print(node.left);
            print(node.right);
        }

    }
}

class TreeNode106 {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode106(int x) {
        val = x;
    }
}

class Solution106 {
    //in是从前面开始找的，post是从后面开始找的
    public TreeNode sub(int[] inorder,int[]postorder,int postbegin,int postend,int inbegin,int inend){
        if (inbegin>inend||postbegin>postend){
            return null;
        }
        if (inbegin==inend||postbegin==postend){
            return new TreeNode(inorder[inbegin]);
        }
        int inindex=0;//记录根节点
        for (int i = inbegin; i <=inend ; i++) {
            if (inorder[i]==postorder[postend]){
                inindex=i;
                break;
            }
        }
        TreeNode root=new TreeNode(inorder[inindex]);

        root.left=sub(inorder,postorder,postbegin,postbegin+inindex-inbegin-1,inbegin,inindex-1);
        root.right=sub(inorder,postorder,postend-inend+inindex, postend-1,inindex+1,inend);
        return root;
    }
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return sub(inorder,postorder,0,postorder.length-1,0,inorder.length-1);
    }
}