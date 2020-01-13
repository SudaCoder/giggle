package greedy;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * Created by 杜文丽 on 2019/12/10 17:16
 **/
public class AssignCookies455 {
    public int findContentChildren(int[] g, int[] s) {
        //g是小朋友的胃，s是饼干的size
        if(g.length==0||s.length==0){
            return 0;
        }
        Arrays.sort(g);
        Arrays.sort(s);
        int num=0;
        int gIndex=0;
        for (int i = 0; i <s.length ; i++) {
            if (gIndex<g.length&&s[i]>=g[gIndex]){
                num++;
                gIndex++;
            }
        }
        return num;
    }
}
