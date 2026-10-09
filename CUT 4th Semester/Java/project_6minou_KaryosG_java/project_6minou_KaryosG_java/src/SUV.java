public class SUV extends Vehicle {

    private static final double DAILY_RATE = 70.0;

    public SUV(String arEggrafis, String marka, String montelo, int etos, int theseis) {
        super(arEggrafis, marka, montelo, etos, theseis);
    }

    @Override
    public double getDailyRate() {
        return DAILY_RATE;
    }

    @Override
    public String getCategory() {
        return "SUV";
    }

    @Override
    public int getMinSeats() {
        return 5;
    }

    @Override
    public int getMaxSeats() {
        return 7;
    }
}
