package greedy;

/**
 * Created by 杜文丽 on 2019/12/5 10:26
 **/
public class GasStation134 {
    private int[] gas;
    private int[] cost;
    public int sum(int[] arr){
        int sum=0;
        for (int i = 0; i <arr.length ; i++) {
            sum+=arr[i];
        }
        return sum;
    }
    public boolean circleArrive(int index){
        int i=index;
        int currGas=gas[i];
        if (i==gas.length-1){
            currGas=currGas+gas[0]-cost[gas.length-1];
            i=0;
        }else{
            while (i<gas.length-1){
                if (currGas<cost[i]){
                    return false;
                }
                currGas=currGas-cost[i]+gas[i+1];//到站了 加油
                i++;
            }
        }
        while (i<index){
            if (currGas<cost[i]){
                return false;
            }
            currGas=currGas-cost[i]+gas[i+1];//到站了 加油
            i++;
        }
        return true;
    }
    public int canCompleteCircuit(int[] gas, int[] cost) {
        if (sum(gas)<sum(cost)){
            return -1;
        }
        this.gas=gas;
        this.cost=cost;
        for (int i = 0; i <gas.length ; i++) {
            if (circleArrive(i)){
                return (i);
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        GasStation134 test=new GasStation134();
        int[] gas={1,2,3,4,5};
        int[] cost={5,4,3,2,1};
        System.out.println(test.canCompleteCircuit(gas,cost));
    }
}
