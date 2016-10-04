#include<stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(){
FILE *input,*output;
char cipher[100];
char texto[100];
char *p=NULL;
int i=0; 
char *CrypText=NULL;

unsigned int lenCipher=0;
unsigned int lenTexto=0;

input=fopen("datos.txt", "rt");
output=fopen("salida.txt","wt");

/*
fscanf(input,"%s",cipher);
fscanf(input,"%s",texto ); 
*/


fgets(cipher,100,input);
fgets(texto,100,input);

p=cipher;
while( *p!='\n'){
	if( !isupper( *p ) )
	{
		*p=toupper(*p) ;
	} 	
	p++;
}
*p=0x0;

p=texto;
while( *p!='\n'){
	if( !isupper( *p ) )
	{
		*p=toupper(*p) ;
	} 	
	p++;
}
*p=0x0;

printf("Cipher: %s \n",cipher);
printf("Texto : %s \n",texto );
lenCipher=strlen(cipher);
lenTexto= strlen(texto );
CrypText=(char * ) malloc( sizeof(char) *lenTexto +1);
CrypText[lenTexto+1]=0x0;
{
int k=0;
for( i=0; i< lenTexto ; i++)
{
	if(!isblank(texto[i]) ){
	CrypText[k]=  (  ( (cipher[k% lenCipher] - 'A' )+ (texto[i]-'A') ) % 26 ) +'A';	

	/*printf(" %c",cipher[k%lenCipher ] );
	printf(" %c \n",texto[k] );
	printf("->%c\n",CrypText[k] );
	*/

	k++;
	}
}
 
}
fprintf(output,"%s",CrypText );

fclose(output);
fclose(input);
return 0;
}
