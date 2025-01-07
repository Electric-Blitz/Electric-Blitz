/* Author: Zachary (Zeke) Kent
 * Enum Practice
 * 
 * Displaying basic knowledge of enumerated types in assignment.
 * 
 * [Like with all assignments from college courses, some code may be adjusted
 *  so as to prevent information unrelated to code itself or to prevent being
 *  used in similar assignments by others.]
 */
public class Enum_Practice {
    
    enum Color {RED, BLUE, GREEN, YELLOW}           //Color enumerated type

    public static void main(String[] args) 
    {
        Color color1 = Color.RED;                   
        Color color2 = Color.YELLOW;                //Declares variables color1, color2 and assigns RED & YELLOW to them repsectively.
        
        System.out.println("color1's name is " + color1);
        System.out.println("color2's name is " + color2);
        System.out.println("");                     //displays what value is in the variables.
        
        System.out.println("color1's ordinal is " + color1.ordinal());
        System.out.println("color2's ordinal is " + color2.ordinal());
        System.out.println("");                     //Returns the int value of the variables
        
        System.out.println("color1.equals(color2) returns " + color1.equals(color2));
        System.out.println("");                     //prints true if color1 is the same as color2. If they are different, false is printed.
        
        System.out.println("color1.toString() returns " + color1.toString());
        System.out.println("");                     //Returns the name of variable as a string.
        
        System.out.println("color1.compareTo(color2) returns " + color1.compareTo(color2));
                                                    //Returns the difference in ordinals between color2 & color1.
                                                    //EX. color1 - color2 = -3
    }
    
}
