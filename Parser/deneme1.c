
#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *filePointer;
    filePointer = fopen("E:\\labuyg\\keywords.txt","w");

   if(filePointer == NULL)
   {
      printf("Error!");

   }

    char n[100];
    n[0] ="";
    printf("Enter keywords: ");

    while (n[0] != NULL){
        gets(n);
        puts(n);
        fprintf(filePointer,"%s",n);

    }

    fclose(filePointer);

    filePointer = fopen("E:\\labuyg\\keywords.txt","r");

    FILE *fptr;
    fptr = fopen("E:\\labuyg\\Code.txt","r");

    if (fptr == NULL){
        printf("Error! opening file");
   }


    int stringcompare(char *a,char *b){
        int flag=0;
        while(*a!='\0' && *b!='\0')  // while loop
        {
            if(*a!=*b)//if characters are diffrent it returns 1
            {
                flag=1;
            }
            a++;
            b++;
        }

        if(flag==0)// stringcompare flag ==0 means string are the same
        return 0;
        else
        return 1;
}

    void read_words_and_compare (FILE *f, FILE *fPtr) {

        char x[100];
        char** y= malloc(100* sizeof(char*));
        /* assumes no word exceeds length of 1023 */
        while (fscanf(f, " %99s", x) == 1) {
            puts(x);
            fscanf(fPtr, "%99s",y);


            while(fscanf(fPtr, " %99s", y) == 1 ) {

                if ( stringcompare(&x, &y) == 0){
                    printf("x ve y ayni");
                }

             rewind(y);
            }

        }


   }





    read_words_and_compare(fptr,filePointer);






    fclose(fptr);




   return 0;
}


