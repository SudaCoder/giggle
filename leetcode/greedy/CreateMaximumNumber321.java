package greedy;

import java.util.*;

/**
 * Created by 杜文丽 on 2019/12/9 16:52
 **/
public class CreateMaximumNumber321 {
    public static void main(String[] args) {
        CreateMaximumNumber321 test = new CreateMaximumNumber321();
        /**
         * [3,8,5,3,4]
         * [8,7,3,6,8]
         */
        int[] num1 = {3,8,5,3,4};
        int[] num2 = {8,7,3,6,8};
        int[] res = test.maxNumber(num1, num2, 5);
    }

    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        int num1Num = 0;
        if (nums2.length < k) {
            num1Num = k - nums2.length;
        }
        int[] i1 = extract(nums1, num1Num);
        int[] i2 = extract(nums2, k - num1Num);
        int[] res = combine(i1, i2);
        for (int i = num1Num + 1; i <= nums1.length && i <= k; i++) {
            i1 = extract(nums1, i);
            i2 = extract(nums2, k - i);
            int[] tmp = combine(i1, i2);
            res = compare(res, tmp) ? res : tmp;
        }
        return res;
    }

    public int[] extract(int[] nums, int k) {
        if (k == 0) {
            return null;
        }
        List<Integer> stack = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {
            if (stack.size() < k) {
                stack.add(nums[i]);
            } else {
                int removeIndex=-1;
                for (int j = 0; j <stack.size()-1 ; j++) {
                    if (stack.get(j)<stack.get(j+1)){
                        removeIndex=j;
                        break;
                    }
                }
                if (removeIndex==-1){
                    if (nums[i]>stack.get(stack.size()-1)){
                        stack.remove(stack.size()-1);
                        stack.add(nums[i]);
                    }else {
                        continue;
                    }
                }else {
                    stack.remove(removeIndex);
                    stack.add(nums[i]);
                }

            }

        }

        int[] res = new int[stack.size()];
        for (int i = 0; i <stack.size() ; i++) {
            res[i]=stack.get(i);
        }
        return res;

    }

    public boolean compare(int[] num1, int[] num2) {
        if (num1 == null || num2 == null) {
            if (num1 == null) {
                return false;
            } else {
                return true;
            }
        }
        for (int i = 0; i < num1.length; i++) {
            if (num1[i] == num2[i]) {
                continue;
            } else {
                return num1[i] > num2[i] ? true : false;
            }
        }
        return false;//true num1大，false num2小于等于num1
    }

    public int[] combine(int[] n1, int[] n2) {
        if (n1 == null) {
            return n2;
        }
        if (n2 == null) {
            return n1;
        }
        int len = n1.length + n2.length;
        int[] res = new int[len];
        int i1 = 0;
        int i2 = 0;
        int i = 0;
        while (i1 < n1.length && i2 < n2.length) {
            if (n1[i1]!=n2[i2]){
                res[i] = n1[i1] >= n2[i2] ? n1[i1++] : n2[i2++];
            }else {
                int tmpi1=i1+1;
                int tmpi2=i2+1;
                while (tmpi1<n1.length&&tmpi2<n2.length){
                    if (n1[tmpi1]>n2[tmpi2]){
                        res[i] = n1[i1++];
                        break;
                    }else if (n1[tmpi1]<n2[tmpi2]){
                        res[i] = n2[i2++] ;
                        break;
                    }else {
                        //依旧相等
                        tmpi1++;
                        tmpi2++;
                    }
                }
                if (tmpi1>=n1.length||tmpi2>=n2.length){
                    //证明没有出现任何转折
                    if (tmpi1>=n1.length&&tmpi2<n2.length){
                            res[i] = n2[i2++];
                    }else{
                        res[i] = n1[i1++];
                    }
                }
            }
            i++;
        }
        if (i1 >= n1.length) {
            while (i2 < n2.length) {
                res[i++] = n2[i2++];
            }
        } else {
            while (i1 < n1.length) {
                res[i++] = n1[i1++];
            }
        }
        return res;
    }
}
