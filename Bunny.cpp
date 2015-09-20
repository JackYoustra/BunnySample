#include "Bunny.h"

// initialization
std::string Bunny::namePool[] = {"Thumper", "Oreo", "Daisy", "Bunny", "Bella", "Charlie", "Lily", "Lola", "Oliver", "Lucy"};
unsigned int Bunny::numberOfNames = sizeof(Bunny::namePool)/sizeof(std::string);
bool Bunny::first = true;

Bunny::Bunny(){
	if(first){
		first = false;
		srand(time(NULL));
	}
	bool male = rand()%2;
	if(male) this->sex = sex_t::MALE;
	else this->sex = sex_t::FEMALE;

	unsigned char color = rand()%4;
	switch (color){
	case 0:
		this->color = color_t::WHITE;
	case 1:
		this->color = color_t::BROWN;
	case 2:
		this->color = color_t::BLACK;
	case 3:
		this->color = color_t::SPOTTED;
	default:
		break;
	}

	unsigned int nameIndex = rand()%numberOfNames;
	this->name = Bunny::namePool[nameIndex];

	this->radioactive_mutant_vampire_bunny = (rand()%50 == 25); // 2% chance
}


Bunny::~Bunny(){
}
