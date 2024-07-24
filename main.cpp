#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

// Function Used In This Program
string generateRandomPassword();
void signUpAdmin();
void signUpCustomer();
bool checkAdminUsernameExists(string username);
bool checkCustomerUsernameExists(string username);
bool loginAdmin();
bool loginCustomer();
void searchProduct();
void addCategories();
void addProducts();
void displayAllProducts();
void displayCategoriesAndSelectProduct();
void deleteCategory();
void deleteProduct();
void addCustomer();
void deleteCustomer();
void viewCart();
void viewFavorites();
void checkout();
void backupProducts();
void backupCustomers();
void goBack();


int main() {

    int option;

    do {
        cout << " " << endl;
        cout << "Welcome to Edalex Tech Store!" << endl;
        cout << "===================================" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Customer" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your option: ";
        cout << " " << endl;


        cin >> option;
        cout << "===================================" << endl;

        if (option == 1) {
            int adminOption;

            do {
                cout << "Admin Menu" << endl;
                cout << "1. Sign Up" << endl;
                cout << "2. Sign In" << endl;
                cout << "3. Go Back" << endl;
                cout << "Enter your option: ";
                cout << " " << endl;
                cin >> adminOption;
                cout << "===================================" << endl;

                if (adminOption == 1) {
                    signUpAdmin();
                } else if (adminOption == 2) {
                    if (loginAdmin()) {
                        int adminMenuOption;

                        do {
                            cout << "Admin Logged In" << endl;
                            cout << "1. Search" << endl;
                            cout << "2. Add Categories" << endl;
                            cout << "3. Add Products" << endl;
                            cout << "4. Delete Categories" << endl;
                            cout << "5. Delete Products" << endl;
                            cout << "6. Add Customers" << endl;
                            cout << "7. Delete Customers" << endl;
                            cout << "8. Backup Products" << endl;
                            cout << "9. Backup Customers" << endl;
                            cout << "10. Go Back" << endl;
                            cout << "Enter your option: ";
                            cin >> adminMenuOption;

                            switch (adminMenuOption) {
                                case 1:
                                    searchProduct();
                                    break;
                                case 2:
                                    addCategories();
                                    break;
                                case 3:
                                    addProducts();
                                    break;
                                case 4:
                                    deleteCategory();
                                    break;
                                case 5:
                                    deleteProduct();
                                    break;
                                case 6:
                                    addCustomer();
                                    break;
                                case 7:
                                    deleteCustomer();
                                    break;
                                case 8:
                                    backupProducts();
                                    break;
                                case 9:
                                    backupCustomers();
                                    break;
                                case 10:
                                    goBack();
                                    break;
                                default:
                                    cout << "Invalid option. Please try again." << endl;
                                    break;
                            }
                        } while (adminMenuOption != 8);
                    } else {
                        cout << "Invalid password. Please try again." << endl;
                    }
                }
            } while (adminOption != 3);
        } else if (option == 2) {
            int customerOption;

            do {
                cout << "Customer Menu" << endl;
                cout << "1. Sign Up" << endl;
                cout << "2. Sign In" << endl;
                cout << "3. Go Back" << endl;
                cout << "Enter your option: ";
                cin >> customerOption;
                cout << "===================================" << endl;

                if (customerOption == 1) {
                    signUpCustomer();
                } else if (customerOption == 2) {
                    if (loginCustomer()) {
                        int customerMenuOption;

                        do {
                            cout << "Customer Logged In" << endl;
                            cout << "1. Show all products" << endl;
                            cout << "2. Show all categories" << endl;
                            cout << "3. Search" << endl;
                            cout << "4. View Cart" << endl;
                            cout << "5. View Favorites" << endl;
                            cout << "6. Checkout" << endl;
                            cout << "7. Go Back" << endl;
                            cout << "Enter your option: ";
                            cin >> customerMenuOption;

                            switch (customerMenuOption) {
                                case 1:
                                    displayAllProducts();
                                    break;
                                case 2:
                                    displayCategoriesAndSelectProduct();
                                    break;
                                case 3:
                                    searchProduct();
                                    break;
                                case 4:
                                    viewCart();
                                    break;
                                case 5:
                                    viewFavorites();
                                    break;
                                case 6:
                                    checkout();
                                    break;
                                default:
                                    cout << "Invalid option. Please try again." << endl;
                                    break;
                            }
                        } while (customerMenuOption != 2);
                    } else {
                        cout << "Invalid password. Please try again." << endl;
                    }
                }
            } while (customerOption != 3);
        }
    } while (option != 3);

    return 0;
}

//Function Definition

// Function to generate a random password
string generateRandomPassword() {
    string password = "";
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int length = 8;

    srand(time(0));

    for (int i = 0; i < length; i++) {
        int index = rand() % characters.length();
        password += characters[index];
    }

    return password;
}

// Function to sign up a new admin
void signUpAdmin() {
    string username;
    string password;
    double bankBalance;

    cout << "Enter your username: ";
    cin >> username;

    password = generateRandomPassword();

    cout << "Your password is: " << password << endl;
    cout << "===================================" << endl;

    cout << "Enter your bank balance: ";
    cin >> bankBalance;

    ofstream adminsFile("admins.txt", ios::app);
    adminsFile << username << " " << password << " " << bankBalance << endl;
    adminsFile.close();

    cout << "Admin account created successfully!" << endl;
    cout << "===================================" << endl;
}

// Function to sign up a new customer
void signUpCustomer() {
    string username;
    string password;
    double bankBalance;

    cout << "Enter your username: ";
    cin >> username;

    password = generateRandomPassword();

    cout << "Your password is: " << password << endl;

    cout << "Enter your bank balance: ";
    cin >> bankBalance;
    cout << "===================================" << endl;

    ofstream customersFile("customers.txt", ios::app);
    customersFile << username << " " << password << " " << bankBalance << endl;
    customersFile.close();

    cout << "Customer account created successfully!" << endl;
    cout << "===================================" << endl;
}
// Function to check if a username exists in the admins.txt file
bool checkAdminUsernameExists(string username) {
    ifstream adminsFile("admins.txt");
    string line;

    while (getline(adminsFile, line)) {
        string adminUsername = line.substr(0, line.find(" "));
        if (adminUsername == username) {
            adminsFile.close();
            return true;
        }
    }

    adminsFile.close();
    return false;
}

// Function to check if a username exists in the customers.txt file
bool checkCustomerUsernameExists(string username) {
    ifstream customersFile("customers.txt");
    string line;

    while (getline(customersFile, line)) {
        string customerUsername = line.substr(0, line.find(" "));
        if (customerUsername == username) {
            customersFile.close();
            return true;
        }
    }

    customersFile.close();
    return false;
}

// Function to log in an admin
bool loginAdmin() {
    string username;
    string password;

    cout << "Enter your username: ";
    cin >> username;

    if (!checkAdminUsernameExists(username)) {
        cout << "Username does not exist. Please try again." << endl;
        return false;
    }

    cout << "Enter your password: ";
    cin >> password;
    cout << "===================================" << endl;

    ifstream adminsFile("admins.txt");
    string line;

    while (getline(adminsFile, line)) {
        string adminUsername = line.substr(0, line.find(" "));
        string adminPassword = line.substr(line.find(" ") + 1, line.find_last_of(" ") - line.find(" ") - 1);

        if (adminUsername == username && adminPassword == password) {
            adminsFile.close();
            return true;
        }
    }

    adminsFile.close();
    return false;
}

// Function to log in a customer
bool loginCustomer() {
    string username;
    string password;

    cout << "Enter your username: ";
    cin >> username;

    if (!checkCustomerUsernameExists(username)) {
        cout << "Username does not exist. Please try again." << endl;
        return false;
    }

    cout << "Enter your password: ";
    cin >> password;

    ifstream customersFile("customers.txt");
    string line;

    while (getline(customersFile, line)) {
        string customerUsername = line.substr(0, line.find(" "));
        string customerPassword = line.substr(line.find(" ") + 1, line.find_last_of(" ") - line.find(" ") - 1);

        if (customerUsername == username && customerPassword == password) {
            customersFile.close();
            return true;
        }
    }

    customersFile.close();
    return false;
}

// Function to search for a product
void searchProduct() {
    string productName;
    bool productFound = false;

    cout << "Choose the category to search in: " << endl;

    // Display all categories
    ifstream allCategoriesFile("allCategories.txt");
    string category;

    while (getline(allCategoriesFile, category)) {
        cout << category << endl;
    }

    allCategoriesFile.close();

    cout << "Enter the category to search in: ";
    cin >> category;

    ifstream productsFile(category + ".txt");
    string line;

    do {
        cout << "Enter the name of the product you're searching for: ";
        cin >> productName;

        while (getline(productsFile, line)) {
            if (line == productName) {
                cout << "Product found in category " << category << ": " << productName << endl;
                productFound = true;
                break;
            }
        }

        if (!productFound) {
            cout << "Product not found." << endl;
            cout << "Do you want to try again? (y/n): ";
            char choice;
            cin >> choice;
            if (choice == 'n' || choice == 'N') {
                break;
            }
        }
    } while (!productFound);

    productsFile.close();
}

// Function to add a category
void addCategories() {
    string categoryName;
    cout << "Enter a category you want to add: ";
    cin >> categoryName;

    ofstream categoryFile(categoryName + ".txt");
    categoryFile.close();

    ofstream allCategoriesFile("allCategories.txt", ios::app);
    allCategoriesFile << categoryName << endl;
    allCategoriesFile.close();

    cout << "Category " << categoryName << " successfully added." << endl;
}

const int MAX_CATEGORIES = 100;
const int MAX_PRODUCTS = 100;

// Function to add a product to a category
void addProducts() {
    double productPrice;
    string productName;
    string categoryName;

    cout << "Enter the name of the product you want to add: ";
    cin >> productName;

    cout << "Enter the price of the product: ";
    cin >> productPrice;

    cout << "Choose the category to save the product in: " << endl;

    // Array to store categories
    string categories[MAX_CATEGORIES];
    int numCategories = 0;

    // Read categories from file and store in the array
    ifstream categoryFiles("categories.txt");
    string category;

    while (getline(categoryFiles, category)) {
        categories[numCategories++] = category;
        cout << category << endl;
    }

    categoryFiles.close();

    cin >> categoryName;

    // Array to store products in a category
    string products[MAX_PRODUCTS];
    int numProducts = 0;

    // Add product to the selected category
    for (int i = 0; i < numCategories; i++) {
        if (categories[i] == categoryName) {
            products[numProducts++] = productName + " " + to_string(productPrice);
            break;
        }
    }

    // Save product to category file
    ofstream categoryFile(categoryName + ".txt", ios::app);
    categoryFile << productName << " " << productPrice << endl;
    categoryFile.close();

        // Save product to all products file
        ofstream allProductsFile("allProducts.txt", ios::app);
        allProductsFile << "[" << productName << ", " << productPrice << "]" << endl;
        allProductsFile.close();

        cout << "Product added to category " << categoryName << " successfully." << endl;
        cout << "===================================" << endl;
    }

    // Function to display all products in every category to the customer
    void displayAllProducts() {
        ifstream allProductsFile("allProducts.txt");
        string line;
        int productNumber = 1;

        cout << "ALL PRODUCTS" << endl;
        cout << "............" << endl;
        cout << " " << endl;
        cout << "===================================" << endl;

        while (getline(allProductsFile, line)) {
            cout << productNumber << ". " << line << endl;
            productNumber++;
        }

        allProductsFile.close();

        //prompt customer to select product
        int choice;
        cout << "Select a product: ";
        cin >> choice;

        // Add to cart or favorites
        int option;
        cout << "1. Add to cart" << endl;
        cout << "2. Add to favorites" << endl;
        cout << "Choose an option: ";
        cin >> option;

        if (option == 1) {
            // Add to cart
            string productName;
            double productPrice;

            cout << "Enter the name of the product: ";
            cin >> productName;

            cout << "Enter the price of the product: ";
            cin >> productPrice;

            ofstream cartFile("cart.txt", ios::app);
            cartFile << "Product Name: " << productName << ", Product Price: " << productPrice << endl;
            cartFile.close();
        } else if (option == 2) {
            // Add to favorites
            string productName;
            double productPrice;

            cout << "Enter the name of the product: ";
            cin >> productName;

            cout << "Enter the price of the product: ";
            cin >> productPrice;

            ofstream favoritesFile("favorites.txt", ios::app);
            favoritesFile << "Product Name: " << productName << ", Product Price: " << productPrice << endl;
            favoritesFile.close();
        }

    // Loop to continue shopping or go back to main menu
    char continueShopping;
    cout << "Continue shopping? (y/n): ";
    cin >> continueShopping;
    cout << "===================================" << endl;

    if (continueShopping == 'y' || continueShopping == 'Y') {
        displayAllProducts();
    } else {
        // Go back to previous menu
        // ...
    }
}

//function to view favorites
void viewFavorites() {
    ifstream favoritesFile("favorites.txt");
    string line;
    int productNumber = 1;

    cout << "YOUR FAVORITES" << endl;
    cout << "............" << endl;
    cout << " " << endl;

    while (getline(favoritesFile, line)) {
        cout << productNumber << ". " << line << endl;
        productNumber++;
    }

    favoritesFile.close();

    //display options to delete products from favorites or clear favorites
    int option;
    cout << "1. Delete product from favorites" << endl;
    cout << "2. Clear favorites" << endl;
    cout << "Go back" << endl;
    cout << "Choose an option: ";
    cin >> option;

    if (option == 1) {
        // Delete product from favorites
        string productToDelete;
        bool productFound = false;

        cout << "Enter the product you want to delete: ";
        cin >> productToDelete;

        ifstream favoritesFile("favorites.txt");
        ofstream tempFile("temp.txt");
        cout << "===================================" << endl;

        string line;

        while (getline(favoritesFile, line)) {
            if (line != productToDelete) {
                tempFile << line << endl;
            } else {
                productFound = true;
            }
        }

        favoritesFile.close();
        tempFile.close();

        if (productFound) {
            remove("favorites.txt");
            rename("temp.txt", "favorites.txt");
            cout << "Product deleted successfully." << endl;
        } else {
            remove("temp.txt");
            cout << "Product not found." << endl;
        }
    } else if (option == 2) {
        // Clear favorites
        ofstream favoritesFile("favorites.txt");
        favoritesFile.close();
        cout << "Favorites cleared successfully." << endl;
    } else {
        // Go back to previous menu
        // ...
    }
}

//function to checkout and subtract the totalprice from the bank balance
void checkout() {
    cout << " " << endl;
    cout << "CHECKOUT" << endl;
    cout << "............" << endl;
    cout << " " << endl;
    ifstream cartFile("cart.txt");
    string line;
    double totalPrice = 0;

    while (getline(cartFile, line)) {
        stringstream ss(line);
        string productName;
        double productPrice;

        ss >> productName >> productPrice;

        totalPrice += productPrice;
        cout <<"total price: "<< totalPrice << endl;
    }

    cartFile.close();


    // Get customer's bank balance
    ifstream customersFile("customers.txt");
    string customerLine;
    double bankBalance;

    while (getline(customersFile, customerLine)) {
        stringstream ss(customerLine);
        string username;
        string password;

        ss >> username >> password >> bankBalance;
        cout << "Bank balance: " << bankBalance << endl;
        cout << "===================================" << endl;
    }

    customersFile.close();

    // Check if customer has enough balance
    //cout << "Bank balance before purchase: " << bankBalance << endl;
    if (totalPrice > bankBalance) {
        cout << "Insufficient balance. Please add money to your account." << endl;
    } else {
        // Subtract total price from bank balance
        bankBalance -= totalPrice;

        // Update bank balance in customers file
        ifstream customersFile("customers.txt");
        ofstream tempFile("temp.txt");

        string line;

        while (getline(customersFile, line)) {
            stringstream ss(line);
            string username;
            string password;
            double balance;

            ss >> username >> password >> balance;

            if (username == "customer") {
                tempFile << username << " " << password << " " << bankBalance << endl;
            } else {
                tempFile << line << endl;
            }
        }

        customersFile.close();
        tempFile.close();

        remove("customers.txt");
        rename("temp.txt", "customers.txt");

        // Clear cart
        ofstream cartFile("cart.txt");
        cartFile.close();
        cout << "Bank balance after purchase: " << bankBalance << endl;
        cout << " " << endl;
        cout << "Checkout successful." << endl;
        cout << "===================================" << endl;
    }
}

//function to backup products
void backupProducts() {
    ifstream allProductsFile("allProducts.txt");
    ofstream productBackupFile("productBackup.txt");

    string line;

    while (getline(allProductsFile, line)) {
        productBackupFile << line << endl;
    }

    allProductsFile.close();
    productBackupFile.close();

    cout << "Products backed up successfully." << endl;
    cout << "===================================" << endl;
}

//function to backup customers
void backupCustomers() {
    ifstream customersFile("customers.txt");
    ofstream customerBackupFile("customerBackup.txt");

    string line;

    while (getline(customersFile, line)) {
        customerBackupFile << line << endl;
    }

    customersFile.close();
    customerBackupFile.close();

    cout << "Customers backed up successfully." << endl;
    cout << "===================================" << endl;
}

//function to view cart and delete products from cart
void viewCart() {
    ifstream cartFile("cart.txt");
    string line;
    int productNumber = 1;

    cout << "YOUR CART" << endl;
    cout << "............" << endl;
    cout << " " << endl;

    while (getline(cartFile, line)) {
        cout << productNumber << ". " << line << endl;
        productNumber++;
        cout << "===================================" << endl;
    }

    cartFile.close();

    //display options to delete products from cart or clear cart
    int option;
    cout << "1. Delete product from cart" << endl;
    cout << "2. Clear cart" << endl;
    cout << "Go back" << endl;
    cout << "Choose an option: ";
    cin >> option;

    if (option == 1) {
        // Delete product from cart
        string productToDelete;
        bool productFound = false;

        cout << "Enter the product you want to delete: ";
        cin >> productToDelete;

        ifstream cartFile("cart.txt");
        ofstream tempFile("temp.txt");

        string line;

        while (getline(cartFile, line)) {
            if (line != productToDelete) {
                tempFile << line << endl;
            } else {
                productFound = true;
            }
        }

        cartFile.close();
        tempFile.close();

        if (productFound) {
            remove("cart.txt");
            rename("temp.txt", "cart.txt");
            cout << "Product deleted successfully." << endl;
        } else {
            remove("temp.txt");
            cout << "Product not found." << endl;
        }
    } else if (option == 2) {
        // Clear cart
        ofstream cartFile("cart.txt");
        cartFile.close();
        cout << "Cart cleared successfully." << endl;
        cout << "===================================" << endl;
    } else {
        // Go back to previous menu
        // ...
    }

}

// Function to display all categories and select a category to view products
void displayCategoriesAndSelectProduct() {
    ifstream allCategoriesFile("allCategories.txt");
    string category;

    // Display all categories
    while (getline(allCategoriesFile, category)) {
        cout << category << endl;
    }

    allCategoriesFile.close();

    // Prompt user to select a category
    string selectedCategory;
    cout << "Choose a category to view products: ";
    cin >> selectedCategory;

    // Display products in the selected category
    ifstream categoryFile(selectedCategory + ".txt");
    string line;

    while (getline(categoryFile, line)) {
        cout << line << endl;
    }

    categoryFile.close();

    // Prompt user to select a product
    int selectedProduct;
    cout << "Select a product: ";
    cin >> selectedProduct;

    // Get product name and price
    string productName;
    double productPrice;

    // Read product details from file
    ifstream productFile("products.txt");
    int count = 1;

    while (getline(productFile, line)) {
        if (count == selectedProduct) {
            // Extract product name and price from line
            stringstream ss(line);
            ss >> productName >> productPrice;
            break;
        }
        count++;
    }

    productFile.close();

    // Prompt user to add to cart or favorites
    int option;
    cout << "1. Add to cart" << endl;
    cout << "2. Add to favorites" << endl;
    cout << "Choose an option: ";
    cin >> option;

    if (option == 1) {
        // Add to cart
        ofstream cartFile("cart.txt", ios::app);
        cartFile << productName << " " << productPrice << endl;
        cartFile.close();
    } else if (option == 2) {
        // Add to favorites
        ofstream favoritesFile("favorites.txt", ios::app);
        favoritesFile << productName << " " << productPrice << endl;
        favoritesFile.close();
    }

    // Prompt user to continue shopping or go back to main menu
    char continueShopping;
    cout << "Continue shopping? (y/n): ";
    cin >> continueShopping;

    if (continueShopping == 'y' || continueShopping == 'Y') {
        displayCategoriesAndSelectProduct();
    } else {
        // Go back to previous menu
        // ...
    }
}


// Function to delete a category and its products
void deleteCategory() {
    string categoryToDelete;

    cout << "Enter the category you want to delete: ";
    cin >> categoryToDelete;

    remove((categoryToDelete + ".txt").c_str());

    cout << "Category deleted successfully." << endl;
    cout << "===================================" << endl;
}

// Function to delete a product
void deleteProduct() {
    string productToDelete;
    bool productFound = false;

    cout << "Enter the product you want to delete: ";
    cin >> productToDelete;

    cout << "Choose the category to delete the product from: " << endl;

    // Display all categories
    ifstream categoryFiles("categories.txt");
    string category;

    while (getline(categoryFiles, category)) {
        cout << category << endl;
    }

    categoryFiles.close();

    cin >> category;

    ifstream file(category + ".txt");
    ofstream tempFile(category + "_temp.txt");

    string line;
    while (getline(file, line)) {
        if (line != productToDelete) {
            tempFile << line << endl;
        } else {
            productFound = true;
        }
    }

    file.close();
    tempFile.close();

    if (productFound) {
        remove((category + ".txt").c_str());
        rename((category + "_temp.txt").c_str(), (category + ".txt").c_str());
        cout << "Product deleted successfully." << endl;
    } else {
        remove((category + "_temp.txt").c_str());
        cout << "Product not found." << endl;
        cout << "===================================" << endl;
    }
}

// Function to add a new customer
void addCustomer() {
    string username;
    string password;
    double bankBalance;

    cout << "Enter the username for the new customer: ";
    cin >> username;

    cout << "Enter the password for the new customer: ";
    cin >> password;

    cout << "Enter the bank balance for the new customer: ";
    cin >> bankBalance;


    ofstream customersFile("customers.txt", ios::app);
    customersFile << username << " " << password << " " << bankBalance << endl;
    customersFile.close();

    cout << "Customer added successfully." << endl;
    cout << "===================================" << endl;
}

void goBack() {
    int option;
    cout << "1. Go back to previous menu" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter your option: ";
    cin >> option;

    if (option == 1) {
        // Go back to main menu
        // ...
    } else {
        // Exit
        exit(0);
    }
}


// Function to delete a customer
void deleteCustomer() {
    string customerToDelete;
    bool customerFound = false;

    cout << "Enter the customer you want to delete: ";
    cin >> customerToDelete;

    ifstream customersFile("customers.txt");
    ofstream tempFile("temp.txt");

    string line;

    while (getline(customersFile, line)) {
        string customer = line.substr(0, line.find(" "));

        if (customer != customerToDelete) {
            tempFile << line << endl;
        } else {
            customerFound = true;
        }
    }

    customersFile.close();
    tempFile.close();

    if (customerFound) {
        remove("customers.txt");
        rename("temp.txt", "customers.txt");
        cout << "Customer deleted successfully." << endl;
    } else {
        remove("temp.txt");
        cout << "Customer not found." << endl;
        cout << "===================================" << endl;
    }
}