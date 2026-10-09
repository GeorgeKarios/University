public class LoyaltyAccount {

    private static final int ELAXISTI_EXARGYROSI = 50;
    private static final int PONTOI_ANA_EURO = 1;
    private static final int PONTOI_GIA_1_EURO = 10;

    private String loyaltyCardId;
    private int pontoi;
    private static int metritisKartas = 0;

    public LoyaltyAccount() {
        metritisKartas++;
        this.loyaltyCardId = String.format("L%03d", metritisKartas);
        this.pontoi = 0;
    }

    public LoyaltyAccount(String loyaltyCardId, int pontoi) {
        this.loyaltyCardId = loyaltyCardId;
        this.pontoi = pontoi;
        if (loyaltyCardId != null && loyaltyCardId.length() > 1) {
            try {
                int ar = Integer.parseInt(loyaltyCardId.substring(1));
                if (ar > metritisKartas) {
                    metritisKartas = ar;
                }
            } catch (NumberFormatException e) {
            }
        }
    }

    public void prosthesePontous(double posoPouPlirwthike) {
        pontoi += ((int) posoPouPlirwthike) * PONTOI_ANA_EURO;
    }

    public double exargyrwsePontous(int pontoiGiaExargyrosi) {
        if (pontoiGiaExargyrosi == 0) {
            return 0;
        }
        if (pontoiGiaExargyrosi < ELAXISTI_EXARGYROSI) {
            System.out.println("Minimum redemption is " + ELAXISTI_EXARGYROSI + " points.");
            return 0;
        }
        if (pontoiGiaExargyrosi > pontoi) {
            System.out.println("Not enough points. Available: " + pontoi);
            return 0;
        }
        pontoi -= pontoiGiaExargyrosi;
        return (double) pontoiGiaExargyrosi / PONTOI_GIA_1_EURO;
    }

    public String getLoyaltyCardId() {
        return loyaltyCardId;
    }

    public int getPoints() {
        return pontoi;
    }

    public void setPoints(int pontoi) {
        this.pontoi = pontoi;
    }

    @Override
    public String toString() {
        return "Loyalty Card: " + loyaltyCardId + " | Loyalty Points: " + pontoi;
    }
}
