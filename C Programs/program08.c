/*************************************************************************
 CLASS INFORMATION
 -----------------
   Program Name: program08.c
   Programmer:   Ian McPherson
   Instructor:   Mrs. Miller for CS 214-3, C Programming
   Date Due:     04/04/2019

 DOCUMENTATION
 -------------
   This program will create a table with the user's specified size and
   type.
 ************************************************************************/
#include <stdio.h>

#define PATTERN1 '1'
#define PATTERN2 '2'
#define PATTERN3 '3'
#define PATTERN4 '4'
#define SIZE_MIN 2
#define SIZE_MAX 9
#define QUIT     '5'

void printInstructions ();
void printMenu();
char getMenuChoice();
int  getUserValue();
void displayPattern1(int value);
void displayPattern2(int value);
void displayPattern3(int value);
void displayPattern4(int value);
void printGoodbye();

int main ()
{
   printInstructions();
   printMenu();

   switch (getMenuChoice())
   {
      case PATTERN1:
         displayPattern1(getUserValue());
         break;
      case PATTERN2:
         displayPattern2(getUserValue());
         break;
      case PATTERN3:
         displayPattern3(getUserValue());
         break;
      case PATTERN4:
         displayPattern4(getUserValue());
         break;
      case QUIT:
         printf("\nEnding the program\n");
         break;
   }

   printGoodbye();

   return 0;
}

/*************************************************************************
  Prints the instructions.
*************************************************************************/
void printInstructions()
{
   printf("\n\n|-----------------------------------------|\n");
   printf("|       McPHERSON PATTERN GENERATOR       |\n");
   printf("|-----------------------------------------|\n");
   printf("|               INSTRUCTIONS              |\n");
   printf("|-----------------------------------------|\n");
   printf("|   Please enter the number that corres-  |\n");
   printf("|  ponds with the pattern that you would  |\n");
   printf("|   like, followed by your number that    |\n");
   printf("|    determines the size of the table     |\n");
   printf("|        you would like generated.        |\n");
   printf("|   Please only enter numbers %d - %d to    |\n", SIZE_MIN,
           SIZE_MAX);
   printf("|  generate a table of your desired size  |\n");

   return;
}

/*************************************************************************
  Prints the menu.
*************************************************************************/
void printMenu()
{
   printf("|-----------------------------------------| \n");
   printf("|Type in '%c' to generate pattern 1        |\n", PATTERN1);
   printf("|-----------------------------------------| \n");
   printf("|Type in '%c' to generate pattern 2        |\n", PATTERN2);
   printf("|-----------------------------------------| \n");
   printf("|Type in '%c' to generate pattern 3        |\n", PATTERN3);
   printf("|-----------------------------------------| \n");
   printf("|Type in '%c' to generate pattern 4        |\n", PATTERN4);
   printf("|-----------------------------------------| \n");
   printf("|Type in '%c' to quit the program          |\n", QUIT);
   printf("|-----------------------------------------| \n");

   return;
}

/*************************************************************************
  Gets the user's input for the type of table.
*************************************************************************/
char getMenuChoice()
{
   char menuChoiceInput;

   printf("\n>>> ");
   scanf(" %c", &menuChoiceInput);

   while (menuChoiceInput != PATTERN1 && menuChoiceInput != PATTERN2 &&
          menuChoiceInput != PATTERN3 && menuChoiceInput != PATTERN4 &&
          menuChoiceInput != QUIT)
   {
      printf("Error: That is an invalid selection, please try again:\n");
      printf(">>> ");
      scanf(" %c", &menuChoiceInput);
   }

   return menuChoiceInput;
}

/*************************************************************************
  Gets the user's input for the size of the table.
*************************************************************************/
int getUserValue()
{
   int value;

   printf("\n>>> ");
   scanf("%d", &value);

   while (value < SIZE_MIN || value > SIZE_MAX)
   {
      printf("Error: That is in invalid number, please try again:\n");
      printf(">>> ");
      scanf("%d", &value);
   }

   return value;
}

/*************************************************************************
  Generates and outputs table 1.
*************************************************************************/
void displayPattern1(int value)
{
   FILE *tableOneOut;

   tableOneOut = fopen("McPherson08.txt", "w");

   for (int rows = 1; rows <= value; rows++)
   {
      for (int columns = 1; columns <= value; columns++)
      {
         if (rows == columns)
         {
            fprintf(tableOneOut, "%d", value);
         }
         else
         {
            fprintf(tableOneOut, "$");
         }
      }

      fprintf(tableOneOut, "\n");
   }
   printf("\nFile (Table 1) created successfully!\n");

   fclose(tableOneOut);

   return;
}

/*************************************************************************
  Generates and outputs table 2.
*************************************************************************/
void displayPattern2(int value)
{
   FILE *tableTwoOut;

   tableTwoOut = fopen("McPherson08.txt", "w");

   for (int rows = 1; rows <= value; rows++)
   {
      for (int columns = 1; columns <= value; columns++)
      {
         if (columns == value - (rows - 1))
         {
            fprintf(tableTwoOut, "%d", value);
         }
         else
         {
            fprintf(tableTwoOut, "$");
         }
      }
      fprintf(tableTwoOut, "\n");
   }
   printf("\nFile (Table 2) created successfully!\n");

   fclose(tableTwoOut);

   return;
}

/*************************************************************************
  Generates and outputs table 3.
*************************************************************************/
void displayPattern3(int value)
{
   FILE *tableThreeOut;

   tableThreeOut = fopen("McPherson08.txt", "w");

   for (int rows = 1; rows <= value; rows++)
   {
      for (int columns = 1; columns <= value; columns++)
      {
         if (columns <= value - (rows - 1))
         {
            fprintf(tableThreeOut, "$");
         }
         else
         {
            fprintf(tableThreeOut, "%d", value);
         }
      }

      fprintf(tableThreeOut, "\n");
   }
   printf("\nFile (Table 3) created successfully!\n");

   fclose(tableThreeOut);

   return;
}

/*************************************************************************
  Generates and outputs table 4.
*************************************************************************/
void displayPattern4(int value)
{
   FILE *tableFourOut;

   tableFourOut = fopen("McPherson08.txt", "w");

   for (int rows = 1; rows <= value; rows++)
   {
      for (int columns = 1; columns <= value; columns++)
      {
         if (rows <= columns)
         {
            fprintf(tableFourOut, "$");
         }
         else
         {
            fprintf(tableFourOut, "%d", value);
         }
      }
      fprintf(tableFourOut, "\n");
   }
   printf("\nFile (Table 4) created successfully!\n");

   fclose(tableFourOut);

   return;
}

/*************************************************************************
  Prints the goodbye message.
*************************************************************************/
void printGoodbye()
{
   printf("\nThank you for using my program!\n\n");

   return;
}
