package greedy;

/**
 * Created by 杜文丽 on 2019/12/9 11:00
 **/
public class JumpGameII45 {
    public int jump(int[] nums) {
        //每一次跳 保证在最少的次数之内，到达最远
        if (nums.length<=1){
            return 0;
        }
        int reach=0;
        int nextreach=nums[0];
        int step=0;
        for (int i = 0; i <nums.length ; i++) {
            nextreach=Math.max(nextreach,i+nums[i]);
            if (nextreach>=nums.length-1){
                return step+1;
            }
            if (reach==i){
                reach=nextreach;
                step++;
            }
        }
        return step;
    }
}
