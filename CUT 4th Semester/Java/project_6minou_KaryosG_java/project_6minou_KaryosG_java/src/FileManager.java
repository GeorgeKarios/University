import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class FileManager {

    private static final String VEHICLES_FILE = "data/vehicles.txt";
    private static final String CUSTOMERS_FILE = "data/customers.txt";
    private static final String RENTALS_FILE = "data/rentals.txt";

    public static void saveVehicles(List<Vehicle> oximata) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter(VEHICLES_FILE));
        for (Vehicle oxima : oximata) {
            writer.write(oxima.getCategory() + "|" +
                         oxima.getRegistrationNumber() + "|" +
                         oxima.getBrand() + "|" +
                         oxima.getModel() + "|" +
                         oxima.getYear() + "|" +
                         oxima.getSeats());
            writer.newLine();
        }
        writer.close();
    }

    public static void saveCustomers(List<Customer> pelates) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter(CUSTOMERS_FILE));
        for (Customer pelatis : pelates) {
            writer.write(pelatis.getFullName() + "|" +
                         pelatis.getIdNumber() + "|" +
                         pelatis.getAddress() + "|" +
                         pelatis.getPhone() + "|" +
                         pelatis.getEmail() + "|" +
                         pelatis.getCreditCardNumber() + "|" +
                         pelatis.getLoyaltyAccount().getLoyaltyCardId() + "|" +
                         pelatis.getLoyaltyAccount().getPoints());
            writer.newLine();
        }
        writer.close();
    }

    public static void saveRentals(List<Rental> enoikiaseis, int metritisEnoikiasewn) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter(RENTALS_FILE));
        writer.write("COUNTER:" + metritisEnoikiasewn);
        writer.newLine();
        for (Rental enoikiasi : enoikiaseis) {
            String extras = "";
            List<AddOnService> lista = enoikiasi.getAddOns();
            for (int i = 0; i < lista.size(); i++) {
                if (i > 0) {
                    extras += ";";
                }
                extras += lista.get(i).getName();
            }
            writer.write(enoikiasi.getRentalId() + "|" +
                         enoikiasi.getCustomer().getIdNumber() + "|" +
                         enoikiasi.getVehicle().getRegistrationNumber() + "|" +
                         enoikiasi.getStartDate() + "|" +
                         enoikiasi.getDays() + "|" +
                         enoikiasi.getDiscount() + "|" +
                         extras);
            writer.newLine();
        }
        writer.close();
    }

    public static ArrayList<Vehicle> loadVehicles() throws IOException {
        ArrayList<Vehicle> oximata = new ArrayList<Vehicle>();
        File file = new File(VEHICLES_FILE);
        if (!file.exists()) {
            return oximata;
        }

        BufferedReader reader = new BufferedReader(new FileReader(file));
        String grammi;
        while ((grammi = reader.readLine()) != null) {
            String[] merh = grammi.split("\\|");
            if (merh.length < 6) {
                continue;
            }
            Vehicle oxima = createVehicle(merh[0], merh[1], merh[2], merh[3],
                                          Integer.parseInt(merh[4]), Integer.parseInt(merh[5]));
            if (oxima != null) {
                oximata.add(oxima);
            }
        }
        reader.close();
        return oximata;
    }

    public static ArrayList<Customer> loadCustomers() throws IOException {
        ArrayList<Customer> pelates = new ArrayList<Customer>();
        File file = new File(CUSTOMERS_FILE);
        if (!file.exists()) {
            return pelates;
        }

        BufferedReader reader = new BufferedReader(new FileReader(file));
        String grammi;
        while ((grammi = reader.readLine()) != null) {
            String[] merh = grammi.split("\\|");
            if (merh.length < 8) {
                continue;
            }
            Customer pelatis = new Customer(merh[0], merh[1], merh[2], merh[3], merh[4], merh[5], merh[6], Integer.parseInt(merh[7]));
            pelates.add(pelatis);
        }
        reader.close();
        return pelates;
    }

    public static int loadRentals(List<Rental> enoikiaseis, List<Vehicle> oximata, List<Customer> pelates) throws IOException {
        int metritis = 0;
        File file = new File(RENTALS_FILE);
        if (!file.exists()) {
            return metritis;
        }

        BufferedReader reader = new BufferedReader(new FileReader(file));
        String grammi;
        while ((grammi = reader.readLine()) != null) {
            if (grammi.startsWith("COUNTER:")) {
                metritis = Integer.parseInt(grammi.split(":")[1]);
                continue;
            }

            String[] merh = grammi.split("\\|");
            if (merh.length < 6) {
                continue;
            }

            String rentalId = merh[0];
            String customerId = merh[1];
            String vehicleReg = merh[2];
            LocalDate arxi = LocalDate.parse(merh[3]);
            int meres = Integer.parseInt(merh[4]);
            double ekptwsi = Double.parseDouble(merh[5]);
            String extras = merh.length > 6 ? merh[6] : "";

            Customer pelatis = vresPelati(pelates, customerId);
            Vehicle oxima = vresOxima(oximata, vehicleReg);

            if (pelatis != null && oxima != null) {
                ArrayList<AddOnService> yp = parseAddOns(extras);
                Rental enoikiasi = new Rental(rentalId, pelatis, oxima, arxi, meres, yp, ekptwsi);
                enoikiaseis.add(enoikiasi);
                pelatis.prostheseEnoikiasi(enoikiasi);
                oxima.prostheseEnoikiasi(enoikiasi);
            }
        }
        reader.close();
        return metritis;
    }

    public static Vehicle createVehicle(String katigoria, String arEggrafis, String marka, String montelo, int etos, int theseis) {
        if (katigoria.equals("EconomyCar")) {
            return new EconomyCar(arEggrafis, marka, montelo, etos, theseis);
        } else if (katigoria.equals("SUV")) {
            return new SUV(arEggrafis, marka, montelo, etos, theseis);
        } else if (katigoria.equals("Convertible")) {
            return new Convertible(arEggrafis, marka, montelo, etos, theseis);
        } else if (katigoria.equals("LuxuryCar")) {
            return new LuxuryCar(arEggrafis, marka, montelo, etos, theseis);
        }
        return null;
    }

    private static ArrayList<AddOnService> parseAddOns(String extras) {
        ArrayList<AddOnService> lista = new ArrayList<AddOnService>();
        if (extras == null || extras.equals("")) {
            return lista;
        }
        String[] merh = extras.split(";");
        for (int i = 0; i < merh.length; i++) {
            if (merh[i].equals("GPS/Navigation")) {
                lista.add(new GPSService());
            } else if (merh[i].equals("Child Seat")) {
                lista.add(new ChildSeatService());
            } else if (merh[i].equals("Additional Insurance")) {
                lista.add(new AdditionalInsuranceService());
            }
        }
        return lista;
    }

    private static Customer vresPelati(List<Customer> pelates, String arTaftotitas) {
        for (Customer pelatis : pelates) {
            if (pelatis.getIdNumber().equals(arTaftotitas)) {
                return pelatis;
            }
        }
        return null;
    }

    private static Vehicle vresOxima(List<Vehicle> oximata, String arEggrafis) {
        for (Vehicle oxima : oximata) {
            if (oxima.getRegistrationNumber().equals(arEggrafis)) {
                return oxima;
            }
        }
        return null;
    }

    public static void ensureDataFolder() {
        new File("data").mkdirs();
    }
}
