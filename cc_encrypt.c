/**************************************************************************
Student name: Younes Boutaleb
Student number: 041019068
Assignment number (and name if any): Lab 02: To perform Data Cryptography 
                                                      and De-cryptography 
Course name and number: CST8234 C Language
Lab section number: 013
Professor’s name: Natalie Gluzman
Due date of assignment: June 4, 2021
Submission date of assignment: May 25, 2021
List of source and header files in the project: cc_encrypt.c
 **************************************************************************/
/**************************************************************************
Declare include files
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**************************************************************************
 Declare MACRO MAX_MESSAGE
 **************************************************************************/
#define MAX_MESSAGE 80

/**************************************************************************
 * Main function
 * this program prompts users to enter a message and a rotation key then
 * decryptes the message and prints it
 * It takes no parameters and returns EXIT_SUCCESS value
 * Version: 1.0
 * Author/Student Name: Younes Boutaleb
 **************************************************************************/
int main()
{
    /*this is the rotation key*/
    int key;
    /*this is an array of charachter which stores the user's message*/
    char text[MAX_MESSAGE + 1];
    /*this is the return code of the rotation key*/
    int rc = 0;
    /*this the for loop variable*/
    int i;
    /*this is the message length*/
    int len;

    /*read the user's message*/
    printf("Enter message to encrypt:\n");
    do
    {
        scanf("%80[^\n]s", text);
        /*calculates the mesage length*/
        len = strlen(text);
        if (len == 0)
            printf("Error - no message. Try again...Enter message to encrypt.\n");
        /*clear the stdin*/
        while (getchar() != '\n')
        {
            /*chomp stdin*/
        } /*end while*/
    } while (len == 0);

    /*read the rotation key and validates the input type and value*/
    while (rc != 1)
    {
        printf("Enter rotation key:\n");
        /*it takes 1 if the entered key is an integer*/
        rc = scanf("%d", &key);
        if (rc != 1 || key > 26 || key < 0)
        {
            rc = 0;
            printf("Error - key must be in range 0 and 26. Try again.\n");
            /*if not a valid input clear the stdin*/
            while (getchar() != '\n')
            {
                /*chomp stdin*/
            } /*end while*/
        }     /*end if*/
    }         /*end while*/

    printf("\nEncrypting message (key = %d): %s\n\n", key, text);
    /*the for loop verifies the type of each charachter*/
    for (i = 0; i < strlen(text); i++)
    {
        /*Adds the key value to each uppercase characheter
         if the sum is an uppercase charachter it store it in the array
         otherwise it look for the corresponding uppercase charachter by subbstracting 26*/
        if (isalpha(text[i]) != 0 && text[i] <= 90)
        {
            text[i] = text[i] + key;
            if (text[i] > 90)
                text[i] = text[i] - 26;
        }
        /*Adds the key value to each lowercase characheter
         if the sum is an uppercase charachter it store it in the array
         otherwise it look for the corresponding lowercase charachter by subbstracting 26*/
        else if (isalpha(text[i]) != 0 && text[i] >= 97)
        {
            if ((text[i] + key) >= 97 && (text[i] + key) <= 122)
                text[i] = text[i] + key;
            else
                text[i] = (text[i] - 26) + key;
        } /*end if*/
    }     /*end for*/
    /*prints the decrypted message*/
    printf("%s\n", text);
    return EXIT_SUCCESS;
} /*end main*/