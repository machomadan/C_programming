/*ilovetowatchmovies


Input:
"radio=2,clients=14,tx_errors=3,rx_errors=7"*/

// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void my_parse(char *str){
 char * temp=str;
 int k=0,i=0;
 char *token,*store[4];
 struct new{
     int radio;
     int clients;
     int tx_errors;
     int rec_errors;
 };
 char *end;
struct new  mynew;  
  token=strtok(temp,",");
    
  while(token!=NULL&&i<4){
      store[i]=strdup(token);
      i++;
     token=strtok(NULL,",");
  }
  for(i=0;i<4;i++){
      char *value_ptr = strchr(store[k], '=');
      if (value_ptr != NULL) {
          int val = atoi(value_ptr + 1);
          if (k == 0) mynew.radio = val;
            else if (k == 1) mynew.clients = val;
            else if (k == 2) mynew.tx_errors = val;
            else if (k == 3) mynew.rec_errors = val;
            k++;
        }
    }
  printf("parsed values:\n");
  printf("%d\n%d\n%d\n%d\n",mynew.radio, mynew.clients, mynew.tx_errors,mynew.rec_errors);
}

int main() {
    // Write C code here
    printf("Try programiz.pro");
    char a[]="radio=2,clients=14,tx_errors=3,rx_errors=";
    my_parse(a);
    
    return 0;
}
    
  