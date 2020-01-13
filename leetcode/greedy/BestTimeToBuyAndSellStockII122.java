package greedy;

/**
 * Created by 杜文丽 on 2019/12/9 16:26
 **/
public class BestTimeToBuyAndSellStockII122 {
    public int maxProfit(int[] prices) {
        if (prices.length<=1){
            return 0;
        }
        int money=0;
        for (int i = 0; i <prices.length-1 ; i++) {
            if (prices[i]<prices[i+1]&&i <prices.length-1){
                while (prices[i]<prices[i+1]){
                    money+=prices[i+1]-prices[i];
                    i++;
                }

            }
        }
        return money;
    }


}
