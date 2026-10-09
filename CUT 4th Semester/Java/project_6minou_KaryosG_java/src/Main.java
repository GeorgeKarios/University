import java.io.IOException;
import java.time.LocalDate;
import java.time.format.DateTimeParseException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    private static RentalSystem systima = new RentalSystem();
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        FileManager.ensureDataFolder();
        fortwseDedomena();

        boolean trexei = true;
        while (trexei) {
            ektypwseKyrioMenu();
            int epilogi = diavaseInt();
            switch (epilogi) {
                case 1:
                    menuOximatwn();
                    break;
                case 2:
                    menuPelatwn();
                    break;
                case 3:
                    menuDimiourgiasEnoikiasis();
                    break;
                case 4:
                    menuTimologiou();
                    break;
                case 5:
                    menuDiathesimotitas();
                    break;
                case 6:
                    menuIstorikouPelati();
                    break;
                case 7:
                    menuIstorikouOximatos();
                    break;
                case 8:
                    menuEktypwsewn();
                    break;
                case 0:
                    System.out.println("Goodbye!");
                    trexei = false;
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
        }
        scanner.close();
    }

    private static void ektypwseKyrioMenu() {
        System.out.println();
        System.out.println("========================================");
        System.out.println("  Car Rental Management System");
        System.out.println("========================================");
        System.out.println("1. Vehicle Management (Add/Remove)");
        System.out.println("2. Customer Management (Register/Search)");
        System.out.println("3. Create Rental");
        System.out.println("4. Print Invoice");
        System.out.println("5. Show Vehicle Availability");
        System.out.println("6. Show Customer History");
        System.out.println("7. Show Vehicle History");
        System.out.println("8. Print All Data");
        System.out.println("0. Exit");
        System.out.print("Choose: ");
    }

    private static void menuOximatwn() {
        boolean piso = false;
        while (!piso) {
            System.out.println();
            System.out.println("-- Vehicle Management --");
            System.out.println("1. Add Vehicle");
            System.out.println("2. Remove Vehicle");
            System.out.println("0. Back");
            System.out.print("Choose: ");
            int epilogi = diavaseInt();
            switch (epilogi) {
                case 1:
                    prosthikiOximatos();
                    break;
                case 2:
                    diagrafiOximatos();
                    break;
                case 0:
                    piso = true;
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
        }
    }

    private static void menuPelatwn() {
        boolean piso = false;
        while (!piso) {
            System.out.println();
            System.out.println("-- Customer Management --");
            System.out.println("1. Register Customer");
            System.out.println("2. Search by ID Number");
            System.out.println("3. Search by Loyalty Card");
            System.out.println("0. Back");
            System.out.print("Choose: ");
            int epilogi = diavaseInt();
            switch (epilogi) {
                case 1:
                    kataxorisiPelati();
                    break;
                case 2:
                    anazitisiPelatiMeTaftotita();
                    break;
                case 3:
                    anazitisiPelatiMeLoyalty();
                    break;
                case 0:
                    piso = true;
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
        }
    }

    private static void menuEktypwsewn() {
        boolean piso = false;
        while (!piso) {
            System.out.println();
            System.out.println("-- Print All Data --");
            System.out.println("1. All Vehicles");
            System.out.println("2. All Customers");
            System.out.println("3. All Rentals");
            System.out.println("4. All of the above");
            System.out.println("0. Back");
            System.out.print("Choose: ");
            int epilogi = diavaseInt();
            switch (epilogi) {
                case 1:
                    systima.ektypwseOlaTaOximata();
                    break;
                case 2:
                    systima.ektypwseOlousTousPelates();
                    break;
                case 3:
                    systima.ektypwseOlesTisEnoikiaseis();
                    break;
                case 4:
                    systima.ektypwseOlaTaOximata();
                    systima.ektypwseOlousTousPelates();
                    systima.ektypwseOlesTisEnoikiaseis();
                    break;
                case 0:
                    piso = true;
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
        }
    }

    private static void prosthikiOximatos() {
        System.out.println("Categories: EconomyCar, SUV, Convertible, LuxuryCar");
        System.out.print("Category: ");
        String katigoria = scanner.nextLine().trim();

        int[] oria = systima.pareOrioThesewn(katigoria);
        if (oria == null) {
            System.out.println("Invalid category.");
            return;
        }

        System.out.print("Registration Number: ");
        String arEggrafis = scanner.nextLine().trim();
        System.out.print("Brand: ");
        String marka = scanner.nextLine().trim();
        System.out.print("Model: ");
        String montelo = scanner.nextLine().trim();
        System.out.print("Year: ");
        int etos = diavaseInt();
        System.out.print("Seats (" + oria[0] + "-" + oria[1] + "): ");
        int theseis = diavaseInt();

        try {
            systima.prostheseOxima(katigoria, arEggrafis, marka, montelo, etos, theseis);
            apothikefseDedomena();
        } catch (VehicleAlreadyExistsException e) {
            System.out.println("Error: " + e.getMessage());
        } catch (InvalidVehicleDataException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    private static void diagrafiOximatos() {
        System.out.print("Registration Number: ");
        String arEggrafis = scanner.nextLine().trim();
        try {
            systima.diagrapseOxima(arEggrafis);
            apothikefseDedomena();
        } catch (VehicleNotFoundException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    private static void kataxorisiPelati() {
        System.out.print("Full Name: ");
        String onoma = scanner.nextLine().trim();
        System.out.print("ID Number: ");
        String taftotita = scanner.nextLine().trim();
        System.out.print("Address: ");
        String dieythinsi = scanner.nextLine().trim();
        System.out.print("Phone: ");
        String tilefwno = scanner.nextLine().trim();
        System.out.print("Email: ");
        String email = scanner.nextLine().trim();
        System.out.print("Credit Card Number: ");
        String karta = scanner.nextLine().trim();

        try {
            systima.kataxorisePelati(onoma, taftotita, dieythinsi, tilefwno, email, karta);
            apothikefseDedomena();
        } catch (CustomerAlreadyExistsException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    private static void anazitisiPelatiMeTaftotita() {
        System.out.print("Customer ID Number: ");
        String taftotita = scanner.nextLine().trim();
        try {
            systima.deikseIstorikoPelatiMeTaftotita(taftotita);
        } catch (CustomerNotFoundException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    private static void anazitisiPelatiMeLoyalty() {
        System.out.print("Loyalty Card ID: ");
        String loyalty = scanner.nextLine().trim();
        try {
            systima.deikseIstorikoPelatiMeLoyalty(loyalty);
        } catch (CustomerNotFoundException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    private static void menuDimiourgiasEnoikiasis() {
        System.out.print("Customer ID Number: ");
        String taftotita = scanner.nextLine().trim();
        Customer pelatis;
        try {
            pelatis = systima.vresPelatiMeTaftotita(taftotita);
        } catch (CustomerNotFoundException e) {
            System.out.println("Error: " + e.getMessage());
            return;
        }

        System.out.print("Start Date (YYYY-MM-DD): ");
        LocalDate arxi;
        try {
            arxi = LocalDate.parse(scanner.nextLine().trim());
        } catch (DateTimeParseException e) {
            System.out.println("Invalid date format.");
            return;
        }

        System.out.print("Duration (days): ");
        int meres = diavaseInt();

        System.out.print("Category (EconomyCar / SUV / Convertible / LuxuryCar): ");
        String katigoria = scanner.nextLine().trim();

        System.out.print("Required Seats: ");
        int theseis = diavaseInt();

        ArrayList<AddOnService> extras = new ArrayList<AddOnService>();
        System.out.print("Add GPS/Navigation? (y/n): ");
        if (scanner.nextLine().trim().equalsIgnoreCase("y")) {
            extras.add(new GPSService());
        }
        System.out.print("Add Child Seat? (y/n): ");
        if (scanner.nextLine().trim().equalsIgnoreCase("y")) {
            extras.add(new ChildSeatService());
        }
        System.out.print("Add Additional Insurance? (y/n): ");
        if (scanner.nextLine().trim().equalsIgnoreCase("y")) {
            extras.add(new AdditionalInsuranceService());
        }
        int pontoiGiaExargyrosi = 0;
        int diathesimoiPontoi = pelatis.getLoyaltyAccount().getPoints();
        if (diathesimoiPontoi >= 50) {
            System.out.println("You have " + diathesimoiPontoi + " loyalty points.");
            System.out.print("How many points to redeem? (0 to skip): ");
            pontoiGiaExargyrosi = diavaseInt();
        }
        try {
            Rental enoikiasi = systima.dimiourgiseEnoikiasi(pelatis, arxi, meres, katigoria, theseis, extras, pontoiGiaExargyrosi);
            if (enoikiasi != null) {
                apothikefseDedomena();
            }
        } catch (NoVehicleAvailableException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
    private static void menuTimologiou() {
        System.out.print("Rental ID: ");
        String rentalId = scanner.nextLine().trim();
        try {
            Rental enoikiasi = systima.vresEnoikiasiMeId(rentalId);
            enoikiasi.ektypwseTimologio();
        } catch (RentalNotFoundException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
    private static void menuDiathesimotitas() {
        System.out.print("Start Date (YYYY-MM-DD): ");
        LocalDate arxi;
        try {
            arxi = LocalDate.parse(scanner.nextLine().trim());
        } catch (DateTimeParseException e) {
            System.out.println("Invalid date format.");
            return;
        }
        System.out.print("Duration (days): ");
        int meres = diavaseInt();
        systima.deikseDiathesimotita(arxi, meres);
    }
    private static void menuIstorikouPelati() {
        System.out.println("1. Search by ID Number");
        System.out.println("2. Search by Loyalty Card");
        System.out.print("Choose: ");
        int epilogi = diavaseInt();
        if (epilogi == 1) {
            anazitisiPelatiMeTaftotita();
        } else if (epilogi == 2) {
            anazitisiPelatiMeLoyalty();
        } else {
            System.out.println("Invalid choice.");
        }
    }

    private static void menuIstorikouOximatos() {
        System.out.print("Registration Number: ");
        String arEggrafis = scanner.nextLine().trim();
        try {
            systima.deikseIstorikoOximatos(arEggrafis);
        } catch (VehicleNotFoundException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    private static void fortwseDedomena() {
        try {
            ArrayList<Vehicle> oximata = FileManager.loadVehicles();
            ArrayList<Customer> pelates = FileManager.loadCustomers();
            ArrayList<Rental> enoikiaseis = new ArrayList<Rental>();
            int metritis = FileManager.loadRentals(enoikiaseis, oximata, pelates);

            systima.getVehicles().addAll(oximata);
            systima.getCustomers().addAll(pelates);
            systima.getRentals().addAll(enoikiaseis);
            systima.setRentalCounter(metritis);

            System.out.println("Data loaded: " + oximata.size() + "vehicles, " + pelates.size() +
                               " customers, " + enoikiaseis.size() + "rentals.");
        } catch (IOException e) {
            System.out.println("No existing data found. Starting fresh.");
        }
    }

    private static void apothikefseDedomena() {
        try {
            FileManager.saveVehicles(systima.getVehicles());
            FileManager.saveCustomers(systima.getCustomers());
            FileManager.saveRentals(systima.getRentals(), systima.getRentalCounter());
        } catch (IOException e) {
            System.out.println("Error saving data: " + e.getMessage());
        }
    }

    private static int diavaseInt() {
        try {
            return Integer.parseInt(scanner.nextLine().trim());
        } catch (NumberFormatException e) {
            System.out.println("Invalid number");
            return -1;
        }
    }
}
