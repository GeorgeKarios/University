package lab4_karios_ex1;

import java.util.ArrayList;

public class lab4_ex1 {

    public static void main(String[] args){

        ArrayList<Pizza> order = new ArrayList<>();

        Pizza p1 = new VegetarianPizza("small","thin");
        Pizza p2 = new MeatLoversPizza("large","normal");
        Pizza p3 = new SpecialPizza("XL","cheese stuffed");

        CustomPizza p4 = new CustomPizza("medium","thin");
        p4.addIngredient(new Ingredient("Tomato",1,20,false));
        p4.addIngredient(new Ingredient("Mushrooms",1,20,false));
        p4.addIngredient(new Ingredient("Onion",1,20,false));
        p4.addIngredient(new Ingredient("Ham",1.5,20,true));
        p4.addIngredient(new Ingredient("Mozzarella",1.5,20,true));

        order.add(p1);
        order.add(p2);
        order.add(p3);
        order.add(p4);

        double total = 0;

        for(Pizza p : order){
            System.out.println(p);
            total += p.calculatePrice();
        }

        System.out.println("Total order cost: €" + total);
    }
}