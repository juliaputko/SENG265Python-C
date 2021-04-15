#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

#define CMDLINE_ER 1
#define OPEN_ER 2
#define MEM_ER 3
#define MAX_LINES 1000
char *lines;  //in assignment 3 will need to use realloc to reassign memory 
int   num_lines;

typedef struct node_lf {
    int length;
    int freq;   
    struct node_lf  *next;
} node_lf;


typedef struct node_w {
    char *words;
    int count;
    struct node_w *next;
} node_w;

node_lf *bucket = NULL;
node_w *wordlist = NULL; 


void filestuff(FILE *infile, int flag);
int compareA(const void *s, const void *t);
int compareB(const void *s, const void *t);
node_w *add_word (node_w *wordlist, char *word);
void *emalloc(size_t);
void remove_duplicates(node_w* wordlist);
int second_to_last(node_w* head);
void print_hist(node_w *wordlist, node_lf *buckets);
node_lf *add_front(node_lf *, node_lf *);
node_lf *add_end(node_lf *, node_lf *);
node_lf *add_inorder(node_lf *, node_lf *);



void filestuff(FILE *fp, int flag){
  
    char *buffer;
    int arr_size =100;
    int i;
    num_lines = 0;
    buffer = NULL;
    size_t buffer_len;

    char *line = NULL;
    char *lines = NULL;

    lines = (char*)emalloc(sizeof(char*) * arr_size-1);

    if (lines == NULL){
        fprintf(stderr, "Unable to allocate memory:");
        exit(MEM_ER);
    }
//get words from file 
    while(getdelim(&buffer, &buffer_len, 32, fp) != -1){
       //insert 

        line = (char*)emalloc(sizeof(char)*(buffer_len+1));
        if (line == NULL){
            fprintf(stderr, "Unable to allocate memory");
            exit(MEM_ER);
        }
        strncpy(line,buffer,buffer_len-1);
        lines[num_lines] = *line;
        num_lines++;
        //realloc if needed 
        if (num_lines > arr_size){
            lines = (char*)realloc(lines, sizeof(char*) * arr_size*2);
            arr_size *= 2;     
        } 
        /*
void insertArray(Int_Struct *a, int element) { 
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (int *)realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
} 
*/
    }
    //free memory 
    free(buffer);
    free(line);
    
    if (flag == 1){
      qsort(lines, num_lines, sizeof(char*), compareA);
    }
    else if (flag ==2){
      qsort(lines, num_lines, sizeof(char*), compareB); //reverse alphabetical ordering 
    }
 
    node_lf *bucket = NULL;
    node_w *wordlist = NULL; 
    char *t;
    int  num = 0;

    t = strtok(lines, "  .,;()");
    while (t) {
        num++;
        wordlist = add_word(wordlist, t); 
  //add word takes the node and the thing to be added 
        if (wordlist->words != NULL){
          strcpy(wordlist->words, t);
        }
        t = strtok(NULL, "  .,;()");
    }
 

    fclose(fp);
    node_w* new_list = wordlist;
    node_lf  *head = NULL;
    print_hist(wordlist, head);
    //analysis(new_list);
    node_w *temp_n =NULL;
    for (; wordlist!= NULL; wordlist = temp_n){
        temp_n = wordlist->next;
        free(wordlist);
    } 
    free(new_list);
    free(lines);
    free(wordlist);
    free(temp_n);
    exit(0);

} //end filestuff

void *emalloc(size_t n) {
    void *p; 

    p = malloc(n);
    if (p == NULL) {
        fprintf(stderr, "Unable to allocate memory"); 
        exit(MEM_ER);
    }   

    return p;
}


int compareA(const void *s, const void *t) //normal aphabetical ordering 
{
    //void * --> char ** --> (dereference) *(char **) --> char *
    //double pointer, dereference to get single pointer 
    return strcmp(*(char **)s, *(char **)t);  //cast as char 
}

int compareB(const void *s, const void *t) //reverse order 
{
    //void * --> char ** --> (dereference) *(char **) --> char *
    //double pointer, dereference to get single pointer 
    return strcmp(*(char **)t, *(char **)s);  //cast as char 
}


node_lf *create_buckets(int length, int freq){

    node_lf *newbuck = emalloc(sizeof(int)+1);

    if (newbuck != NULL){
        newbuck->length = length;
        newbuck-> freq = freq;
        newbuck->next = NULL;
    }

}

node_lf *add_front(node_lf *list, node_lf *new) {
    new->next = list;
    return new;
}


node_lf *add_end(node_lf *list, node_lf *new) {
    node_lf *curr;

    if (list == NULL) {
        new->next = NULL;
        return new;
    }

    for (curr = list; curr->next != NULL; curr = curr->next);
    curr->next = new;
    new->next = NULL;
    return list;
}

node_lf *add_inorder(node_lf * list, node_lf *new) {

    if(list == NULL || list -> length > new-> length){
        list = add_front(list, new);
    }
    node_lf *curr = list;
    int node_added =0;
    while (curr->next != NULL){ //curr cant be nulll and curr-> next cannot be nUL 
        if(curr->next->length > new->length){
            node_lf * temp = curr->next;
            curr -> next = new;
            new-> next = temp;
            node_added =1;
            break;
        }

        curr = curr -> next;
    }
    if(!node_added){
        list = add_end(list, new);
    }
    //first node, last 
    return list;
}

node_w *create_words (char *word)
{
    //+allocate space for the structure
    printf ("%lu\n", strlen (word)); // print length of the word 
    node_w *newWord = emalloc (sizeof (word)+1); 
    node_lf *newbuck =emalloc (sizeof(int)+1);
    if (NULL != newWord) {
        //+allocate space for storing the new word in "words"
        //+if str was array of fixed size, storage wud be wasted
        newWord->words = (char *) emalloc ((strlen (word)) + 1);
        strcpy (newWord->words, word);    //+copy “word” into newWord->str
        newWord->words[strlen (word)] = '\0';
       // printf (" Create: %s \n", newWord->words);
        //+initialize count to 1;
        //newWord->count = 1;
        //add to bucket histogram 
        newbuck->freq = 1;  
        newbuck = add_inorder(bucket, create_buckets(strlen(word), newbuck->freq));
        newbuck->length = strlen(newWord->words);
        //+initialize next;
        newWord->next = NULL;
    }
    return newWord;
}

node_w *add_word (node_w *wordlist, char *word) //add in the other linked list, so can update count fo wtv or maybe frequency 
{
    if (!wordlist) {       /* handle EMPTY list */
        printf ("NEW LIST\n");      
        return wordlist = create_words (word);
    }

    node_w *temp = wordlist;
    //+ search if word exists in the list; if so, make found=1
    while (temp->next != NULL) {    /* iterate while temp->next != NULL */

        if (strcmp (temp->words, word) == 0) {    //+use strcmp command
            temp->count = temp->count + 1;      //+increment count;
            return wordlist;
        }
        else
            temp = temp->next;  //+update temp
    }
    node_w *newWord = create_words(word);
    if (NULL != newWord) {  /* insert at TAIL of list */
        temp->next = newWord; 
        printf (" NEW WORD: %s\n ", newWord->words);
    }
    return newWord;
}

//https://www.faceprep.in/c/remove-duplicates-from-a-linked-list/
void remove_duplicates(node_w* head)
{
    node_w* current = head;
    node_w* next_next;

    if (current == NULL)
    return;

    while (current -> next != NULL)
    {
        if (current -> words == current -> next -> words){
            next_next = current -> next -> next;
            free(current -> next);
            current -> next = next_next;
        }
        else
        {
            current = current -> next;
        }
    }
}
//https://www.geeksforgeeks.org/find-the-second-last-node-of-a-linked-list-in-single-traversal/#:~:text=If%20the%20list%20is%20empty,is%20the%20second%20last%20node.
int second_to_last(node_w* head) 
{ 
    node_w* temp = head; 
    if (temp == NULL || temp->next == NULL) 
        return 0; 
    while (temp != NULL) { 
        if (temp->next->next == NULL) 
            return 1; 
        temp = temp->next; 
    } 
    
} 

void print_hist(node_w *wordlist, node_lf *buckets){
    node_lf *curr1 = buckets;
    node_w *curr2 = wordlist;
    while(curr1 ->next != NULL){
        printf("Count [%d] = 0%d;", buckets->length, buckets->freq);
        int flag = second_to_last(curr2);
        remove_duplicates(wordlist);
        while(curr1 ->next != NULL){
            if (flag==1){ //second to last
            //print it with an and 
                printf("%s, and", wordlist->words);
            }else if (flag==0){
                printf("%s, ", wordlist->words);
            //print it normally 
            }
        
        }

    }  

}



   
