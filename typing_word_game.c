/*Sender Shepard*/
/*This file implements a typing game speed. The game will test the user's
speed in typing the correct world that is being presented in random order.
The string array contains 9 words and each word appears exactly once and 
in random order each time. The program will output the word and the user will
be given the opportunity to type in the word. If it is an incorrect match the 
program will prompt the user to type the word again. There will be a time variable
that will hold the time in the beginning and another one when the timer stops.
These two variables will be subtracted from one another and then dispaly the time
that the user took to type the 9 words.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define SIZE 9

int main()
{
	int i, r; 					/*Initializing int variables */
	struct timeval start, end, res; /*Variables that will represent lapsed time */
	srand(time(NULL)); 				/*Randomizing the seed to call rand()*/
	
	/*Array of strings that will be compared with user input*/
	static char * word[] = 
	{
		"The", "quick", "brown", "fox", "jumped", "over", "the", "lazy", "dog"
	};

	/*Initializing the array of strings in a random fashion*/
	for (i = 0; i < SIZE; ++i )
	{
		r = (rand() % SIZE - 1) + 1;	/*Setting r in a random fashion*/
		char * temp = word[r]; 		/*Swapping word algorithm*/
		word[r] = word[0];
		word[0] = temp; 
	}
		
	printf("\nThis is a game that tests typing speed\n");
	printf("\nType the following words: \n");
	
	gettimeofday(&start, NULL); /*Beginning to run the time counter*/

	/*This loop will go through string array to run the typing word game*/
	for (i = 0; i < SIZE; ++i) 
	{	
		char scompare[20]; /*Creating a variable to hold user's input */
		printf("\tWord #%i is: %s ", 1 + i, word[i]);
		scanf("%s", scompare);
		
			if ( strcmp(word[i], scompare) == 0 ) /*Comparing user answer*/
				printf("Nice!!!");
		else
			do /*If input is incorrect the loop helps the user try again*/
			{
				printf("Incorrect. Try again: \n");
				printf("\tWord #%i is: %s ", 1 + i, word[i]);
				scanf("%s", scompare);

			}while ( strcmp(word[i],scompare) != 0 );

		printf("\n");
	}

	gettimeofday(&end, NULL); /*Stopping the time counter*/

	timersub(&end, &start, &res); /*Subtracting the time from end to start*/

	printf("Correct! Your time is: %ld secs %ld usecs\n", res.tv_sec, res.tv_usec);

   return 0;

}

