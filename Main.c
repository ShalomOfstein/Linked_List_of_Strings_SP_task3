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
         list = inputList(&list);
      }
      if(mode == 2){
         int index = -1;
         char* word;
         scanf("%d",&index);
         scanf("%s",word);
         StrList_insertAt(list,word,index);
      }
      if(mode == 3){
         StrList_print(list);
      }
      if(mode == 4){
         int size = StrList_size(list);
         printf("%d",size);
      }
      if(mode == 5){
         int index = -1;
         scanf("%d",&index);
         StrList_printAt(list,index);
      }
      if(mode == 6){
         StrList_printLen(list);
      }


   }

}