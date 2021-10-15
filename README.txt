After working on "Gladiator" for a while, I got stuck in speghetii hell, so I am starting over with
lessons learned. Hopefully I will be able to reinforce the object oriented principles and clean up 
the code so things dont get so tangled. I need to:

1.) Start the project with the SFML framework already worked into the code.
2.) Re-organize everything into their own objects not leaving rogue functions laying round.
3.) Create animation objects for all relevant objects.
4.) Break the heak out of the coupling. 
5.) Use pointers to objects with smart pointers.

####################################################################################################
# COMPILE INSTRUCTIONS(g++):
####################################################################################################
Run the below command. You man need to add missing ".cpp" files to the first line:

g++ -c main.cpp battle/battle.cpp battle/battleAnimation.cpp
g++ main.o battle.o battleAnimation.o -o executable.out -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

####################################################################################################
# COMPILE INSTRUCTIONS(CMake):
# Note: Only step 4 will be used in most cases unless you need to remake the 'build' folder.
# Also, in the CMakeLists.txt file, the folder to generate the executable is an absolute path, which
# will not work on other systems. I havent figured out how to set relative paths yet.
####################################################################################################
1.) Create build folder (if doesnt exist). 
2.) cd into build folder.
3.) Run command: "ccmake .." 
	Configure anything needed but you should only need to add "Debug" to the 1 blank.
	Hit "c" to create crap. If it works, a "g" option will appear to generate and exit.
4.) Run command: "make" This will create a "Main.out" executable in the source folder.

