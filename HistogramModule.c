#include <stdio.h>
#include <string.h>
#include "FileInput.h"


//Here we declare a prototype of our function defined in the end
void displayHistogram(const int counts[], int max_count);

int main(int argc, char** argv)
{
	// Here we declare the array to store the contents of the word file
	char readinfo[MAX_FILE];
	
	int size = readFile("wonder.txt",readinfo);
	// here we check if the file is read without any error
	if(size>0){
		printf("?? ? ??  ??  ?????????????? ???? ??????????????????  ??  ?? ? ??");
		int lettercount;			//It calculates the alphabetical index in the for loop
		int wLengthCount = 0;  			//It is the (current)wordlength in the for loop
		int wordCount[21];				//It is the arry of counters to store the number of words;
		
		for( int i=0 ; i<=20 ; i++ ){			//initializing the counters in the array
			wordCount[i] = 0;
		}							
		// here we calculate the number of words of every length and fill their stats inside wordCount[]
		for ( lettercount=0 ; lettercount<size ; lettercount++ ){
			if(readinfo[lettercount] >= 'A' && readinfo[lettercount] <= 'Z'){
				wLengthCount++;
			}
			else if(readinfo[lettercount] >= 'a' && readinfo[lettercount] <= 'z'){
				wLengthCount++;
			}
			else {
				if( wLengthCount > 0 && wLengthCount < 21){
					wordCount[wLengthCount]++;
					wLengthCount = 0;					// here we reset the counter for the new word
				}
			}
		}
		// here maxCountLetter is used to store the maximum occurance of the most common word
		int maxCountLetter = wordCount[1];
		int MostCommonWord;						// It is the length of the most common word
		for( int k = 1 ; k <= 21 ; k++){
				if(wordCount[k] > maxCountLetter){
				maxCountLetter = wordCount[k];
				MostCommonWord = k;
			}
		}
		
		int shortestWord = 1;					//It will store the length of the shortest word
		int longestWord = 1;					//It will store the length of the longest word
		// The following is the algorithm to find the length of the Shortest and longest word
		for( int n = 1 ; n < 21 ; n++){
			if(wordCount[n] > 0){
				if( n > longestWord ){
					longestWord = n;
				}
			}
			if(wordCount[n] > 0){
				if( n < shortestWord ){
					shortestWord = n;
				}
			}
		}
		// Here we print the results of our Search
		printf("Word length counts: \n");
		displayHistogram( wordCount , maxCountLetter ) ;
		printf("\nMost common word length is: %d letters",MostCommonWord);
		printf("\nLength of the shortest word: %d letter(s) ",shortestWord);
		printf("\nLength of the longest word: %d letters \n",longestWord);
	}
	else{
		printf("File not found");
	}
	return 0;
}


void displayHistogram(const int counts[], int max_count) {
	
	//It is the scaling factor we will use in calculations below to create a normalised histogram
	float sFactor = 70.0/max_count;					
	
	// It will store the number of x's which will be printed in each line
	int nCounts;						
	
	if(max_count > 70){
		for(int i = 1 ; i < 21 ; i++){
			if( counts[i] > 0 ){
				nCounts = (sFactor * counts[i]) + 1;
				printf("%d ",i);
				for(int j = 0 ; j < nCounts ; j++){
					printf("x");
				}
				printf(" %d\n",counts[i]);
			}
			else{
				nCounts = 0;
				printf("%d ",i);
				printf(" %d\n",counts[i]);
			}
		}
	}
}
