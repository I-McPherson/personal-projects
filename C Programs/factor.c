/**********************************************************************/
/*                                                                    */
/* Program Name: Factor Finder - Find every factor of a user's input  */
/* Author:       Ian McPherson                                        */
/* Date Written: December 6, 2019                                     */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* This program will read in a user's input and then will find every  */
/* factor for that number.  It will then print that and then          */
/* terminate the program and print a goodbye message.                 */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                            Includes                                */
/**********************************************************************/
#include <stdio.h> /* scanf(), printf()                               */
#include <ctype.h> /* tolower()                                       */

/**********************************************************************/
/*                        Symbolic Constants                          */
/**********************************************************************/
#define PROGRAM_NAME    "Factor Finder" /* What the program is        */
#define PROGRAM_NUMBER  1               /* The number of the program  */
#define PROGRAMMER_NAME "McPherson"     /* Programmer's last name     */

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
void print_instructions();
char get_response();
void factor_finder(int user_input);

/**********************************************************************/
/*                          Main Function                             */
/**********************************************************************/
int main()
{
   int user_input;

   print_heading();
   while (print_instructions(), get_response() == 'y')
   {
      printf("\nPlease enter the number you want factored: ");
      scanf ("%d", &user_input);
      factor_finder(user_input);
   }

   printf("\n\nThank you for using my factoring program!");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                    Print the program heading                       */
/**********************************************************************/
void print_heading()
{
   printf("\n\n\n\n\n\n");
   printf("\n========================================================");
   printf("\n                Program Number: %d", PROGRAM_NUMBER);
   printf("\n                Programmer: %s",     PROGRAMMER_NAME);
   printf("\n                Program Name: %s",   PROGRAM_NAME);
   printf("\n========================================================");
   return;
}

/**********************************************************************/
/*                Print the program instructions                      */
/**********************************************************************/
void print_instructions()
{
   printf("\n\n   This program will read in your number and find");
   printf(  "\n   every factor of that number, down to zero.");
   return;
}

/**********************************************************************/
/*                Get the response to continue or quit                */
/**********************************************************************/
char get_response()
{
   char response[2]; /* Stores the menu option entered by the user    */

   do
   {
      printf("\n\nDo you want to enter another number to");
      printf(" factor  (y or n): ");
      scanf("%1s", &response[0]);
      response[0] = tolower(response[0]);
   } 
   while ((response[0] != 'y') && (response[0] != 'n'));
   return response[0];
}

/**********************************************************************/
/*                Find all factors for a user's input                 */
/**********************************************************************/
void factor_finder(int user_input)
{
   int factor_checker,
       factor_complete,
       factors = 1;

   while (factors != user_input / 2 && factors != user_input / -2 && 
          factors != 0)
   {
      factor_checker = user_input % factors;
      if (factor_checker == 0)
      {
         factor_complete = user_input / factors;
         printf("\n%-10d|%10d", factors, factor_complete);
         printf("\n---------------------");
         if (user_input == 0)
      printf("\nThere are no factors");
      }
      factors++;
   }
   return;
}