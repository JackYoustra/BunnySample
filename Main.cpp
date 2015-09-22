#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp" // for template problem
#include "Bunny.h"

LinkedList<Bunny*> bunnyList;

void setup(){
	for(int i = 0; i < 5; i++){
		bunnyList.prepend(new Bunny());
	}
}

void age(){

}

int main(){
	setup();
	for(int i = 0; i < bunnyList.getSize(); i++){
		Bunny *currentBunny = bunnyList.get(i);
		std::cout << currentBunny->toString() << "\n";
	}
	system("Pause");
	return 0;
}