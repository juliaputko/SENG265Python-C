#ifndef A1_H
#define A1_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define FILE_NOT_FOUND  1
#define BAD_ARGS        2
#define MAX_FILESIZE    5000
#define MAX_WORD_CNT    750
#define MAX_WORD_LEN    35 //Supercalifragilisticexpialidocious
#define TRUE 1
#define FALSE 0

/* 
 * Debugging print function that can has the same 
 * format as `printf`.  If `-D DEBUG` is passed to
 * the compiler then the print code is compiled, 
 * otherwise, it's an empty function.
 *
 */
void debug(const char* format, ... );

void debug(const char* format, ... ){
#ifdef DEBUG 
	va_list args;
	
	fprintf(stdout, "  -->  ");
	va_start(args, format);
	vfprintf(stdout, format, args);
	va_end(args);

	fprintf(stdout, "\n");
	fflush(stdout);
#endif	
}

typedef struct word_t
{
    char *bucket[MAX_WORD_CNT];
    int freq;
    int  len;
    //TODO
} word_t;

//struct word_t *content[MAX_FILESIZE];

size_t read_file(char* filepath, char* buffer);
int tokenize_string(word_t* content, char* buffer, int *number_of_buckets);
void print_histogram(word_t* content, int print_words, int print_sorted);
void print_median(word_t* content, int number_of_buckets);

int by_freq( const void* a, const void* b);
int by_len( const void* a, const void* b);
int by_alphanum( const void* a, const void* b);

int tokenize_string(word_t *content, char *buffer, int *number_of_buckets) {
    /* char* buffer: Input string to tokenize
     * size_t bytes: size of buffer in bytes
     * word_t* bucket: pointer to struct word array that holds the word histogram
     *
     * Function tokenizes the buffer and update the appropriate word_t buckets 
     *
     * Returns: number of buckets 
     */

    char *tokenize;
    int i = 0;
    //memset(content, '0', sizeof(word_t)*MAX_WORD_CNT);

   // struct word_t* ptr = content;

    //struct word_t* end = content + sizeof(content)/sizeof(content[0]);

    tokenize = strtok(buffer, "  ,.;:()[]{}^&"); 
    
    while (tokenize != NULL){ 
        strncpy((char*)content[i].bucket, tokenize, MAX_WORD_LEN);       
        tokenize = strtok(NULL, " ,.;:()[]{}^&");
        i++;
    }
   
    *number_of_buckets= sizeof(*content[0].bucket);
    return *number_of_buckets;
    return 0;
}

void print_histogram(word_t *content,  int print_words, int print_sorted){
    /* word_t* bucket: pointer to struct word array that holds the word histogram
     * print_words: flag to print words (Part C) or not
     * print_sorted: flag to print out the histogram sorted or not
     * Function prints out the word histogram 
     */
    
    //loop to get length of words and store them in len
    for (int i=0; i<MAX_WORD_CNT-1; i++){
         content[i].len =(int)strlen(*content[i].bucket);
   //causing seg fault 
    }

    if (print_words == 1 && print_sorted == 1){
        //part C: sort and print words

        //find frequency of all word lengths 
        for (int i=0; i<MAX_FILESIZE-2; i++){
            for (int k=0; k<MAX_FILESIZE-2; k++){
                if (strlen((char*)content[i].bucket) == strlen((char*)content[k].bucket) ){
                    content[i].freq++; //increment the frequency of each word if a repetition if found
                } //end if
            } //end for
        } //end for

        //sort struct by frequency 
        qsort(content, MAX_WORD_CNT, sizeof(word_t), by_freq);

        //if any requencies repeat, sort struct by length 
        for (int i=0; i<MAX_FILESIZE-2; i++){
            for (int k=0; k<MAX_FILESIZE-2; k++){
                if (content[i].freq == content[k].freq){

                    qsort(content, MAX_WORD_CNT, sizeof(word_t), by_len); 
                    break;
                } //end if 
            } //end for 
        } //end for 

        //print the histogram including the words 
        for (int i=0; i<MAX_FILESIZE-2; i++){
             printf("Count[0%zu] = 0%d;", strlen((char*)content[i].bucket), content[i].freq);  //printing out the word histogram  content[i].freq
             for (int j=0; j<MAX_FILESIZE-2; j++){
                printf("Words:%c%s%c, /n", '"', (char*)content[j].bucket, '"'); 
            } //end for 
        } //end for

    }// end if 

    

    else if (print_words == 0 && print_sorted == 1){
        //part B: sorted with median 
         //find frequency of all word lengths 
        for (int i=0; i < MAX_FILESIZE-2; i++){
            for (int k=0; k < MAX_FILESIZE-2; k++){
                if (strlen((char*)content[i].bucket) == strlen((char*)content[k].bucket)){
                    content[i].freq++; //increment the frequency of each word if a repetition if found
                } //end if
            } //end for
        } //end for

        //sort struct by frequency 
        qsort(content, MAX_WORD_CNT, sizeof(word_t), by_freq);

        //if frequencies repeat, sort struct by length 
        for (int i=0; i<MAX_FILESIZE-2; i++){
            for (int k=0; k<MAX_FILESIZE-2; k++){
                if (content[i].freq == content[k].freq){
                    qsort(content, MAX_WORD_CNT, sizeof(word_t), by_len); 
                    break;
                } //end if 
            } //end for 
        } //end for 

        //print the histogram including the words 
        for (int i=0; i<MAX_FILESIZE-2; i++){
             printf("Count[0%zu] = 0%d;", strlen((char*)content[i].bucket), content[i].freq);  //printing out the word histogram  
        } //end for
        //median is called in the main function

    }// end else if 

    

    else{
        //part A: not sorted, do not print words or median 

        for (int i=0; i<MAX_FILESIZE-2; i++){
            for (int k=0; k<MAX_FILESIZE-2; k++){
                if (strlen((char*)content[i].bucket) == strlen((char*)content[k].bucket)){
                    content[i].freq++; //increment the frequency of each word if a repetition if found
                } //end if
            } //end for
        } //end for

        //sort the struct aphabetically 
        qsort(content, MAX_WORD_CNT, sizeof(word_t), by_alphanum);

        //print the histogram including the words 
        for (int i=0; i<MAX_FILESIZE-2; i++){
             printf("Count[0%d] = 0%d;", content[i].len, content[i].freq);  //printing out the word histogram  
        }// end for  

    } //end else
}

void print_median(word_t *content, int number_of_buckets)
{
    /* word_t* bucket: pointer to struct word array that holds the word histogram
     * int number_of_buckets: Number of buckets (unique word lengths) 
     *
     * Function prints out the word length median value 
     */

    int len = 0;
    int median;

    //const char *bucket = (const char*) bucket;

    for (int i=0; i<MAX_FILESIZE-2; i++)
    {
        len += (strlen((const char*)content[i].bucket));  //content[i].bucket
        
    }

    median = ceil(len/number_of_buckets);

    printf("Median word length: %d\n", median);
}


/* Functions to be used by `qsort`
 *
 * These functions should sort by these rules:
 *      a left of b   return positive value
 *      a equals b    return 0
 *      b right of a  return negative value
 *
 * In you function, you need to cast your pointer
 * to the correct pointer type:
 *     
 *     const char *ai = (const char*) a;  
 */

int by_freq( const void* a, const void* b)
{
    //Sort by word count/frequency (--sort flag)
    //In the case of a tie, sort by word length
    struct word_t *ai = (struct word_t*)a;  //(struct word_t*) 
    struct word_t *bi = (struct word_t*)b;
    return bi->freq - ai->freq;  //(int)

}

int by_len( const void* a, const void* b)
{
    //Sort by word length
    struct word_t *ai = (struct word_t*) a; 
    struct word_t *bi = (struct word_t*) b; 
    return (int)(ai->len - bi->len);

}

int by_alphanum( const void* a, const void* b)
{
    //Sort alphaphetically
    //Remember that upper should come before lowercase

    const char ai = *(const char*) a; 
    const char bi = *(const char*) b; 
    const char aii = toupper(ai);
    const char bii = toupper(bi);

    if (aii != bii){
        return (aii > bii) - (aii < bii);
    }
    return (ai > bi) - (ai < bi);

}


#endif
