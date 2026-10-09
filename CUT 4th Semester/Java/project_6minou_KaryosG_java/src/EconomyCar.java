public class EconomyCar extends Vehicle {

    private static final double DAILY_RATE = 45.0;

    public EconomyCar(String arEggrafis, String marka, String montelo, int etos, int theseis) {
        super(arEggrafis, marka, montelo, etos, theseis);
    }

    @Override
    public double getDailyRate() {
        return DAILY_RATE;
    }

    @Override
    public String getCategory() {
        return "EconomyCar";
    }

    @Override
    public int getMinSeats() {
        return 4;
    }

    @Override
    public int getMaxSeats() {
        return 5;
    }
}
