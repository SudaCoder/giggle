package linkedList;

import java.util.*;
import java.util.List;
public class Circle_link_II_142 {
/** 请完成下面这个函数，实现题目要求的功能 **/
    /**
     * 当然，你也可以不按照这个模板来作答，完全按照自己的想法来
     **/
    public static String measureDistance(List<Double> xList, List<Double> yList, double x, double y) {
        boolean xx=isin(xList,x);
        boolean yy=isin(yList,y);
        if(xx&&yy){
            return "yes,0";
         }
        else{
            double small=Math.sqrt(Math.pow(xList.get(0)-x,2)+Math.pow(yList.get(0)-y,2));
            for (int i = 1; i <xList.size() ; i++) {
                double temp=Math.sqrt(Math.pow(xList.get(i)-x,2)+Math.pow(yList.get(i)-y,2));
                if(temp<small){
                    small=temp;
                }
            }
            if(small-(int)small<0.5){
                return "no,"+(int)small;
            }else{
                return "no,"+((int)(small)+1);
            }
        }
    }

    public static boolean isin(List<Double> xList,double x){
        boolean small=false;
        boolean big=false;
        for (Double d:xList
             ) {
            if(d<x){
                small=true;
            }else{
                big=true;
            }
        }
        return small&&big;
    }


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String line = in.nextLine();
        //(x,y)为小广所在的位置
        double x = Double.parseDouble(line.split(",")[0]);
        double y = Double.parseDouble(line.split(",")[1]);

        line = in.nextLine();
        //xList记录了多边形n个点的x坐标,yList记录了多边形n个点的y坐标
        List<Double> xList = new ArrayList<>();
        List<Double> yList = new ArrayList<>();
        String[] array = line.split(",");
        for(int i = 0; i < array.length; i++) {
            xList.add(Double.parseDouble(array[i]));
            yList.add(Double.parseDouble(array[i+1]));
            i++;
        }
        in.close();
        System.out.println(measureDistance(xList, yList, x, y));
    }
}