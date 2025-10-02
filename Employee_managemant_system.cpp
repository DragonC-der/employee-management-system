#include <bits/stdc++.h>
using namespace std;

struct Employee {
    string id;
    string name;
    string address;
    string dob;
    string maritalStatus;
    string doj;
    string department;
    string location;
    string ctc;
    string socialInsuranceId;
    string mobile;
    string email;
};

vector<Employee> employees;

// Utility function to get input
string input(string prompt) {
    string value;
    cout << prompt;
    getline(cin, value);
    return value;
}

void addEmployee() {
    int count;
    cout << "How many employees do you want to add? ";
    cin >> count;
    cin.ignore(); // clear newline

    for (int i = 1; i <= count; i++) {
        Employee emp;
        cout << "\nEnter data for Employee " << (i) << ":\n";

        cout << "\n--- PERSONAL DETAILS ---\n";
        emp.name = input("Name: ");
        emp.address = input("Address: ");
        emp.dob = input("Date of Birth (DD/MM/YYYY): ");
        emp.maritalStatus = input("Marital Status: ");

        cout << "\n--- WORK DETAILS ---\n";
        emp.id = input("Employee ID: ");
        emp.doj = input("Date of Joining (DD/MM/YYYY): ");
        emp.department = input("Department: ");
        emp.location = input("Work Location: ");
        emp.ctc = input("CTC: ");
        emp.socialInsuranceId = input("Social Insurance ID: ");

        cout << "\n--- CONTACT DETAILS ---\n";
        emp.mobile = input("Mobile Number: ");
        emp.email = input("Email: ");

        employees.emplace_back(emp);
        cout << "\nEmployee added successfully!\n";
    }
}

void showEmployees() {
    if (employees.empty()) {
        cout << "No employee records found.\n";
        return;
    }
    else
    cout << "\n========= EMPLOYEE LIST =========\n";
    for (int i = 0; i < employees.size(); i++) {
        const Employee& emp = employees[i];
        cout << "\nEmployee " << (i + 1) << ":\n";
        cout << "Name: " << emp.name << "\n";
        cout << "Address: " << emp.address << "\n";
        cout << "DOB: " << emp.dob << "\n";
        cout << "Marital Status: " << emp.maritalStatus << "\n";
        cout << "ID: " << emp.id << "\n";
        cout << "DOJ: " << emp.doj << "\n";
        cout << "Department: " << emp.department << "\n";
        cout << "Location: " << emp.location << "\n";
        cout << "CTC: " << emp.ctc << "\n";
        cout << "Social Insurance ID: " << emp.socialInsuranceId << "\n";
        cout << "Mobile: " << emp.mobile << "\n";
        cout << "Email: " << emp.email << "\n";
    }
}

void searchEmployee() {
    string searchId;
    cout << "Enter Employee ID to search: ";
    cin.ignore();
    getline(cin, searchId);

    bool found = false;
    for (auto emp : employees) {
        if (emp.id == searchId) {
            found = true;
            cout << "\nEmployee Found:\n";
            cout << "Name: " << emp.name << "\n";
            cout << "Address: " << emp.address << "\n";
            cout << "DOB: " << emp.dob << "\n";
            cout << "Marital Status: " << emp.maritalStatus << "\n";
            cout << "ID: " << emp.id << "\n";
            cout << "DOJ: " << emp.doj << "\n";
            cout << "Department: " << emp.department << "\n";
            cout << "Location: " << emp.location << "\n";
            cout << "CTC: " << emp.ctc << "\n";
            cout << "Social Insurance ID: " << emp.socialInsuranceId << "\n";
            cout << "Mobile: " << emp.mobile << "\n";
            cout << "Email: " << emp.email << "\n";
            break;
        }
    }

    if (!found)
        cout << "Employee with ID " << searchId << " not found.\n";
}

void updateEmployee() {
    string updateId;
    cout << "Enter Employee ID to update: ";
    cin.ignore();
    getline(cin, updateId);

    for (auto emp : employees) {
        if (emp.id == updateId) {
            cout << "\nEnter new data for Employee ID " << updateId << ":\n";

            emp.name = input("Name: ");
            emp.address = input("Address: ");
            emp.dob = input("Date of Birth: ");
            emp.maritalStatus = input("Marital Status: ");
            emp.doj = input("Date of Joining: ");
            emp.department = input("Department: ");
            emp.location = input("Work Location: ");
            emp.ctc = input("CTC: ");
            emp.socialInsuranceId = input("Social Insurance ID: ");
            emp.mobile = input("Mobile: ");
            emp.email = input("Email: ");

            cout << "Employee record updated successfully.\n";
            return;
        }
    }

    cout << "Employee with ID " << updateId << " not found.\n";
}

void deleteEmployee() {
    string deleteId;
    cout << "Enter Employee ID to delete: ";
    cin.ignore();
    getline(cin, deleteId);

    for (auto it = employees.begin(); it != employees.end(); it++) {
        if (it->id == deleteId) {
            employees.erase(it);
            cout << "Employee record deleted successfully.\n";
            return;
        }
    }

    cout << "Employee with ID " << deleteId << " not found.\n";
}

void deleteAllEmployees() {
    char confirm;
    cout << "Are you sure you want to delete ALL employee records? (y/n): ";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y') {
        employees.clear();
        cout << "All employee records deleted.\n";
    } else {
        cout << "Operation cancelled.\n";
    }
}

int main() {
    int choice;
    int j = 0;
    do {
        cout << "\n===== EMPLOYEE MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Employee\n";
        cout << "2. Show All Employees\n";
        cout << "3. Search Employee\n";
        cout << "4. Update Employee\n";
        cout << "5. Delete Specific Employee\n";
        cout << "6. Delete All Employees\n";
        cout << "7. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1: addEmployee(); break;
        case 2: showEmployees(); break;
        case 3: searchEmployee(); break;
        case 4: updateEmployee(); break;
        case 5: deleteEmployee(); break;
        case 6: deleteAllEmployees(); break;
        case 7: cout << "Please, do visit again\n"; break;
        default: cout << "Invalid choice. Try again.\n"; break;
        j++;
        }

    } while (choice != 7);

    return 0;
}
