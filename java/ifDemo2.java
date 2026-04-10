package com.ifDemo;


import java.util.Scanner;

public class ifDemo2 {
    public static void main(String[] args) {
        //定义变量记录人物血量
        int hp=200;


        //键盘录入一个值，表示当前人物受到的伤害
        System.out.println("请输入当前人物受到的伤害");
        Scanner sc=new Scanner(System.in);
        int hurt =sc.nextInt();//应当判断输入的值是否为正的
        //计算当前血量
        hp=hp-hurt;

        //游戏人物不会死亡，最少一点血
        if(hp<=0)
        {
            hp=1;
        }
        System.out.println("当前游戏人物的血量是："+hp);

        //键盘输入一个值，表示技能回复的血量
        System.out.println("请输入技能回复的血量");
        int add=sc.nextInt();
        hp=hp+add;
        if(hp>200)
        {
            hp=200;
        }

        System.out.println("当前游戏人物的血量：" +hp);

    }
}
