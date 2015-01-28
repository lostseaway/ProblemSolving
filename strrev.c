#include <stdio.h>
int mystrlen(char* st)
{
  int l = 0;
  char* p = st;
  while(*p != '\0') {
    p++;
    l++;
  }
  return l;
}

char buffer[1000];
char outbuffer[1000];

char* mystrcpy(char* dest, char* src,int n)
{
  char* sp = src;
  char* dp = dest;
  dp+=n-1;
 
  while(*sp != '\0') {
    *dp = *sp;
    sp++;
    dp--;
  }
  *dp = '\0';
  return dest;
}

int main(){
	scanf("%s", buffer);
	mystrcpy(outbuffer, buffer,mystrlen(buffer));
  	printf("%s\n", outbuffer);
}