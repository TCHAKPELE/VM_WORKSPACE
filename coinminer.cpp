#include "sha1.hpp"
#include <string>
#include <cstring>
#include <iostream>
#include <time.h>
using std::string;
using std::cout;
using std::endl;

string random (char *chaineAleatoire,int longueurChaine,string trigramme)
{
char tab[24]={'-','C','C','1','.','0','-','1','5','0','9','1','9','3','4','3','5','-','o','f','o','f','o','f'};
int i =0;
int j=0;
int z=0;
char chaine[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int taille=strlen(chaine);



for(i=0;i<longueurChaine;i++){
if(i<32){
chaineAleatoire[i]=chaine[rand()%taille];
}else
if(i==32){
chaineAleatoire[i]='-';

}else
if(i>32 && i<36){
chaineAleatoire[i]=trigramme.at(j);
j++;
}else
if(i>=36){
chaineAleatoire[i]=tab[z];
z++;
}


}


return chaineAleatoire;

}


int main(int argc , const char ** argv )

{
double time = 0;

int i =0;
int taille = 60;
int m = atoi(argv[4]);
string trigramme =argv[2];
    char passWd[taille];
    
int count = 0;
string input;
try{
while (count<9){



time = clock()/1000000;
   count=0;
   char *pointeur=passWd;
   int valueMax =12;
    input = random(pointeur,taille,trigramme);

    SHA1 checksum;
    checksum.update(input);
  	const string hash = checksum.final();

for(i=0;i<valueMax;i++){

if(hash.at(i)=='c' && hash.at(i+1)=='c'){
count++;

}

}
if(count<6 ){
if(count>=m){
cout<<count<<" c (miette) "<<time<< " s "<<endl;

}
}
else
if(count==6){
if(count>=m){
cout<<count<<"c (subcoin)  "<<time << " s "<< endl;
}

}else
if(count==7){
if(count>=m){

cout<<count<<"c (coin)    "<< time <<" s "<<endl;
}

}else
if(count ==8){
if(count>=m){

cout<<count<<"c (hexcoin)"<<time << " s " <<endl;
}

}else 
if(count == 9){
if(count>=m){

cout<<count<<"c (arkenstone)"<<time<<" s "<<endl;

}

}


}

}
catch (int valueMax){

valueMax--;

}


    return 0;
}
