#include "xmlParser.h"

/* 
* Instructions to set and read XML nodes:
* 
*/

void XMLParser::getAndVerifySpriteDataFromXMLFile(const char* file) {

	string errorMsg = "Error loading from XML file '" + string(file) + "'!\n"
					  "Possible issues:\n" +
					  "\t* Is your .xml file present in the correct folder and spelled correctly?\n"
					  "\t* There could be a syntax error in the .xml file preventing it from being read.\n"
                 	  "See XMLParser::insertCharacterNodeIntoMap(map, node) for more info.";

	
	try {
		XMLError eResult = xmlDocument.LoadFile(file);

		if(eResult) 
			throw errorMsg;
	}
	catch (string errorMsg) {
		cout << errorMsg << endl;
		exit(3);
	}
}

/*------------------------------------------------------------------------------------------------*/

void XMLParser::populateAndVerifyRootNode() {

		rootNode = xmlDocument.FirstChildElement();
		verifyXMLNode(rootNode, "", false);
		string rootNodeName = rootNode->Value();

		if(rootNodeName != "characters")
			cout << "WARNING! Expected root element named 'characters'. " 
		         << "Name of current root: '" << rootNode->Value() << "'." << endl;
}

/*------------------------------------------------------------------------------------------------*/

void XMLParser::populateCharacterGetterMap() {
	insertCharacterNodeIntoMap(characterGetterMap, rootNode);
}

/*------------------------------------------------------------------------------------------------*/

void XMLParser::insertCharacterNodeIntoMap(map<string, XMLElement*> & map, XMLElement* node) {
	
	verifyXMLNode(node, "", false);

	for(XMLElement* child = node->FirstChildElement(); child; child = child->NextSiblingElement()) {
		
		verifyXMLNode(child, "name", false);
		verifyXMLNode(child->FirstChildElement("name"), "", true);

    	string name = child->FirstChildElement("name")->GetText();
    	map.insert(pair<string, XMLElement*>(name, child));
	}
}

/*------------------------------------------------------------------------------------------------*/

void XMLParser::verifyAllCharacterNodes() {
	for(XMLElement* characterNode = xmlDocument.FirstChildElement()->FirstChildElement(); characterNode; 
		characterNode = characterNode->NextSiblingElement()) {	

		verifyXMLNode(characterNode, "name",      false);
		verifyXMLNode(characterNode, "fileName",  false);
		verifyXMLNode(characterNode, "imgWidth",  false);
		verifyXMLNode(characterNode, "imgHeight", false);
		verifyXMLNode(characterNode, "idle",      false);
		verifyXMLNode(characterNode, "attack",	  false);
		verifyXMLNode(characterNode, "defend", 	  false);
		verifyXMLNode(characterNode, "damage",	  false);
		verifyXMLNode(characterNode, "death", 	  false);
		verifyCharacterActions(characterNode);
	}
}

/*------------------------------------------------------------------------------------------------*/

void XMLParser::verifyCharacterActions(XMLElement* characterNode) {

	XMLElement* idleNode   = characterNode->FirstChildElement("idle");
	XMLElement* attackNode = characterNode->FirstChildElement("attack");
	XMLElement* defendNode = characterNode->FirstChildElement("defend");
	XMLElement* damageNode = characterNode->FirstChildElement("damage");
	XMLElement* deathNode  = characterNode->FirstChildElement("death");
	XMLElement* nameNode   = characterNode->FirstChildElement("name");
	XMLElement* fileName   = characterNode->FirstChildElement("fileName");		
	XMLElement* imgWidth   = characterNode->FirstChildElement("imgWidth");
	XMLElement* imgHeight  = characterNode->FirstChildElement("imgHeight");	

	verifyXMLNode(nameNode,  "", true);
	verifyXMLNode(fileName,  "", true);
	verifyXMLNode(imgWidth,  "", true);
	verifyXMLNode(imgHeight, "", true);

	verifyXMLNode(idleNode, "X_axes", false);
	verifyXMLNode(idleNode, "Y_axes", false);
	verifyXMLNode(idleNode, "animationSpeed", false);

	verifyXMLNode(attackNode, "X_axes", false);
	verifyXMLNode(attackNode, "Y_axes", false);
	verifyXMLNode(attackNode, "animationSpeed", false);

	verifyXMLNode(defendNode, "X_axes", false);
	verifyXMLNode(defendNode, "Y_axes", false);
	verifyXMLNode(defendNode, "animationSpeed", false);

	verifyXMLNode(damageNode, "X_axes", false);
	verifyXMLNode(damageNode, "Y_axes", false);
	verifyXMLNode(damageNode, "animationSpeed", false);

	verifyXMLNode(deathNode, "X_axes", false);
	verifyXMLNode(deathNode, "Y_axes", false);
	verifyXMLNode(deathNode, "animationSpeed", false);				

	verifyActionPoints(idleNode);
	verifyActionPoints(attackNode);
	verifyActionPoints(defendNode);
	verifyActionPoints(damageNode);
	verifyActionPoints(deathNode);
}

/*------------------------------------------------------------------------------------------------*/
// I have to re-do the schema to wrap the character actions in an <action> group. This will need to
// be redone. Here is a temporary function to make crap happen though.

void XMLParser::verifyActionPoints(XMLElement* actionNode) {
	for(XMLElement* axisNode = actionNode->FirstChildElement("X_axes");	axisNode; 
		axisNode = axisNode->NextSiblingElement()) {

		verifyXMLNode(actionNode->FirstChildElement("X_axes"), "X1", false);
		verifyXMLNode(actionNode->FirstChildElement("Y_axes"), "Y1", false);
		verifyAllAxesHaveText(axisNode);	
	}
}

/*------------------------------------------------------------------------------------------------*/

void XMLParser::verifyAllAxesHaveText(XMLElement* pointsNode) {
	for(XMLElement* node = pointsNode->FirstChildElement(); node; node = node->NextSiblingElement()) {

		verifyXMLNode(node, "", true);
	}
}

/*------------------------------------------------------------------------------------------------*/

void XMLParser::verifyXMLNode(XMLElement* node, string childName, bool holdsText) {

	// Check to be sure the node is set.
	if(!node) {
		cout << "XML element <" << node->Value() << "> failed to set before being called!"
	         << "See xmlParser.h for more info." << endl;
		exit(3);
	}

    // This node should contain a child node named...
    if(childName != "") {
		const char* cName = childName.c_str();
		if(!node->FirstChildElement(cName)) {
			cout << "Error getting child element <" << childName << "> from <" 
				 << node->Parent()->Parent()->Value() << "><"
			     << node->Parent()->Value() << "><" << node->Value() 
			     << ">. Check your .xml file!\n"
			     << "See XMLParser::insertCharacterNodeIntoMap(map, node) for more info." << endl;
			exit(3);
		}
	}

	// If the node should have text, check to make sure it is set.
	else if(holdsText) { 
		if(!node->GetText()) {
			cout << "ERROR: No text is set for XML element <" 
			     << node->Parent()->Parent()->Parent()->Value() << "><" 
			     << node->Parent()->Parent()->Value() 			<< "><" 
			     << node->Parent()->Value()   			    	<< "><" 
			     << node->Value() << ">!\n"
			     << "See XMLParser::insertCharacterNodeIntoMap(map, node) for more info." << endl;
			exit(3);
		}
    }
}




/*################################################################################################*/

void XMLParser::printNodeData(XMLElement* node) {
	cout << "Printing..." << endl;	
	for(XMLElement* child = node->FirstChildElement(); 
	    child; 
	    child = child->NextSiblingElement()) {	        
	        cout << "\t" << child->FirstChildElement("name")->GetText() << endl;
	}
}

/*------------------------------------------------------------------------------------------------*/

void XMLParser::printMapData(map<string, XMLElement*> map) {
    cout << "{ Name : Node }" << endl;
    for (auto const & pair : map) {
        cout << "{ " << pair.first << " : " 
             << pair.second->FirstChildElement("name")->GetText() << " }\n";
    }
}