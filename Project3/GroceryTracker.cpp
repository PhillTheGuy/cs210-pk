#include "GroceryTracker.h"

using namespace std;
//Reads Input file
void GroceryTracker::readInputFile(const string& filename) {
    ifstream inputFile(filename);
    string item;
    if (!inputFile) {
        throw runtime_error("Error Opening input file.");
    }
    while (inputFile >> item) {
        itemFrequency[item]++;
    }

    inputFile.close();
}
//Writes frequencies in backup
void GroceryTracker::writeBackupFile(const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile) {
        throw runtime_error("Error creating backup file");
    }
    for (const auto& pair : itemFrequency) {
        outputFile << pair.first << " " << pair.second << endl;
    }
    outputFile.close();
}
// Prints out Item and the amount of times in input
void GroceryTracker::searchForItem() {
    cout << "Enter Item: ";
    string searchItem;
    cin >> searchItem;
    cout << searchItem << " " << itemFrequency[searchItem] << endl;
}
// Prints an item list
void GroceryTracker::printItemList() {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }
}
// Prints histograms for the items
void GroceryTracker::printHistogram() {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}
//Prints Main menu
void GroceryTracker::displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Search items" << endl;
    cout << "2. Print list of items" << endl;
    cout << "3. Print histogram of items" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter choice: ";
}
void GroceryTracker::run() {
    try {
        readInputFile("CS210_Project_Three_Input_File.txt.");

        int choice;
        do {
            displayMenu();
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input." << endl;
                continue;
            }
            //Make the input work for the main menu
            switch (choice) {
            case 1:
                searchForItem();
                break;
            case 2:
                printItemList();
                break;
            case 3:
                printHistogram();
                break;
            case 4:
                cout << "Exiting." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
            }
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

        } while (choice != 4);

        writeBackupFile("frequency.dat");
    }
    catch (const exception& e) {
        cout << "An error occurred: " << e.what() << endl;
    }
    catch (...) {
        cout << "An Error has occurred." << endl;
    }
}