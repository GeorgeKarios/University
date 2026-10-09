import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JRadioButton;
import javax.swing.JTextField;

public class ExerciseFrame extends JFrame {

    private JLabel nameLabel;
    private JLabel ageLabel;
    private JTextField nameField;
    private JTextField ageField;
    private JRadioButton uppercaseButton;
    private JRadioButton lowercaseButton;
    private JCheckBox colorsBox;
    private JCheckBox boldBox;
    private JButton showInfoButton;

    public ExerciseFrame() {
        super("2nd Test");

        nameLabel = new JLabel("Type your name:");
        ageLabel = new JLabel("Type your age:");

        nameField = new JTextField(10);
        ageField = new JTextField(3);

        uppercaseButton = new JRadioButton("Uppercase");
        lowercaseButton = new JRadioButton("Lowercase");
        colorsBox = new JCheckBox("Colors");
        boldBox = new JCheckBox("Bold");
        showInfoButton = new JButton("Show Info");

        ButtonGroup group = new ButtonGroup();
        group.add(uppercaseButton);
        group.add(lowercaseButton);

        setLayout(new FlowLayout());

        add(nameLabel);
        add(nameField);
        add(ageLabel);
        add(ageField);
        add(uppercaseButton);
        add(lowercaseButton);
        add(colorsBox);
        add(boldBox);
        add(showInfoButton);

        uppercaseButton.addActionListener(e -> nameField.setText(nameField.getText().toUpperCase()));
        lowercaseButton.addActionListener(e -> nameField.setText(nameField.getText().toLowerCase()));
        colorsBox.addActionListener(e -> changeColors());
        boldBox.addActionListener(e -> changeFont());
        showInfoButton.addActionListener(e -> showInfo());
    }

    private void changeColors() {
        if (colorsBox.isSelected()) {
            nameField.setBackground(Color.RED);
            nameField.setForeground(Color.YELLOW);
            ageField.setBackground(Color.YELLOW);
            ageField.setForeground(Color.RED);
        } else {
            nameField.setBackground(Color.WHITE);
            nameField.setForeground(Color.BLACK);
            ageField.setBackground(Color.WHITE);
            ageField.setForeground(Color.BLACK);
        }
    }

    private void changeFont() {
        if (boldBox.isSelected()) {
            nameField.setFont(new Font(nameField.getFont().getName(), Font.BOLD, nameField.getFont().getSize()));
            ageField.setFont(new Font(ageField.getFont().getName(), Font.BOLD, ageField.getFont().getSize()));
        } else {
            nameField.setFont(new Font(nameField.getFont().getName(), Font.PLAIN, nameField.getFont().getSize()));
            ageField.setFont(new Font(ageField.getFont().getName(), Font.PLAIN, ageField.getFont().getSize()));
        }
    }

    private void showInfo() {
        try {
            String name = nameField.getText();
            int age = Integer.parseInt(ageField.getText());
            JOptionPane.showMessageDialog(this, "Your name is " + name + " and you are " + age + " years old");
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Please give a valid age");
        }
    }
}
