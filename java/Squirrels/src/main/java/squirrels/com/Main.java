package main.java.squirrels.com;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<Squirrel> squirrels = new ArrayList<>();
        List<Food> foods = new ArrayList<>();
        String currLine = null;
        String[] input;

        Scanner scan = new Scanner(System.in);

        do{
            currLine = scan.nextLine();
            if(currLine.equals("stop"))break;
            input = currLine.split(" ");
            Integer age = Integer.parseInt(input[2]);
            Squirrel squirrel = new Squirrel(input[1], input[0], age);
            squirrels.add(squirrel);

            System.out.printf("<%s> %s(%d)\n", squirrel.getType(), squirrel.getName(), squirrel.getAge());
        }while (true);

        int countOfSquirrels = 0;
        int countOfFoods = 0;
        do{
            currLine = scan.nextLine();
            if(currLine.equals("stop"))break;
            input = currLine.split(" ");
            Double currQuan = Double.parseDouble(input[1]);
            Double currQual = Double.parseDouble(input[2]);

            if(countOfFoods == squirrels.get(countOfSquirrels).getMaxGoForFood()){
                countOfFoods = 0;
                countOfSquirrels += 1;
            }

            if(countOfSquirrels == squirrels.size()){
                for(Squirrel sq : squirrels){
                    sq.passWinter();
                }
                countOfSquirrels = 0;
                countOfFoods = 0;
            }

            if (input[0].equals("cake")) {
                Cake food = new Cake(currQuan, currQual);
                foods.add(food);
                System.out.printf("%s quantity:%f quality:%f\n", input[0], food.getQuantity(), food.getQuality());
                countOfFoods += 1;
                squirrels.get(countOfSquirrels).addFood(food);
            }
            if (input[0].equals("nuts")){
                Nuts food = new Nuts(currQuan, currQual);
                foods.add(food);
                System.out.printf("%s quantity:%f quality:%f\n", input[0], food.getQuantity(), food.getQuality());
                countOfFoods += 1;
                squirrels.get(countOfSquirrels).addFood(food);
            }
            if (input[0].equals("mcburger")){
                McBurger food = new McBurger(currQuan, currQual);
                foods.add(food);
                System.out.printf("%s quantity:%f quality:%f\n", input[0], food.getQuantity(), food.getQuality());
                countOfFoods += 1;
                squirrels.get(countOfSquirrels).addFood(food);
            }

        }while (true);

    }

}
