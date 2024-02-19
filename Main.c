#include <stdio.h>
#include <string.h>
#include "StrList.h"



StrList* inputList(StrList* list){
   char a;
   int numOfWords;
   scanf("%c",&a);
   if(a=="A"){
      scanf("%d",&numOfWords);
      for(int i=0;i<numOfWords;i++){
         char* word;
         scanf("%s",word);
         StrList_insertLast(list,word);
      }
   }
}


/*

*/

 int main(){

   StrList* list = StrList_alloc();
   int mode=14;

   while(mode!=0){
      scanf("%d",&mode);
      if (mode == 1){
         if(StrList_size(list) > 0){
            StrList_free(list); // what happens to the pointer list? 
         }
         list = inputList(&list);
      }
      else if(mode == 2){
         int index = -1;
         char* word;
         scanf("%d",&index);
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
         StrList_printLen(list);
      }
      else if(mode == 7){
         char* word;
         scanf("%s",word);
         int count = StrList_count(list,word);
         printf("%d",count);
      }
      else if(mode == 8){
         char* word;
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
         StrList_sort(list);
      }
      else if(mode == 13){
         printf("%d",StrList_isSorted(list)); 
      }   

   }

}