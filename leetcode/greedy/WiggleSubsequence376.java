package greedy;

import java.util.Stack;

/**
 * Created by 杜文丽 on 2019/12/11 9:33
 **/
public class WiggleSubsequence376 {
    public static void main(String[] args) {
        WiggleSubsequence376 test = new WiggleSubsequence376();
        int[] nums = {1,1,1,2,2,2,1,1,1,3,3,3,2,2,2};
        int len = test.wiggleMaxLength(nums);
    }

    public int wiggleMaxLength(int[] nums) {
        if (nums.length < 2) {
            return nums.length;
        }
        Stack<Integer> stack = new Stack<>();
        boolean big;
        int begin = 0;
        int end=nums.length-1;
        while (begin + 1 < nums.length && nums[begin] == nums[begin + 1]) {
            begin++;
        }
        while (end>=1&&nums[end]==nums[end-1]){
            end--;
        }
        if (begin>=end){
            return 1;
        }else {
            if (nums[begin] > nums[begin + 1]) {
                big = false;
            } else {
                big = true;
            }
        }
        stack.add(nums[begin]);

        for (int i = begin+1; i < end; i++) {

            if (big) {
                if (nums[i] > nums[i + 1]) {
                    stack.add(nums[i]);
                    big = !big;
                    if (i + 1 >= end) {
                        stack.add(nums[i + 1]);
                    }
                } else if (nums[i] < nums[i + 1]) {
                    //当前的数是大数，且越大越好
                    if (i + 1 >= end) {
                        stack.push(nums[i + 1]);
                    }
                }
            } else {
                //当前的数是小数，且越小越好
                if (nums[i] > nums[i + 1]) {
                    if (i + 1 >= end) {
                        stack.push(nums[i + 1]);
                    }
                } else if (nums[i] < nums[i + 1]) {
                    stack.add(nums[i]);
                    big = !big;
                    if (i + 1 >= end) {
                        stack.add(nums[i + 1]);
                    }
                }
            }

        }
        return stack.size();
    }
}
