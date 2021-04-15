#include "word_count.h"

int main(int argc, char *argv[]){
	
	FILE *fp;
	char c;

	if (strcmp(argv[1], "--infile")==0){

		fp = fopen(argv[2], "r");

		if (fp == NULL){
			fprintf(stderr, "Unable to open --infile %s \n", argv[2]);
			exit(CMDLINE_ER);
		}
		int flag = 1;
		filestuff(fp, flag);
		exit(0);
	}

	else if (strcmp(argv[1], "--sort")==0 && strcmp(argv[2], "--infile")==0){
		fp = fopen(argv[3], "r");

		if (fp == NULL){
			fprintf(stderr, "Unable to open --infile %s \n", argv[3]);
			exit(CMDLINE_ER);
		}
		int flag =2;
		filestuff(fp, flag);
		exit(0);
	}

	else if (strcmp(argv[1], "--infile")==0 && strcmp(argv[3], "--sort")==0){
		fp = fopen(argv[3], "r");

		if (fp == NULL){
			fprintf(stderr, "Unable to open --infile %s \n", argv[3]);
			exit(CMDLINE_ER);
		}
		int flag =2;
		filestuff(fp, flag);
		exit(0);
	}

	else{
		fprintf(stderr, "Invalid command line arguments");
		exit(CMDLINE_ER);
	}




}