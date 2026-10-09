package lab4_karios_ex1;

public class Ingredient {
    private String name;
    private double price;
    private int quantity;
    private boolean animalBased;

    public Ingredient(String name, double price, int quantity, boolean animalBased) {
        this.name = name;
        this.price = price;
        this.quantity = quantity;
        this.animalBased = animalBased;
    }

    public String getName() { return name; }
    public double getPrice() { return price; }
    public int getQuantity() { return quantity; }
    public boolean isAnimalBased() { return animalBased; }

    public void setPrice(double price) { this.price = price; }
    public void setQuantity(int quantity) { this.quantity = quantity; }

    public void increaseQuantity(int amount) { quantity += amount; }

    public void decreaseQuantity(int amount) {
        if(amount <= quantity) quantity -= amount;
    }

    public String toString() {
        return name + " (€" + price + ", qty=" + quantity + ")";
    }
}