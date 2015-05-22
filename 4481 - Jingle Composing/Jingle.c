#include <stdio.h>
int main() {
    char lin0[203];
	register char *lin;
	register int suma=0,lleno;
    int arr[42];arr[0]=0;arr[22]=8;arr[25]=32;arr[34]=16;arr[36]=4;arr[37]=2;arr[40]=64;arr[41]=1;
	fgets(lin0,202,stdin);
	while(*lin0!='*') {
		for(lin=lin0+1,lleno=0;*lin!='\n';lin++) {
            if(*lin=='/') {
                if(suma==64) lleno++;
                suma=0;
            }
            suma+=arr[*lin-'/'];
        }
		for(lin=lin0+3,lin0[4]='\0';lleno>9;lin--) {
			*lin=lleno%10+'0';
			lleno/=10;
		}
		*lin=lleno%10+'0';
		puts(lin);
		fgets(lin0,202,stdin);
	}
}
