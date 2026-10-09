public class GPSService extends AddOnService {

    private static final double TIMI_ANA_MERA = 5.0;

    public GPSService() {
        super("GPS/Navigation");
    }

    @Override
    public double ypologiseKostos(int meres) {
        return meres * TIMI_ANA_MERA;
    }
}
