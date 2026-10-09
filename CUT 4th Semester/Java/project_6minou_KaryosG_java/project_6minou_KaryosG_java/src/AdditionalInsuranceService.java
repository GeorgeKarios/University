public class AdditionalInsuranceService extends AddOnService {

    private static final double TIMI_ANA_PERIOD = 30.0;
    private static final int MERES_ANA_PERIOD = 5;

    public AdditionalInsuranceService() {
        super("Additional Insurance");
    }

    @Override
    public double ypologiseKostos(int meres) {
        int periodoi = (int) Math.ceil((double) meres / MERES_ANA_PERIOD);
        return periodoi * TIMI_ANA_PERIOD;
    }
}
