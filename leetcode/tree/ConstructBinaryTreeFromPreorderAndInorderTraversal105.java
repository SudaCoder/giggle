package tree;

/**
 * Created by 杜文丽 on 2020/1/13 15:01
 * 前序是先遍历根节点 中序是先遍历左子树 再遍历根节点 在遍历右子树
 * 前序第一个节点是根节点，在中序中找到该根节点，然后根节点左边的是左子树，右边的是右子树
 *
 * 思路：
 * 预处理：
 *从前序遍历中取出第一个数==>根节点
 * 根据根节点值从中序遍历中找到index 将中序遍历拆分成左中序和右中序
 * 根据左中序和右中序的数量把前序拆成左前序和右前序
 *
 * 正式处理：
 * 找到左前序第一个数 是左子树的根节点 再进行上述拆分
 * 找到右前序第一个数 是右子树的根节点 再进行上述拆分
 **/
public class ConstructBinaryTreeFromPreorderAndInorderTraversal105 {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        TreeNode root=new TreeNode(preorder[0]);

    }
    public TreeNode 
    public int find(int val,int[] inorder,int left,int right){
        for (int i = left; i <=right; i++) {
            if (inorder[i]==val){
                return i;
            }

        }
        return 0;
    }
}
