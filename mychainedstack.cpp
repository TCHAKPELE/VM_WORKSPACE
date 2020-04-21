#include <iostream>
#include "mychainedstack.h"


void Mychainedstack :: push(int number) {
	list *l = new list();
	l->element = number;
	l->suivant = nullptr;
	if(this->base == nullptr){

	this->base=l;


	}else{
	list *newelement = this->base;
	while(newelement->suivant != nullptr){

	newelement = newelement->suivant;

	}
	newelement->suivant = l;


	}


}

void Mychainedstack :: pop(){
if(this->base == nullptr){
return -16380;

}
list * x = this->base ;
list * previous = this->base;

while( x->suivant != nullptr){

previous = x;
x = x->suivant;

}
int value = x->element;
delete x;
if(x==previous){
this->base = nullptr;

}else{
previous->suivant = nullptr;

}
return value ;


}

int Mychainedstack :: operator%(int mod) const{

if(mod<2){

 return -65530;

}

return this->size() % mod;


}




void Mychainedstack :: clear() {

int nbrelement = this->size();

for (int i=0 ; i<nbrelement; i++){

this->pop();

}

}
