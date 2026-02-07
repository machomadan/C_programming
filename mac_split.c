/*The changes in the C program related to strotok function usage which extracts the macs accordingly, mac_split() will split the macs and act as call by reference.*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int mac_split(char * str, char *p[],int count){
	char *ctx;
	char *copy;
	int i=0;
	copy=strdup(str);
	ctx=strtok(copy,",");
	while(ctx!=NULL && i<count){
		p[i]=strdup(ctx);
		ctx=strtok(NULL,",");
		i++;
	}
	return count;
}

int main(){
	char a[]="00:11:22:33:44:55,AA:BB:CC:DD:EE:FF";
	char *b,*new=a;
	char *ch=',';
	char *p;
	int i=0,result;
	while(ch=strchr(,',') !=NULL){
		i++;
		new++;
	}
	b=(char **)malloc(i*1);
	result=mac_split(a,&b,i);
	for(i=0;i<result;i++){
		printf("mac value b[%d]=%s",i,b[i]);
	}
	return;
}


