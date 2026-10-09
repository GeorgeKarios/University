import java.awt.FlowLayout;
import java.awt.GridLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class Exercise1Frame extends JFrame {

    private JTextField firstNumber;
    private JTextField secondNumber;
    private JButton addButton;
    private JButton subtractButton;
    private JButton multiplyButton;
    private JButton divideButton;

    public Exercise1Frame() {
        super("Calculator");

        firstNumber = new JTextField(7);
        secondNumber = new JTextField(7);

        addButton = new JButton("+");
        subtractButton = new JButton("-");
        multiplyButton = new JButton("*");
        divideButton = new JButton("/");

        JPanel numbersPanel = new JPanel();
        numbersPanel.setLayout(new FlowLayout());
        numbersPanel.add(firstNumber);
        numbersPanel.add(secondNumber);

        JPanel buttonsPanel = new JPanel();
        buttonsPanel.setLayout(new GridLayout(2, 2, 5, 5));
        buttonsPanel.add(addButton);
        buttonsPanel.add(subtractButton);
        buttonsPanel.add(multiplyButton);
        buttonsPanel.add(divideButton);

        setLayout(new GridLayout(2, 1, 5, 5));
        add(numbersPanel);
        add(buttonsPanel);

        addButton.addActionListener(e -> showResult("+"));
        subtractButton.addActionListener(e -> showResult("-"));
        multiplyButton.addActionListener(e -> showResult("*"));
        divideButton.addActionListener(e -> showResult("/"));
    }

    private void showResult(String symbol) {
        try {
            int number1 = Integer.parseInt(firstNumber.getText());
            int number2 = Integer.parseInt(secondNumber.getText());
            int result = 0;

            if (symbol.equals("+")) {
                result = number1 + number2;
            } else if (symbol.equals("-")) {
                result = number1 - number2;
            } else if (symbol.equals("*")) {
                result = number1 * number2;
            } else if (symbol.equals("/")) {
                if (number2 == 0) {
                    JOptionPane.showMessageDialog(this, "Cannot divide by zero");
                    return;
                }
                result = number1 / number2;
            }

            JOptionPane.showMessageDialog(this, result);
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Please give valid numbers");
        }
    }
}
