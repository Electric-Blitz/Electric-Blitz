/* Author: Zachary (Zeke) Kent
 * Bank Check Fees
 * 
 * User inputs number of checks to be written this month
 * and calculate the fees resulted.
 * 
 * [Like with all assignments from college courses, some code may be adjusted
 *  so as to prevent information unrelated to code itself or to prevent being
 *  used in similar assignments by others.]
 */

 import java.util.Scanner;           //Allows ability to use system.in with scanners

public class BankCheckFees {

    public static void main(String[] args) {
        Scanner keyboard = new Scanner (System.in);     //Takes input from keyboard.
        int checks;                                     //User input.
        double total = 0;                               //total of bank fee initialized as 0.
        double base = 10.00;                            //Base fee before additional fee.
        double fee = 0;                                 //Fee depending on amount of checks.
        int counter = 1;                                //To go through the while loops.
        
        System.out.print("Enter the number of checks written this month: ");
        checks = keyboard.nextInt();
        System.out.print("");                           //Asking user for amount of checks.
        
        while (checks < 20 && counter == 1)             //While amount of checks less than 20.
        {
        fee += 0.10;
        counter--;
        }
        
        while (checks >= 20 && checks <= 39 && counter == 1)
        {
        fee = 0.08;                                     //While checks is between 20-39.
        counter--;
        }
        
        while (checks >= 40 && checks <= 59 && counter == 1)
        {
        fee = 0.06;                                     //While checks is between 40-59.
        counter--;
        }
        
        while (checks >= 60 && counter == 1)            //While checks are more than 60.
        {
        fee = 0.04;
        counter--;
        }
        
        total = base + fee;                             //Total is base and determined fee.
        System.out.print("The total fees are: $" + total);
    }
}