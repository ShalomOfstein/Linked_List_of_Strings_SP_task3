#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StrList.h"


/*
helper function to input a word
it allocates memory for the word and returns it
it allocates the memory dynamically
*/
char* inputWord(){
   char* word = (char*)malloc(sizeof(char));
   *word = '\0';
   char c = getchar(); // get the first character
   while(c!=' '&&c!='\n'&&c!=EOF){
      int len = strlen(word); 
      word = (char*)realloc(word,len+2);  // allocate memory for the new character
      if (word == NULL) {
         // Handle memory allocation failure
         printf("Memory allocation failed in input word\n");
         exit(EXIT_FAILURE);
      }
      word[len] = c;                      // add the character to the word
      word[len+1] = '\0';                 // add the null terminator
      c = getchar();                      // get the next character
   }

   return word;  
}


/*
this function is used to clear the words in the buffer until the new line character
*/

void clearLine(){
   char c;
   while((c=getchar())!='\n'&&c!=EOF);
}


/*
the main function
get a mode from the user and then do the operation
-----------------------------------------------------------------------------------
mode 1 = add words to the list (first get the number of words and then the words)
mode 2 = insert a word at a specific index
mode 3 = print the list
mode 4 = print the size of the list
mode 5 = print the word at a specific index
mode 6 = print the length of the list
mode 7 = count the number of times a word exists in the list
mode 8 = remove a word from the list
mode 9 = remove a word at a specific index
mode 10 = reverse the list
mode 11 = free the list
mode 12 = sort the list
mode 13 = check if the list is sorted
mode 0 = exit
-----------------------------------------------------------------------------------
*/

 int main(){

   StrList* list = StrList_alloc();
   int mode=-1;

   while(mode!=0){
      // get the mode
      if(scanf("%d",&mode)!=1){
         break;
      }
      if(mode<0||mode>13){
         printf("Error: Invalid mode\n");
         continue;
      }

      // mode 1 
   
      if (mode == 1){
         
         int numOfWords = -1;
         if(scanf("%d",&numOfWords)!=1){
            printf("Error: Invalid input\n");
            break;
         }
         clearLine(); // to get rid of the new line character
         for(int i=0; i<numOfWords; i++){
            char* word = inputWord();
            StrList_insertLast(list,word);
         }
      }
      // mode 2
      // Todo: make sure it works
      else if(mode == 2){
         int index = -1;
         scanf("%d",&index);
         if(index<0||index>StrList_size(list)){
            continue;
         }
         clearLine();
         char* word= inputWord();
         StrList_insertAt(list,word,index);
      }
      // mode 3
      else if(mode == 3){
         StrList_print(list);
      }
      // mode 4
      else if(mode == 4){
         int size = StrList_size(list);
         printf("%d\n",size);
      }
      // mode 5
      // Todo: make sure it works
      else if(mode == 5){
         int index = -1;
         scanf("%d",&index);
         if(index<0||index>StrList_size(list)){
            printf("Error: Index out of bounds\n");
            continue;
         }
         StrList_printAt(list,index);
      }
      // mode 6
      else if(mode == 6){
         printf("%d\n" ,StrList_printLen(list)); 
      }
      // mode 7
      else if(mode == 7){
         clearLine();
         char* word= inputWord(); // do i need to clear the char?
         int count = StrList_count(list,word);
         printf("%d\n",count);

      }
      // mode 8
      else if(mode == 8){
         clearLine();
         char* word = inputWord(); 
         StrList_remove(list,word);
      }
      // mode 9
      else if(mode == 9){
         int index = -1;
         scanf("%d",&index);
         StrList_removeAt(list,index);
      }
      // mode 10
      else if(mode == 10){
         StrList_reverse(list);
      }
      // mode 11
      // Todo: make sure it works
      else if(mode == 11){
         while(StrList_size(list)){
            StrList_removeAt(list,0);
         }
      }
      // mode 12
      else if(mode == 12){
         StrList_sort(list); //Todo: segmenation fault core dumped
      }
      // mode 13
      else if(mode == 13){
         if(StrList_isSorted(list)==1){
            printf("true\n");
         }
         else
         printf("false\n"); 
      }   
      // if the mode is 0 exit the loop
   }
   // before finishing the program free the list
   StrList_free(list);
}