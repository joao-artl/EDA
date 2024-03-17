#include<stdio.h>
#include<string.h>

int procura(char *str, char *sub){
	if(*sub == '\0')
    	return 0;
  	if(*str != *sub)
  		return -1;
  	return procura(str+1, sub+1);
}

int subs_inicio(char *str, char *sub, int index){
	if(*str != '\0') {
	int a = -1;
    a = procura(str, sub);
    if(a == 0)
		return index;
    return subs_inicio(str + 1, sub, ++index);
    
	} else
		return -1;
}

int subs_fim(char *str, char *sub, int index){
	int a = -1;
	a = procura(str, sub);
	if(a >= 0)
    	return index;
	return subs_fim(str - 1, sub, --index);
}

int main() {
	char str[101], sub[101];
	scanf("%s", str);
	scanf("%s", sub);
	int init = 0, end = 0;
	init = subs_inicio(str, sub, 0);
	if(init != -1) {
    end = subs_fim(&str[strlen(str)], sub, strlen(str));
    printf("%d\n", end - init + strlen(sub));
	} else
		printf("0\n");
  return 0;
}