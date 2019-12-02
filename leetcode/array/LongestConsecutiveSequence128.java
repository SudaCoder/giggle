package array;

import java.util.HashSet;

/**
 * Created by 杜文丽 on 8/3/2019 11:15 AM
 *
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 *
 * Your algorithm should run in O(n) complexity.
 *
 * Example:
 *
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 **/
public class LongestConsecutiveSequence128 {
    public static void main(String[] args) {

    }
}

/**
 * 首先将所有的数据装到一个hashSet中
 * 顺序遍历，边遍历边计算边删除
 * 返回最大的res
 */
class Solution {
    public int longestConsecutive(int[] nums) {
        int res=0;
        HashSet<Integer> set=new HashSet();
        for (int num:nums
             ) {
            set.add(num);
        }
        for (int num:nums
             ) {
            if (set.remove(num)){
                int pre=num-1;
                int aft=num+1;
                while (set.remove(pre)) pre--;
                while (set.remove(aft)) aft++;
                res=Math.max(aft-pre+1,res);
            }
        }
        return res;
    }
}