#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Player {
    string name;
    int points;
    int assists;
    int rebounds;
};

void addPlayer(vector<Player>& players) {
    Player p;
    cout << "\nEnter player name: ";
    cin >> p.name;

    cout << "Points: ";
    cin >> p.points;

    cout << "Assists: ";
    cin >> p.assists;

    cout << "Rebounds: ";
    cin >> p.rebounds;

    players.push_back(p);
    cout << "Player added!\n";
}

void viewPlayers(const vector<Player>& players) {
    cout << "\n=== Player List ===\n";

    if (players.empty()) {
        cout << "No players yet.\n";
        return;
    }

    for (int i = 0; i < players.size(); i++) {
        cout << i + 1 << ". " << players[i].name
             << " | Pts: " << players[i].points
             << " | Ast: " << players[i].assists
             << " | Reb: " << players[i].rebounds << "\n";
    }
}
// AI from here
void saveToFile(const vector<Player>& players) {
    ofstream out("players.txt");

    for (const Player& p : players) {
        out << p.name << " "
            << p.points << " "
            << p.assists << " "
            << p.rebounds << "\n";
    }

    cout << "Saved to players.txt\n";
}

void loadFromFile(vector<Player>& players) {
    ifstream in("players.txt");

    if (!in.is_open()) {
        cout << "No saved file found. Starting fresh.\n";
        return;
    }

    Player p;
    while (in >> p.name >> p.points >> p.assists >> p.rebounds) {
        players.push_back(p);
    }

    cout << "Loaded saved players.\n";
}
// AI from to here

int main() {
    vector<Player> players;
    loadFromFile(players);

    int choice;

    while (true) {
        cout << "\n=== Sports Stats Tracker ===\n";
        cout << "1. Add Player\n";
        cout << "2. View Players\n";
        cout << "3. Save & Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            addPlayer(players);
        }
        else if (choice == 2) {
            viewPlayers(players);
        }
        else if (choice == 3) {
            saveToFile(players);
            cout << "Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
