package stack;

/**
 * Created by 杜文丽 on 2019/12/3 21:53
 **/
public class TrappingRainWater42 {
    //此题之前刷过 奈何今日又迷惑了 看了个题解 想对那个仁兄说 牛皮！两三句话一下子就懂了

    private int[] myHeight;
    private int[] currMax;
    private int[] water;
    /**
     * 从左到右依次扫描，找到左边最高的 找到右边最高的 雨水即是min(leftMax,rightMax)-currHeight
     * @param height
     * @return
     */
    public int trap(int[] height) {

        if (height.length<=2){
            return 0;//只有两格 是接不到水 滴！
        }
        this.myHeight=height;
        this.currMax=new int[height.length];
        this.water=new int[height.length];

        calCurrMax();
        calWater();

        int res=0;
        for (int i = 0; i <height.length ; i++) {
            res+=water[i];
        }
        return res;
    }
    public void calCurrMax(){
        //currMax=min(leftMax,rightMax,curr)
        currMax[0]=myHeight[0];//左边最大是自己，右边最小是自己，因而当前也就是自己
        currMax[myHeight.length-1]=myHeight[myHeight.length-1];
        int maxVal=myHeight[0];
        int maxIndex=0;
        //找到当前最大值的val和index
        for (int i = 1; i <myHeight.length ; i++) {
            if (maxVal<myHeight[i]){
                maxVal=myHeight[i];
                maxIndex=i;
            }
        }
        for (int i = 1; i <maxIndex ; i++) {
            int leftMax=currMax[i-1];
            currMax[i]=Integer.min(Integer.max(leftMax,myHeight[i]),maxVal);
        }
        currMax[maxIndex]=myHeight[maxIndex];

        for (int i = myHeight.length-2; i >maxIndex ; i--) {
            int rightMax=currMax[i+1];
            currMax[i]=Integer.min(Integer.max(rightMax,myHeight[i]),maxVal);
        }
    }
    public void calWater(){
        for (int i = 0; i <myHeight.length ; i++) {
            water[i]=currMax[i]-myHeight[i];
        }
    }
    public static void main(String[] args) {

    }
}
