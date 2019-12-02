package array;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by 杜文丽 on 8/6/2019 1:39 PM
 **/
public class Triangle120 {
    public static void main(String[] args) {
        ArrayList<Integer> list1=new ArrayList<>();
        ArrayList<Integer> list2=new ArrayList<>();
        ArrayList<Integer> list3=new ArrayList<>();
        ArrayList<Integer> list4=new ArrayList<>();
        list1.add(2);
        list2.add(3);list2.add(4);
        list3.add(6);list3.add(5);list3.add(7);
        list4.add(4);list4.add(1);list4.add(8);list4.add(3);

        List<List<Integer>> lists = new ArrayList<>();
        lists.add(list1);
        lists.add(list2);
        lists.add(list3);
        lists.add(list4);
        Solution120 s=new Solution120();
        System.out.println(s.minimumTotal(lists));
    }
}
class Solution120 {
    int[][] res=new int[1000][1000];
    int[][] dp=new int[1000][1000];
    int mymax=1000000;
    int dep;
    public void init(List<List<Integer>> triangle){
        dep=triangle.size();
        for (int i=0;i<dep;i++){
            for (int j=0;j<=i;j++){
                res[i][j]=triangle.get(i).get(j);
                dp[i][j]=mymax;
            }
        }
        for (int i=0;i<dep;i++){
            dp[dep-1][i]=res[dep-1][i];
        }
    }
    public int sub(int currx,int curry){
        if (currx>=dep||curry>=dep){
            return 0;
        }
        if (dp[currx][curry]!=mymax){
            return dp[currx][curry];
        }
        dp[currx][curry]=Math.min(dp[currx+1][curry+1]+res[currx][curry],dp[currx+1][curry]+res[currx][curry]);
        return dp[currx][curry];

    }
    public int minimumTotal(List<List<Integer>> triangle) {
        init(triangle);
        for (int i=dep-2;i>=0;i--){
            for (int j=dep-2;j>=0;j--){
                sub(i,j);
            }

        }
        dp[0][0]=res[0][0]+Math.min(dp[1][0],dp[1][1]);

        return dp[0][0];
    }
}