import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class Rental {

    private String rentalId;
    private Customer pelatis;
    private Vehicle oxima;
    private LocalDate imerominiaEnarksis;
    private int meres;
    private ArrayList<AddOnService> extraYpiresies;
    private double ekptwsi;

    public Rental(String rentalId, Customer pelatis, Vehicle oxima,
                  LocalDate imerominiaEnarksis, int meres,
                  List<AddOnService> extraYpiresies, double ekptwsi) {
        this.rentalId = rentalId;
        this.pelatis = pelatis;
        this.oxima = oxima;
        this.imerominiaEnarksis = imerominiaEnarksis;
        this.meres = meres;
        this.extraYpiresies = new ArrayList<AddOnService>();
        if (extraYpiresies != null) {
            this.extraYpiresies.addAll(extraYpiresies);
        }
        this.ekptwsi = ekptwsi;
    }

    public boolean epikaliptetai(LocalDate arxi, LocalDate telos) {
        LocalDate telosEnoikiasis = imerominiaEnarksis.plusDays(meres - 1);
        return !telos.isBefore(imerominiaEnarksis) && !arxi.isAfter(telosEnoikiasis);
    }

    public double ypologiseVasikoKostos() {
        return oxima.getDailyRate() * meres;
    }

    public double ypologiseKostosExtras() {
        double sinolo = 0;
        for (AddOnService yp : extraYpiresies) {
            sinolo += yp.ypologiseKostos(meres);
        }
        return sinolo;
    }

    public double ypologiseSynolikoKostos() {
        return ypologiseVasikoKostos() + ypologiseKostosExtras() - ekptwsi;
    }

    public boolean einaiEnergi() {
        LocalDate simera = LocalDate.now();
        return !simera.isBefore(imerominiaEnarksis) && !simera.isAfter(getEndDate());
    }

    public void ektypwseTimologio() {
        LocalDate telos = getEndDate();
        System.out.println("========================================");
        System.out.println("                INVOICE");
        System.out.println("========================================");
        System.out.println("Rental ID   : " + rentalId);
        System.out.println("Customer    : " + pelatis.getFullName());
        System.out.println("ID Number   : " + pelatis.getIdNumber());
        System.out.println("Vehicle     : " + oxima.getBrand() + " " + oxima.getModel());
        System.out.println("Category    : " + oxima.getCategory());
        System.out.println("Reg. Number : " + oxima.getRegistrationNumber());
        System.out.println("Start Date  : " + imerominiaEnarksis);
        System.out.println("End Date    : " + telos);
        System.out.println("Duration    : " + meres + " day(s)");
        System.out.println("----------------------------------------");
        System.out.printf("Base Cost   : €%.2f%n", ypologiseVasikoKostos());
        for (AddOnService yp : extraYpiresies) {
            System.out.printf("%-12s: €%.2f%n", yp.getName(), yp.ypologiseKostos(meres));
        }
        if (ekptwsi > 0) {
            System.out.printf("Discount    : -€%.2f%n", ekptwsi);
        }
        System.out.println("----------------------------------------");
        System.out.printf("TOTAL       : €%.2f%n", ypologiseSynolikoKostos());
        System.out.println("========================================");
    }

    public String getRentalId() {
        return rentalId;
    }

    public Customer getCustomer() {
        return pelatis;
    }

    public Vehicle getVehicle() {
        return oxima;
    }

    public LocalDate getStartDate() {
        return imerominiaEnarksis;
    }

    public LocalDate getEndDate() {
        return imerominiaEnarksis.plusDays(meres - 1);
    }

    public int getDays() {
        return meres;
    }

    public List<AddOnService> getAddOns() {
        return extraYpiresies;
    }

    public double getDiscount() {
        return ekptwsi;
    }

    @Override
    public String toString() {
        return "Rental " + rentalId + " | " + pelatis.getFullName() + " | " +
               oxima.getBrand() + " " + oxima.getModel() + " | " +
               imerominiaEnarksis + " to " + getEndDate() + " (" + meres + " days) | Total: €" +
               String.format("%.2f", ypologiseSynolikoKostos());
    }
}
