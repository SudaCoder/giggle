package tree;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by 杜文丽 on 2019/12/25 17:29
 * 把所有的结点放在列表里面，遍历一次列表，取出结点，把非空子节点加入列表，一直到为空为止
 **/
public class BinaryTreeLevelOrderTraversal102 {
    List<List<Integer>> res=new ArrayList<>();
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root==null){
            return res;
        }
        List<TreeNode> nodes=new ArrayList<>();
        nodes.add(root);
        sub(nodes);
        return res;
    }
    public void sub(List<TreeNode> nodes){
        if (nodes.size()==0){
            return;
        }
        List<Integer> layer=new ArrayList<>();
        List<TreeNode> nextLayer=new ArrayList<>();
        for (int i = 0; i <nodes.size() ; i++) {
            layer.add(nodes.get(i).val);
            if (nodes.get(i).left!=null){
                nextLayer.add(nodes.get(i).left);
            }
            if (nodes.get(i).right!=null){
                nextLayer.add(nodes.get(i).right);
            }
        }
        res.add(layer);
        sub(nextLayer);
    }
}
