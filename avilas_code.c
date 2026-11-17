// Name: Neil Ryan C. Avila
// Programming 1 : Final Project

#include <stdio.h>
#include <ctype.h> //for tolower() function

int main() {
	//variables for main menu
	int choice;
	int running = 1;
	char cont; //stands for continue
	//variables for module 1: pattern generator
	int sub, n, i, j, layer;
	//variables for module 2: pascal triangle
	int rows, value;
	//variables for module 3: grade calculator
	float prelim, midterm, prefinal, final, average;
	//variables for module 4: palindrome checker
	char word[50];
	int len, isPalindrome;
	char c1, c2; //holders for each compared character

	do {
		printf("\nPlease Select Operation to Perform: \n");
		printf("1. Pattern Generator\n");
		printf("2. Pascal Triangle\n");
		printf("3. Grade Calculator and Evaluator\n");
		printf("4. Palindrome Checker\n");
		printf("5. Exit\n");
		printf("--------------------");

		printf("\nEnter a Choice: ");
		scanf("%d", &choice); //%d format specifier for integer

		switch (choice) { // perform specific action based on user choice
		/*
		case 1: will perform if user choice is == 1.
		        - first ask for the SIZE, then show shape sub-menu
		*/
		case 1:
			printf("\n-- Pattern Generator --");
			printf("\nEnter size: ");//size asked ONCE, before shapes
			scanf("%d", &n);

			if (n < 1) { //if size entered is less than 1, break
				printf("Invalid size. Please input a valid number.\n");
				break;
			}

			do {
				printf("\nTo Generate Pattern Please Select Shape (1-5):\n");
				printf("1. Right Triangle\n");
				printf("2. Square\n");
				printf("3. Isosceles Triangle\n");
				printf("4. Inverted Right Triangle\n");
				printf("5. Christmas Tree\n");
				printf("6. Back to Main Menu\n");
				printf("--------------------");

				printf("\nEnter a Choice: ");
				scanf("%d", &sub);

				//based on user choice it will generate specific pattern
				if (sub == 1)
				{
					printf("Right Triangle selected\n"); //n stands for size of the shape
					for (i = 1; i <= n; i++) {          //outer loop = rows
						for (j = 1; j <= i; j++) {      //inner loop = stars
							printf("*");
						}
						printf("\n");
					}//outer for loop
				}
				else if (sub == 2)
				{
					printf("Square selected\n");
					for (i = 1; i <= n; i++) {
						for (j = 1; j <= n; j++) {
							printf("* ");
						}
						printf("\n");
					}//outer for loop
				}
				else if (sub == 3)
				{
					printf("Isosceles Triangle selected\n");
					for (i = 1; i <= n; i++) {
						for (j = 1; j <= n - i; j++) {      //leading spaces
							printf(" ");
						}
						for (j = 1; j <= 2 * i - 1; j++) {  //stars
							printf("*");
						}
						printf("\n");
					}//outer for loop
				}
				else if (sub == 4)
				{
					printf("Inverted Right Triangle selected\n");
					for (i = n; i >= 1; i--) {      //rows count down
						for (j = 1; j <= i; j++) {
							printf("*");
						}
						printf("\n");
					}//outer for loop
				}
				else if (sub == 5)
				{
					printf("Christmas Tree selected\n");
					for (layer = 1; layer <= 3; layer++)
					{	//3 triangles
						for (i = 1; i <= layer + 1; i++) {
							for (j = 1; j <= n - i; j++) {
								printf(" ");
							}
							for (j = 1; j <= 2 * i - 1; j++) {
								printf("*");
							}
							printf("\n");
						}
					}//outer for loop

					for (i = 1; i <= 2; i++) {                  //trunk
						for (j = 1; j <= n - 2; j++) {
							printf(" ");
						}
						printf("***\n");
					}//another outer for loop
				}
				else if (sub == 6) {
					printf("Back to Main Menu.\n");
				}
				else {
					printf("Invalid input. Please try again. (Must be between 1-6)\n");
				}
			}
			while (sub != 6); //as long as choice is not yet back to menu, pattern generator will run.
			break;

		/*
		case 2: will perform if user choice is == 2.
		        - then prompt user to enter number of rows
		*/
		case 2:
			printf("\nPascal Triangle selected.\n");
			printf("Enter number of rows (1-15): ");
			scanf("%d", &rows);

			if (rows < 1 || rows > 15)
			{
				printf("Please enter 1 to 15 only.\n");
			}
			else
			{
				for (i = 0; i < rows; i++)
				{
					for (j = 0; j < rows - i - 1; j++) {    //leading spaces
						printf("  ");
					}
					value = 1; //compute each value on the fly, no array
					for (j = 0; j <= i; j++) {
						if (j > 0) {
							value = value * (i - j + 1) / j;
						}
						printf("%4d", value);
					}
					printf("\n");
				}//outer for loop
			}
			break;

		/*
		case 3: will perform if user choice is == 3.
		        - then prompt user to enter grades starting from prelim-final
		*/
		
        case 3:
            printf("\nGrade Calculator and Evaluator selected.\n");
        
            printf("Enter Prelim grade: ");
            scanf("%f", &prelim);
            printf("Enter Midterm grade: ");
            scanf("%f", &midterm);
            printf("Enter Pre-Final grade: ");
            scanf("%f", &prefinal);
            printf("Enter Final grade: ");
            scanf("%f", &final);
        
            average = (prelim + midterm + prefinal + final) / 4.0;
            printf("\nAverage: %.2f\n", average);
        
            // College grading system
            if (average <= 1.5) {
                printf("Excellent\n");
            }
            else if (average <= 2.5) {
                printf("Good\n");
            }
            else if (average <= 3.0) {
                printf("Fair\n");
            }
            else {
                printf("Failed\n");
            }
            break;
            
		/*
		case 4: will perform if user choice is == 4.
		        - then prompt user to enter a word
		*/
		case 4:
			printf("\nPalindrome Checker selected.\n");
			printf("Enter a word: ");
			scanf("%s", word); //%s format specifier for string

			len = 0; //start at 0 before loop starts
			while (word[len] != '\0') {    //'\0' is the null terminator
				len = len + 1; //take current len, add 1
			}

			isPalindrome = 1; //compare first half with reversed second half
			for (i = 0; i < len / 2; i++) {
				c1 = word[i];                //left character
				c2 = word[len - 1 - i];      //right character

				//convert both characters to lowercase to ignore case sensitivity
				c1 = tolower(c1); 
				c2 = tolower(c2);

				if (c1 != c2) { // if left and right characters don't match
					isPalindrome = 0; //flip value to 0 to indicate its not palindrome
					break;
				}
			}

			if (isPalindrome == 1) { //displaying msg
				printf("%s is a PALINDROME.\n", word);
			}
			else {
				printf("%s is NOT a palindrome.\n", word);
			}
			break;

		/*
		case 5: will perform if user choice is exit
		*/
		case 5:
			printf("Exit program.\n");
			running = 0;
			break;

		// if user choice is not between the given choices
		default:
			printf("Invalid input. Please try again. (Must be between 1-5)\n");
			break;
		}

		//TRY AGAIN LOOP ----------------
		if (running == 1 && choice >= 1 && choice <= 4) {
			printf("\nDo you want to try another operation? (Y/N): ");
			scanf(" %c", &cont); //space before %c skips leftover newline
			if (cont == 'N' || cont == 'n') {
				printf("Exit program.\n");
				running = 0;
			}
			else {
				printf("--------------------------------------------------------------\n");
			}
		}

	}
	while (running == 1); //as long as di pa exit, program will run.

	return 0;
}
