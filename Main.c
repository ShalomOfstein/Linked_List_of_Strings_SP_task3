#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StrList.h"



char* inputWord(){
   char* word = (char*)malloc(sizeof(char));
   *word = '\0';
   char c = getchar();
   while(c!=' '&&c!='\n'&&c!=EOF){
      int len = strlen(word);
      word = (char*)realloc(word,len+2);
      word[len] = c;
      word[len+1] = '\0';
      c = getchar();
   }
   return word;  
}


/*

*/

 int main(){

   StrList* list = StrList_alloc();
   int mode=-1;

   while(mode!=0){
      scanf("%d",&mode);
      if (mode == 1){
         printf("mode is 1");
         printf("Enter the number of words to add: ");
         int numOfWords = -1;
         scanf("%d",&numOfWords);
         getchar();
         printf("Enter the words: ");
         for(int i=0; i<numOfWords; i++){
            char* word = inputWord();
            StrList_insertLast(list,word);
            printf("%s was added \n",word);
         }
      }
      else if(mode == 2){
         int index = -1;
         scanf("%d",&index);
         char* word=0;
         scanf("%s",word);
         StrList_insertAt(list,word,index);
      }
      else if(mode == 3){
         StrList_print(list);
      }
      else if(mode == 4){
         int size = StrList_size(list);
         printf("%d",size);
      }
      else if(mode == 5){
         int index = -1;
         scanf("%d",&index);
         StrList_printAt(list,index);
      }
      else if(mode == 6){
         StrList_printLen(list); // doesnt do enything
      }
      else if(mode == 7){
         char* word=0;
         scanf("%s",word);
         int count = StrList_count(list,word);
         printf("%d",count);
      }
      else if(mode == 8){
         char* word =0;
         scanf("%s",word);
         StrList_remove(list,word);
      }
      else if(mode == 9){
         int index = -1;
         scanf("%d",&index);
         StrList_removeAt(list,index);
      }
      else if(mode == 10){
         StrList_reverse(list);
      }
      else if(mode == 11){
         StrList_free(list);
      }
      else if(mode == 12){
         StrList_sort(list); /// segmenation fault core dumped
      }
      else if(mode == 13){
         printf("%d",StrList_isSorted(list)); 
      }   
      
   }
   
   StrList_free(list);
   
}