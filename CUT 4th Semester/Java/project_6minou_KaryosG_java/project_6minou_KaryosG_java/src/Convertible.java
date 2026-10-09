public class Convertible extends Vehicle {

    private static final double DAILY_RATE = 90.0;

    public Convertible(String arEggrafis, String marka, String montelo, int etos, int theseis) {
        super(arEggrafis, marka, montelo, etos, theseis);
    }

    @Override
    public double getDailyRate() {
        return DAILY_RATE;
    }

    @Override
    public String getCategory() {
        return "Convertible";
    }

    @Override
    public int getMinSeats() {
        return 2;
    }

    @Override
    public int getMaxSeats() {
        return 4;
    }
}
