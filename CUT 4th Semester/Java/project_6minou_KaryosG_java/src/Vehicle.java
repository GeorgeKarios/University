import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
//afirimeni - xrisimopoieitai pou tis ipoklaseis taxa suv & economycar
public abstract class Vehicle implements Bookable {

    private String arEggrafis;
    private String marka;
    private String montelo;
    private int etos;
    private int theseis;
    private ArrayList<Rental> istorikoEnoikiasewn;

    public Vehicle(String arEggrafis, String marka, String montelo, int etos, int theseis){ //o constructor arxikopoiei tis times
        this.arEggrafis = arEggrafis;
        this.marka = marka;
        this.montelo = montelo;
        this.etos = etos;
        this.theseis = theseis;
        this.istorikoEnoikiasewn = new ArrayList<Rental>();
    }
// afirimenes gt oi ipoklaseis gia ta aftokinita en diaforetikes gia to kathena
    public abstract int getMinSeats();
    public abstract int getMaxSeats();
    @Override
    public boolean einaiDiathesimo(LocalDate arxi, int meres) {
        LocalDate telos = arxi.plusDays(meres - 1);
        for (Rental enoikiasi : istorikoEnoikiasewn) {
            if (enoikiasi.epikaliptetai(arxi, telos)) {
                return false;
            }
        }
        return true;
    }

    public void prostheseEnoikiasi(Rental enoikiasi) {
        istorikoEnoikiasewn.add(enoikiasi);
    }

    public void afaireseEnoikiasi(Rental enoikiasi) {
        istorikoEnoikiasewn.remove(enoikiasi);
    }

    public List<Rental> getRentals() {
        return istorikoEnoikiasewn;
    }

    public String getRegistrationNumber() {
        return arEggrafis;
    }

    public String getBrand() {
        return marka;
    }

    public String getModel() {
        return montelo;
    }

    public int getYear() {
        return etos;
    }

    public int getSeats() {
        return theseis;
    }

    public void setSeats(int theseis) {
        this.theseis = theseis;
    }

    @Override
    public String toString() {
        return "[" + arEggrafis + "] " + marka + " " + montelo + " (" + etos + ") | " +
               getCategory() + " | " + theseis + " seats | €" + String.format("%.2f", getDailyRate()) + "/day";
    }
}
