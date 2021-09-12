#include <iostream>
#include <string>
#include <vector>
#include "my_header.h"

#define NUMBER_OF_SAME_TYPE_CHARS 3;
/*
	FlyweightCharacterAbstractBuilder sýnýfý özellikleri tutarak 
	diðer sýnýflarýn her birinde bu özellikler için yer ayrýlmasýna gerek býrakmýyor.
*/
class FlyweightCharacterAbstractBuilder {
	FlyweightCharacterAbstractBuilder() {}
	~FlyweightCharacterAbstractBuilder() {}
public:
	static std::vector<float> fontSizes; 
	static std::vector<std::string> fontNames; 

	static void setFontsAndNames();
	static FlyweightCharacter createFlyweightCharacter(unsigned short fontSizeIndex,
		unsigned short fontNameIndex,
		unsigned short positionInStream);
};

std::vector<float> FlyweightCharacterAbstractBuilder::fontSizes(3);
std::vector<std::string> FlyweightCharacterAbstractBuilder::fontNames(3);
void FlyweightCharacterAbstractBuilder::setFontsAndNames() {
	fontSizes[0] = 1.0;
	fontSizes[1] = 1.5;
	fontSizes[2] = 2.0;

	fontNames[0] = "first_font";
	fontNames[1] = "second_font";
	fontNames[2] = "third_font";
}

class FlyweightCharacter {
	unsigned short fontSizeIndex; 
	unsigned short fontNameIndex; 

	unsigned positionInStream;

public:

	FlyweightCharacter(unsigned short fontSizeIndex, unsigned short fontNameIndex, unsigned short positionInStream) :
		fontSizeIndex(fontSizeIndex), fontNameIndex(fontNameIndex), positionInStream(positionInStream) {}
	void print() {
		std::cout << "Font Size: " << FlyweightCharacterAbstractBuilder::fontSizes[fontSizeIndex]
			<< ", font Name: " << FlyweightCharacterAbstractBuilder::fontNames[fontNameIndex]
			<< ", character stream position: " << positionInStream << std::endl;
	}
	~FlyweightCharacter() {}
};

FlyweightCharacter FlyweightCharacterAbstractBuilder::createFlyweightCharacter
	(unsigned short fontSizeIndex, unsigned short fontNameIndex, unsigned short positionInStream) {
	FlyweightCharacter fc(fontSizeIndex, fontNameIndex, positionInStream);

	return fc;
}

int main(int argc, char** argv) {
	std::vector<FlyweightCharacter> chars;

	FlyweightCharacterAbstractBuilder::setFontsAndNames();
	unsigned short limit = NUMBER_OF_SAME_TYPE_CHARS;

	for (unsigned short i = 0; i < limit; i++) {
		chars.push_back(FlyweightCharacterAbstractBuilder::createFlyweightCharacter(0, 0, i));
		chars.push_back(FlyweightCharacterAbstractBuilder::createFlyweightCharacter(1, 1, i + 1 * limit));
		chars.push_back(FlyweightCharacterAbstractBuilder::createFlyweightCharacter(2, 2, i + 2 * limit));
	}

	for (unsigned short i = 0; i < chars.size(); i++) {
		chars[i].print();
	}

	 return 0;
}