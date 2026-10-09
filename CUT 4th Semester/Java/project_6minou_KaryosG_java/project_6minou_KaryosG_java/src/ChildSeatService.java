public class ChildSeatService extends AddOnService {

    private static final double STATHERI_TIMI = 20.0;

    public ChildSeatService() {
        super("Child Seat");
    }

    @Override
    public double ypologiseKostos(int meres) {
        return STATHERI_TIMI;
    }
}
