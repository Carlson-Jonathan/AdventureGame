#include <iostream>
#include <memory>
#include "tinyxml2.h"
#include "xmlParser.h"
#include "initializer.h"
using namespace std;

int main() {


	auto globalData = make_shared<Initializer>();
	XMLElement* node;

	cout << "Attempting to set node..." << endl;

	node = globalData->xmlParser->getMonster("dragon");

	cout << "Attempting to get data from node..." << endl;
	cout << node->FirstChildElement("imgWidth")->GetText() << endl;

	return 0;
}