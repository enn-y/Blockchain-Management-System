#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

struct Block { // Block structure
    int blockNumber; // Block number
    string currentHashNumber; // Current hash number
    string previousHashNumber; // Previous hash number
    string currentTimeStamp; // Current time stamp
    vector<pair<string, string> > information;  // Information stored in the block
    bool isHardDeleted; // Flag to indicate if block is deleted
    bool isSoftDeleted; // Flag to indicate if block is deleted

    Block(int blockN, string currentH, string previousH, string timeStamp) { // Constructor for Block
        blockNumber = blockN; // Set block number
        currentHashNumber = currentH; // Set current hash number
        previousHashNumber = previousH; // Set previous hash number
        currentTimeStamp = timeStamp; // Set current time stamp
        isHardDeleted = false; // Set isHardDeleted flag to false
        isSoftDeleted = false; // Set isSoftDeleted flag to false
    }
};

struct BlockNode { // BlockNode structure
    Block data; // Block data
    BlockNode* next; // Pointer to the next block

    BlockNode(Block block) : data(block) { // Constructor for BlockNode
        next = nullptr; // Set next to nullptr
    }
};

class Blockchain { // Blockchain class
private: // Private members
    BlockNode* head; // Pointer to the head of the blockchain
    int currentBlockNumber; // Current block number
    string hashNumber; // Hash number

    bool procurementAdded; // Procurement information added flag
    bool inventoryAdded; // Inventory information added flag
    bool orderFulfillmentAdded; // Order fulfillment information added flag
    bool transportationAdded; // Transportation information added flag
    bool customerDeliverySatisfactionAdded; // Customer delivery satisfaction information added flag
    bool qualityControlAdded; // Quality control information added flag
    bool productReturn; // Product return information added flag
    bool productWorthiness; // Product worthiness information added flag

public: // Public members
    Blockchain() {  // Constructor for Blockchain
        head = nullptr; // Set head to nullptr, which is the start of the blockchain
        currentBlockNumber = 0; // Set current block number to 1
        hashNumber = generateRandomHash(); // Generate a random hash number
        time_t timeNow = time(0); // Get the current time
        char* dateTime = ctime(&timeNow); // Convert the current time to a string so it can be stored in the block
        Block firstBlock(currentBlockNumber, hashNumber, hashNumber, dateTime); // Create the first block
        head = new BlockNode(firstBlock); // Set the head of the blockchain to the first block

        procurementAdded = false; // Set procurement information added flag to false
        inventoryAdded = false; // Set inventory information added flag to false
        orderFulfillmentAdded = false; // Set order fulfillment information added flag to false
        transportationAdded = false; // Set transportation information added flag to false
        customerDeliverySatisfactionAdded = false; // Set customer delivery satisfaction information added flag to false
        qualityControlAdded = false; // Set quality control information added flag to false
        productReturn = false; // Set product return information added flag to false
        productWorthiness = false; // Set product worthiness information added flag to false
    }

    void addBlock(const vector<pair<string, string> >& info) { // Add a block to the blockchain with the information passed in, information is a vector pair of strings
        hashNumber = generateRandomHash(); // Generate a random hash number for the new block to be added
        time_t timeNow = time(0); // Get the current time for the new block to be added
        char* dateTime = ctime(&timeNow); // Convert the current time to a string so it can be stored in the block because the time is stored as a string in the block
        int chosenBlockNumber; // Chosen block number by the user to add to the blockchain

        Block newBlock(currentBlockNumber, hashNumber, head->data.currentHashNumber, dateTime); // Create a new block with the current block number, the hash number, the previous hash number, and the current time
        newBlock.information = info; // Set the information of the new block to the information passed in as a parameter

        do { // Loop until the user chooses to add all the blocks they want to add, only one of each block can be added
            cout << "\nWhich block do you want to add? (1-8):" << endl; // Ask the user which block they want to add
            cout << "\n1. Procurement Stage" << endl; // Add Procurement Stage
            cout << "\n2. Inventory Storage Stage" << endl; // Add Inventory Storage Stage
            cout << "\n3. Order Fulfillment Stage" << endl; // Add Order Fulfillment Stage
            cout << "\n4. Transportation Stage" << endl; // Add Transportation Stage
            cout << "\n5. Customer Delivery Satisfaction Stage" << endl; // Add Customer Delivery Satisfaction Stage
            cout << "\n6. Quality Control Stage" << endl; // Add Quality Control Stage
            cout << "\n7. Product Return Stage" << endl; // Add Product Return Stage
            cout << "\n8. Product Worthiness Stage" << endl; // Add Product Worthiness Stage
            cout << "\nEnter your choice: "; // Ask the user to enter their choice
            cin >> chosenBlockNumber; // Get the user's choice
            cin.ignore(); // Ignore the newline character

            if (cin.fail()) { // If the user enters an invalid input
                cin.clear(); // Clear the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input
                cout << "\nInvalid input. Please enter a number." << endl; // Tell the user that they entered an invalid input
                continue; // Continue to the next iteration of the loop
            }

            switch (chosenBlockNumber) { // Switch statement based on the user's choice
                case 1: // If the user chooses 1
                    if(procurementAdded) { // If procurement information has already been added
                        cout << "Procurement Information has already been added." << endl; // Tell the user that procurement information has already been added
                        chosenBlockNumber = 0; // Set chosen block number to 0 because the user has already added procurement information so the switch statement will break
                        break; // Break out of the switch statement
                    }
                    addProcurementInformation(newBlock); // Add procurement information to the new block
                    procurementAdded = true; // Set procurement information added flag to true
                    break; // Break out of the switch statement
                case 2:  // If the user chooses 2
                    if(inventoryAdded) { // If inventory information has already been added
                        cout << "Inventory Information has already been added." << endl; // Tell the user that inventory information has already been added
                        chosenBlockNumber = 0; // Set chosen block number to 0 because the user has already added inventory information so the switch statement will break
                        break; // Break out of the switch statement
                    }
                    addInventoryInformation(newBlock); // Add inventory information to the new block
                    inventoryAdded = true; // Set inventory information added flag to true
                    break; // Break out of the switch statement
                case 3: // If the user chooses 3
                    if(orderFulfillmentAdded) { // If order fulfillment information has already been added
                        cout << "Order Fulfillment Information has already been added." << endl; // Tell the user that order fulfillment information has already been added
                        chosenBlockNumber = 0; // Set chosen block number to 0 because the user has already added order fulfillment information so the switch statement will break
                        break; // Break out of the switch statement
                    }
                    addOrderFulfillmentInformation(newBlock); // Add order fulfillment information to the new block
                    orderFulfillmentAdded = true; // Set order fulfillment information added flag to true
                    break; // Break out of the switch statement
                case 4: // If the user chooses 4
                    if(transportationAdded) { // If transportation information has already been added
                        cout << "Transportation Information has already been added." << endl; // Tell the user that transportation information has already been added
                        chosenBlockNumber = 0; // Set chosen block number to 0 because the user has already added transportation information so the switch statement will break
                        break; // Break out of the switch statement
                    }
                    addTransportationInformation(newBlock); // Add transportation information to the new block
                    transportationAdded = true; // Set transportation information added flag to true
                    break; // Break out of the switch statement
                case 5: // If the user chooses 5
                    if(customerDeliverySatisfactionAdded) { // If customer delivery satisfaction information has already been added
                        cout << "Customer Delivery Satisfaction Information has already been added." << endl; // Tell the user that customer delivery satisfaction information has already been added
                        chosenBlockNumber = 0; // Set chosen block number to 0 because the user has already added customer delivery satisfaction information so the switch statement will break
                        break; // Break out of the switch statement
                    }
                    addCustomerDeliverySatisfactionInformation(newBlock); // Add customer delivery satisfaction information to the new block
                    customerDeliverySatisfactionAdded = true; // Set customer delivery satisfaction information added flag to true
                    break; // Break out of the switch statement
                case 6: // If the user chooses 6
                    if(qualityControlAdded) { // If quality control information has already been added
                        cout << "Quality Control Information has already been added." << endl; // Tell the user that quality control information has already been added
                        chosenBlockNumber = 0; // Set chosen block number to 0 because the user has already added quality control information so the switch statement will break
                        break; // Break out of the switch statement
                    }
                    addQualityInspectionControlInformation(newBlock); // Add quality control information to the new block
                    qualityControlAdded = true; // Set quality control information added flag to true
                    break; // Break out of the switch statement
                case 7: // If the user chooses 7
                    if(productReturn) { // If product return information has already been added
                        cout << "Product Return Information has already been added." << endl; // Tell the user that product return information has already been added
                        chosenBlockNumber = 0; // Set chosen block number to 0 because the user has already added product return information so the switch statement will break
                        break; // Break out of the switch statement
                    } // Add product return information to the new block 
                    addProductReturnInformation(newBlock); // Add product return information to the new block
                    productReturn = true; // Set product return information added flag to true
                    break; // Break out of the switch statement
                case 8: // If the user chooses 8
                    if(productWorthiness) { // If product worthiness information has already been added
                        cout << "Product Worthiness Information has already been added." << endl; // Tell the user that product worthiness information has already been added
                        chosenBlockNumber = 0; // Set chosen block number to 0 because the user has already added product worthiness information so the switch statement will break
                        break; // Break out of the switch statement
                    }
                    addProductWorthinessInformation(newBlock); // Add product worthiness information to the new block
                    productWorthiness = true; // Set product worthiness information added flag to true
                    break; // Break out of the switch statement
                default:
                    cout << "Invalid choice. Please enter a number between 1-8." << endl; // Tell the user that their choice is invalid
                    break; // Break out of the switch statement
            }
        } while (chosenBlockNumber < 1 || chosenBlockNumber > 8); // Keep asking the user to enter a number between 1-8 until they do so
        
        if (currentBlockNumber == 0) { // If the current block number is 1
            head->data.information = newBlock.information;  // Set the head's data to the new block's information
        } else { // If the current block number is not 1
            BlockNode* newNode = new BlockNode(newBlock); // Create a new block node with the new block's information
            newNode->next = head; // Set the new node's next to the head
            head = newNode; // Set the head to the new node
        }

        currentBlockNumber++; // Increment the current block number
    }

    void addProcurementInformation(Block& block) { // Add procurement information to the block, called when the user chooses 1
        string supplierID, supplierName, orderQuantity, orderDate, orderState, shippingDetails; // Declare variables for the supplier ID, supplier name, order quantity, order date, order state, and shipping details
        bool correctSupplierID = false; // Set the correct supplier ID flag to false

        while (!correctSupplierID) { // While loop to keep asking the user to enter a valid supplier ID
            cout << "\nEnter Supplier ID (format: SIDxxxxx): "; // Ask the user to enter the supplier ID, the format is string SID followed by 5 digits
            getline(cin, supplierID); // Get user input for the supplier ID

            if (supplierID.length() == 8 && supplierID.substr(0, 3) == "SID") { // Check if the supplier ID is 8 characters long and starts with "SID"
                bool validLength = true; // Set the valid flag to true
                for (int i = 3; i < 8; i++) { // For loop to check if the rest of the characters are digits
                    if (!isdigit(supplierID[i])) { // If the character is not a digit
                        validLength = false; // Then set the valid flag to false
                        break; // Break out of the for loop
                    }
                }
                if (validLength) { // If the valid flag is true
                    correctSupplierID = true; // Set the correct supplier ID flag to true, this means that the supplier ID is valid
                }
            }
            else { // If the supplier ID is not 8 characters long and does not start with "SID"
                cout << "Invalid format. Please enter a valid Supplier ID." << endl; // Tell the user that the supplier ID is invalid
            }
        }

        cout << "Enter Supplier Name: "; // Ask the user to enter the supplier name
        getline(cin, supplierName); // Get user input for the supplier name

        bool validOrderQuantity = false; // Set the valid order quantity flag to false
        while (!validOrderQuantity) { // While loop to keep asking the user to enter a valid order quantity
            cout << "Enter Order Quantity: "; // Ask the user to enter the order quantity
            getline(cin, orderQuantity); // Get user input for the order quantity
 
            if (orderQuantity.find_first_not_of("0123456789") == string::npos) { // Check if the order quantity contains only digits, no other characters but digits
                validOrderQuantity = true; // Set the valid order quantity flag to true, this means that the order quantity is valid
            } else { // If the order quantity contains characters other than digits
                cout << "Invalid input. Please enter a valid number for Order Quantity." << endl; // Tell the user that the order quantity is invalid
            }
        }

        bool correctOrderDate = false; // Set the correct order date flag to false
        while (!correctOrderDate) { // While loop to keep asking the user to enter a valid order date
            cout << "Enter Order Date (format: dd/mm/yy): "; // Ask the user to enter the order date, the format is strictly day/month/year
            getline(cin, orderDate); // Get user input for the order date

            if (orderDate.length() == 8 && orderDate[2] == '/' && orderDate[5] == '/') { // Check if the order date is 8 characters long and contains "/" at the 3rd and 6th position, no other characters but "/"
                string dayString = orderDate.substr(0, 2); // Get the day from the order date
                string monthString = orderDate.substr(3, 2); // Get the month from the order date
                string yearString = orderDate.substr(6, 2); // Get the year from the order date
                int day = stoi(dayString); // Convert the day string to an integer
                int month = stoi(monthString); // Convert the month string to an integer
                int year = stoi(yearString); // Convert the year string to an integer

                if (day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 0 && year >= 24) { // Check that the day is between 1-31, month is between 1-12, and year is after 2024, only valid day month and year
                    correctOrderDate = true; // Set the correct order date flag to true, this means that the order date is valid
                }
            }

            if (!correctOrderDate) { // If the order date is not valid
                cout << "Invalid format. Please enter a valid Order Date (format: dd/mm/yy) Ensure that year is on or after 2024." << endl; // Tell the user that the order date is invalid, will loop again
            }
        }

        bool validOrderState = false; // Set the valid order state flag to false

        while (!validOrderState) { // While loop to keep asking the user to enter a valid order state
            cout << "Enter Order State (Pending, In Progress, Completed, Cancelled): "; // Ask the user to enter the order state, the options are Pending, In Progress, Completed, Cancelled
            getline(cin, orderState); // Get user input for the order state

            transform(orderState.begin(), orderState.end(), orderState.begin(), ::tolower); // Convert the order state to lowercase, so that the user can enter the order state in any case, doesnt affect the input

            if (orderState == "pending" || orderState == "in progress" || orderState == "completed" || orderState == "cancelled") { // Check if the order state is one of the valid options, pending, in progress, completed, or cancelled
                validOrderState = true; // Set the valid order state flag to true, this means that the order state is valid
            }
            else { // If the order state is not one of the valid options
                cout << "Invalid status. Please enter 'Pending', 'In Progress', 'Completed', 'Cancelled'." << endl; // Tell the user that the order state is invalid
            }
        }

        cout << "Enter Shipping Details: "; // Ask the user to enter the shipping details
        getline(cin, shippingDetails); // Get user input for the shipping details

        block.information.push_back(make_pair("Block", "Procurement Information")); // Add the block name and block type to the block information
        block.information.push_back(make_pair("Supplier ID", supplierID)); // Add the supplier ID to the block information
        block.information.push_back(make_pair("Supplier Name", supplierName)); // Add the supplier name to the block information
        block.information.push_back(make_pair("Order Quantity", orderQuantity)); // Add the order quantity to the block information
        block.information.push_back(make_pair("Order Date", orderDate)); // Add the order date to the block information
        block.information.push_back(make_pair("Order State", orderState)); // Add the order state to the block information
        block.information.push_back(make_pair("Shipping Details", shippingDetails)); // Add the shipping details to the block information

        cout << "\n\nProcurement Information Block Successfully Added.\n"; // Tell the user that the procurement information block has been successfully added, and the information has been stored in the block, block now has the information
    }

    void addInventoryInformation(Block& block) { // Function to add inventory information to the block
        string warehouseID, storageLocation, inventoryQuantity, inventoryStatus; // Declare the variables for the warehouse ID, storage location, inventory quantity, and inventory status
        bool correctWarehouseID = false; // Set the correct warehouse ID flag to false

        while (!correctWarehouseID) { // While loop to keep asking the user to enter a valid warehouse ID
            cout << "\nEnter Warehouse ID (format: WIDxxxxx): "; // Ask the user to enter the warehouse ID, the format is strictly WID followed by 5 digits
            getline(cin, warehouseID); // Get user input for the warehouse ID

            if (warehouseID.length() == 8 && warehouseID.substr(0, 3) == "WID") { // Check if the warehouse ID is 8 characters long and starts with WID, no other characters but WID and 5 digits
                bool validLength = true; // Set the valid flag to true, this means that the warehouse ID is valid
                for (int i = 3; i < 8; i++) { // For loop to check the 5 digits of the warehouse ID
                    if (!isdigit(warehouseID[i])) { // If the character is not a digit
                        validLength = false; // Set the valid flag to false, this means that the warehouse ID is invalid
                        break; // Break the for loop, no need to check the rest of the digits
                    }
                }
                if (validLength) { // If the warehouse ID is valid
                    correctWarehouseID = true; // Set the correct warehouse ID flag to true, this means that the warehouse ID is valid
                }
            }
            else { // If the warehouse ID is not valid
                cout << "Invalid format. Please enter a valid Warehouse ID." << endl; // Tell the user that the warehouse ID is invalid, will loop again
            }
        }

        vector<string> validLocations; // Create a vector of strings to store the valid locations, valid locations are cities and states, the format is: city, state
        ifstream file("valid_locations.txt"); // Open the valid locations file, file name is valid_locations.txt
        if (file.is_open()) { // If the file is open
            string line; // Declare a string to store the line of the file
            while (getline(file, line)) { // While loop to read the file line by line
                validLocations.push_back(line); // Add the line to the valid locations vector
            }
            file.close(); // Close the file
        } else { // If the file is not open
            cout << "Error: Unable to open valid locations file." << endl; // Tell the user that the file is not open, file is not found
            return; // Return from the function
        }

        bool validStorageLocation = false; // Set the valid storage location flag to false

        while (!validStorageLocation) { // While loop to keep asking the user to enter a valid storage location
            cout << "Enter Storage Location (format: city, state): "; // Ask the user to enter the storage location, the format is city, state
            getline(cin, storageLocation); // Get user input for the storage location

            validStorageLocation = isValidLocation(storageLocation, validLocations); // Call the isValidLocation function to check if the storage location is valid, pass the storage location and the valid locations vector as arguments

            if (!validStorageLocation) { // If the storage location is not valid
                cout << "Invalid format. Please enter a valid location in the format 'city, state'." << endl; // Tell the user that the storage location is invalid, will loop again
            }
        }

        bool validInventoryQuantity = false; // Set the valid inventory quantity flag to false
        while (!validInventoryQuantity) { // While loop to keep asking the user to enter a valid inventory quantity
            cout << "Enter Inventory Quantity: "; // Ask the user to enter the inventory quantity
            getline(cin, inventoryQuantity); // Get user input for the inventory quantity

            if (inventoryQuantity.find_first_not_of("0123456789") == string::npos) { // Check if the inventory quantity contains only digits, no other characters
                validInventoryQuantity = true; // Set the valid inventory quantity flag to true, this means that the inventory quantity is valid
            } else {
                cout << "Invalid input. Please enter a valid number for Inventory Quantity." << endl; // Tell the user that the inventory quantity is invalid, will loop again
            }
        }

        bool validInventoryStatus = false; // Set the valid inventory status flag to false
        while (!validInventoryStatus) { // While loop to keep asking the user to enter a valid inventory status
            cout << "Enter Inventory Status (Available, Low Stock, or Not Available): "; // Ask the user to enter the inventory status, the options are available, low stock, or not available
            getline(cin, inventoryStatus); // Get user input for the inventory status

            transform(inventoryStatus.begin(), inventoryStatus.end(), inventoryStatus.begin(), ::tolower); // Convert the inventory status to lowercase

            if (inventoryStatus == "available" || inventoryStatus == "low stock" || inventoryStatus == "not available") { // Check if the inventory status is available, low stock, or not available
                validInventoryStatus = true; // Set the valid inventory status flag to true, this means that the inventory status is valid
            } 
            else { // If the inventory status is not valid
                cout << "Invalid status. Please enter 'Available', 'Low Stock', or 'Not Available'." << endl; // Tell the user that the inventory status is invalid, will loop again
            }
        }

        block.information.push_back(make_pair("Block", "Inventory Information")); // Add the inventory information block to the block
        block.information.push_back(make_pair("Warehouse ID", warehouseID)); // Add the warehouse ID to the block
        block.information.push_back(make_pair("Storage Location", storageLocation)); // Add the storage location to the block
        block.information.push_back(make_pair("Inventory Quantity", inventoryQuantity)); // Add the inventory quantity to the block
        block.information.push_back(make_pair("Inventory Status", inventoryStatus)); // Add the inventory status to the block

        cout << "\n\nInventory Information Block Successfully Added.\n"; // Tell the user that the inventory information block is successfully added
    }

    void addOrderFulfillmentInformation(Block& block) { // Function to add order fulfillment information to the block
        string customerID, orderQuantityF, orderDateF, orderStateF, shippingDetailsF; // Declare strings to store the customer ID, order quantity, order date, order state, and shipping details

        bool correctCustomerID = false; // Set the correct customer ID flag to false

        while (!correctCustomerID) { // While loop to keep asking the user to enter a valid customer ID
            cout << "\nEnter Customer ID (format: CIDxxxxx): "; // Ask the user to enter the customer ID, the format is CID followed by 5 digits
            getline(cin, customerID); // Get user input for the customer ID

            if (customerID.length() == 8 && customerID.substr(0, 3) == "CID") { // Check if the customer ID is 8 characters long and starts with CID
                bool validLength = true; // Set the valid flag to true
                for (int i = 3; i < 8; i++) { // For loop to check if the rest of the customer ID contains only digits
                    if (!isdigit(customerID[i])) { // If the character is not a digit
                        validLength = false; // Set the valid flag to false
                        break; // Break from the for loop
                    }
                }
                if (validLength) { // If the customer ID is valid
                    correctCustomerID = true; // Set the correct customer ID flag to true, this means that the customer ID is valid
                }
            }
            else { // If the customer ID is not valid
                cout << "Invalid format. Please enter a valid Customer ID." << endl; // Tell the user that the customer ID is invalid, will loop again
            }
        }

        bool validOrderQuantityF = false; // Set the valid order quantity flag to false
        while (!validOrderQuantityF) { // While loop to keep asking the user to enter a valid order quantity
            cout << "Enter Order Quantity: "; // Ask the user to enter the order quantity
            getline(cin, orderQuantityF); // Get user input for the order quantity

            if (orderQuantityF.find_first_not_of("0123456789") == string::npos) { // Check if the order quantity contains only digits, no other characters, only digits
                validOrderQuantityF = true; // Set the valid order quantity flag to true, this means that the order quantity is valid
            } else { // If the order quantity is not valid
                cout << "Invalid input. Please enter a valid number for Order Quantity." << endl; // Tell the user that the order quantity is invalid, will loop again
            }
        }

        bool correctOrderDateF = false; // Set the correct order date flag to false
        while (!correctOrderDateF) { // While loop to keep asking the user to enter a valid order date
            cout << "Enter Order Date (format: dd/mm/yy): "; // Ask the user to enter the order date, the format is dd/mm/yy
            getline(cin, orderDateF); // Get user input for the order date
 
            if (orderDateF.length() == 8 && orderDateF[2] == '/' && orderDateF[5] == '/') { // Check if the order date is 8 characters long and contains / at the 3rd and 6th position, no other characters
                string dayString = orderDateF.substr(0, 2); // Extract the day, month, and year from the order date
                string monthString = orderDateF.substr(3, 2); // Extract the day, month, and year from the order date
                string yearString = orderDateF.substr(6, 2); // Extract the day, month, and year from the order date
                int day = stoi(dayString); // Convert the day, month, and year to integers 
                int month = stoi(monthString); // Convert the day, month, and year to integers
                int year = stoi(yearString); // Convert the day, month, and year to integers

                if (day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 0 && year >= 24) { // Check if the day, month, and year are valid and year is after 2024
                    correctOrderDateF = true; // Set the correct order date flag to true, this means that the order date is valid
                }
            }
 
            if (!correctOrderDateF) { // If the order date is not valid
                cout << "Invalid format. Please enter a valid Order Date (format: dd/mm/yy) Ensure that year is on or after 2024." << endl; // Tell the user that the order date is invalid, will loop again
            }
        }

        bool validOrderState = false; // Set the valid order state flag to false
        while (!validOrderState) { // While loop to keep asking the user to enter a valid order state
            cout << "Enter Order State (Pending, In Progress, Completed, Cancelled): "; // Ask the user to enter the order state, the options are Pending, In Progress, Completed, Cancelled
            getline(cin, orderStateF); // Get user input for the order state

            transform(orderStateF.begin(), orderStateF.end(), orderStateF.begin(), ::tolower); // Convert the order state to lowercase

            if (orderStateF == "pending" || orderStateF == "in progress" || orderStateF == "completed" || orderStateF == "cancelled") { // Check if the order state is valid
                validOrderState = true; // Set the valid order state flag to true, this means that the order state is valid
            }
            else { // If the order state is not valid
                cout << "Invalid status. Please enter 'Pending', 'In Progress', 'Completed', 'Cancelled'." << endl; // Tell the user that the order state is invalid, will loop again
            }
        }

        cout << "Enter Shipping Details: "; // Ask the user to enter the shipping details
        getline(cin, shippingDetailsF); // Get user input for the shipping details

        block.information.push_back(make_pair("Block", "Order Fulfillment Information")); // Add the order fulfillment information block to the block information vector
        block.information.push_back(make_pair("Customer ID", customerID)); // Add the customer ID to the block information vector
        block.information.push_back(make_pair("Order Quantity", orderQuantityF)); // Add the order quantity to the block information vector
        block.information.push_back(make_pair("Order Date", orderDateF)); // Add the order date to the block information vector
        block.information.push_back(make_pair("Order State", orderStateF)); // Add the order state to the block information vector
        block.information.push_back(make_pair("Shipping Details", shippingDetailsF)); // Add the shipping details to the block information vector

        cout << "\n\nOrder Fulfillment Information Block Successfully Added.\n"; // Tell the user that the order fulfillment information block has been successfully added
    }

    void addTransportationInformation(Block& block) { // Function to add transportation information to the block
        string transportationMode, transportationCompany, transportationRouteFrom, transportationRouteTo, transportationDepartureDateTime, transportationEstimatedArrivalDateTime; // Declare variables for the transportation information, variables declared are transportation mode, transportation company, transportation route from, transportation route to, transportation departure date and time, and transportation estimated arrival date and time
        bool validTransportationMode = false; // Set the valid transportation mode flag to false

        while (!validTransportationMode) { // While loop to keep asking the user to enter a valid transportation mode
            cout << "\nEnter Transportation Mode (Road, Rail, Sea, Air): "; // Ask the user to enter the transportation mode, the options are Road, Rail, Sea, Air
            getline(cin, transportationMode); // Get user input for the transportation mode

            transform(transportationMode.begin(), transportationMode.end(), transportationMode.begin(), ::tolower); // Convert the transportation mode to lowercase

            if (transportationMode == "road" || transportationMode == "rail" || transportationMode == "sea" || transportationMode == "air") { // Check if the transportation mode is valid
                validTransportationMode = true; // Set the valid transportation mode flag to true, this means that the transportation mode is valid
            }
            else { // If the transportation mode is not valid
                cout << "Invalid status. Please enter 'Road', 'Rail', 'Sea', 'Air" << endl; // Tell the user that the transportation mode is invalid, will loop again
            }
        }

        cout << "Enter Transportation Company: "; // Ask the user to enter the transportation company
        getline(cin, transportationCompany); // Get user input for the transportation company

        vector<string> validLocations; // Declare a vector of strings for the valid locations
        ifstream file("valid_locations.txt"); // Open the valid locations file
        if (file.is_open()) { // If the valid locations file is open
            string Locationline; // Declare a string for the line
            while (getline(file, Locationline)) { // While loop to get each line from the valid locations file
                validLocations.push_back(Locationline); // Add the line to the valid locations vector
            }
            file.close(); // Close the valid locations file
        } else { // If the valid locations file is not open
            cout << "Error: Unable to open valid locations file." << endl; // Tell the user that the valid locations file cannot be opened
            return; // Return from the function
        }

        cout << "Enter Transportation Route: "; // Ask the user to enter the transportation route
        bool validTransportationRouteFrom = false; // Set the valid transportation route from flag to false
        while (!validTransportationRouteFrom) { // While loop to keep asking the user to enter a valid transportation route from
            cout << "\nFrom (format: city, state): "; // Ask the user to enter the transportation route from, the format is: city, state
            getline(cin, transportationRouteFrom); // Get user input for the transportation route from

            validTransportationRouteFrom = isValidLocation(transportationRouteFrom, validLocations); // Check if the transportation route from is valid

            if (!validTransportationRouteFrom) { // If the transportation route from is not valid
                cout << "Invalid format. Please enter a valid location in the format 'city, state'." << endl; // Tell the user that the transportation route from is invalid, will loop again
            }
        }
        
        bool validTransportationRouteTo = false; // Set the valid transportation route to flag to false
        while (!validTransportationRouteTo) { // While loop to keep asking the user to enter a valid transportation route to
            cout << "To (format: city, state): "; // Ask the user to enter the transportation route to, the format is: city, state
            getline(cin, transportationRouteTo); // Get user input for the transportation route to

            validTransportationRouteTo = isValidLocation(transportationRouteTo, validLocations); // Check if the transportation route to is valid

            if (!validTransportationRouteTo) { // If the transportation route to is not valid
                cout << "Invalid format. Please enter a valid location in the format 'city, state'." << endl; // Tell the user that the transportation route to is invalid, will loop again
            }
        }

        bool correctTransportationDepartureDate = false; // Set the correct transportation departure date flag to false
        while (!correctTransportationDepartureDate) { // While loop to keep asking the user to enter a valid transportation departure date
            cout << "Enter Transportation Departure Date (format: dd/mm/yy): "; // Ask the user to enter the transportation departure date, the format is: dd/mm/yy
            getline(cin, transportationDepartureDateTime); // Get user input for the transportation departure date

            if (transportationDepartureDateTime.length() == 8 && transportationDepartureDateTime[2] == '/' && transportationDepartureDateTime[5] == '/') { // Check if the transportation departure date is in the correct format
                string dayString = transportationDepartureDateTime.substr(0, 2); // Get the day from the transportation departure date
                string monthString = transportationDepartureDateTime.substr(3, 2); // Get the month from the transportation departure date
                string yearString = transportationDepartureDateTime.substr(6, 2); // Get the year from the transportation departure date
                int day = stoi(dayString); // Convert the day string to an integer
                int month = stoi(monthString); // Convert the month string to an integer
                int year = stoi(yearString); // Convert the year string to an integer

                if (day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 0 && year >= 24) { // Check if the day, month, and year are valid, the day must be between 1 and 31, the month must be between 1 and 12, and the year must be between 0 and 99
                    correctTransportationDepartureDate = true; // Set the correct transportation departure date flag to true, this means that the transportation departure date is valid
                }
            }

            if (!correctTransportationDepartureDate) { // If the transportation departure date is not valid
                cout << "Invalid format. Please enter a valid Order Date (format: dd/mm/yy) Ensure that year is on or after 2024." << endl; // Tell the user that the transportation departure date is invalid, will loop again
            }
        }

        bool correctTransportationArrivalDate = false; // Set the correct transportation arrival date flag to false
        while (!correctTransportationArrivalDate) { // While loop to keep asking the user to enter a valid transportation arrival date
            cout << "Enter Transportation Estimated Arrival Date (format: dd/mm/yy): "; // Ask the user to enter the transportation estimated arrival date, the format is: dd/mm/yy
            getline(cin, transportationEstimatedArrivalDateTime); // Get user input for the transportation estimated arrival date

            if (transportationEstimatedArrivalDateTime.length() == 8 && transportationEstimatedArrivalDateTime[2] == '/' && transportationEstimatedArrivalDateTime[5] == '/') { // Check if the transportation estimated arrival date is in the correct format
                string dayString = transportationEstimatedArrivalDateTime.substr(0, 2); // Get the day from the transportation estimated arrival date
                string monthString = transportationEstimatedArrivalDateTime.substr(3, 2); // Get the month from the transportation estimated arrival date
                string yearString = transportationEstimatedArrivalDateTime.substr(6, 2); // Get the year from the transportation estimated arrival date
                int day = stoi(dayString); // Convert the day string to an integer
                int month = stoi(monthString); // Convert the month string to an integer
                int year = stoi(yearString); // Convert the year string to an integer

                if (day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 0 && year >= 24) { // Check if the day, month, and year are valid, the day must be between 1 and 31, the month must be between 1 and 12, and the year must be between 0 and 99
                    // Check if the arrival date is equal to or after the departure date
                    if (year > stoi(transportationDepartureDateTime.substr(6, 2)) ||
                        (year == stoi(transportationDepartureDateTime.substr(6, 2)) && month > stoi(transportationDepartureDateTime.substr(3, 2))) ||
                        (year == stoi(transportationDepartureDateTime.substr(6, 2)) && month == stoi(transportationDepartureDateTime.substr(3, 2)) && day >= stoi(transportationDepartureDateTime.substr(0, 2)))) {
                        correctTransportationArrivalDate = true; // Set the correct transportation arrival date flag to true, this means that the transportation arrival date is valid
                    } else {
                        cout << "Invalid arrival date. Arrival date must be equal to or after the departure date." << endl; // Tell the user that the transportation arrival date is invalid, will loop again
                    }
                }
            }

            if (!correctTransportationArrivalDate) { // If the transportation arrival date is not valid
                cout << "Invalid format. Please enter a valid Order Date (format: dd/mm/yy) Ensure that year is on or after 2024." << endl; // Tell the user that the transportation arrival date is invalid, will loop again
            }
        }
        
        block.information.push_back(make_pair("Block", "Transportation Information")); // Add the transportation information block to the block information
        block.information.push_back(make_pair("Transportation Mode", transportationMode)); // Add the transportation mode to the block information
        block.information.push_back(make_pair("Transportation Company", transportationCompany)); // Add the transportation company to the block information
        block.information.push_back(make_pair("Transportation Route", transportationRouteFrom + " to " + transportationRouteTo)); // Add the transportation route to the block information
        block.information.push_back(make_pair("Transportation Departure Date", transportationDepartureDateTime)); // Add the transportation departure date to the block information
        block.information.push_back(make_pair("Transportation Estimated Arrival Date", transportationEstimatedArrivalDateTime)); // Add the transportation estimated arrival date to the block information

        cout << "\n\nTransportation Information Block Successfully Added.\n"; // Tell the user that the transportation information block has been successfully added
    }

    string expectedProductWorthiness; // Declare a string to store the expected product worthiness value

    void addCustomerDeliverySatisfactionInformation(Block& block) { // Function to add the customer delivery satisfaction information to the block
        string deliveryConfirmation, customerFeedbackCollection, satisfactionSurvey; // Declare strings to store the delivery confirmation, customer feedback collection, and satisfaction survey values

        bool validDeliveryConfirmation = false; // Set the valid delivery confirmation flag to false
 
        while (!validDeliveryConfirmation) { // While loop to keep asking the user to enter a valid delivery confirmation
            cout << "\nEnter Delivery Confirmation (format: Delivered, Unsuccessful, Rescheduled): "; // Ask the user to enter the delivery confirmation, the format is: Delivered, Unsuccessful, Rescheduled
            getline(cin, deliveryConfirmation); // Get user input for the delivery confirmation

            transform(deliveryConfirmation.begin(), deliveryConfirmation.end(), deliveryConfirmation.begin(), ::tolower); // Convert the delivery confirmation to lowercase

            if (deliveryConfirmation == "delivered" || deliveryConfirmation == "unsuccessful" || deliveryConfirmation == "rescheduled") { // Check if the delivery confirmation is valid, the delivery confirmation must be: Delivered, Unsuccessful, Rescheduled
                validDeliveryConfirmation = true; // Set the valid delivery confirmation flag to true, this means that the delivery confirmation is valid
            }
            else { // If the delivery confirmation is not valid
                cout << "Invalid status. Please enter 'Delivered', 'Unsuccessful', 'Rescheduled'." << endl; // Tell the user that the delivery confirmation is invalid, will loop again
            }
        }

        bool validCustomerFeedbackConfirmation = false; // Set the valid customer feedback confirmation flag to false

        while (!validCustomerFeedbackConfirmation) { // While loop to keep asking the user to enter a valid customer feedback collection
            cout << "Enter Customer Feedback Collection Result (format: Excellent, Good, Average, Poor): "; // Ask the user to enter the customer feedback collection result, the format is: Excellent, Good, Average, Poor
            getline(cin, customerFeedbackCollection); // Get user input for the customer feedback collection

            transform(customerFeedbackCollection.begin(), customerFeedbackCollection.end(), customerFeedbackCollection.begin(), ::tolower); // Convert the customer feedback collection to lowercase
 
            if (customerFeedbackCollection == "excellent" || customerFeedbackCollection == "good" || customerFeedbackCollection == "average" || customerFeedbackCollection == "poor") { // Check if the customer feedback collection is valid, the customer feedback collection must be: Excellent, Good, Average, Poor
                validCustomerFeedbackConfirmation = true; // Set the valid customer feedback confirmation flag to true, this means that the customer feedback collection is valid
            }
            else { // If the customer feedback collection is not valid
                cout << "Invalid status. Please enter 'Excellent', 'Good', 'Average', 'Poor'." << endl; // Tell the user that the customer feedback collection is invalid, will loop again
            }
        }

        bool correctSatisfactionSurvey = false; // Set the correct satisfaction survey flag to false
        while (!correctSatisfactionSurvey) { // While loop to keep asking the user to enter a valid satisfaction survey
            cout << "Enter Satisfaction Survey Result (format: 1-10): "; // Ask the user to enter the satisfaction survey result, the format is: 1-10
            getline(cin, satisfactionSurvey); // Get user input for the satisfaction survey

            try { // Try to convert the satisfaction survey to an integer
                int surveyResult = stoi(satisfactionSurvey); // Convert the satisfaction survey to an integer
                if (surveyResult >= 1 && surveyResult <= 10) { // Check if the satisfaction survey is valid, the satisfaction survey must be between 1 and 10
                    correctSatisfactionSurvey = true; // Set the correct satisfaction survey flag to true, this means that the satisfaction survey is valid
                } else { // If the satisfaction survey is not valid
                    cout << "Invalid input. Please enter a number between 1 and 10." << endl; // Tell the user that the satisfaction survey is invalid, will loop again
                }
            } catch (...) { // Catch any errors
                cout << "Invalid input. Please enter a number between 1 and 10." << endl; // Tell the user that the satisfaction survey is invalid, will loop again
            } 
            expectedProductWorthiness = satisfactionSurvey; // Set the expected product worthiness to the satisfaction survey
        }

        block.information.push_back(make_pair("Block", "Customer Delivery Satisfactory Information")); // Add the customer delivery satisfactory information block to the block information
        block.information.push_back(make_pair("Delivery Confirmation", deliveryConfirmation)); // Add the delivery confirmation to the block information
        block.information.push_back(make_pair("Customer Feedback Collection", customerFeedbackCollection)); // Add the customer feedback collection to the block information
        block.information.push_back(make_pair("Satisfaction Survey", satisfactionSurvey)); // Add the satisfaction survey to the block information

        cout << "\n\nCustomer Delivery Satisfactory Information Block Successfully Added.\n"; // Tell the user that the customer delivery satisfactory information block has been successfully added
    }

    void addQualityInspectionControlInformation(Block& block) { // Function to add the quality inspection control information to the block
        string productInspectionDetails, productQuality; // Declare strings to store the product inspection details and product quality values

        bool validproductInspectionDetails = false; // Set the valid product inspection details flag to false

        while(validproductInspectionDetails == false) { // While loop to keep asking the user to enter a valid product inspection details
            cout << "\nEnter Product Quality Inspection Result (format: Pass, Fail): "; // Ask the user to enter the product inspection details, the format is: Pass, Fail
            getline(cin, productInspectionDetails); // Get user input for the product inspection details

            transform(productInspectionDetails.begin(), productInspectionDetails.end(), productInspectionDetails.begin(), ::tolower); // Convert the product inspection details to lowercase
            if(productInspectionDetails == "pass" || productInspectionDetails == "fail") { // Check if the product inspection details is valid, the product inspection details must be: Pass, Fail
                validproductInspectionDetails = true; // Set the valid product inspection details flag to true, this means that the product inspection details is valid
            } else { // If the product inspection details is not valid
                cout << "Invalid status. Please enter 'Pass', 'Fail'." << endl; // Tell the user that the product inspection details is invalid, will loop again
            }
        }

        bool validProductQuality = false; // Set the valid product quality flag to false

        while(validProductQuality == false) { // While loop to keep asking the user to enter a valid product quality
            cout << "Enter Product Quality (format: Excellent, Good, Average, Poor): "; // Ask the user to enter the product quality, the format is: Excellent, Good, Average, Poor
            getline(cin, productQuality); // Get user input for the product quality

            transform(productQuality.begin(), productQuality.end(), productQuality.begin(), ::tolower); // Convert the product quality to lowercase
            if(productQuality == "excellent" || productQuality == "good" || productQuality == "average" || productQuality == "poor") { // Check if the product quality is valid, the product quality must be: Excellent, Good, Average, Poor
                validProductQuality = true; // Set the valid product quality flag to true, this means that the product quality is valid
            } else { // If the product quality is not valid
                cout << "Invalid status. Please enter 'Excellent', 'Good', 'Average', 'Poor'." << endl; // Tell the user that the product quality is invalid, will loop again
            }
        }

        block.information.push_back(make_pair("Block", "Quality Inspection Control Information")); // Add the quality inspection control information block to the block information
        block.information.push_back(make_pair("Quality Inspection Result", productInspectionDetails)); // Add the product inspection details to the block information
        block.information.push_back(make_pair("Product Quality", productQuality)); // Add the product quality to the block information

        cout << "\n\nQuality Inspection Control Information Block Successfully Added.\n"; // Tell the user that the quality inspection control information block has been successfully added
    }

    void addProductReturnInformation(Block& block) { // Function to add the product return information to the block
        string productReturnStatus, productReturnReason, productRefundStatus; // Declare strings to store the product return status, product return reason and product refund status values

        bool validProductReturnStatus = false; // Set the valid product return status flag to false

        while(validProductReturnStatus == false) { // While loop to keep asking the user to enter a valid product return status
            cout << "\nEnter Product Return Status (format: Returned, Not Returned): "; // Ask the user to enter the product return status, the format is: Returned, Not Returned
            getline(cin, productReturnStatus); // Get user input for the product return status

            transform(productReturnStatus.begin(), productReturnStatus.end(), productReturnStatus.begin(), ::tolower); // Convert the product return status to lowercase
            if(productReturnStatus == "returned" || productReturnStatus == "not returned") { // Check if the product return status is valid, the product return status must be: Returned, Not Returned
                validProductReturnStatus = true; // Set the valid product return status flag to true, this means that the product return status is valid
            } else { // If the product return status is not valid
                cout << "Invalid status. Please enter 'Returned', 'Not Returned'." << endl; // Tell the user that the product return status is invalid, will loop again
            }
        }

        bool validProductRefundStatus = false; // Set the valid product refund status flag to false

        while(validProductRefundStatus == false) { // While loop to keep asking the user to enter a valid product refund status
            cout << "Enter Product Refund Status (format: Refunded, Not Refunded): "; // Ask the user to enter the product refund status, the format is: Refunded, Not Refunded
            getline(cin, productRefundStatus); // Get user input for the product refund status

            transform(productRefundStatus.begin(), productRefundStatus.end(), productRefundStatus.begin(), ::tolower); // Convert the product refund status to lowercase
            if(productRefundStatus == "refunded" || productRefundStatus == "not refunded") { // Check if the product refund status is valid, the product refund status must be: Refunded, Not Refunded
                validProductRefundStatus = true; // Set the valid product refund status flag to true, this means that the product refund status is valid
            } else { // If the product refund status is not valid
                cout << "Invalid status. Please enter 'Refunded', 'Not Refunded'." << endl; // Tell the user that the product refund status is invalid, will loop again
            }
        }

        cout << "Enter Product Return Reason: "; // Ask the user to enter the product return reason
        getline(cin, productReturnReason); // Get user input for the product return reason

        string productReturnNumber = "R" + to_string(rand() % 90000 + 10000); // Generate a random product return number

        block.information.push_back(make_pair("Block", "Product Returns Information")); // Add the product returns information block to the block information
        block.information.push_back(make_pair("Product Return Number", productReturnNumber)); // Add the product return number to the block information
        block.information.push_back(make_pair("Product Return Status", productReturnStatus)); // Add the product return status to the block information
        block.information.push_back(make_pair("Product Return Reason", productReturnReason)); // Add the product return reason to the block information

        cout << "\n\nProduct Returns Information Block Successfully Added.\n"; // Tell the user that the product returns information block has been successfully added
    }
 
    void addProductWorthinessInformation(Block& block) { // Function to add the product worthiness information to the block
        string productWorthinessStatus, productWorthinessReason; // Declare strings to store the product worthiness status and product worthiness reason values

        bool validProductWorthinessStatus = false; // Set the valid product worthiness status flag to false
 
        while (!validProductWorthinessStatus) { // While loop to keep asking the user to enter a valid product worthiness status
            cout << "\nEnter Product Worthiness Status (format: Continue Product, Discontinue Product): "; // Ask the user to enter the product worthiness status, the format is: Continue Product, Discontinue Product
            getline(cin, productWorthinessStatus); // Get user input for the product worthiness status

            transform(productWorthinessStatus.begin(), productWorthinessStatus.end(), productWorthinessStatus.begin(), ::tolower); // Convert the product worthiness status to lowercase
            if (productWorthinessStatus == "continue product" || productWorthinessStatus == "discontinue product") { // Check if the product worthiness status is valid, the product worthiness status must be: Continue Product, Discontinue Product
                validProductWorthinessStatus = true; // Set the valid product worthiness status flag to true, this means that the product worthiness status is valid
            } else { // If the product worthiness status is not valid
                cout << "Invalid status. Please enter 'Continue Product', 'Discontinue Product'." << endl; // Tell the user that the product worthiness status is invalid, will loop again
            }
        }

        cout << "Enter Product Worthiness Reason: "; // Ask the user to enter the product worthiness reason
        getline(cin, productWorthinessReason); // Get user input for the product worthiness reason

        bool correctProductWorthiness = false; // Set the correct product worthiness flag to false
        while (!correctProductWorthiness) { // While loop to keep asking the user to confirm the product worthiness status
            string userInput; // Declare a string to store the user input
            cout << "Based on the customer feedback number, the expected product worthiness is '" << expectedProductWorthiness << "'. Enter 'confirm' to proceed or 'reenter' to re-enter the product worthiness status: "; // Ask the user to confirm the product worthiness status, it uses the productworthiness variable to display the expected product worthiness
            getline(cin, userInput); // Get user input for the product worthiness status confirmation

            transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower); // Convert the user input to lowercase
            if (userInput == "confirm") { // If the user input is confirm
                correctProductWorthiness = true; // Set the correct product worthiness flag to true, this means that the product worthiness status is correct
            } else if (userInput == "reenter") { // If the user input is reenter
                cout << "\nEnter Product Worthiness Status (format: Continue Product, Discontinue Product): "; // Ask the user to re-enter the product worthiness status, the format is: Continue Product, Discontinue Product
                getline(cin, productWorthinessStatus); // Get user input for the product worthiness status

                transform(productWorthinessStatus.begin(), productWorthinessStatus.end(), productWorthinessStatus.begin(), ::tolower); // Convert the product worthiness status to lowercase
                if (productWorthinessStatus == "continue product" || productWorthinessStatus == "discontinue product") { // Check if the product worthiness status is valid, the product worthiness status must be: Continue Product, Discontinue Product
                    validProductWorthinessStatus = true; // Set the valid product worthiness status flag to true, this means that the product worthiness status is valid
                } else { // If the product worthiness status is not valid
                    cout << "Invalid status. Please enter 'Continue Product', 'Discontinue Product'." << endl; // Tell the user that the product worthiness status is invalid, will loop again
                }
            } else { // If the user input is not confirm or reenter
                cout << "Invalid input. Please enter 'confirm' or 'reenter'." << endl; // Tell the user that the input is invalid, will loop again
            }
        }

        block.information.push_back(make_pair("Block", "Product Worthiness Information")); // Add the product worthiness information block to the block information
        block.information.push_back(make_pair("Product Worthiness Status", productWorthinessStatus)); // Add the product worthiness status to the block information
        block.information.push_back(make_pair("Product Worthiness Reason", productWorthinessReason)); // Add the product worthiness reason to the block information

        cout << "\n\nProduct Worthiness Information Block Successfully Added.\n"; // Tell the user that the product worthiness information block has been successfully added
    }

    string generateRandomHash() { // Function to generate a random hash
        srand(static_cast<unsigned int>(time(nullptr)));  // Seed the random number generator
        string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; // Declare a string of characters to use for the random hash
        string randHash = ""; // Declare a string to store the random hash
        for (int i = 0; i < 20; i++) { // For loop to generate the random hash, loop 20 times
            int index = rand() % chars.size(); // Generate a random index
            randHash += chars[index]; // Add the character at the random index to the random hash
        }
        return randHash; // Return the random hash
    }
 
    void exportBlocksToFile(const string& filename) { // Function to export the blockchain to a file
        ofstream outfile(filename); // Create an output file stream with the filename
        if (!outfile.is_open()) { // If the file is not open
            cout << "Error: Unable to open file for writing." << endl; // Tell the user that there was an error opening the file
            return; // Return from the function
        }

        BlockNode* temp = head; // Create a temporary block node and set it to the head of the blockchain, this will be used to traverse the blockchain to export the blocks to the file
        while (temp != nullptr) { // While loop to traverse the blockchain
            const Block& block = temp->data; // Get the block data from the temporary block node
            outfile << "Block " << block.blockNumber << " | " << block.currentHashNumber << " | " << block.previousHashNumber << " | " << block.currentTimeStamp << "information: "; // Write the block number, current hash number, previous hash number, and current time stamp to the file

            for (size_t i = 0; i < block.information.size(); ++i) { // For loop to write the block information to the file
                const pair<string, string>& info = block.information[i]; // Get the block information from the block data
                outfile << " " << info.first << ": " << info.second << " | "; // Write the block information to the file
            }
            outfile << endl; // End the line

            temp = temp->next; // Move to the next block
        }

        outfile.close(); // Close the file
        cout << "Blocks exported to " << filename << " successfully." << endl; // Tell the user that the blocks have been successfully exported to the file
    } 

    bool isValidLocation(const string& location, const vector<string>& validLocations) { // Method to check if a location is valid
        return find(validLocations.begin(), validLocations.end(), location) != validLocations.end(); // Return true if the location is found in the valid locations vector, otherwise return false
    }

    int getCurrentBlockNumber() { // Method to get the current block number, this is a getter method used to get the current block number
        return currentBlockNumber; // Return the current block number
    }

    void displayChain() { //Method to display block, this is strictly for displaying purposes and is strictly "virtual"
        BlockNode* temp = head; // Create a temporary block node and set it to the head of the blockchain, this will be used to traverse the blockchain to search for the block
        string blockNumberInput; // Declare a variable to store the block number that the user wants to search
        cout << "\nEnter the block number you want to view (format: 1, 2, 3, ...) (* to view all): "; //Users can enter the specific block number of enter "*" asterisk to view all
        cin >> blockNumberInput; // Get user input for the block number they want to search

        bool found = false; // Declare a flag to indicate if the block was found
        while (temp != nullptr) { // While loop to traverse the blockchain
            const Block& block = temp->data; // Get the block data from the temporary block node
            if (!block.isHardDeleted && (blockNumberInput == "*" || stoi(blockNumberInput) == block.blockNumber)) {
                found = true;
                cout << "\nBlock " << block.blockNumber << " | " << block.currentHashNumber << " | " << block.previousHashNumber << " | " << block.currentTimeStamp;

                if (!block.isSoftDeleted) { //If the block is soft deleted
                    cout << " information: ";
                    for (size_t i = 0; i < block.information.size(); ++i) {
                        const pair<string, string>& info = block.information[i];
                        cout << " " << info.first << ": " << info.second << " | ";
                    }
                }

                cout << endl;

                if (blockNumberInput != "*") {
                    return;
                }
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "\nBlock with number " << blockNumberInput << " not found." << endl;
        }
    }

    void searchBlockByNumber() { // Method to search block, unaffected by any deletions
        BlockNode* temp = head; // Create a temporary block node and set it to the head of the blockchain, this will be used to traverse the blockchain to search for the block
        bool found = false;  // Declare flag to indicate if the block was found
        cout << "\nEnter which block number you want to search (format: 1, 2, 3, ...) (* to view all): "; 
        string blockNumberInput; // Delcare variable
        cin >> blockNumberInput;  // Get user input

        if (blockNumberInput == "*") { //If is asterisk then show all
            while (temp != nullptr) { 
                const Block& block = temp->data; 
                cout << "\nBlock " << block.blockNumber << " | " << block.currentHashNumber << " | " << block.previousHashNumber << " | " << block.currentTimeStamp << " information: "; 

                for (size_t i = 0; i < block.information.size(); ++i) { 
                    const pair<string, string>& info = block.information[i]; 
                    cout << " " << info.first << ": " << info.second << " | "; 
                }
                cout << endl; 
                temp = temp->next; 
            } 
            return; 
        }

        int blockNumber = stoi(blockNumberInput);  //convert the string into int so user can search for speciic block
        while (temp != nullptr) { 
            const Block& block = temp->data; 
            if (block.blockNumber == blockNumber) { 
                found = true; 
                cout << "\nBlock " << block.blockNumber << " | " << block.currentHashNumber << " | " << block.previousHashNumber << " | " << block.currentTimeStamp << " information: "; 

                for (size_t i = 0; i < block.information.size(); ++i) { 
                    const pair<string, string>& info = block.information[i]; 
                    cout << " " << info.first << ": " << info.second << " | "; 
                }
                cout << endl; 
                break; 
            }
            temp = temp->next; 
        } 

        if (!found) { 
            cout << "\nBlock with number " << blockNumber << " not found." << endl; 
        }
    }

    void softDeleteBlock(int blockNumber) { // Function to soft delete a block by block number
        BlockNode* currentNode = head; // Create a temporary block node and set it to the head of the blockchain, this will be used to traverse the blockchain to search for the block
        while (currentNode != nullptr && currentNode->data.blockNumber != blockNumber) { // While loop to traverse the blockchain to search for the block
            currentNode = currentNode->next; // Move to the next block
        }

        if (currentNode == nullptr) { // If the block was not found
            cout << "Block with block number " << blockNumber << " not found." << endl; // Tell the user that the block with the specified block number was not found
            return;
        }

        if (currentNode->data.isSoftDeleted) { // If the block has already been soft deleted
            cout << "Block with block number " << blockNumber << " has already been soft deleted." << endl; // Tell the user that the block with the specified block number has already been soft deleted
            return;
        }

        if (currentNode->data.isHardDeleted) { // If the block has already been hard deleted
            cout << "Block with block number " << blockNumber << " has been hard deleted and cannot be soft deleted." << endl; // Tell the user that the block with the specified block number has already been hard deleted and cannot be soft deleted
            return;
        }

        currentNode->data.isSoftDeleted = true; // Set the isSoftDeleted flag to true
        cout << "Information in block with block number " << blockNumber << " has been soft deleted." << endl; // Tell the user that the information in the block with the specified block number has been soft deleted
    }

    void hardDeleteBlock(int blockNumber) { // Function to hard delete a block by block number
        BlockNode* currentNode = head; // Create a temporary block node and set it to the head of the blockchain, this will be used to traverse the blockchain to search for the block
        while (currentNode != nullptr && currentNode->data.blockNumber != blockNumber) { // While loop to traverse the blockchain to search for the block
            currentNode = currentNode->next; // Move to the next block
        }

        if (currentNode == nullptr) { // If the block was not found
            cout << "Block with block number " << blockNumber << " not found." << endl; // Tell the user that the block with the specified block number was not found
            return;
        }

        if (currentNode->data.isHardDeleted) { // If the block has already been hard deleted
            cout << "Block with block number " << blockNumber << " has already been hard deleted." << endl; // Tell the user that the block with the specified block number has already been hard deleted
            return;
        }

        if (currentNode->data.isSoftDeleted) { // If the block has been soft deleted
            cout << "Block with block number " << blockNumber << " has been soft deleted and cannot be hard deleted." << endl; // Tell the user that the block with the specified block number has been soft deleted and cannot be hard deleted
            return;
        }

        currentNode->data.isHardDeleted = true; // Set the isHardDeleted flag to true
        cout << "Block with block number " << blockNumber << " has been hard deleted." << endl; // Tell the user that the block with the specified block number has been hard deleted
    }
};

bool authenticate(const string& username, const string& password) { // Function to authenticate the user, this function takes a username and password as parameters
    ifstream file("username_password.txt"); // Create an input file stream with the filename
    if (!file.is_open()) { // If the file is not open
        cout << "Error opening file." << endl; // Tell the user that there was an error opening the file
        return false; // Return false
    }

    string lineUsernamePassword; // Declare a string to store each line of the file
    while (getline(file, lineUsernamePassword)) { // While loop to read each line of the file
        stringstream ss(lineUsernamePassword); // Create a string stream with the line
        string storedUsername, storedPassword; // Declare strings to store the username and password from the file
        if (getline(ss, storedUsername, ',') && getline(ss, storedPassword)) { // If the username and password are successfully read from the file
            storedUsername.erase(remove_if(storedUsername.begin(), storedUsername.end(), ::isspace), storedUsername.end()); // Remove any whitespace from the stored username
            storedPassword.erase(remove_if(storedPassword.begin(), storedPassword.end(), ::isspace), storedPassword.end()); // Remove any whitespace from the stored password
            if (username == storedUsername && password == storedPassword) { // If the username and password match the stored username and password
                file.close(); // Close the file
                return true; // Return true
            }
        }
    }

    file.close(); // Close the file
    return false; // Return false
}
 
int main() { // Main function
    srand(time(0)); // Seed the random number generator

    Blockchain blockchain; // Create a blockchain object

    cout << "\nInventory and Transportation Management System." << endl;
    cout << "\nName: Lua Chong En";
    cout << "\nStudent ID: 20417309\n";

    int attempts = 0; // Declare an integer to store the number of login attempts
    bool authenticated = false; // Declare a boolean to store whether the user has been authenticated
    while (attempts < 3) { // While loop to limit the number of login attempts to 3
        cout << "\n\nEnter Username: "; // Prompt the user to enter their username
        string username;
        cin >> username;
        cout << "\n\nEnter Password: "; // Prompt the user to enter their password
        string password;
        cin >> password;

        if (authenticate(username, password)) { // If the user is authenticated
            authenticated = true; // Set the authenticated flag to true
            break;
        } else { // If the user is not authenticated
            cout << "\nInvalid username or password. Please try again." << endl; // Tell the user that the username or password is invalid
            attempts++; // Increment the number of login attempts, maximum 3
        }
    }

    if (!authenticated) { // If the user is not authenticated
        cout << "\nExceeded maximum login attempts. Exit program." << endl; // Tell the user that the maximum number of login attempts has been exceeded
        return 0;
    }

    int userChoice; // Declare an integer to store the user's choice
    do { // Do-while loop to display the menu and process the user's choice
        cout << "\nBlockchain Menu\n"
            << "1. Add Block\n"
            << "2. Display Block - DEMO (Allows for Hard and Soft deletion which are strictly \"Virtual\")\n"
            << "3. Search Block (Deletions does not affect searching for blocks as deletions are strictly \"Virtual\")\n"
            << "4. Export to text file\n"
            << "5. Hard Delete Block\n"
            << "6. Soft Delete Block\n"
            << "7. Exit\n"
            << "Enter your choice: ";
        cin >> userChoice; // User input 
        cin.ignore(); // Ignore the newline character in the input buffer

        if (cin.fail()) { // If the input is invalid
            cin.clear(); // Clear the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input
            cout << "\nInvalid input. Please enter a number." << endl; // Tell the user that the input is invalid
            continue;
        }
 
        switch (userChoice) { // Switch statement to process user input
            case 1: { // If the user chooses to add a block
                if (blockchain.getCurrentBlockNumber() == 8) {
                    cout << "\nAll blocks in the blockchain have been added. No more blocks can be added." << endl;
                    break;
                }
                vector<pair<string, string> > informationPair;
                blockchain.addBlock(informationPair);
                break;
            }
            case 2: { // If the user chooses to display the blockchain
                blockchain.displayChain();
                break;
            }
            case 3: { // If the user chooses to search for a block
                blockchain.searchBlockByNumber();
                break;
            }
            case 4: { // If the user chooses to export the blockchain to a text file
                blockchain.exportBlocksToFile("blockchain.txt");
                break;
            }
            case 5: { // If the user chooses to hard delete a block
                cout << "\nEnter which block number you want to hard delete: ";
                int blockNumber;
                cin >> blockNumber;
                blockchain.hardDeleteBlock(blockNumber);
                break;
            }
            case 6: { // If the user chooses to soft delete a block
                cout << "\nEnter which block number you want to soft delete: ";
                int blockNumber;
                cin >> blockNumber;
                blockchain.softDeleteBlock(blockNumber);
                break;
            }
            case 7: // If the user chooses to exit the program
                cout << "\nExit Program." << endl;
                break;
            default: // If the user chooses an invalid option
                cout << "\nInvalid choice. Please enter a valid choice." << endl;
        }
    } while (userChoice != 7); // If user enters an invalid number

    return 0;
}