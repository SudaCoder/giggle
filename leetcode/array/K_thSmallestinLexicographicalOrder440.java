package array;

/**
 * Created by 杜文丽 on 9/11/2019 4:44 PM
 * 找出1-n中利用逻辑排序之后的第k小的数字
 *
 * 思路：
 * 此树是根据前序遍历即可得到逻辑顺序
 * 先判断从i到i+1需要x步
 * 如果x大于k，进入i+1,否则进入i
 **/
public class K_thSmallestinLexicographicalOrder440 {
    public static void main(String[] args) {

    }

    public static int subcal(int n,int curr){
        //返回从curr到curr+1之间的数据个数
        int index=curr*10;
        int num=1;
        while (index<n){
            for (int i = 0; i < 10; i++) {
                int currindex=index+i;
                if (currindex<=n){
                    num++;
                }else {
                    break;
                }
            }
            index*=10;
        }

        return 0;
    }
    public static int find(int curr,int kth,int n){
        //返回从curr开头的第k个数


        return 0;
    }
    public static int solve(int n,int k){
        int curr=1;
        int number_num=0;
        int res=0;
        while (curr<9){
            //返回从curr到curr+1有多少个数据
            number_num=subcal(n,curr);
            if (number_num<k){
                curr++;
                k-=number_num;
                continue;
            }else{
                //从curr开头的第k个数
                res=find(curr,k,n);
            }
        }
        return res;
    }

}
