LAB 7 - Java Swing GUI

Exercise 1:
Run Exercise1Test.java.
The program opens a calculator window with two text fields and four buttons:
+, -, *, /.
Each button calculates the result and shows it in a pop-up message.

Exercise 2:
Run ExerciseTest.java.
This class creates an ExerciseFrame exactly as required:
ExerciseFrame frame = new ExerciseFrame();
frame.setSize(750, 75);
frame.setVisible(true);
frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

The GUI includes:
name field
age field
Uppercase
Lowercase
Colors
Bold
Show Info

Compile from terminal:
javac src/*.java

Run exercise 1:
java -cp src Exercise1Test

Run exercise 2:
java -cp src ExerciseTest
