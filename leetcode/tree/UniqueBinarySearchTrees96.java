package tree;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by 杜文丽 on 2019/12/12 17:03
 **/
public class UniqueBinarySearchTrees96 {
    public int numTrees(int n) {
        //所有的树 可总结为 G(n)=G(0)(left node nums)*G(N-1)+G(1)*G(N-2)+...+G(N-1)*G(0)
        if (n<=1){
            return 1;
        }
        int[] dp=new int[n+1];
        dp[0]=1;
        for (int i = 1; i <=n ; i++) {
            for (int j = 1; j <=i ; j++) {
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }

}
