#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Medicine struct for medicine information
struct Medicine {
    int id;
    string name;
    double price;
    int quantity;
    string expiry_date;

    // Display medicine details
    void display() const {
        cout << setw(10) << id 
             << setw(20) << name 
             << setw(10) << price 
             << setw(10) << quantity 
             << setw(15) << expiry_date << "\n";
    }
};

// Inventory class to manage medicine stock
class Inventory {
private:
    unordered_map<int, Medicine> medicines;

public:
    // Add new medicine to inventory
    void addMedicine(const Medicine& med) {
        medicines[med.id] = med;
        cout << "Medicine added successfully!\n";
    }

    // Delete medicine by ID
    void deleteMedicine(int id) {
        if (medicines.erase(id)) {
            cout << "Medicine deleted successfully!\n";
        } else {
            cout << "Medicine not found.\n";
        }
    }

    // Update medicine details
    void updateMedicine(int id) {
        if (medicines.find(id) != medicines.end()) {
            Medicine& med = medicines[id];
            cout << "Enter new details:\n";
            cout << "Name: "; cin >> med.name;
            cout << "Price: "; cin >> med.price;
            cout << "Quantity: "; cin >> med.quantity;
            cout << "Expiry Date: "; cin >> med.expiry_date;
            cout << "Medicine updated successfully!\n";
        } else {
            cout << "Medicine not found.\n";
        }
    }

    // Search medicine by ID
    Medicine* searchMedicine(int id) {
        if (medicines.find(id) != medicines.end()) {
            return &medicines[id];
        }
        cout << "Medicine not found.\n";
        return nullptr;
    }

    // Display all medicines in stock
    void displayStock() {
        cout << setw(10) << "ID" 
             << setw(20) << "Name" 
             << setw(10) << "Price" 
             << setw(10) << "Qty" 
             << setw(15) << "Expiry Date\n";
        for (const auto& pair : medicines) {
            const Medicine& med = pair.second;
            med.display();
        }
    }

    // Get a reference to medicines map (for use in Receipt class)
    const unordered_map<int, Medicine>& getMedicines() const {
        return medicines;
    }
};

// Receipt class for handling sales and receipt generation
class Receipt {
private:
    struct Sale {
        int medicine_id;
        int quantity;
        double total_price;
    };
    
    Inventory& inventory;
    vector<Sale> sales;

public:
    Receipt(Inventory& inv) : inventory(inv) {}

    // Add a sale to the receipt
    void addSale(int id, int quantity) {
        Medicine* med = inventory.searchMedicine(id);
        if (med && med->quantity >= quantity) {
            double total_price = quantity * med->price;
            sales.push_back({id, quantity, total_price});
            med->quantity -= quantity; // Reduce inventory stock
            cout << "Sale added successfully! Total Price: " << total_price << "\n";
        } else {
            cout << "Insufficient quantity or medicine not found.\n";
        }
    }

    // Print receipt
    void printReceipt() {
        cout << "Receipt:\n";
        cout << setw(10) << "ID" 
             << setw(20) << "Quantity" 
             << setw(15) << "Total Price\n";
        for (const Sale& sale : sales) {
            cout << setw(10) << sale.medicine_id 
                 << setw(20) << sale.quantity 
                 << setw(15) << sale.total_price << "\n";
        }
    }
};

// Database class for managing file operations
class Database {
private:
    const string filename = "inventory.txt";

public:
    // Save inventory to a file
    void saveInventory(const Inventory& inventory) {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& pair : inventory.getMedicines()) {
                const Medicine& med = pair.second;
                file << med.id << "\n" << med.name << "\n" 
                     << med.price << "\n" << med.quantity << "\n" 
                     << med.expiry_date << "\n";
            }
            file.close();
            cout << "Inventory saved successfully!\n";
        } else {
            cout << "Unable to open file for saving.\n";
        }
    }

    // Load inventory from a file
    void loadInventory(Inventory& inventory) {
        ifstream file(filename);
        if (file.is_open()) {
            Medicine med;
            while (file >> med.id) {
                file.ignore(); // Ignore newline
                getline(file, med.name);
                file >> med.price >> med.quantity;
                file.ignore(); // Ignore newline
                getline(file, med.expiry_date);
                inventory.addMedicine(med);
            }
            file.close();
            cout << "Inventory loaded successfully!\n";
        } else {
            cout << "Unable to open file for loading.\n";
        }
    }
};

// Main function to run the system
int main() {
    Inventory inventory;
    Database db;
    Receipt receipt(inventory);
    int choice;

    // Load inventory at the start
    db.loadInventory(inventory);

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Medicine\n";
        cout << "2. Delete Medicine\n";
        cout << "3. Update Medicine\n";
        cout << "4. Search Medicine\n";
        cout << "5. Display Stock\n";
        cout << "6. Add Sale\n";
        cout << "7. Print Receipt\n";
        cout << "8. Save Inventory\n";
        cout << "9. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Medicine med;
                cout << "Enter ID: "; cin >> med.id;
                cout << "Enter Name: "; cin >> med.name;
                cout << "Enter Price: "; cin >> med.price;
                cout << "Enter Quantity: "; cin >> med.quantity;
                cout << "Enter Expiry Date: "; cin >> med.expiry_date;
                inventory.addMedicine(med);
                break;
            }
            case 2: {
                int id;
                cout << "Enter Medicine ID to delete: "; cin >> id;
                inventory.deleteMedicine(id);
                break;
            }
            case 3: {
                int id;
                cout << "Enter Medicine ID to update: "; cin >> id;
                inventory.updateMedicine(id);
                break;
            }
            case 4: {
                int id;
                cout << "Enter Medicine ID to search: "; cin >> id;
                Medicine* med = inventory.searchMedicine(id);
                if (med) {
                    cout << "Found Medicine: ";
                    med->display();
                }
                break;
            }
            case 5: {
                inventory.displayStock();
                break;
            }
            case 6: {
                int id, quantity;
                cout << "Enter Medicine ID: "; cin >> id;
                cout << "Enter Quantity: "; cin >> quantity;
                receipt.addSale(id, quantity);
                break;
            }
            case 7: {
                receipt.printReceipt();
                break;
            }
            case 8: {
                db.saveInventory(inventory);
                break;
            }
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
