#include <iostream>
#include <memory>
#include "tinyxml2.h"
#include "xmlParser.h"
using namespace std;

int main() {

	auto xmlParser = make_shared<XMLParser>();

	XMLElement* dragon;

	dragon = xmlParser->getMonster("dragon");
	cout << dragon->FirstChildElement("fileName")->GetText() << endl;

	return 0;
}