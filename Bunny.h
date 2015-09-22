#include <string>
#include <ctime>

#pragma once
class Bunny{
private:
	static std::string namePool[];
	static unsigned int numberOfNames;
	static bool first;
	static enum sex_t{
		MALE,
		FEMALE
	};
	sex_t sex;
	static std::string sexToString(sex_t sex);
	static enum color_t{
		WHITE,
		BROWN,
		BLACK,
		SPOTTED
	};
	color_t color;
	static std::string colorToString(color_t color);

	unsigned char age; // 0 - 10 years old
	std::string name;
	
	bool radioactive_mutant_vampire_bunny;
public:
	Bunny();
	~Bunny();
	std::string toString();
};

