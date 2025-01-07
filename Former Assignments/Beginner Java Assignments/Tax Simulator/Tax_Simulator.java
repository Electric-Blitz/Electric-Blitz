/* Author: Zachary (Zeke) Kent
 * Tax Simulator
 * 
 * Input an amount. The program will then calculate a static state
 *  and county tax before returning the overall total.
 * 
 * [Like with all assignments from college courses, some code may be adjusted
 *  so as to prevent information unrelated to code itself or to prevent being
 *  used in similar assignments by others.]
 */

import java.util.Scanner;           //Allows system.in with scanners

public class Tax_Simulator {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner (System.in);     //Takes input from keyboard
        double amount;
        double total;
        double stateTax;
        double countyTax;
        double totalTax;                                //Declarations
        
        System.out.print("Please enter purchase amount: ");
        amount = keyboard.nextDouble();
        System.out.println("");                         //Asking user input of amount
        
        System.out.println("Purchase amount: $" + amount);
        System.out.println("");                         //Output amount.
        
        stateTax = amount * 0.04;
        System.out.println("State Tax: $" + stateTax);
        System.out.println("");                         //Calculates then outputs state tax
        
        countyTax = amount * 0.02;
        System.out.println("County Tax: $" + countyTax);
        System.out.println("");                         //Calculates then outputs county tax
        
        totalTax = stateTax + countyTax;
        System.out.println("Total tax: $" + totalTax);
        System.out.println("");                         //Calculates then outputs total tax
        
        System.out.println("-----------------------");
        total = totalTax + amount;
        System.out.println("Total cost: $" + total);    //Calculates then outputs the overall total.

        keyboard.close();
    }
    
}