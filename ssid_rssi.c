/*SSID: RDK_Home_WiFi, RSSI: -45 dBm*/
 // Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void my_parse(char *str){
 char * temp=str;
 int k=0,i=0;
 char *token,*store[2];
 struct new{
     char * SSID;
     int RSSI;
 };
 char *end;
struct new  mynew;  
  token=strtok(temp,",");
    
  while(token!=NULL&&i<2){
      store[i]=strdup(token);
      i++;
     token=strtok(NULL,",");
  }
  for(i=0;i<2;i++){
      char *value_ptr = strchr(store[k], ':');
      if (value_ptr != NULL) {
          if (k == 0){
              char * val = (value_ptr + 1);
              mynew.SSID = val;
          }
          else if (k == 1){
              int val = atoi(value_ptr + 1);
              mynew.RSSI = val;
              } 
            k++;
        }
    }
  printf("parsed values:\n");
  printf("SSID=%s\nRSSI=%d dBm\n", mynew.SSID, mynew.RSSI);
}

int main() {
    // Write C code here
    printf("Try programiz.pro\n");
    char a[]="SSID: RDK_Home_WiFi, RSSI: -45 dBm";
    my_parse(a);
    
    return 0;
}