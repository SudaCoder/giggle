package greedy;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by 杜文丽 on 2019/12/5 15:19
 **/
public class Candy135 {

    public int candy(int[] ratings) {
        if (ratings.length<=0){
            return 0;
        }else if (ratings.length<=1){
            return 1;
        }else if (ratings.length==2){
            return ratings[0]==ratings[1]?2:3;
        }
        int[] candy=new int[ratings.length];
        //全部初始化成1
        for (int i = 0; i <ratings.length ; i++) {
            candy[i]=1;
        }
        boolean change=true;
        while (change){
            change=false;
            for (int i = 0; i <ratings.length-1 ; i++) {
                if (ratings[i]<ratings[i+1]&&candy[i]>=candy[i+1]){
                    candy[i+1]=candy[i]+1;
                    change=true;
                }

            }
            for (int i = ratings.length-1 ; i>0 ; i--) {
                if (ratings[i]<ratings[i-1]&&candy[i]>=candy[i-1]){
                    candy[i-1]=candy[i]+1;
                    change=true;
                }

            }
        }

        int sum=0;
        for (int i = 0; i <ratings.length ; i++) {
            sum+=candy[i];
        }
        return sum;
    }

}
