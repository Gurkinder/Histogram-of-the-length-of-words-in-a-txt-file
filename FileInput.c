#include <stdio.h>
#include "FileInput.h" 

// Reads a text file into a char array (string).
// 'fileName' is the name of the text file to read.
// 'textStr' returns the text from the file as a string. You must pass
//           a char array that is large enough to hold the entire file.
//           Use MAX_FILE when declaring the array.
// Return value: Returns the number of characters read, or -1 on errors.
// Example calling sequence:
//    char str[MAX_FILE];
//    int len = readFile("looking_glass.txt", str);
//    if (len == -1) {
//        printf("An error occurred\n");
//    }
//    else {
//        // Process the characters in 'str' here
//    }
int readFile(const char fName[], char textStr[])
{
	FILE *fPtr;
	char ch;
	int size = 0;
	
	if ((fPtr = fopen(fName, "r")) == NULL) {
		fprintf(stderr, "Error, failed to open %s: ", fName);
		perror("");
		return -1;
	}
	
	while ((ch = fgetc(fPtr)) != EOF) {
	    if (size >= MAX_FILE - 1)
	        break;
		textStr[size++] = ch;
    }
		
	textStr[size] = '\0';
	
	return size;	
}

