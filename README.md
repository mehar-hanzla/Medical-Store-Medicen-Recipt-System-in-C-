# Medical-Store-Medicen-Recipt-System-in-C-
Medicine Receipt Management System
A C++ console application for a Medicine Receipt Management System, designed to manage the sales and inventory of medicines in a pharmacy or medical store. This project applies basic data structures and algorithms, making it ideal for students exploring DSA concepts in practical applications. It includes features such as inventory management, customer receipt generation, and receipt history tracking.

Features
Inventory Management:
Add, update, delete, and search for medicines in the inventory.
Each medicine includes attributes such as name, price, quantity, and expiry date.
Displays available stock and alerts when stock is low.
Customer Receipt Generation:
Create new receipts for customers based on their purchases.
Calculate the total cost, apply discounts, and display the final payable amount.
Option to view and print receipts.
Receipt History Tracking:
Save each generated receipt to maintain a history of customer purchases.
View past receipts and search receipts by date or customer.
Functionality
Add Medicine:

Allows the store owner to add a new medicine to the inventory.
Stores details like medicine name, price, stock, and expiry date.
Update Inventory:

Modify the details of existing medicines in the inventory, including price and stock.
Delete Medicine:

Delete an item from the inventory if it's no longer available.
Search Medicine:

Search for a medicine in the inventory by name or ID to quickly locate stock details.
Generate Receipt:

Select medicines from the inventory for a customer.
Calculate the total cost and generate a detailed receipt for printing.
View Receipt History:

Browse or search past receipts using customer information or transaction date.
Technical Overview
This project uses C++ Standard Template Library (STL) for data structures such as vectors, maps, and lists to efficiently handle the operations. The project has been developed with a clear modular structure separating functionality and using object-oriented principles.

Data Structures Used
Vectors: Used to store the list of medicines and customer receipts.
Maps: For searching and organizing medicines by their IDs.
Classes: Separate classes for handling medicine data, receipt generation, and history tracking.
Code Structure
Medicine Class: Manages individual medicine information.
Inventory Class: Handles the medicine inventory, including adding, updating, and deleting medicines.
Receipt Class: Generates and maintains customer purchase details.
History Class: Manages past receipts for easy lookup.
Getting Started
Clone the Repository:

bash
Copy code
git clone https://github.com/your-username/medicine-receipt-management.git
cd medicine-receipt-management
Compile the Program:

bash
Copy code
g++ medicine_receipt.cpp -o medicine_receipt
Run the Application:

bash
Copy code
medicine_receipt
Usage
Manage Inventory:

Use options to add, update, search, or delete medicines.
Generate Receipt:

Select medicines and create a receipt for customers.
View Past Receipts:

Lookup receipt history using date or customer information.
Future Improvements
Implement a database for storing receipts and inventory data for persistence.
Add a graphical user interface (GUI) for a more user-friendly experience.
Add receipt export functionality (e.g., PDF).
License
This project is licensed under the MIT License. See the LICENSE file for details.
