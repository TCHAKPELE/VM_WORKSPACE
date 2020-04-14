#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int myatoibase(const char *nptr,const int base)
{

unsigned char charActu =0;
int result;
int signe = 1;
int resultat = 0;
if(base<2 || base >37){
result =  -2 ;
return result;

}else if (nptr==Null){
result =0;
return result;

}else if (nptr[charActu]=='-' && nptr[charActu+1]!= '0') {

result = -1;
return result;

}

else {if(nptr[charActu]=='-'){
signe = -1;
charActu++;

}
while (nptr[charActu !='\0')
{
if(nptr[charActu]>='0' && nptr[nptrActu]<='9'){

if(resultat * 10 <resultat){
return (0);
}

resultat = resultat * 10 +nptr[charActu]
if(resultat <0)
{
return(0);
}


}
else {

return (0);
}
charActu ++;

}


if (base>=2 && base <=9)

{


int reste;
int q = resultat;
int bin = 0, j=1;

while (q!=0)
{
reste = q%base;

bin = bin + (reste*j);
j=j*10;

if(bin <0){
return (42);

}


}
resultat = bin;

}
return signe*resultat;

}

}
