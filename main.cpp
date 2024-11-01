#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int main_menu();
void add_villager(map<string, tuple<int, string, string>>&);
void del_villager(map<string, tuple<int, string, string>>&);
void increase_friendship(map<string, tuple<int, string, string>>&);
void decrease_friendship(map<string, tuple<int, string, string>>&);
void search(map<string, tuple<int, string, string>>&);

int main() {
    cout << "Villager Map!" << endl;
    // declarations
    map<string, tuple<int, string, string>> villagerColors;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
   ///     for (auto color : pair.second)
     //       cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

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
    cout << "Villager name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Friendship level: ";
    cin >> friendship;
    cout << "Species: ";
    cin.ignore();
    getline(cin, species);
    cout << "Catchphrase: ";
    cin.ignore();
    getline(cin, catchphrase);
    mapp[name] = make_tuple(friendship, species, catchphrase);
    cout << name << " added." << endl;
}

void delete_villager(map<string, tuple<int, string, string>>& mapp) {
    string name;
    cout << "Enter villager name: ";
    cin.ignore();
    getline(cin, name);
    mapp.erase(name);
    cout << name << " deleted." << endl;
}

void increase_friendship(map<string, tuple<int, string, string>>& mapp) {
    string name;
    cout << "Enter villager name: ";
    cin.ignore();
    getline(cin, name);

    auto it = mapp.find(name);
    if (it != mapp.end()) {
        int &friendship = get<0>(it->second);
        if (friendship < 10) {
            friendship++;
            cout << name << "'s friendship level has increased\n";
        }
        else {
            cout << name << "'s friendship level is at maximum\n";
        }
    }
    else {
        cout << "Not in map\n";
    }
}

void decrease_friendship(map<string, tuple<int, string, string>>& mapp) {
    string name;
    cout << "Enter villager name: ";
    cin.ignore();
    getline(cin, name);

    auto it = mapp.find(name);
    if (it != mapp.end()) {
        int &friendship = get<0>(it->second);
        if (friendship > 0) {
            friendship--;
            cout << name << "'s friendship level has decreased\n";
        }
        else {
            cout << name << "'s friendship level is at minimum\n";
        }
    }
    else {
        cout << "Not in map\n";
    }
}

void search(map<string, tuple<int, string, string>>&) {
    
}

