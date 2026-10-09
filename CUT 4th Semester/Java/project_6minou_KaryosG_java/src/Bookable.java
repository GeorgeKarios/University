import java.time.LocalDate;

public interface Bookable {
    boolean einaiDiathesimo(LocalDate arxi, int meres);
    String getCategory();
    double getDailyRate();
}
