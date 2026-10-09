package lab4_karios_ex1;

import java.util.ArrayList;

public abstract class Pizza {
    protected String size;
    protected String doughType;
    protected ArrayList<Ingredient> ingredients;
    protected int freeChangesUsed;

    public Pizza(String size, String doughType) {
        this.size = size;
        this.doughType = doughType;
        ingredients = new ArrayList<>();
        freeChangesUsed = 0;
    }

    protected int getSizeMultiplier() {
        if(size.equalsIgnoreCase("small")) return 2;
        if(size.equalsIgnoreCase("medium")) return 3;
        if(size.equalsIgnoreCase("large")) return 4;
        return 5;
    }

    public void addIngredient(Ingredient i) {
        ingredients.add(i);
    }

    public abstract double calculatePrice();

    public String toString() {
        return getClass().getSimpleName() +
                " | Size: " + size +
                " | Dough: " + doughType +
                " | Price: €" + calculatePrice();
    }
}