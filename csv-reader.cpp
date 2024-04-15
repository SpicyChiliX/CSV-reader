#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

/* struct for storing information we read, example used is player information for a game  */

struct PlayerRecord {
public:
	PlayerRecord(
		int id,
		string name,
		int hp,
		string weapon,
		int xp,
		int level
	) {
		ID = id;
		NM = name;
		HP = hp;
		WP = weapon;
		XP = xp;
		LVL = level;
	}

	void display() {
		cout << "	ID: " << ID << endl;
		cout << "	Name: " << NM << endl;
		cout << "	HP: " << HP << endl;
		cout << "	Weapon: " << WP << endl;
		cout << "	XP: " << XP << endl;
		cout << "	Level: " << LVL << endl;
		cout << endl;
	}

	int ID;
	string NM;
	int HP;
	string WP;
	int XP;
	int LVL;
};

void displayPlayers(vector<PlayerRecord>& players) {

	for (auto player : players) {
		player.display();
	}
}

int main() {
	ifstream inputFile;
	inputFile.open("players.csv");
	string line = "";

	vector<PlayerRecord> players;
	while (getline(inputFile, line)) {
		stringstream inputString(line);

		int id;
		string name;
		int hp;
		string weapon;
		int xp;
		int level;
		string tempString;

		getline(inputString, tempString, ',');
		id = atoi(tempString.c_str());
		getline(inputString, name, ',');
		getline(inputString, tempString, ',');
		hp = atoi(tempString.c_str());
		getline(inputString, weapon, ',');
		getline(inputString, tempString, ',');
		xp = atoi(tempString.c_str());
		getline(inputString, tempString, ',');
		level = atoi(tempString.c_str());

		PlayerRecord player(id, name, hp, weapon, xp, level);
		players.push_back(player);
		line = "";
	}
    
    inputFile.close();

    displayPlayers(players);
}
