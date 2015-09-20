#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp" // for template problem
#include "Bunny.h"

int main(){
	LinkedList<Bunny*> bunnyList;
	for(int i = 0; i < 5; i++){
		bunnyList.prepend(new Bunny());
	}
	return 0;
}