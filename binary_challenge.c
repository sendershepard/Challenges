/*Sender Shepard*/
/*This program is used to decipher a binafy file. 
 * In order to decode the file there are a specific set
 * of steps that need to take place. Three total steps
 * are taken in order to shift bits. To shift the bits
 * we use a mask and certain instructions such as: AND
 * or XOR. 
 * An external file is passed as an argument to main that will be read 
 * with the stdio.h capabilities of fread.
 * The external file is called 'esc'.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char * argv [] )
{
    int i; /*Initializing int variables */
    FILE * file = fopen (argv[1], "r"); /*Opening the file passed as an argument*/
    char buffer[4]; /*Initializing a character array of 4 */

    /*While loop that reads 4 characters at a time until all the file has been read.*/
    while(fread ( buffer , sizeof(char), 4, file ) )/*Reads 4 chars at a time*/
    {
        /*The file's name is 'esc':  First stage Swap bytes c1 and c2 for letter 'e'.*/
        char temp = buffer[1]; /*Swapping bit algorithm*/
        buffer[1] = buffer[2];
        buffer[2] = temp;
	
        /*Second stage Swap bits b7 and b5, Swap b6 and b4 for letter 's'.*/
        /*This is a for loop that will go through each character array that is being
         * read at a time, and because we read 4 at a time the for loop iterates 4 times.*/
	for (i = 0; i < 4; ++i) 
	{	
                /*Creating a mask here to shift the bits.*/
		unsigned char c1 = ( (buffer[i] & 0x80) >> 2 ) | ( (buffer[i] & 0x20) << 2 );
		unsigned char c2 = ( (buffer[i] & 0x40) >> 2 ) | ( (buffer[i] & 0x10) << 2 );
    
                /*using the mask c1 and c2 to shift the bits in their proper place.
                 * We use the AND and the mask by OR'ing it.*/
                buffer[i] = ( (buffer[i] & 0x5F) | c1);
                buffer[i] = ( (buffer[i] & 0xAF) | c2);
	}
        
        /*Third stage XOR bytes c0 and c3 with letter 'c'.*/
        /*In here we use the XOR with the mask of the third letter from the last name*/
        buffer[0] = (buffer[0] ^ 'c');
        buffer[3] = (buffer[3] ^ 'c');

        /*Printing the characters after the bits have been re-ordered.*/
	printf("%s", buffer );
    }
	
    printf( "\n" ); /*Pringing a new line here.*/

    fclose(file); /* Closing the file here once done reading */
    
    return 0;
}

