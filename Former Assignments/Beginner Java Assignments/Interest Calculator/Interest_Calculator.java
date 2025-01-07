/* Author: Zachary (Zeke) Kent
 * Interest Calculator
 * 
 * User provides a desired amount of earnings that they would like to see from
 *  an investment. They also provides an annual interest rate and the number
 *  of years the user would like to see that result by. The calculator then
 *  provides how much money would need to be deposited to begin.
 * 
 * [Like with all assignments from college courses, some code may be adjusted
 *  so as to prevent information unrelated to code itself or to prevent being
 *  used in similar assignments by others.]
 */
import java.text.DecimalFormat;
import java.util.Scanner;

public class Interest_Calculator {

    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in); // Takes input from keyboard
        double P; // Present value, amount to deposit today.
        double F; // future value, amount desired.
        double r; // annual interest rate.
        int n; // number of years to let money sit.
        char again; // To see if the user wants to type more combinations.

        System.out.println("Hello and thank you for choosing the Electric Blitz");
        System.out.println("Favour Foundation (EBFF) Interest Determiner!");
        System.out.println(""); // Greeting

        do {

            System.out.println("What is the desired future amount you seek? ");
            F = keyboard.nextDouble(); // User input of future value

            System.out.println("What is the annual interest rate? ");
            r = keyboard.nextDouble();

            System.out.println("For how many years? ");
            n = keyboard.nextInt();

            P = presentValue(F, r, n);

            DecimalFormat changer = new DecimalFormat("#0.00");

            System.out.println("You need to invest: $" + changer.format(P));
            System.out.println("");

            System.out.println("Do you want to try different values?");
            System.out.println("Type 'y' for yes, or any other letter for no.");
            again = keyboard.next().charAt(0);

            System.out.println("");
            System.out.println("");

        } while (again == 'y' || again == 'Y');

    }

    public static double presentValue(double future, double annual, int years) {
        double present;

        present = future / Math.pow(1 + annual, years);

        return present;
    }
}