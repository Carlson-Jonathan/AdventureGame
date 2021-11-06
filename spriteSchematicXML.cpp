#include "spriteSchematicXML.h"

void SpriteSchematicXML::setCharacterNode() {
	characterNode = globalData->xmlParser.getCharacter(character);
}

/*------------------------------------------------------------------------------------------------*/

void SpriteSchematicXML::populateEntireSchematic() {
	this->name     = characterNode->FirstChildElement("name")->GetText();
	this->fileName = characterNode->FirstChildElement("fileName")->GetText();
	this->width    = stoi(characterNode->FirstChildElement("imgWidth")->GetText());
	this->height   = stoi(characterNode->FirstChildElement("imgHeight")->GetText());
	populatePointsInAllActions();
}

/*------------------------------------------------------------------------------------------------*/

void SpriteSchematicXML::populateActionPoints(char* actionName, vector<pair<short, short>>* pointArray) {
	XMLElement* Xnode = characterNode->FirstChildElement(actionName)->FirstChildElement("X_axes")->FirstChildElement();
	XMLElement* Ynode = characterNode->FirstChildElement(actionName)->FirstChildElement("Y_axes")->FirstChildElement();

    for(;Xnode; Xnode = Xnode->NextSiblingElement(), Ynode = Ynode->NextSiblingElement()) {	  
        pointArray->push_back({{short(stoi(Xnode->GetText()))}, {short(stoi(Ynode->GetText()))}});
	}
}	

/*------------------------------------------------------------------------------------------------*/

void SpriteSchematicXML::populatePointsInAllActions() {
	char idl[] = "idle";
	char att[] = "attack";
	char def[] = "defend";
	char dmg[] = "damage";
	char dth[] = "death";

	if(name != "heroine") {
		populateActionPoints(idl, &idle);
		populateActionPoints(att, &attack);
		populateActionPoints(def, &defend);
		populateActionPoints(dmg, &takeDamage);
		populateActionPoints(dth, &death);
	}
}



/*################################################################################################*/

void SpriteSchematicXML::printActionPoints(vector<pair<short, short>> points) {
	for(auto i : points) {
		cout << "{" << i.first << ", " << i.second << "}, ";
	}
}

/*------------------------------------------------------------------------------------------------*/

void SpriteSchematicXML::printSchematicData() {
	cout << "Name = " << name << endl;
	cout << "FileName = " << fileName << endl;
	cout << "Width = " << width << endl;
	cout << "Height = " << height << endl;

	cout << "idle points: ";
	printActionPoints(idle);

	cout << "\nattack points: ";
	printActionPoints(attack);

	cout << "\ndefend points: ";
	printActionPoints(defend);

	cout << "\ntakeDamage points: ";
	printActionPoints(takeDamage);

	cout << "\ndeath points: ";
	printActionPoints(death);
	cout << endl;
}
