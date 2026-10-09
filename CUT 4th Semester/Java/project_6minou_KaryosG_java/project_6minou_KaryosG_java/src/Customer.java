import java.util.ArrayList;
import java.util.List;

public class Customer {

    private String onomatepwnymo;
    private String arTaftotitas;
    private String dieythinsi;
    private String tilefwno;
    private String email;
    private String pistwtikiKarta;
    private LoyaltyAccount loyaltyLogariasmos;
    private ArrayList<Rental> istorikoEnoikiasewn;

    public Customer(String onomatepwnymo, String arTaftotitas, String dieythinsi,
                    String tilefwno, String email, String pistwtikiKarta) {
        this.onomatepwnymo = onomatepwnymo;
        this.arTaftotitas = arTaftotitas;
        this.dieythinsi = dieythinsi;
        this.tilefwno = tilefwno;
        this.email = email;
        this.pistwtikiKarta = pistwtikiKarta;
        this.loyaltyLogariasmos = new LoyaltyAccount();
        this.istorikoEnoikiasewn = new ArrayList<Rental>();
    }

    public Customer(String onomatepwnymo, String arTaftotitas, String dieythinsi,
                    String tilefwno, String email, String pistwtikiKarta,
                    String loyaltyCardId, int pontoi) {
        this.onomatepwnymo = onomatepwnymo;
        this.arTaftotitas = arTaftotitas;
        this.dieythinsi = dieythinsi;
        this.tilefwno = tilefwno;
        this.email = email;
        this.pistwtikiKarta = pistwtikiKarta;
        this.loyaltyLogariasmos = new LoyaltyAccount(loyaltyCardId, pontoi);
        this.istorikoEnoikiasewn = new ArrayList<Rental>();
    }

    public void prostheseEnoikiasi(Rental enoikiasi) {
        istorikoEnoikiasewn.add(enoikiasi);
    }

    public List<Rental> getRentalHistory() {
        return istorikoEnoikiasewn;
    }

    public Rental getCurrentActiveRental() {
        for (int i = istorikoEnoikiasewn.size() - 1; i >= 0; i--) {
            Rental enoikiasi = istorikoEnoikiasewn.get(i);
            if (enoikiasi.einaiEnergi()) {
                return enoikiasi;
            }
        }
        return null;
    }

    public String getFullName() {
        return onomatepwnymo;
    }

    public String getIdNumber() {
        return arTaftotitas;
    }

    public String getAddress() {
        return dieythinsi;
    }

    public String getPhone() {
        return tilefwno;
    }

    public String getEmail() {
        return email;
    }

    public String getCreditCardNumber() {
        return pistwtikiKarta;
    }

    public LoyaltyAccount getLoyaltyAccount() {
        return loyaltyLogariasmos;
    }

    @Override
    public String toString() {
        return "Name: " + onomatepwnymo + " | ID: " + arTaftotitas + " | Address: " + dieythinsi +
               " | Phone: " + tilefwno + " | Email: " + email + " | " + loyaltyLogariasmos;
    }
}
