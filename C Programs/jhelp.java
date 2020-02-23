import java.util.Scanner;

public class jhelp
{
   public static final int BAR_CALORIES = 230;

   public static void main(String[] args)
   {
      float weightInPounds,
            heightInInches,
            caloriesInMan,
            caloriesInWoman;
      int   ageInYears;

      System.out.println("This program displays Male BMR and Female BMR for users");
      Scanner keyboard = new Scanner(System.in);
      System.out.print("Enter your weight in pounds: ");
      weightInPounds = keyboard.nextFloat();
      System.out.print("Enter your height in inches: ");
      heightInInches = keyboard.nextFloat();
      System.out.print("Enter your age in years: ");
      ageInYears = keyboard.nextInt();

      caloriesInWoman = 655 + (4.3f * weightInPounds) + (4.7f * heightInInches) - (4.7f * ageInYears);
      caloriesInMan   = 66 + (6.3f * weightInPounds) + (12.9f * heightInInches) - (6.8f * ageInYears);

      System.out.println("The number of candy bars for a female is: " + (int)(caloriesInWoman / BAR_CALORIES));
      System.out.println("The number of candy bars for a male is: " + (int)(caloriesInMan / BAR_CALORIES));
   }
}