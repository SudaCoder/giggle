package array;

/**
 * Created by 杜文丽 on 8/3/2019 11:23 AM
 * Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
 *
 * Example 1:
 *
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 **/
public class MaximumProductSubarray152 {
    public static void main(String[] args) {
        Solution152 s=new Solution152();
        int[] nums={-1,2,2,-3};
        System.out.println(s.maxProduct(nums));
    }
}
class Solution152 {
//
//    int[][] dp=new int[100][10000];
//    int res=0;
//    int symbols=0;
//    boolean zero=false;
//    public void symbolSum(int[] nums){
//        for (int i = 0; i <nums.length ; i++) {
//            if (nums[i]<0){
//                symbols++;
//            }
//            if (nums[i]==0){
//                zero=true;
//            }
//        }
//    }
//    public int sub(int[] nums,int mini,int maxj){
//        if (maxj>=nums.length){
//            return 0;
//        }
//        if (dp[mini][maxj]!=0){
//            return dp[mini][maxj];
//        }
//        int sum=1;
//        for (int i=mini;i<=maxj;i++){
//            sum*=nums[i];
//        }
//        dp[mini][maxj]=sum;
//        return sum;
//    }
//    public int maxProduct(int[] nums) {
//        symbolSum(nums);
//        if (nums.length<=1){
//            return nums[0];
//        }
//        if (symbols%2==0&&zero==false){
//            return sub(nums,0,nums.length-1);
//        }
//        for (int i = 0; i <nums.length ; i++) {
//            for (int j = i; j <nums.length ; j++) {
//                if (nums[i]==0||nums[i]==1||nums[i]==-1){
//                    continue;
//                }
//                res=Math.max(res,sub(nums,i,j));
//            }
//        }
//        return res;
//    }

    //日妈 dp这个也太强了吧，直接降到O(n)
    int[] dpmin=new int[100000];
    int[] dpmax=new int[100000];
    int res=0;

    public int maxProduct(int[] nums) {
        for (int i = 0; i <100000 ; i++) {
            dpmin[i]=100000;
            dpmax[i]=-100000;
        }
        dpmax[0]=nums[0];
        dpmin[0]=nums[0];
        res=nums[0];

        for (int i = 1; i <nums.length ; i++) {
            dpmax[i]=Math.max(dpmax[i-1]*nums[i],dpmin[i-1]*nums[i]);
            dpmin[i]=Math.min(dpmax[i-1]*nums[i],dpmin[i-1]*nums[i]);
            res=Math.max(dpmax[i],dpmin[i]);
        }


        return res;
    }
}