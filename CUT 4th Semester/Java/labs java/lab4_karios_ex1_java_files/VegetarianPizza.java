package lab4_karios_ex1;

public class VegetarianPizza extends Pizza {

    private final double basePrice = 6.0;
    private int extraIngredients;

    public VegetarianPizza(String size, String doughType) {
        super(size, doughType);

        ingredients.add(new Ingredient("Tomato",1,50,false));
        ingredients.add(new Ingredient("Mushrooms",1,50,false));
        ingredients.add(new Ingredient("Peppers",1,50,false));
        ingredients.add(new Ingredient("Onion",1,50,false));
        ingredients.add(new Ingredient("Mozzarella",1.5,50,true));
    }

    public void addExtraIngredient(Ingredient i) {
        ingredients.add(i);
        extraIngredients++;
    }

    public double calculatePrice() {
        double price = basePrice * getSizeMultiplier();
        price += extraIngredients * 1;
        return price;
    }
}