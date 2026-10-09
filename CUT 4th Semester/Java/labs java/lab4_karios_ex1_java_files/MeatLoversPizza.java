package lab4_karios_ex1;

public class MeatLoversPizza extends Pizza {

    private final double basePrice = 7.0;
    private int extraIngredients;

    public MeatLoversPizza(String size, String doughType) {
        super(size,doughType);

        ingredients.add(new Ingredient("Pepperoni",1.5,50,true));
        ingredients.add(new Ingredient("Ham",1.5,50,true));
        ingredients.add(new Ingredient("Bacon",1.5,50,true));
        ingredients.add(new Ingredient("Mozzarella",1.5,50,true));
    }

    public void addExtraIngredient(Ingredient i){
        ingredients.add(i);
        extraIngredients++;
    }

    public double calculatePrice(){
        double price = basePrice * getSizeMultiplier();
        price += extraIngredients * 1.5;
        return price;
    }
}