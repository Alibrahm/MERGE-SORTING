//ALI IBRAHIM
//UNIVERSITY OF NAIROBI
#include <stdio.h>
#include<conio.h>
#include<ctype.h>
#include <windows.h>

void mergesort(int arr[], int l, int h); //Mergesort function prototype  called here


int main(void)
{
 int array[100],n,i= 0;
 int end;
 char buf[BUFSIZ];
   SetColor(10);
 printf("\t\t\t\t WELCOME TO MY MERGE SORTING PROGRAM ");
   SetColor(15);
 printf("\nEnter the number of elements to be sorted: ");
 fflush(stdout);
    while (fgets(buf, sizeof buf, stdin) == NULL ||
           sscanf(buf, "%d%n", &n, &end) != 1 ||
           !isspace(buf[end]))
    {
         SetColor(12);
        printf("\t\tEnter an Integer value size of ARRAY!!!: ");
        fflush(stdout);
    }
    SetColor(15);
 printf("\t\nEnter the elements to be sorted: \n");
 for(i = 0 ; i < n ; i++ )
 {
    SetColor(14);
  printf("\tArray[%d] = ",i+1);


  fflush(stdout); //make the operating system flush any buffers to the underlying file
    while (fgets(buf, sizeof buf, stdin) == NULL ||
           sscanf(buf, "%d%n",&array[i],&end) != 1 ||
           !isspace(buf[end]))
    {
        SetColor(12);
        printf("\tInvalid integer! Please try again for [%d]:",i+1);
        fflush(stdout);
    }
 }

     SetColor(15);
 printf("\t\t\nBefore Merge sort the numbers are:");  //Unsorted array before Merge sort
 for(i = 0; i < n; i++)
 {SetColor(14);
  printf("%4d", array[i]);
 }
 printf("\n");

 mergesort(array, 0, n - 1);

SetColor(15);
 printf("\t\t\nAfter Merge sort the numbers are:");  // Sorted Array After Mergesort
 for(i = 0; i < n; i++)
 {SetColor(14);
  printf("%4d", array[i]);
 }
 printf("\n");
 getch();
}

void mergesort(int arr[], int l, int h) //Mergesort function defined
{
 int i = 0;
 int length = h - l + 1;
 int pivot  = 0;
 int merge1 = 0;
 int merge2 = 0;
 int temp[100];

 if(l == h)
 return;

 pivot  = (l + h) / 2;

 mergesort(arr, l, pivot);
 mergesort(arr, pivot + 1, h);

 for(i = 0; i < length; i++)
 {
  temp[i] = arr[l + i];
 }

 merge1 = 0;
 merge2 = pivot - l + 1;

 for(i = 0; i < length; i++)
 {
  if(merge2 <= h - l)
  {
   if(merge1 <= pivot - l)
   {
    if(temp[merge1] > temp[merge2])
    {
     arr[i + l] = temp[merge2++];
    }

    else
    {
     arr[i + l] = temp[merge1++];
    }
   }

   else
   {
    arr[i + l] = temp[merge2++];
   }
  }

  else
  {
   arr[i + l] = temp[merge1++];
  }
 }
 return ;
}

void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //csbi is for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the foreground color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}
