#include "word_count.h" 

int
real_main(int argc, char *argv[]) {
    //TODO


    //PART A 

    struct word_t *content[MAX_WORD_CNT]= {0};
    //memset(content, '0', sizeof(word_t)*MAX_WORD_CNT);



    char *buffer[MAX_FILESIZE]= {'\0'};  //initialize a buffer char array 
    //memset(buffer, '\0', sizeof(char)*MAX_FILESIZE);


    int number_of_buckets;
    struct content;

    if (argc<2){
		fprintf(stderr, "Error: You must provide a filename\n");
  		return(FILE_NOT_FOUND);
	}
    
	FILE *filepath = fopen(argv[2], "r");

	fgets((char*)buffer, MAX_FILESIZE-2, filepath);


	fclose(filepath);


	if (strcmp(argv[1], "--infile")== 0){

		//PART A 
		//not sorted, no words, no median 

		int print_words = 0;
		int print_sorted = 0;

		//do something 
		tokenize_string((word_t*)content, (char*)buffer, &number_of_buckets);
		print_histogram((word_t*)content, print_words, print_sorted);

		fclose(filepath);

	}

	else if( (strcmp(argv[1], "--sort")== 0 && strcmp(argv[2], "--infile") == 0) 
          
          || (strcmp(argv[2], "--sort") == 0 && strcmp(argv[1], "--infile") == 0) ){

//PART B
// sorted and with median

		int print_words = 0;
		int print_sorted = 1;

		//do something 
		tokenize_string((word_t*)content, (char*)buffer, &number_of_buckets);
		
		print_histogram((word_t*)content, print_words, print_sorted);

		print_median((word_t*)content, number_of_buckets);

		fclose(filepath);

	}

	else if (

		(strcmp(argv[1], "--sort") == 0 && strcmp(argv[2], "--print-words") == 0 && strcmp(argv[3], "--infile") == 0)

      || (strcmp(argv[2], "--sort") == 0 && strcmp(argv[3], "--print-words") == 0 && strcmp(argv[1], "--infile") == 0)

      || (strcmp(argv[3], "--sort") == 0 && strcmp(argv[1], "--print-words") == 0 && strcmp(argv[2], "--infile") == 0)

      || (strcmp(argv[2], "--sort") == 0 && strcmp(argv[1], "--print-words") == 0 && strcmp(argv[3], "--infile") == 0)

      || (strcmp(argv[3], "--sort") == 0 && strcmp(argv[2], "--print-words") == 0 && strcmp(argv[1], "--infile") == 0) 

      || (strcmp(argv[1], "--sort") == 0 && strcmp(argv[3], "--print-words") == 0 && strcmp(argv[2], "--infile") == 0)

		){

		//PART C sorted w/out median but also with words printed
		int print_words = 1;
		int print_sorted = 1;

		tokenize_string((word_t*)content, (char*)buffer, &number_of_buckets);
		
		print_histogram((word_t*)content, print_words, print_sorted);

		fclose(filepath);

	}

	//call function to tokenize what is in buffer, and put it into bucket struct 

    return 0;
}


#ifndef TEST
int
main(int argc, char *argv[]) {
    return real_main(argc, argv);
}
#endif
