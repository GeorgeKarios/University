import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class RentalSystem {

    private ArrayList<Vehicle> oximata;
    private ArrayList<Customer> pelates;
    private ArrayList<Rental> enoikiaseis;
    private int metritisEnoikiasewn;

    public RentalSystem() {
        this.oximata = new ArrayList<Vehicle>();
        this.pelates = new ArrayList<Customer>();
        this.enoikiaseis = new ArrayList<Rental>();
        this.metritisEnoikiasewn = 0;
    }

    public void prostheseOxima(String katigoria, String arEggrafis, String marka, String montelo, int etos, int theseis)
            throws VehicleAlreadyExistsException, InvalidVehicleDataException {

        Vehicle oxima = FileManager.createVehicle(katigoria, arEggrafis, marka, montelo, etos, theseis);
        if (oxima == null) {
            throw new InvalidVehicleDataException("Invalid category: " + katigoria);
        }
        if (theseis < oxima.getMinSeats() || theseis > oxima.getMaxSeats()) {
            throw new InvalidVehicleDataException("Seats for " + katigoria + " must be between " +
                                                  oxima.getMinSeats() + " and " + oxima.getMaxSeats() + ".");
        }

        try {
            vresOximaMeArEggrafis(arEggrafis);
            throw new VehicleAlreadyExistsException("Vehicle with registration " + arEggrafis + " already exists.");
        } catch (VehicleNotFoundException e) {
            oximata.add(oxima);
            System.out.println("Vehicle added: " + oxima);
        }
    }

    public void diagrapseOxima(String arEggrafis) throws VehicleNotFoundException {
        Vehicle oxima = vresOximaMeArEggrafis(arEggrafis);
        oximata.remove(oxima);
        System.out.println("Vehicle removed: " + arEggrafis);
    }

    public Vehicle vresOximaMeArEggrafis(String arEggrafis) throws VehicleNotFoundException {
        for (Vehicle oxima : oximata) {
            if (oxima.getRegistrationNumber().equalsIgnoreCase(arEggrafis)) {
                return oxima;
            }
        }
        throw new VehicleNotFoundException("Vehicle not found: " + arEggrafis);
    }

    public int[] pareOrioThesewn(String katigoria) {
        Vehicle proswrino = FileManager.createVehicle(katigoria, "", "", "", 2000, 1);
        if (proswrino == null) {
            return null;
        }
        return new int[] { proswrino.getMinSeats(), proswrino.getMaxSeats() };
    }

    public void kataxorisePelati(String onomatepwnymo, String arTaftotitas, String dieythinsi,
                                 String tilefwno, String email, String pistwtikiKarta)
            throws CustomerAlreadyExistsException {
        try {
            vresPelatiMeTaftotita(arTaftotitas);
            throw new CustomerAlreadyExistsException("Customer with ID " + arTaftotitas + " already exists.");
        } catch (CustomerNotFoundException e) {
            Customer pelatis = new Customer(onomatepwnymo, arTaftotitas, dieythinsi, tilefwno, email, pistwtikiKarta);
            pelates.add(pelatis);
            System.out.println("Customer registered: " + onomatepwnymo);
        }
    }

    public Customer vresPelatiMeTaftotita(String arTaftotitas) throws CustomerNotFoundException {
        for (Customer pelatis : pelates) {
            if (pelatis.getIdNumber().equalsIgnoreCase(arTaftotitas)) {
                return pelatis;
            }
        }
        throw new CustomerNotFoundException("Customer not found: " + arTaftotitas);
    }

    public Customer vresPelatiMeLoyaltyCard(String loyaltyCardId) throws CustomerNotFoundException {
        for (Customer pelatis : pelates) {
            if (pelatis.getLoyaltyAccount().getLoyaltyCardId().equalsIgnoreCase(loyaltyCardId)) {
                return pelatis;
            }
        }
        throw new CustomerNotFoundException("Customer not found with loyalty card: " + loyaltyCardId);
    }

    private String dimiourgiseRentalId() {
        metritisEnoikiasewn++;
        return String.format("R%03d", metritisEnoikiasewn);
    }

    public Rental dimiourgiseEnoikiasi(Customer pelatis, LocalDate arxi, int meres,
                                       String katigoria, int apaitoumenesTheseis,
                                       List<AddOnService> extraYpiresies, int pontoiGiaExargyrosi)
            throws NoVehicleAvailableException {

        ArrayList<Vehicle> antistoixa = vresDiathesimaOximata(arxi, meres, katigoria, apaitoumenesTheseis);

        if (antistoixa.isEmpty()) {
            System.out.println("No available " + katigoria + " with " + apaitoumenesTheseis + " seats found.");
            System.out.println("Alternatives from cheapest to most expensive:");
            ArrayList<Vehicle> enallaktika = vresDiathesimaOximata(arxi, meres, null, apaitoumenesTheseis);
            if (enallaktika.isEmpty()) {
                throw new NoVehicleAvailableException("No vehicles available for the requested dates and seats.");
            }
            enallaktika.sort(Comparator.comparingDouble(Vehicle::getDailyRate));
            for (Vehicle oxima : enallaktika) {
                System.out.println("  " + oxima);
            }
            return null;
        }

        antistoixa.sort(Comparator.comparingDouble(Vehicle::getDailyRate));
        Vehicle epilegmeno = antistoixa.get(0);

        double ekptwsi = pelatis.getLoyaltyAccount().exargyrwsePontous(pontoiGiaExargyrosi);
        String rentalId = dimiourgiseRentalId();

        Rental enoikiasi = new Rental(rentalId, pelatis, epilegmeno, arxi, meres, extraYpiresies, ekptwsi);

        epilegmeno.prostheseEnoikiasi(enoikiasi);
        pelatis.prostheseEnoikiasi(enoikiasi);
        enoikiaseis.add(enoikiasi);

        pelatis.getLoyaltyAccount().prosthesePontous(enoikiasi.ypologiseSynolikoKostos());

        enoikiasi.ektypwseTimologio();
        return enoikiasi;
    }

    public Rental vresEnoikiasiMeId(String rentalId) throws RentalNotFoundException {
        for (Rental enoikiasi : enoikiaseis) {
            if (enoikiasi.getRentalId().equalsIgnoreCase(rentalId)) {
                return enoikiasi;
            }
        }
        throw new RentalNotFoundException("Rental not found: " + rentalId);
    }

    private ArrayList<Vehicle> vresDiathesimaOximata(LocalDate arxi, int meres, String katigoria, int apaitoumenesTheseis) {
        ArrayList<Vehicle> lista = new ArrayList<Vehicle>();
        for (Vehicle oxima : oximata) {
            boolean swstiKatigoria = (katigoria == null) || oxima.getCategory().equalsIgnoreCase(katigoria);
            if (swstiKatigoria && oxima.getSeats() >= apaitoumenesTheseis && oxima.einaiDiathesimo(arxi, meres)) {
                lista.add(oxima);
            }
        }
        return lista;
    }

    public void deikseDiathesimotita(LocalDate arxi, int meres) {
        LocalDate telos = arxi.plusDays(meres - 1);
        System.out.println("=== Vehicle Availability (" + arxi + " to " + telos + ") ===");
        for (Vehicle oxima : oximata) {
            if (oxima.einaiDiathesimo(arxi, meres)) {
                System.out.println("[AVAILABLE]     " + oxima);
            } else {
                System.out.println("[NOT AVAILABLE] " + oxima);
                for (Rental enoikiasi : oxima.getRentals()) {
                    if (enoikiasi.epikaliptetai(arxi, telos)) {
                        System.out.println("   -> " + enoikiasi);
                    }
                }
            }
        }
    }

    private void ektypwseListaEnoikiasewn(List<Rental> lista) {
        System.out.println("=== Rental History ===");
        if (lista.isEmpty()) {
            System.out.println("No rentals found.");
        } else {
            for (Rental enoikiasi : lista) {
                System.out.println(enoikiasi);
            }
        }
    }

    public void deikseIstorikoPelatiMeTaftotita(String arTaftotitas) throws CustomerNotFoundException {
        Customer pelatis = vresPelatiMeTaftotita(arTaftotitas);
        deikseIstorikoPelati(pelatis);
    }

    public void deikseIstorikoPelatiMeLoyalty(String loyaltyCardId) throws CustomerNotFoundException {
        Customer pelatis = vresPelatiMeLoyaltyCard(loyaltyCardId);
        deikseIstorikoPelati(pelatis);
    }

    private void deikseIstorikoPelati(Customer pelatis) {
        System.out.println("=== Customer Info ===");
        System.out.println(pelatis);
        ektypwseListaEnoikiasewn(pelatis.getRentalHistory());
        Rental energh = pelatis.getCurrentActiveRental();
        if (energh != null) {
            System.out.println("=== Current Active Rental Invoice ===");
            energh.ektypwseTimologio();
        }
    }

    public void deikseIstorikoOximatos(String arEggrafis) throws VehicleNotFoundException {
        Vehicle oxima = vresOximaMeArEggrafis(arEggrafis);
        System.out.println("=== Vehicle Info ===");
        System.out.println(oxima);
        if (oxima.einaiDiathesimo(LocalDate.now(), 1)) {
            System.out.println("Current Status: AVAILABLE");
        } else {
            System.out.println("Current Status: NOT AVAILABLE");
        }
        ektypwseListaEnoikiasewn(oxima.getRentals());
    }

    public void ektypwseOlaTaOximata() {
        System.out.println("=== All Vehicles (" + oximata.size() + ") ===");
        for (Vehicle oxima : oximata) {
            System.out.println(oxima);
        }
    }

    public void ektypwseOlousTousPelates() {
        System.out.println("=== All Customers (" + pelates.size() + ") ===");
        for (Customer pelatis : pelates) {
            System.out.println(pelatis);
        }
    }

    public void ektypwseOlesTisEnoikiaseis() {
        System.out.println("=== All Rentals (" + enoikiaseis.size() + ") ===");
        for (Rental enoikiasi : enoikiaseis) {
            System.out.println(enoikiasi);
        }
    }

    public ArrayList<Vehicle> getVehicles() {
        return oximata;
    }

    public ArrayList<Customer> getCustomers() {
        return pelates;
    }

    public ArrayList<Rental> getRentals() {
        return enoikiaseis;
    }

    public int getRentalCounter() {
        return metritisEnoikiasewn;
    }

    public void setRentalCounter(int metritisEnoikiasewn) {
        this.metritisEnoikiasewn = metritisEnoikiasewn;
    }
}
