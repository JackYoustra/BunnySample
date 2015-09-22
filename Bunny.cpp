#include "Bunny.h"

// initialization
std::string Bunny::namePool[] = {"Thumper", "Oreo", "Daisy", "Bunny", "Bella", "Charlie", "Lily", "Lola", "Oliver", "Lucy"};
unsigned int Bunny::numberOfNames = sizeof(Bunny::namePool)/sizeof(std::string);
bool Bunny::first = true;

std::string Bunny::sexToString(sex_t sex){
	if(sex == sex_t::MALE) return "Male";
	else return "Female";
}

std::string Bunny::colorToString(color_t color){
	switch (color){
	case Bunny::WHITE:
		return "White";
	case Bunny::BROWN:
		return "Brown";
	case Bunny::BLACK:
		return "Black";
	case Bunny::SPOTTED:
		return "Spotted";
	default:
		throw "Out of bounds conversion";
		break;
	}
}

Bunny::Bunny(){
	if(first){
		first = false;
		srand(time(NULL));
	}
	this->age = 0;

	bool male = rand()%2;
	if(male) this->sex = sex_t::MALE;
	else this->sex = sex_t::FEMALE;

	unsigned char color = rand()%4;
	switch (color){
	case 0:
		this->color = color_t::WHITE;
		break;
	case 1:
		this->color = color_t::BROWN;
		break;
	case 2:
		this->color = color_t::BLACK;
		break;
	case 3:
		this->color = color_t::SPOTTED;
		break;
	default:
		throw "Problem at conversion";
	}

	unsigned int nameIndex = rand()%numberOfNames;
	this->name = Bunny::namePool[nameIndex];

	this->radioactive_mutant_vampire_bunny = (rand()%50 == 25); // 2% chance
}

Bunny::~Bunny(){
}

std::string Bunny::toString(){
	std::string radioactiveString;
	if(this->radioactive_mutant_vampire_bunny) radioactiveString = "Radioactive mutant vampire";
	else radioactiveString = "";
	return std::to_string(age) + "-year-old " +  this->name + ", a " + Bunny::sexToString(this->sex) + " " + Bunny::colorToString(this->color) + " " + radioactiveString + " bunny";
}