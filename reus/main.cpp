////////////////////////////////////////////////////////////////
//  Kevin Finck       E-115-LB / E-115-A
//  Chris Kruger      E-115-LH / E-115 C
//  Liam Velazquez    E-115-LL / E-115 C
//  Chris Youngclaus  E-115-LF / E-115-B
////////////////////////////////////////////////////////////////

#include "classes.cpp"
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

// Player Weapons
weapon dagger("Bone Knife", 5);
weapon club("Wooden Club", 8);
weapon sword("Broadsword", 12);
weapon book("Book of Code", 16);
weapon vaccuum("Vaccuum", 30);
weapon rock("Rock", 2);
weapon SnailSword("Sword of the Snail", 10);
weapon ICESPEAR("ICE SPEAR", 15);
// Enemy Weapons
weapon rockSpine("Rock Spine", 8);
weapon spike("Spikey Dagger", 7);
weapon knife("Goblin Knife", 5);
weapon claws("Claws", 2);
weapon flextape("Roll of Flex Tape", 10);
weapon boo("Boo!", 1);
weapon tongue("Tongue", 0);
weapon teeth("Literally just his teeth wtf", 12);
weapon bigtongue("Big Tongue", 14);
weapon FIST("Fist", 15);
// Enemies
enemy snail("Snail", "Snails", 20, 20, tongue);
enemy rMonster("Rock Monster", "Rock Monsters", 40, 40, rock);
enemy wolf("Wolf", "Wolves", 20, 20, claws);
enemy goblin("Goblin", "Goblins", 25, 25, knife);
enemy knight("Knight", "Knights", 40, 40, sword);
enemy wizard("Iyengar", "", 60, 60, book);
enemy ghost("Spooky Ass Demon", "", 25, 25, boo);
enemy swift("The Ghost of Phil Swift", "", 40, 40, flextape);
enemy Shia("Shia Labeouf", "", 22, 22, spike);
enemy Shia2("Shia Labeouf", "", 45, 45, teeth);
enemy kingsnail("King Snail", "", 40, 40, bigtongue);
enemy YETI("YETI", "", 40, 40, FIST);
// Player 1
playerNPC player1("", 20, dagger, 30);

// A time counter used as delay between output
void delay(unsigned int secs) { // Delay between outputs
	unsigned int end = time(0) + secs;
	while (time(0) < end);
	cout << "\n";
}

void detailChar(enemy e) { // Details the enemy
	cout << "| " << e.name << ": " << e.health << " Health, " << e.w.damageW << " Damage. " << endl;
}

void fight(playerNPC player1, enemy e, int x, int z) {
	char q;
	bool f;
	string y;
	cout << "\n----------------------------" << endl;
	if (x > 1) {
		cout << "\nYou encounter " << x << " " << e.nameP << "." << endl;
	} else {
		cout << "\nYou encounter " << x << " " << e.name << "." << endl;
	}
	detailChar(e);
	for (int i = 0; i < x; i++) {
		e.health = e.maxhealth;
		char b = 0;
		bool tf = true;
		cout << "| " << e.name << " #" << i + 1 << endl; //  | Enemy #i
		while (tf) {
			cout << "\n| What would you like to do?\n(1) Attack\n(2) Heal" << endl;
			cin >> b;
			switch (b) {
			case ('1'):
				cout << "\n| You attack the " << e.name << "." << endl;
				e.health -= player1.w.damageW;
				detailChar(e);
				if (e.health > 0) {
					player1.health -= e.w.damageW;
					cout << "| The " << e.name << " hit you for " << e.w.damageW << " and you have " << player1.health << " health remaining." << endl;
				}
				break;
			case ('2'):
				cout << "| You take a second to heal." << endl;
				if (player1.healpot > 0) {
					player1.health += z;
					player1.healpot--;
					if (player1.healpot == 1) {
						y = "healpot";
					} else {
						y = "healpots";
					}
					cout << "| You healed " << z << " health and have " << player1.healpot << " " << y << " remaining." << endl;
					player1.health -= e.w.damageW;
					cout << "| The " << e.name << " hit you for   " << e.w.damageW << " and you have " << player1.health << " health remaining." << endl;
				} else { // Gives player1 health and subtracts a health pot
					cout << "No healing items remaining." << endl;
				}
				break;
			default:
				cout << "\nThat is not an option." << endl;
				break;
			}
			if (player1.health <= 0) {
				cout << "You died..." << endl;
				exit(1);
			} else if (e.health <= 0) {
				cout << e.name << " #" << i + 1 << " has died.\n " << endl;
				tf = false;
			}
		}
	}
	cout << "You win the fight!" << endl;
	cout << "----------------------------\n" << endl;
}

void chap1() { // Kruger 
	bool mom;
	int momc;
	cout << "| Chapter 1: A New Beginning" << endl;
	string inputAnswer;
	cout << "You arrive at your job, a bartender at the local pub." << endl;
	delay(2);
	cout << "The walk from home to the pub was nothing unusual, just an abnormally cold day. " << endl;
	delay(2);
	cout << "The year is 3000. You live in the country of Hoboken." << endl;
	delay(2);
	cout << "It's a dreary country. The people are either very rude or suspiciouslly nice. Sometimes there are heat waves and then the next day is a snowstorm" << endl;
	delay(5);
	cout << "The legend around town is that when there is a suddenly cold day, either good luck or bad luck would come your way. " << endl;
	delay(5);
	cout << "You pay that old-wives-tale no mind." << endl;
	delay(2);
	cout << "You wave to the people walking by. They don't know you're name but everyone is friendly atleast in your town. You then walk into the bar, and you see the daily drinkers." << endl;
	delay(3);
	cout << "The daily drinkers raise their drink and give you a toast..."<< endl;
	delay(3);
	cout << "'TO THE BEST BARTENDER IN TOWN,' they say." << endl;
	delay(3);
	cout << "You take note to the friendly gesture and give everyone a free round of drinks, on the house. " << endl;
	delay(4);
	cout << "It was a standard day, going through the motions of greeting and meeting different patrons." << endl;
	delay(4);
	cout << "...time passes on..." << endl;
	delay(5);
	cout << "The day was starting to end as you see the sun going down the mountains in the horizon." << endl;
	delay(3);
	cout << "'Hey give us some light in here, will ya? I can't even see what I'm drinking!' someone says" << endl;
	delay(4);
	cout << "You laugh at the comment and begin to note that it is getting dark. " << endl;
	delay(4);
	cout << "You go to the oil lamp to give some light in the dimly lit bar." << endl;
	delay(2);
	cout << "As you make your way to the lamp, a mysterious man approaches you. He's not anyone you've met before, but nevertheless seemed harmless. " << endl;
	delay(4);
	cout << "What would you like to do? \n 1- talk to the kind patron \n 2-hit him over the head with the lamp" << endl;
	bool lamp = true;
	int lampc;
  cin >> lampc;
	while (lamp) {
		switch (lampc) 
    {
		case 1:
    
			lamp = false;
			cout << "'What can I do for you?' you ask him. " << endl;
			delay(2);
			cout << " He quietly laughs. 'I heard you were looking for work,' he responds." << endl;
			delay(2);
			cout << "'Well I have a job bartending right here, but thank you for the offer.' You wave him away. " << endl;
			delay(3);
			cout << "He looks you in the eye and says, 'Not that kind of work.'" << endl;
			delay(4);
			cout << "You know what the man is referencing but refrain from agreeing to anything on the spot. Could he be talking about the Hoboken legend? He goes on to explain..." << endl;
			delay(3);
			cout << "'Theres an evil wizard on that mountain up there', he says as he points out the window." << endl;
			delay(3);
			cout << "'You go fight that wizard, and you'll be the richest bar tender in all of Hoboken' he says." << endl;
			delay(3);
			cout << "'How so?' you say. " << endl;
			delay(3);
			cout << "A little birdy told me today that the wizard is awake. If you didn't know, the wizard wakes up only every 5000 years in December. " << endl;
			delay(6);
			cout << "You think to yourself, 'This guy is full of it' and should probably pay him no mind." << endl;
			delay(3);
			cout << "Y'know, if theres one thing you should know about this town, its that word travels fast, and you never want to be thought to be weak by your hometown." << endl;
			delay(6);
			cout << "You hate to admit it, but it is true. The whole country of Hoboken, especially your town, turns sour on those who are believed to be weak..." << endl;
			cout << "...Responding to the passive-agressive threat, you say, 'Fine! I'll do it.'\n'I should give up drinking while I'm at it!' you say as you storm off out of the bar, making your way to the mountains." << endl;
			delay(4);
			cout << "You leave your job, knowing that the man would talk bad about you if you don't go on this journey. " << endl;
      delay(4);
			break;
		case 2:
    
			cout << "You hit him square in the face with the lamp and he goes out cold" << endl;
			delay(1);
			cout << "You had enough of that job anyways" << endl;
			delay(1);
			cout << "You grab a drink and leave" << endl;
      delay(2);
      lamp = false;
			break;
    
		}
	}
	cout << "You run out, passing your house. You slowly and quietly walk in, not wanting to disturb anyone in the house. " << endl;
	delay(3);
	cout << "You grab a scarf, health potions, and a jacket, and begin to step onto the path that travels up the mountain. " << endl;
	delay(3);
	cout << "You see your extremely talkative mom in the house" << endl;
	delay(1);
	cout << "Will you talk to her? \n 1-Sure! \n 2-Sneak out, you don't want to deal with her right now" << endl;
  cin >> momc;
	while (mom) {
		switch (momc) {
		case 1:
			mom = false;
			cout << "'Wait " << player1.name << ", where are you going?' your mother calls." << endl;
			delay(3);
			cout << "'The grocery store!' you scream back at her." << endl;
			delay(2);
			cout << "'With health potions?' she asks." << endl;
			delay(2);
			cout << "Yeah Mom, I heard there were stray bears throughout town." << endl;
			delay(4);
			break;
		case 2:
			mom = false;
			break;
		}
	}
	cout << "Your mother smiles and waves you good bye although you weren't looking back at her." << endl;
	delay(4);
	cout << "You begin to climb but you know it will be a long journey... " << endl;
	delay(3);
	cout << "...but you know it will be worth it." << endl;
	delay(3);
	cout << "~~~" << endl;
	delay(2);
	cout << "~~~" << endl;
	delay(2);
	cout << "You have been climbing the mountain for a while now, and just as you climb past some rubble a wolf jumps at you." << endl;
	delay(3);
	cout << "You grab a stick and begin to fight" << endl;
	delay(3);
	fight(player1, wolf, 1, 8);
	cout << "Confident in your self-defense you think, 'That was a close one,' and continue past the wolf's carcass." << endl;
	delay(4);
	cout << "You hear a faint wolf cry in the distance, knowing you will fight against more enemies in your travels." << endl;
	delay(3);
	cout << "You travel farther up the mountain..." << endl;
	delay(2);
	cout << "~~~" << endl;
	delay(2);
	cout << "~~~" << endl;
	delay(2);
	cout << "You begin to feel tired after traversing the mountain for hours..." << endl;
	delay(4);
	cout << "It was now really dark so you set up camp, taking out your bed, and food " << endl;
	delay(2);
	cout << "'Finally a nice break' you think to yourself..." << endl;
	delay(2);
	cout << "You begin to take out your powdered eggs from the local dinner, 'Pierce Dining Hall'" << endl;
	delay(4);
	cout << "You take one whiff and you say to yourself, 'God Damn, thats rough.'" << endl;
	delay(3);
	cout << "...HOWEVER, With the smell of your rancid food unfortunately comes three more wolves." << endl;
	delay(3);
	cout << "One wolf out of nowhere opens his mouth and says to you, 'You killed my sister's roommate's brother in law's teacher from Steven's Institute of Technology! I'll have your head!" << endl;
	delay(5);
	cout << "You have no choice but to defend yourself." << endl;
	delay(2);
	cout << "Alright, let's do this. You down the eggs and pull out the stick." << endl;
	delay(2);
	fight(player1, wolf, 3, 8);
	delay(2);
	cout << "Having beaten all the wolves, you pick the big one's massive tooth out with no remorse and carve at it while resting by the campfire..." << endl;
	delay(5);
	cout << "Before you sleep, you make a handle out of some stray wood and put your new bone knife in your back pocket.\n\n| You equip the " << dagger.name << ".\n" << endl;
	delay(3);
	player1.w.damageW = dagger.damageW;
	cout << "You are now more prepared for any enemies. You will now deal more damage." << endl;
	delay(3);
	cout << "With the knife in your backpocket, you begin to feel a little nervous for whats ahead..." << endl;
	delay(4);
	cout << "'What can come after wolves?' you say to yourself, unaware of the dangers to come." << endl;
	delay(4);
	cout << "You put away your fear and begin to walk ahead." << endl;
	delay(3);
	cout << "~~" << endl;
	delay(2);
	cout << "You've been walking for hours once again so you take out some food, making sure it is something with little smell " << endl;
	delay(3);
	cout << "You take out pizza from Pierce Dining Hall. Although there is no smell and little taste, it's better than nothing you think." << endl;
	delay(4);
	cout << "You look up ahead and you see the path diverges. You can go into the trees or you can travel behind big boulders" << endl;
	delay(3);
	cout << "You have a feeling your mental skills will be tested in the trees..." << endl;
	delay(3);
	cout << "... and yet your physical skills will be tested in the rocks. Accomplishing either task will grant a reward." << endl;
	delay(5);
	cout << "What do you do?" << endl;
	delay(2);
	cout << "Enter '1' for tree or '2' for rock " << endl;
	delay(2);
	int krugChoice;
	cin >> krugChoice;
	bool krug = true;
	while (krug == true) {
		switch (krugChoice) {
		case 1:
			krug = false;
			cout << "You start to walk to the trees. As you are walking you begin to hear faint noises coming from around the trees..." << endl;
			delay(3);
			cout << "BANG" << endl;
			delay(1);
			cout << "BOOM" << endl;
			delay(1);
			cout << "You hear a tree come down behind you. You pull out your weapon expecting another battle..." << endl;
			delay(2);
			cout << "...but nothing happens! You keep walking and you find a little goblin sitting on the ground, as if he was expecting you. " << endl;
			delay(3);
			cout << "'Very odd,' you say to yourself." << endl;
			delay(3);
			cout << "Out of curiosity, you go up to the weird looking goblin." << endl;
			delay(4);
			cout << "He looked harmless enough, no weapon to see. He only had a book with him" << endl;
			delay(3);
			cout << "'Hello?' you say, making sure not to disturb it. " << endl;
			delay(3);
			cout << "He looks at you. 'What are you doing here?' you ask." << endl;
			delay(4);
			cout << "He puts his book away, and walks up to you" << endl;
			delay(3);
			cout << "'Here is a riddle for you. What am I? If you throw me out the window, you will leave a grieving wife. Leave me in the middle of the door, and you may just save a life,' he says." << endl;
			delay(6);
			cout << "You think to yourself..." << endl;
			delay(2);
			cout << "What is the answer?" << endl;
			cin >> inputAnswer;
			if (inputAnswer == "n" || inputAnswer == "N") {
				cout << "Congragulations! Take this weapon!" << endl;
				delay(3);
				cout << "'You have a sharp mind! Now take this sharp weapon!' the goblin says with a smile." << endl;
				delay(4);
				cout << "The goblin gives you a new weapon.\n\n| You equip the " << spike.name << ".\n" << endl;
				delay(3);
				player1.w.damageW = spike.damageW;
				cout << "You are now more prepared for any enemies. You will now deal more damage." << endl;
				delay(4);
				cout << "Suddenly, the goblin dissapears out of thin air." << endl;
				delay(3);
			} else {
				cout << "You get the answer wrong and then the goblin dissapears out of thin air." << endl;
				delay(3);
			}
			cout << "You look around you, not a piece of evidence to show a goblin was just here." << endl;
			delay(3);
			cout << "You walk forward, not exactly sure on what just happened..." << endl;
			delay(3);
			cout << "...and yet you laugh at how weird that was" << endl;
			delay(3);
			break;

		case 2:
			krug = false;
			cout << "You go behind the rocks" << endl;
			delay(3);
			cout << "The air becomes dry, almost full of dust" << endl;
			delay(2);
			cout << "You take in your surroundings. It's almost beautiul the view, and yet the air makes everything seem dead." << endl;
			delay(5);
			cout << "All of a sudden, a large boulder lands from the sky and blocks the path you came from. " << endl;
			delay(3);
			cout << "'No turning back now,' you think to yourself. " << endl;
			delay(2);
			cout << "'No, there is no turning back now,' you hear from ahead of you. " << endl;
			delay(3);
			cout << "All of a sudden, a monster seemingly made of rock emerges from the big boulder in front of you. " << endl;
			fight(player1, rMonster, 1, 8);
			cout << "You beat the rock monster and he begins to crumble apart." << endl;
			delay(2);
			cout << "Little by little, every rock that makes up what he is starts to fall off. You notice the rock that made up his spine looks perfect for a weapon." << endl;
			delay(4);
			cout << "You go in to take it" << endl;
			delay(2);
			player1.w.damageW = rockSpine.damageW;
			cout << "You are now more prepared for any enemies. You will now deal more damage." << endl;
			delay(4);
			cout << "You walk forward out of the area" << endl;
			delay(2);
			break;
		default:
			cout << "Not a choice." << endl;
			break;
		}
	}
	cout << "You now are proud of your journey so far and continue up the mountain. " << endl;
	delay(3);
	cout << "You see a dirt path and you begin to walk along it. " << endl;
	delay(3);
	cout << "The path begins to become less and less clear due to not a lot of people getting this far on the path" << endl;
	delay(4);
	cout << "You walk for over 5 hours..." << endl;
	delay(2);
	cout << "...and you see a cave. You then walk inside the cave!" << endl;
  delay(1);
  cout << "You have completed this chapter \n the cheat code to skip this chapter is 'chrisk'" << endl;
  delay(5);
}


void chap2(){
	cout << "| Chapter 2: The Journey Continues |" << endl;
  delay(2);
  
  player1.health = 45;
  player1.healpot = 12;
	int firstchoice;
	int secondchoice;
	int thirdchoice;
	int fourthchoice;
	int fifthchoice;
	int sixthchoice;
	int seventhchoice;
	int eighthchoice;
	bool snailkill = false;
	bool snailcoin = false;
	bool first = true;
	bool second = true;
	bool third = true;
	bool fourth = true;
	bool fifth = true;
	bool sixth = true;
	bool seventh = true;
	bool eighth = true;
	// CONTINUE THIS FROM THE CAVE
	delay(3);
	cout << "You wake up from a good night's sleep." << endl;
	delay(2);
	cout << "You've now set up camp in the middle of a forest" << endl;
	delay(2);
	cout << "You have been wandering around since your last endeavor, waiting for adventure's call"<< endl;
  delay(2);
  cout << "Through training your health is now " << player1.health;
	delay(4);
	cout << "you hear quick footsteps in the distance" << endl;
	delay(3);
	cout << "...it's getting closer..." << endl;
	delay(2);
	cout << "You must act! \n what do you do?" << endl;
	cout << "1-run" << endl;
	cout << "2-stay and get ready to fight" << endl;
	cout << "3-curl up into a ball and pray it doesn't see you" << endl;
	cin >> firstchoice;
	// choose path
	while (first == true) {
		switch (firstchoice) {
		case 1:
			first = false;
			cout << "you turn around and sprint in the opposite direction - like a coward" << endl;
			delay(2);
			cout << "They're still gaining on you" << endl;
			delay(3);
			cout << "They're right behind you now, but you're too afraid to look..."<< endl;
			delay(3);
			cout << "...what do you do? \n 1-swing at it with your weapon \n 2-try to trip it \n 3-jump into a bush" << endl;
			cin >> secondchoice;
			while (second == true) {
				switch (secondchoice) {
				case 1:
					second = false;
					cout << "You swing your sword - but the figure is too fast"
						 << endl;
					break;
				case 2:
					second = false;
					cout << "The figure leaps over your foot and sprints into "
							"the distance"
						 << endl;
					break;
				case 3:
					second = false;
					cout << "The figure sprints past your cowardly body" << endl;
					cout << "You feel a horribly moist sensation on the back of your neck" << endl;
					delay(3);
					cout << "You turn around and it's a giant snail \n it seems like it likes you" << endl;
					delay(3);
					cout << "what to do? \n 1. give it a berry from one of the higher trees \n 2. fight it" << endl;
					cin >> fourthchoice;
					while (fourth == true) {
						switch (fourthchoice) {
						case 1:
							fourth = false;
							cout << "how kind of you \n it shows its gratitude by spitting a silver coin at your feet" << endl;
							snailcoin = true;
							delay(4);
							cout << "You give it a good pet and go on your way"<< endl;
							break;
						case 2:
							fourth = false;
							cout << "You monster! - only cowards prey on the weak!" << endl;
							fight(player1, snail, 1, 8);
							cout << "There is no honor in killing innocent creatures" << endl;
							delay(2);
							cout << "You will get your Comeuppance one day" << endl;
							snailkill = true;
							break;
						default:
							cout << "Not an option." << endl;
							break;
						}
					}
				}
			}
			break;

		case 2:
			first = false;
			cout << "You stay and fight - like a true warrior!" << endl;
			delay(2);
			cout << "You stare at the bushes, weapon in hand, ready to strike" << endl;
			delay(1);
			cout << "a dark figure appears! Act quickly!" << endl;
			cout << "1 - swing your weapon \n 2 - reconsider jumping into the bush" << endl;
			cin >> thirdchoice;
			while (third == true) {
				switch (thirdchoice) {
				case 1:
					third = false;
					cout << "You swing your sword - but the figure is too fast" << endl;
					delay(2);
					cout << "Your courage is appreciated, but the figure is already far gone"<< endl;
					break;
				case 2:
					third = false;
					cout << "The figure blows right past your cowardly body"<< endl;
					cout << "You feel a horribly moist sensation on the back of your neck"<< endl;
					delay(3);
					cout << "You turn around and it's a giant snail \n it seems like it likes you"<< endl;
					delay(3);
					cout << "what to do? \n 1. give it a berry from one of the higher trees \n 2. fight it" << endl;
					cin >> fourthchoice;
					while (fourth == true) {
						switch (fourthchoice) {
						case 1:
							fourth = false;
							cout << "how kind of you \n it shows its gratitude by spitting a silver coin at your feet" << endl;
							snailcoin = true;
							delay(4);
							cout << "You give it a good pet and go on your way" << endl;
							break;
						case 2:
							fourth = false;
							cout << "You monster! - only cowards prey on the weak!"<< endl;
							fight(player1, snail, 1, 8);
							cout << "There is no honor in killing innocent creatures" << endl;
							delay(2);
							cout << "You will get your Comeuppance one day" << endl;
							snailkill = true;
							break;
						}
					}
					delay(3);
					cout << "You turn around and it's a giant snail \n it seems like it likes you" << endl;
					delay(3);
					cout << "what to do? \n 1. give it a berry from one of the higher trees \n 2. fight it" << endl;
					cin >> fourthchoice;
					while (fourth == true) {
						switch (fourthchoice) {
						case 1:
							fourth = false;
							cout << "how kind of you \n it shows its gratitude by spitting a silver coin at your feet" << endl;
							snailcoin = true;
							delay(4);
							cout << "You give it a good pet and go on your way" << endl;
							break;
						case 2:
							fourth = false;
							cout << "You monster! - only cowards prey on the weak!" << endl;
							fight(player1, snail, 1, 8);
							cout << "There is no honor in killing innocent creatures"<< endl;
							delay(2);
							cout << "You will get your Comeuppance one day" << endl;
							snailkill = true;
							break;
						}
					}
					break;
				}
			}
			break;

		case 3:
			first = false;
			cout << "The figure sprints past your cowardly body" << endl;
			cout << "You feel a horribly moist sensation on the back of your neck" << endl;
			delay(3);
			cout << "You turn around and it's a giant snail \n it seems like it likes you" << endl;
			delay(3);
			cout << "what to do? \n 1. give it a berry from one of the higher trees \n 2. fight it" << endl;
			cin >> fourthchoice;
			while (fourth == true) {
				switch (fourthchoice) {
				case 1:
					fourth = false;
					cout << "how kind of you \n it shows its gratitude by spitting a silver coin at your feet"<< endl;
					snailcoin = true;
					delay(4);
					cout << "You give it a good pet and go on your way" << endl;
					break;
				case 2:
					fourth = false;
					cout << "You monster! - only cowards prey on the weak!" << endl;
					fight(player1, snail, 1, 8);
					cout << "There is no honor in killing innocent creatures"<< endl;
					delay(2);
					cout << "You will get your Comeuppance one day" << endl;
					snailkill = true;
					break;
				}
			}
			break;
		}
	}
	// end of while
	cout << "You should probably see where that mysterious figure went" << endl;
	delay(2);
	cout << "You see a cave in the direction that he went in" << endl;
	delay(2);
	cout << "You proceed toward the cave" << endl;
	delay(2);
	cout << "..." << endl;
	delay(1);
	cout << "it's kinda far away" << endl;
	delay(1);
	cout << "..." << endl;
	delay(2);
	cout << "..." << endl;
	delay(1);
	cout << "almost there" << endl;
	delay(2);
	cout << "..." << endl;
	delay(1);
	cout << "You've finally arrived" << endl;
	delay(1);
	cout << "You are standing at the entrance of the cave \n will you enter? \n 1 - enter \n 2 -don't" << endl;
	cin >> fifthchoice;
	while (fifth) {
		switch (fifthchoice) {
		case 1:
			fifth = false;
			cout << "good idea" << endl;
			break;
		case 2:
    fifth = false;
			cout << "Are you sure? \n will you enter? \n 1-enter \n 2-don't" << endl;
			cin >> sixthchoice;
			while (sixth) {
				switch (sixthchoice) {
				case 1:
					sixth = false;
					cout << "Good thinking" << endl;
					break;
				case 2:
					sixth = false;
          cout << "Im begging you, please enter the cave \n will you enter? \n 1-enter \n 2-don't" << endl;
					cin >> seventhchoice;
					while (seventh) {
						switch (seventhchoice) {
						case 1:
							seventh = false;
							cout	<< "I'm glad you've finally come to your senses"	<< endl;
							break;
						case 2:
            seventh = false;
							cout << "You buffoon" << endl;
							delay(1);
							cout << "You came all this way for nothing?" << endl;
							delay(2);
							cout << "You will pay" << endl;
							delay(2);
							cout << "A boulder falls on your head, crushing you and killing you in the process" << endl;
							delay(2);
							cout << "You are dead" << endl;
							exit(1);
							break;
						}
					}
					break;
				}
			}
			break;
		}
	}
	cout << "You see a door to your right" << endl;
	delay(2);
	cout << "There is a slot the size of a coin in the door" << endl;
	cout << "Might you have something to fit in there" << endl;
	delay(2);
	if (snailcoin) {
		cout << "You put the snailcoin into the slot \n the door opens" << endl;
		cout << "inside the room is an extremely slimy sword" << endl;
		cout << "1 - pick up the sword. 2- don't" << endl;
    cin >> eighthchoice;
		while (eighth) {
			switch (eighthchoice) {
			case 1:
				eighth = false;
				cout << "You obtained the sword of the snail!" << endl;
				player1.w.damageW = SnailSword.damageW;
				break;
			case 2:
				cout << "Are you sure? He lookin kinda strong doe..." << endl;
				break;
			}
		}
	} else {
		cout << "perhaps not" << endl;
	}
	cout << "You see a light deeper in the cave and start walking towards it" << endl;
	delay(4);
	cout << "sitting on his throne is..." << endl;
	delay(2);
	cout << "Hollywood superstar Shia Labeouf!" << endl;
	delay(2);
	cout << "He's also a cannibal apparently" << endl;
	delay(1);
	cout << "'I tried to leave you be, but you've left me no choice!'" << endl;
	delay(2);
	cout << "I WILL CONSUME YOUR FLESH" << endl;
	delay(1);
	cout << "The exit closes behind you" << endl;
	delay(1);
	cout << "You must fight for your life with Shia Labeouf" << endl;
	fight(player1, Shia, 1, 15);
  delay(1);
	cout << "You have just slain Shia Labeo-" << endl;
	delay(2);
	cout << "Oh wait he isn't dead! Shia Suprise!" << endl;
  delay(3);
	fight(player1, Shia2, 1, 15);
	cout << "Congrats - Now you have actually slain Shia Labeouf" << endl;
  delay(1);
	cout << "The top of the cave opens up and a giant snail with a crown on its head comes floating down" << endl;
	delay(2);
	cout << "'Thank you for saving our kingdom from Shia's reign of terror'" << endl;
	delay(1);
	if (snailkill) {
		cout << "However, you killed my son" << endl;
		delay(1);
		cout << "prepare to die" << endl;
		fight(player1, kingsnail, 1, 15);
		cout << "You are more powerful than I expected, take these berries as a symbol of your victory over me" << endl;
		delay(2);
	} 
  else {
		cout << "Take these berries as a sign of my appreciation" << endl;
		delay(2);
	}
	cout << "You are starving, so you eat the berries" << endl;
	delay(2);
	cout << "They taste amazing" << endl;
	delay(1);
	cout << "..." << endl;
	delay(1);
	cout << "Everything is getting darker" << endl;
	delay(1);
	cout << "..." << endl;
	delay(1);
	cout << "..." << endl;
	delay(1);
  cout << "You have completed this chapter \n the cheat code to skip this chapter is 'kevinf'" << endl;
  delay(5);
} // end of function

void chap3() {
	cout << "| Chapter 3: Dreamland" << endl; 
  player1.health=25;
	delay(3);
	cout << "You wake from a dank ass nightmare. In a cold sweat you turn on the tv." << endl;
	delay(3);
	cout << "*static*" << endl;
	delay(3);
	cout << "'Hm. None of the channels seem to be working.' you think." << endl;
	delay(2);
	cout << "You get up and walk to the bathroom in your Harambe boxers." << endl;
	delay(3);
	cout << "Feeling a bit woozy you splash water in your face, but when you look back into the mirror a spooky ass demon is staring at you." << endl;
	delay(3);
	cout << "You take the vaccuum from the corner and prepare to fight." << endl;
	cout << "*ghostbusters song fades in*" << endl;
	player1.w.damageW = vaccuum.damageW;
	fight(player1, ghost, 1, 10);
	cout << "'Wow, it must be #2spoopy4u szn.'" << endl;
	delay(2);
	cout << "You head downstairs only to find that your living room is crowded with ghosts who all simultaneously look at you and lunge forward." << endl;
	fight(player1, ghost, 4, 10);
	delay(2);
	cout << "Exhausted from the fight you fall onto the couch and stare at the black screen on the TV trying to understand what's going on." << endl;
	delay(3);
	cout << "..." << endl;
	delay(3);
	cout << "You come to the conclusion that it's all a dream and as you begin to head back upstairs, the TV turns on." << endl;
	delay(3);
	cout << "Static." << endl;
	delay(2);
	cout << "Things get worse, however, as the ghost of Phil Swift comes out of the TV holding what looks to be a roll of flex tape.\n'I'M ABOUT TO SHOW YOU THE POWER OF FLEX SEAL!'\n He takes a swing but you duck and prepare to fight." << endl;
	fight(player1, swift, 1, 10);
	cout << "'THAT'S A LOT OF DAMAGE!' the demon cries as he's sucked back into the TV." << endl;
	delay(3);
	cout << "After breathing a sigh of relief your body falls into the floor." << endl;
	delay(2);
	cout << "You wake up again, but this you're back on the mountain. Looking around, you feel as if everything is back to normal and go back to sleep." << endl;
	player1.w.damageW = sword.damageW;
  cout << "You have completed this chapter \n the cheat code to skip this chapter is 'chrisy'" << endl;
  delay(5);
}

void chap4() {
	int choice1;
	int choice2;
	int choice2a;
	bool tf = true;
	bool tf2 = true;
	delay(2);
	cout << "| Chapter 4 " << endl;
	delay(3); 
	cout << "Your journey has been long and treacherous \nYou feel fatigued in every step you take but you press on. " << endl;
	delay(2);
	cout << "You hear your stomach growl\nWould you like to:\n 1-Eat the wild berries on the ground\n 2-Continue your ascent" << endl;
	cin >> choice1;
	while (tf) {
		switch (choice1) {
		case 1: {
			cout << "You eat the berries\nThe taste is incomparable to nothing you've ever had before." << endl;
			delay(4);
			cout << "Suddenly you double over in pain." << endl;
			player1.health -= 2;
			cout << "Your health is now " << player1.health << endl;
			tf = false;
			break;
		}
		case 2: {
			delay(1);
			cout << "Those berries looked sketch anyway\nNot worth the stomach ache." << endl;
			delay(2);
			cout << "As you continue you become more desperate" << endl;
			delay(2);
			cout << "Maybe you don't need your arm so much... it's looking mighty tasty" << endl;
			tf = false;
			break;
		}
		} // end switch
	}	 // end while
	delay(2);
	cout << "You start to feel weak" << endl;
	delay(2);
	cout << "You see a figure in the distance" << endl;
	delay(2);
	cout << "IT'S THE YETI" << endl;
	cout << "Is he friendly? \n1-Try to befriend the Yeti \n2-Fight the Yeti" << endl;
	cin >> choice2;
	tf = true;
	while (tf) {
		switch (choice2) {
		case 1: {
			cout << "You call out to the yeti" << endl;
			delay(1);
			cout << "He quickly looks in your direction then motions for you to follow him into his cave" << endl;
			delay(2);
			cout << "Do you:\n1-Follow him\nor\n2-continue on your way" << endl;
			cin >> choice2a;
			while (tf2) {
				switch (choice2a) {
				case 1: {
					cout << "You follow him into his cave" << endl;
					delay(2);
					cout << "You are greeted by a warm fire" << endl;
					delay(2);
					cout << "The Yeti offers you a grand meal of boneless wings and a sprite"<< endl;
					delay(2);
					cout << "You wonder how he got Cluck-U this high up the mountain but you're too hungry to question it"<< endl;
					delay(3);
					player1.health += 45;
					cout << "Your health is now " << player1.health;
					delay(2);
					cout << "You tell the yeti about your journey while you eat\nHe listens attentively" << endl;
					delay(2);
					cout << "You thank him for the food and tell him you must be on your way" << endl;
					delay(2);
					cout << "On your way out the cave the Yeti stops you" <<endl;
					cout << "He presents to you an ICE SPEAR\nIts power is like nothing you've ever seen." << endl;
					player1.w.damageW = ICESPEAR.damageW;
          cout << "Your damage is now " << player1.w.damageW << endl;
					tf2 = false;
					break;
				}
				case 2: {
					delay(1);
					cout << "Maybe it's better to avoid him completely" << endl;
					delay(1);
					tf2 = false;
					break;
				}
				}
			}
			tf = false;
			break;
		}
		case 2: {
			cout << "You decide to attack while you still have the element of surprise "<< endl;
			fight(player1, YETI, 1, 15);
			tf = false;
			break;
		}
		}
	}
  delay(1);
	cout << "You continue on your ascent" << endl;
  delay(1);
  cout << "You can now see the peak of the mountain" << endl;
  delay(2);
  cout << "Everything has lead up to this" << endl;
  delay(2);
  cout << "Now with Iyengar in your sights you challenge him to a fight" << endl;
  delay(2);
  cout << "'You have come to take my knowledge of code?'\nYou'll have to kill me for it" << endl;
  fight(player1, wizard, 1, 17);
  cout << "ARGH YOU HAVE DEFEATED ME " << endl;
  delay(2);
  cout << "With this new coding knowledge the world becomes yours" << endl;
  delay(1);
  cout << "THE END" << endl;

}

int main() {
	string f;
	string q;
	cout << "Welcome to The Kookiest, Wackiest Adventure of a Cool yet Charismatic Character! We decided to create a 'linear' adventure game to test the logistics and practice our story telling" << endl;
	cout << "This project was written by Chris Youngclaus, Chris Kruger, Kevin Finck, and Liam Velazquez." << endl;
	// STORY PART
	cout << "Greetings, traveler. Whats your name?" << endl;
	cin >> player1.name;
	if (player1.name == "Kruger" || player1.name == "kruger") {
		cout << "Please confirm that the name you have selected is 'Idiot'" << endl;
		cin >> f;
		if (f == "Chris" || "chris" || "Idiot" || "idiot" || "Yes" || "yes" || "Kruger" || "kruger" || "Mark" || "mark") {
			player1.name = "an Idiot";
		}
	}
  if (player1.name == "Mark" || player1.name == "mark") {
    player1.name = "the kid who doesn't leave his room";
  }
	cout << "You are " << player1.name << ", a legend in the making." << endl;
	delay(2);
  string h;
  h = player1.name;
  if(h == "chrisk"){
  chap2();
	chap3();
	chap4();
  }
  else if(h == "kevinf"){
  chap3();
	chap4();
  }
  else if( h == "chrisy"){
  chap4();
  }
  else{
  chap1();
  chap2();
	chap3();
	chap4();
  }
}