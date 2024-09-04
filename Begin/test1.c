#include<stdlib.h>
#include<stdio.h>
int main ()
{
  char numbers[] = "2001 60c0c0 -1101110100110100100000 0x6fffff";
  char * pEnd;
  long int li1 = strtol(numbers, &pEnd, 10), // преобразовать первую часть строки в значение 10-й СС
           li2 = strtol(pEnd,    &pEnd, 16), // преобразовать часть строки в значение 16-й СС
           li3 = strtol(pEnd,    &pEnd,  2), // преобразовать часть строки в значение 2-й СС
           li4 = strtol(pEnd,     NULL,  0); // преобразовать оставшуюся часть строки в распознав значение автоматически
  char arr[100];
  scanf("%s",&arr);
  printf("%s\n",arr);
  long int li5 = strtol(arr, NULL, 10); // преобразовать первую часть строки в значение 10-й СС
           printf ("%ld\n",li1);
           printf ("%ld\n",li2);
           printf ("%ld\n",li3);
           printf ("%ld\n",li4);
           printf ("%ld\n",li5);
 
  return 0;
}