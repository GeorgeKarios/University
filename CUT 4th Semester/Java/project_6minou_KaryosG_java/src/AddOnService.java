public abstract class AddOnService {

    private String onoma;

    public AddOnService(String onoma) {
        this.onoma = onoma;
    }

    public abstract double ypologiseKostos(int meres);

    public String getName() {
        return onoma;
    }

    @Override
    public String toString() {
        return onoma;
    }
}
