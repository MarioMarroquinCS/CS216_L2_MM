// Mario Marroquin
// Lab #2

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int COL = 20;
const int STRENGTH = 100;
const int HEALTH = 100;
const string NAME = "Great Creature";

class Creature {
  int strength;
  int health;
  string name;

  void setCreature(int nStrength, int nHealth, string nName);

 public:
  Creature() { setCreature(STRENGTH, HEALTH, NAME); }

  Creature(int nStrength, int nHealth, string nName) {
    setCreature(nStrength, nHealth, nName);
  }

  void setHealth(int nHealth) { setCreature(strength, nHealth, name); }
  void setName(string nName) { setCreature(strength, health, nName); }

  int getHealth() const { return health; }
  int getStrength() const { return strength; }
  string getName() const { return name; }
  int getDamage() const { return (rand() % strength) + 1; }

  string toString();
};

void showMenu();
void clearFailedInput(string errorMessage);
void battle();
int getRandomAttributeValues();
string tableHeading();
string battleHeading();
string printRound();

int main() { showMenu(); }

string Creature::toString() {
  stringstream ss;

  string header;

  ss << setw(COL) << getName() << setw(COL) << getHealth() << setw(COL)
     << getStrength() << setw(COL) << endl;

  header = ss.str();

  return header;
}

void Creature::setCreature(int nStrength, int nHealth, string nName) {
  strength = nStrength;
  health = max(nHealth, 0);
  name = nName;
}

void showMenu() {
  int choice = 0;

  cout << "\nChoose an option. Input the number of your selection:\n";

  while (choice != 2) {
    cout << "1. Let's Battle\n"
         << "2. Quit" << endl;

    cin >> choice;

    switch (choice) {
      case 1:
        battle();
        break;
      case 2:
        cout << "\nProgram will now be quitting." << endl;
        break;
      default:
        clearFailedInput("Invalid choice! Please select 1 or 2.\n");
        break;
    }
  }
}

void clearFailedInput(string errorMessage) {
  cout << errorMessage;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void battle() {
  string firstCreatureName = NAME;

  cout << "What is the name of your first Creature?\n";

  cin >> firstCreatureName;
  int firstCreatureHealth = getRandomAttributeValues();
  int firstCreatureStrength = getRandomAttributeValues();

  Creature firstCreature(firstCreatureStrength, firstCreatureHealth,
                         firstCreatureName);

  string secondCreatureName = NAME;

  cout << "What is the name of your second Creature?\n";

  cin >> secondCreatureName;
  int secondCreatureHealth = getRandomAttributeValues();
  int secondCreatureStrength = getRandomAttributeValues();

  Creature secondCreature(secondCreatureStrength, secondCreatureHealth,
                          secondCreatureName);

  cout << tableHeading() << "\n"
       << firstCreature.toString() << secondCreature.toString() << endl;

  int offense = rand() % 2;
  int round = 0;
  int damage = 0;
  int newHealth = 0;

  cout << battleHeading() << endl;

  while (firstCreature.getHealth() != 0 && secondCreature.getHealth() != 0) {
    round++;

    if (offense == 0) {
      damage = firstCreature.getDamage();
      newHealth = secondCreature.getHealth() - damage;
      secondCreature.setHealth(newHealth);
      cout << setw(COL) << round << setw(COL) << firstCreature.getName()
           << setw(COL) << damage << setw(COL) << secondCreature.getName()
           << setw(COL) << secondCreature.getHealth() << endl;
      offense = 1;
    } else {
      damage = firstCreature.getDamage();
      newHealth = firstCreature.getHealth() - damage;
      firstCreature.setHealth(newHealth);
      cout << setw(COL) << round << setw(COL) << secondCreature.getName()
           << setw(COL) << damage << setw(COL) << firstCreature.getName()
           << setw(COL) << firstCreature.getHealth() << endl;
      offense = 0;
    }
  }

  if (offense == 0) {
    cout << firstCreature.getName() << " defeated " << secondCreature.getName()
         << " after " << round << " rounds." << endl;
  } else {
    cout << secondCreature.getName() << " defeated " << firstCreature.getName()
         << " after " << round << " rounds." << endl;
  }
}

int getRandomAttributeValues() {
  int min = 60;
  int max = 200;

  return rand() % (max - min) + min;
}

string tableHeading() {
  stringstream ss;

  string header;

  ss << setw(COL) << "Name" << setw(COL) << "Health " << setw(COL) << "Strength"
     << setw(COL) << endl;

  header = ss.str();

  return header;
}

string battleHeading() {
  stringstream ss;

  string header;

  ss << setw(COL) << "Round" << setw(COL) << "Attacker " << setw(COL)
     << "Damage" << setw(COL) << "Defender" << setw(COL) << "Defender Health"
     << endl;

  header = ss.str();

  return header;
}

/*
Choose an option. Input the number of your selection:
1. Let's Battle
2. Quit
1
What is the name of your first Creature?
Mario
What is the name of your second Creature?
Juan
                Name             Health             Strength

               Mario                  67                 109
                Juan                 153                 178

               Round           Attacker               Damage            Defender     Defender Health

                   1               Mario                  97                Juan                  56
                   2                Juan                  23               Mario                  44
                   3               Mario                  77                Juan                   0
Mario defeated Juan after 4 rounds.
1. Let's Battle
2. Quit
2

Program will now be quitting.
 */
