#include <stdio.h>
#define MAX 1000

int roman_case(char c){
    switch (c)
    {
    case 'M':case'm':return 1000; 
    case 'D':case'd':return 500; 
    case 'C':case'c':return 100; 
    case 'L':case'l':return 50; 
    case 'X':case'x':return 10; 
    case 'V':case'v':return 5; 
    case 'I':case'i':return 1; 
    default:
    return 0;}}

int roman_to_int(char *arr){
   int sum=0, initial=0,final=0,current=0;
  while(*arr){
    initial = roman_case(*arr);
       if(initial>final){
          sum+=initial-2*final;
       }
       else{
           sum+=initial;
       }
    final=initial;
    arr++;
    }
    return sum;
}

int main() {
char arr[MAX];
int result;
printf("ENTER the roman number : ");
 scanf("%s",&arr);
 result = roman_to_int(arr);

 printf("the integer value : %d\n", result);

return 0;
}