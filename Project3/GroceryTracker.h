#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <limits>

using namespace std;

class GroceryTracker {
private:
    map<std::string, int> itemFrequency;
    void readInputFile(const string& filename);
    void writeBackupFile(const string& filename);
    void searchForItem();
    void printItemList();
    void printHistogram();
    void displayMenu();

public:
    void run();
};