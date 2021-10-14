After working on "Gladiator" for a while, I got stuck in speghetii hell, so I am starting over with
lessons learned. Hopefully I will be able to reinforce the object oriented principles and clean up 
the code so things dont get so tangled. I need to:

1.) Start the project with the SFML framework already worked into the code.
2.) Re-organize everything into their own objects not leaving rogue functions laying round.
3.) Create animation objects for all relevant objects.
4.) Break the heak out of the coupling. 
5.) Use pointers to objects with smart pointers.


The last thing I was doing:

main.cpp creates a party of heros by creating 'Hero' objects. 'Hero' is derived from 'Character'. 
the parent class 'Character' creates a battle animation, which all characters should have, HOWEVER, 
since constructors do not inherit, I need to have 'Hero' create a battle animation so it can pass
the textures pointer through.
