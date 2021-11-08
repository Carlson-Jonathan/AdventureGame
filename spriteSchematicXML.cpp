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

void SpriteSchematicXML::populateActionPoints(char* actionName, vector<pair<short, short>> & pointArray) {

	XMLElement* Xnode = characterNode->FirstChildElement(actionName)->
	                    FirstChildElement("X_axes")->FirstChildElement();

	XMLElement* Ynode = characterNode->FirstChildElement(actionName)->
	                    FirstChildElement("Y_axes")->FirstChildElement();

    for(;Xnode; Xnode = Xnode->NextSiblingElement(), Ynode = Ynode->NextSiblingElement()) {	  
        pointArray.push_back({{short(stoi(Xnode->GetText()))}, {short(stoi(Ynode->GetText()))}});
	}
}	

/*------------------------------------------------------------------------------------------------*/

void SpriteSchematicXML::populatePointsInAllActions() {
	char idl[] = "idle";
	char att[] = "attack";
	char def[] = "defend";
	char dmg[] = "damage";
	char dth[] = "death";

	populateActionPoints(idl, idle);
	populateActionPoints(att, attack);
	populateActionPoints(def, defend);
	populateActionPoints(dmg, takeDamage);
	populateActionPoints(dth, death);

	populateActionSpeeds(idl);
	populateActionSpeeds(att);
	populateActionSpeeds(def);
	populateActionSpeeds(dmg);
	populateActionSpeeds(dth);
}

/*------------------------------------------------------------------------------------------------*/

void SpriteSchematicXML::populateActionSpeeds(char* actionName) {

	const char* actionSpeed = characterNode->FirstChildElement(actionName)->
					  FirstChildElement("animationSpeed")->GetText();

	if(!actionSpeed) {
		cout << "Error retrieving XML <animationSpeed> for <" << character << "><" << actionName 
		<< ">" << endl;
		exit(3);
	}

	string sActionSpeed = actionSpeed;					  

	animationSpeeds.push_back(Miscellaneous::convertStringToFloat(actionSpeed));
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

	cout << "idle speed: " << animationSpeeds[0] << endl;
	cout << "idle points: ";
	printActionPoints(idle);

	cout << "idle speed: " << animationSpeeds[1] << endl;
	cout << "\nattack points: ";
	printActionPoints(attack);

	cout << "idle speed: " << animationSpeeds[2] << endl;
	cout << "\ndefend points: ";
	printActionPoints(defend);

	cout << "idle speed: " << animationSpeeds[3] << endl;
	cout << "\ntakeDamage points: ";
	printActionPoints(takeDamage);

	cout << "idle speed: " << animationSpeeds[4] << endl;
	cout << "\ndeath points: ";
	printActionPoints(death);
	cout << endl;
}
