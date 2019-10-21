#include "stdio.h"
#include "string.h"
#include "stdlib.h"
	
int Cstrpos(char* string,char* substr)
{					
	char* p;													
	p = strstr(string,substr);																				
	if(p)
	{															
		return p - string;										
	}																			
	return -1;													
}	

char* Csubstr(const char* string,int pos)
{							
	int i;															
	char* out = (char*)malloc(strlen(string)-pos);					
	if(pos > sizeof(string))
	{										
		out[0]='\0';												
		return out;													
	}
	for(i=0;string[pos]!='\0';i++)								
		out[i] = string[pos++];

	out[i] = '\0';													
	return out;														
}

char* Creplace(char* str1,char* str2,char* string)
{
	char * out = (char*)malloc(strlen(string) + strlen(str2));
	char * fm = (char*)malloc(strlen(string) + strlen(str2));
	char * nout = (char*)malloc(strlen(string) + strlen(str2));
	char * p;
	int length1 = strlen(str1);										
	int length2 = strlen(str2);	
	int length3 = strlen(string);
	int k = 0;
	int m = 0;
	int j = 0;

	p = strstr(string,str1);

 	if(!p)															
		return string;	

	int strpos = p - string;	

	for(int i = 0; i < strpos;i++)								
		out[i] = string[i];													

	for(j = strpos;j < strpos + length2;j++)
	{							
		out[j] = str2[j - strpos];	
	}
	
	for(k = j - 1;k <= length3;k++,m++)
	{
		fm[m] = string[k];
	}
	fm[m] = '\0';

	if(strstr(fm,str1))   
	{
		nout = out;
		return strcat(nout,Creplace(str1,str2,fm));
	}
	else
	{
		return strcat(out,fm);
	}

}
			

int main()
{

	char* chr = "assaddassada";
	char* str1 = "a";
	char* str2 = "as";
	char * a;
	a = Creplace(str1,str2,chr);
	printf("%s\n",a);
	return 0;
}