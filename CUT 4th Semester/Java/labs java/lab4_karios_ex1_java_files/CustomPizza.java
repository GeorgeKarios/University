package lab4_karios_ex1;

public class CustomPizza extends Pizza {

    public CustomPizza(String size, String doughType){
        super(size,doughType);
    }

    public double calculatePrice(){

        if(ingredients.size() < 5)
            return 0;

        double base = 0;

        for(Ingredient i : ingredients){

            if(i.isAnimalBased())
                base += 1.5;
            else
                base += 1;
        }

        return base * getSizeMultiplier();
    }
}