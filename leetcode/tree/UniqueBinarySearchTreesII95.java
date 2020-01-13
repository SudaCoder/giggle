package tree;

import com.sun.source.doctree.TextTree;
import com.sun.source.tree.Tree;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by 杜文丽 on 2019/12/11 10:30
 **/
public class UniqueBinarySearchTreesII95 {

    public List<TreeNode> generateTrees(int n) {
        if (n>=1){
            return gengerate(1,n);
        }else {
            List<TreeNode> res=new ArrayList<>();
            return res;
        }
    }
    public List<TreeNode> gengerate(int left,int right){
        List<TreeNode> res=new ArrayList<>();
        if (left>right){
            res.add(null);
            return res;
        }
        for (int i = left; i <=right ; i++) {
            List<TreeNode> leftNodes=gengerate(left,i-1);
            List<TreeNode> rightNodes=gengerate(i+1,right);

            for (TreeNode l:leftNodes
                 ) {
                for (TreeNode r: rightNodes
                     ) {
                    TreeNode node=new TreeNode(i);
                    node.left=l;
                    node.right=r;
                    res.add(node);
                }
            }

        }
        return res;
    }
}
