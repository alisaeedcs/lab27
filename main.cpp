#include <iostream>
#include <map>
#include <tuple>
#include <string>
#include <vector>
using namespace std;


int main_menu();
void add_villager(map<string, tuple<int, string, string>>&);
void del_villager(map<string, tuple<int, string, string>>&);
void increase_friendship(map<string, tuple<int, string, string>>&);
void decrease_friendship(map<string, tuple<int, string, string>>&);
void search(map<string, tuple<int, string, string>>&);
void display_all(map<string, tuple<int, string, string>>& mapp);

int main() {
    cout << "Villager Map!" << endl;
    // declarations
    map<string, tuple<int, string, string>> villagerColors;

    int choice = 0;
    while (choice != 6) {
        choice = main_menu();
        switch(choice) {
            case 1:
                add_villager(villagerColors);
                break;
            case 2:
                del_villager(villagerColors);
                break;
            case 3:
                increase_friendship(villagerColors);
                break;
            case 4:
                decrease_friendship(villagerColors);
                break;
            case 5:
                search(villagerColors);
                break;
            case 6:
                display_all(villagerColors);
                break;
            default: 
                cout << "Invalid choice.\n";
        }
    }
//took a little long because coderunner errors in vscode
    return 0;
}

int main_menu() {
    cout << "1. Add Villager" << endl;
    cout << "2. Delete Villager" << endl;
    cout << "3. Increase Friendship" << endl;
    cout << "4. Decrease Friendship" << endl;
    cout << "5. Search for Villager" << endl;   
    cout << "6. Exit" << endl;
    cout << "Enter choice: ";
    int choice;
    cin >> choice;
    return choice;
}

void add_villager(map<string, tuple<int, string, string>>& mapp) {
    string name, species, catchphrase;
    int friendship; 
    cout << "\tVillager name: ";
    cin.ignore();
    getline(cin, name);
    cout << "\tFriendship level: ";
    cin >> friendship;
    cout << "\tSpecies: ";
    cin.ignore();
    getline(cin, species);
    cout << "\tCatchphrase: ";
    getline(cin, catchphrase);
    mapp[name] = make_tuple(friendship, species, catchphrase);
    cout << "\t" << name << " added." << endl;
}

void del_villager(map<string, tuple<int, string, string>>& mapp) {
    string name;
    cout << "\tEnter villager name: ";
    cin.ignore();
    getline(cin, name);

    auto it = mapp.find(name);
    
    mapp.erase(name);
    cout << "\t" << name << " deleted." << endl;
}

void increase_friendship(map<string, tuple<int, string, string>>& mapp) {
    string name;
    cout << "\tEnter villager name: ";
    cin.ignore();
    getline(cin, name);

    auto it = mapp.find(name);
    if (it != mapp.end()) {
        int &friendship = get<0>(it->second);
        if (friendship < 10) {
            friendship++;
            cout << "\t" << name << "'s friendship level has increased\n";
        }
        else {
            cout << "\t" << name << "'s friendship level is at maximum\n";
        }
    }
    else {
        cout << "\t" << "Not in map\n";
    }
}

void decrease_friendship(map<string, tuple<int, string, string>>& mapp) {
    string name;
    cout << "\tEnter villager name: ";
    cin.ignore();
    getline(cin, name);

    auto it = mapp.find(name);
    if (it != mapp.end()) {
        int &friendship = get<0>(it->second);
        if (friendship > 0) {
            friendship--;
            cout << "\t" << name << "'s friendship level has decreased\n";
        }
        else {
            cout << "\t" << name << "'s friendship level is at minimum\n";
        }
    }
    else {
        cout << "\tNot in map\n";
    }
}

void search(map<string, tuple<int, string, string>>& mapp) {
    string name;
    cout << "\tEnter villager name: ";
    cin.ignore();
    getline(cin, name);

    auto it = mapp.find(name);
    if (it != mapp.end()) {
        int &friendship = get<0>(it->second);
        string &species = get<1>(it->second);
        string &catchphrase = get<2>(it->second);
        cout << "\tVillager Found: " << name << "[" << friendship << ", " << species << ", " << catchphrase << "]\n";
    }
    else {
        cout << "\tVillager not found\n";
    }

}

void display_all(map<string, tuple<int, string, string>>& mapp) {
    if (mapp.empty()) {
        cout << "No villagers." << endl;
        return;
    }

    cout << "\tVillager Details: \n";
    for (const auto& [name, info] : mapp) {
        int friendship = get<0>(info);
        string species = get<1>(info);
        string catchphrase = get<2>(info);
        cout << "\t" << name << " [" << friendship << ", " << species << ", " << catchphrase << "]\n";
    }

}

