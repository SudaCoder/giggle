package greedy;

/**
 * Created by 杜文丽 on 2019/12/6 21:57
 * 从后往前遍历
 * 如果所有的元素都不为零，则能够到达
 * 如果有元素为零，则在零前面寻找一个元素，是的该元素的值能够跳过这个零
 **/
public class JumpGame55 {
    public boolean canJump(int[] nums) {
        if (nums.length<=1){
            return true;
        }
        for (int i = nums.length-2; i >=0 ; i--) {
            if (nums[i]==0){
                boolean canFind=false;
                for (int j =i-1 ; j >=0 ; j--) {
                    if (nums[j]>=i-j+1){
                        i=j;
                        canFind=true;
                    }
                }
                if (!canFind){
                    return false;
                }
            }
        }
        return true;
    }
}
