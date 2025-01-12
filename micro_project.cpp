#include <iostream>
#include <string>

using namespace std;

const int MAX_PRODUCTS = 5;


int arrproductIds[MAX_PRODUCTS] = {1, 2, 3, 4, 5};
string arrproductNames[MAX_PRODUCTS] = {"Laptop", "Phone", "Tablet", "Headphones", "Mouse"};    //product catalog
double arrproductPrices[MAX_PRODUCTS] = {800.00, 500.00, 300.00, 50.00, 20.00};


int cartProductIds[MAX_PRODUCTS] = {0};              //cart data
int cartQuantities[MAX_PRODUCTS] = {0};


void displayProducts();        //using function
void addToCart();
void viewCart();

int main() {
    int choice;

    do {
        cout << "\n=== E-Commerce Application ===\n";
        cout << "1. View Products\n";
        cout << "2. Add to Cart\n";
        cout << "3. View Cart\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayProducts();
                break;
            case 2:
                addToCart();
                break;
            case 3:
                viewCart();
                break;
            case 4:
                cout << "Thank you for shopping with us!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}


void displayProducts() {            //to display the cart
    cout << "\nAvailable Products:\n";
    cout << "ID\tName\t\tPrice\n";
    cout << "----------------------------------\n";
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        cout << arrproductIds[i] << "\t" << arrproductNames[i] << "\t\t$" << arrproductPrices[i] << endl;
    }
    cout << "----------------------------------\n";
}

void addToCart() {
    int productId, quantity;

    cout << "Enter the Product ID to add to cart: ";
    cin >> productId;

    bool found = false;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (arrproductIds[i] == productId) {
            found = true;

            cout << "Enter quantity: ";
            cin >> quantity;

            if (quantity <= 0) {
                cout << "Quantity must be positive.\n";
                return;
            }

            cartProductIds[i] = productId;
            cartQuantities[i] += quantity;

            cout << "Added " << quantity << " of " << arrproductNames[i] << " to the cart.\n";
            break;
        }
    }

    if (!found) {
        cout << "Product not found.\n";
    }
}

void viewCart() {
    cout << "\nYour Cart:\n";
    cout << "ID\tName\t\tPrice\tQuantity\tTotal\n";
    cout << "-----------------------------------------------------\n";

    double grandTotal = 0.0;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (cartProductIds[i] != 0) {
            double total = cartQuantities[i] * arrproductPrices[i];
            grandTotal += total;

            cout << cartProductIds[i] << "\t" << arrproductNames[i] << "\t\t$" << arrproductPrices[i]
                 << "\t" << cartQuantities[i] << "\t\t$" << total << endl;
        }
    }

    if (grandTotal == 0.0) {
        cout << "Your cart is empty.\n";
    } else {
        cout << "-----------------------------------------------------\n";
        cout << "Grand Total: $" << grandTotal << endl;
    }
}