#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

struct Appliance {
    int id;
    string name;
    double power;   // Watts
    double hours;   // hours per day
    double days;    // number of days
};

vector<Appliance> appliances;
int nextId = 1; // FIXED ID SYSTEM

// FIND APPLIANCE BY ID
int findIndexById(int id) {
    for (int i = 0; i < appliances.size(); i++) {
        if (appliances[i].id == id) {
            return i;
        }
    }
    return -1;
}

// MANUAL CALCULATION
void manualCalculation() {
    cout << "\n=== MANUAL BILL CALCULATION ===\n";

    double kwh, rate;

    cout << "Enter total kWh used: ";
    cin >> kwh;

    if (cin.fail() || kwh < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input!\n";
        return;
    }

    cout << "Enter rate per kWh: ";
    cin >> rate;

    if (cin.fail() || rate < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input!\n";
        return;
    }

    cout << fixed << setprecision(2);
    cout << "TOTAL BILL: PHP " << kwh * rate << "\n";
}

// ADD APPLIANCE
void addAppliance() {
    cout << "\n=== ADD APPLIANCE ===\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        Appliance app;

        app.id = nextId++; // FIXED ID

        cout << "Appliance name: ";
        getline(cin, app.name);

        cout << "Power (Watts): ";
        cin >> app.power;

        cout << "Hours used per day: ";
        cin >> app.hours;

        cout << "Days used: ";
        cin >> app.days;

        if (cin.fail() || app.name.empty() || app.power < 0 || app.hours < 0 || app.days < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Not added.\n";
        } else {
            appliances.push_back(app);
            cout << "Added successfully! ID: " << app.id << "\n";
        }

        cout << "Add another? (y/n): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// VIEW APPLIANCES
void viewAppliances() {
    cout << "\n=== APPLIANCE RECORDS ===\n";

    if (appliances.empty()) {
        cout << "No appliances found.\n";
        return;
    }

    cout << fixed << setprecision(2);

    for (const auto &app : appliances) {
        double kwh = (app.power * app.hours * app.days) / 1000;

        cout << "\n---------------------------------\n";
        cout << "ID    : " << app.id << "\n";
        cout << "Name  : " << app.name << "\n";
        cout << "Power : " << app.power << " W\n";
        cout << "Hours : " << app.hours << " /day\n";
        cout << "Days  : " << app.days << "\n";
        cout << "kWh   : " << kwh << "\n";
        cout << "---------------------------------\n";
    }
}

// UPDATE APPLIANCE
void updateAppliance() {
    cout << "\n=== UPDATE APPLIANCE ===\n";

    int id;
    cout << "Enter Appliance ID: ";
    cin >> id;

    int index = findIndexById(id);

    if (index == -1) {
        cout << "Appliance not found!\n";
        return;
    }

    Appliance &app = appliances[index];

    cin.ignore();

    cout << "New name (" << app.name << "): ";
    getline(cin, app.name);

    cout << "New power: ";
    cin >> app.power;

    cout << "New hours/day: ";
    cin >> app.hours;

    cout << "New days: ";
    cin >> app.days;

    if (cin.fail() || app.power < 0 || app.hours < 0 || app.days < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid update!\n";
        return;
    }

    cout << "Updated successfully!\n";
}

// DELETE APPLIANCE
void deleteAppliance() {
    cout << "\n=== DELETE APPLIANCE ===\n";

    int id;
    cout << "Enter Appliance ID: ";
    cin >> id;

    int index = findIndexById(id);

    if (index == -1) {
        cout << "Appliance not found!\n";
        return;
    }

    appliances.erase(appliances.begin() + index);

    cout << "Deleted successfully!\n";
}

// CALCULATE BILL
void calculateBill() {
    cout << "\n=== APPLIANCE-BASED BILL ===\n";

    if (appliances.empty()) {
        cout << "No appliances available.\n";
        return;
    }

    double rate;
    cout << "Enter rate per kWh: ";
    cin >> rate;

    if (cin.fail() || rate < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid rate!\n";
        return;
    }

    double total_kwh = 0;

    for (const auto &app : appliances) {
        total_kwh += (app.power * app.hours * app.days) / 1000;
    }

    cout << fixed << setprecision(2);
    cout << "TOTAL kWh : " << total_kwh << "\n";
    cout << "BILL      : PHP " << total_kwh * rate << "\n";
}

// MAIN MENU
int main() {
    int choice;

    do {
        cout << "\n===================================\n";
        cout << "    ELECTRICITY BILL ESTIMATOR\n";
        cout << "===================================\n";
        cout << "[1] Manual Calculation\n";
        cout << "[2] Add Appliance\n";
        cout << "[3] View Appliances\n";
        cout << "[4] Calculate Bill\n";
        cout << "[5] Update Appliance\n";
        cout << "[6] Delete Appliance\n";
        cout << "[7] Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!\n";
            continue;
        }

        switch (choice) {
            case 1: manualCalculation(); break;
            case 2: addAppliance(); break;
            case 3: viewAppliances(); break;
            case 4: calculateBill(); break;
            case 5: updateAppliance(); break;
            case 6: deleteAppliance(); break;
            case 7: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}