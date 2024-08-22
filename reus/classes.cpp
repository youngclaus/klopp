#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <functional>
#include <sstream>
#include <cstdlib>

using namespace std;

class weapon {
public:
	string name;
	int damageW;
  weapon(string name, int damageW): 
    name(name), damageW(damageW){}
};

class playerNPC {
public:
	string name;
	int health;
	weapon w;
  int healpot;
  playerNPC(string name, int health, weapon w, int healpot):
    name(name), health(health), w(w), healpot(healpot){}
};

class enemy {
public:
	string name;
  string nameP;
  int maxhealth;
  int health;
  weapon w;
  enemy(string name, string nameP, int maxhealth, int health, weapon w): 
    name(name), nameP(nameP), maxhealth(maxhealth), health(health), w(w){}
};