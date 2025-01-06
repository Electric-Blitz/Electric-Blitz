/* Author: Zachary (Zeke) Kent
 * Petri Dish Simulator
 * 
 * This program asks for the amount of subjects (organisms), the daily pop.
 *  increase, and the # of days watched. It will then show the size of the
 *  population for every day within the given amount of days.
 * 
 * [Like with all assignments from college courses, some code may be adjusted
 *  so as to prevent information unrelated to code itself or to prevent being
 *  used in similar assignments by others.]
 */

import java.util.Scanner; //Allows ability to use system.in with scanners

public class Petri_Dish {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in); // Takes input from keyboard
        double organisms; // Amount of subjects
        double popIncrease; // daily pop. increase
        int daysGiven; // Days organisms are multiplied
        int dayCounter; // to increment the for loop
        double newAmount = 0; // To add the new amount of organisms
                              // with original subjects

        System.out.println("Hello and thank you for choosing this");
        System.out.println("Petri Dish Simulator!");
        System.out.println(""); // Greeting

        System.out.println("To begin, please enter the starting # of organisms.");
        System.out.println("Note: Starting amount must be 2 or higher.");
        // Prompt for subjects
        System.out.println("");
        System.out.print("# of Organisms: ");
        organisms = keyboard.nextInt(); // User input of organisms

        while (organisms < 2) {
            System.out.println("Invalid. Starting organism count must exceed 2.");
            System.out.print("Try again: ");
            organisms = keyboard.nextInt(); // Checking for invalid input.
        }

        System.out.println("");
        System.out.println("Next, please enter the daily population increase.");
        System.out.println("Note: Give pop. increase as a decimal percentage.");
        System.out.println("Ex. '0.5', '0.75', '0.26', etc.");
        // Prompt for pop increase
        // limited to percentages.
        System.out.println("");
        System.out.print("Daily pop. Increase: ");
        popIncrease = keyboard.nextDouble(); // User input of pop increase

        while (popIncrease < 0 || popIncrease > 1) {
            System.out.println("Invalid. Population increase must be a positive");
            System.out.println("percentage given as a decimal (ex. 0.5).");
            System.out.println("Try again: ");
            popIncrease = keyboard.nextDouble(); // Checking for invalid input.
        }

        System.out.println("");
        System.out.println("Finally, enter the number of days to simulate.");
        System.out.println("Note: Must be a positive, whole number.");
        // Prompt for # of days.
        System.out.println("");
        System.out.print("Days to simulate: ");
        daysGiven = keyboard.nextInt(); // User input of days

        while (daysGiven < 1) {
            System.out.println("Invalid. You can't simulate less than 1 day.");
            System.out.print("Try again: ");
            daysGiven = keyboard.nextInt(); // Checking for invalid input.
        }

        System.out.println("Day" + "\t\t" + "Organisms");
        System.out.println("--------------------------");
        // Top of chart.

        if (popIncrease == 1) // If 100% or '1'
        {
            popIncrease = 2; // 100% = doubled
            for (dayCounter = 1; dayCounter <= daysGiven; dayCounter++) {
                if (dayCounter == 1) // 1st day = starting amount.
                {
                    System.out.println(dayCounter + "\t\t" + organisms);
                } else // Every day after is double
                { // previous day's amount.
                    System.out.println(dayCounter + "\t\t" + (organisms * popIncrease));
                    organisms = (organisms * popIncrease);
                }
            }
        } else // If percentage other than 100%
        {
            for (dayCounter = 1; dayCounter <= daysGiven; dayCounter++) { // To increment the # of days given.

                System.out.println(dayCounter + "\t\t" + (organisms + (newAmount * popIncrease)));
                newAmount = organisms + (newAmount * popIncrease);
                organisms = newAmount; // With newAmount = 0, the 1st day is original
                                       // amount. Each day after, the previous
                                       // amount is saved into both organisms and
                                       // newAmount so the equeation will be correct.
            }
        }

        keyboard.close();
        System.out.println("");
        System.out.println("Thank you for using this Petri Dish Simulator.");
        System.out.println("We hope you enjoyed. Goodbye.");
    }

}