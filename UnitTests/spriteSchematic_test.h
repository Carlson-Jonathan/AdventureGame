#ifndef SPRITESCHEMATIC_TEST
#define SPRITESCHEMATIC_TEST

#include <iostream>
#include <vector>
#include "../battle/spriteSchematic.h"
#include "../miscellaneous.h"
using namespace std;

class SpriteSchematic_Test : public SpriteSchematic {
public:

    SpriteSchematic_Test() {}

	// void populateEntireSpriteSchematic();
    // void getDataFromLibraryAndSetRawData(string keyword);
	// void formatRawData();
	// void setNameImageWidthHeightFromRawData();
	// void setSpeedFromRawData();
	// vector<pair<short, short>> setSpritePointsInActionArrays(vector<string> words);
	// void displayRawCharacterData();
	// void displaySchematicData();

    bool detectKeyword_Test() {
        vector<string> param1_testCases = {
            "This is the first line.",
            "Apple peanut butter beef rainbow.",
            "chocolate scary clown puppy nose.",
            "4567 7537 6541 7893 357 3240",
            "@#% % @#% #@ %23 5235 #@.",
            "     excessive    spacing      goes    here.",
            "$G$G  7775, sdf.",
            "!WORD! 123 123 132"
        };

        vector<string> param2_testCases = {
            "is", "Apple", "chocolate", "45678", "@#%", "excessive", "$G$G", "WORD"
        };

        vector<bool> expectedResults = { 
            false, true, true, false, true, false, true, false
        };

        for(short i = 0; i < param1_testCases.size(); i++) {
            string line = param1_testCases[i];
            string word = param2_testCases[i];
            bool result = detectKeyword(param1_testCases[i], param2_testCases[i]);
            bool expected = expectedResults[i];

            if(result != expected) {
                cout.setf(std::ios::boolalpha); 
                cout << "UNIT TEST FAILED: spriteSchematic_test::detectKeyword_test()'\n"
                     << "Input: ('"  << line << "', '" << word << "').\n"
                     << "Expected: " << expected << "\n"
                     << "Actual:   " << result << endl;
                return false;
            }
        }

        return true;
    }

};

#endif // SPRITESCHEMATIC_TEST