#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <climits>
const int infinity = INT_MAX;

class BurgerShop {
public:
    std::string burgerName[4] = {"Cheese Burger", "Chicken Burger", "Veggie Burger", "Fish Burger"};
    int price[4] = {150, 200, 180, 250};
};

std::string deliveryPoints[6] = {"My Burger Shop", "Noida", "Ghaziabad", "Mohan Nagar", "Location 4", "Location 5"};

std::vector<std::vector<int>> distanceMatrix = {
    {0, 4, 3, 2, 5, 7},
    {4, 0, 6, 2, 7, 3},
    {3, 6, 0, 6, 3, 2},
    {2, 2, 6, 0, 5, 8},
    {5, 7, 3, 5, 0, 4},
    {7, 3, 2, 8, 4, 0}
};

// Function to calculate shortest path using Dijkstra's algorithm
std::vector<int> dijkstra(int sourceNode) {
    int n = distanceMatrix.size();
    std::vector<int> distance(n, infinity);
    std::set<std::pair<int, int>> nodes;

    distance[sourceNode] = 0;
    nodes.insert({0, sourceNode});

    while (!nodes.empty()) {
        int u = nodes.begin()->second;
        nodes.erase(nodes.begin());

        for (int v = 0; v < n; ++v) {
            if (distance[u] + distanceMatrix[u][v] < distance[v]) {
                nodes.erase({distance[v], v});
                distance[v] = distance[u] + distanceMatrix[u][v];
                nodes.insert({distance[v], v});
            }
        }
    }

    return distance;
}

int main() {
    BurgerShop* myburgerShop = new BurgerShop();

    int option = -99;

    std::string registeredPhoneNumber = "1234567890"; // Change this to the registered phone number
    bool discountApplied = false;

    do {
        std::cout << "==============================" << std::endl;
        std::cout << "Welcome to My Burger Shop" << std::endl;
        std::cout << "1. Show Menu" << std::endl;
        std::cout << "2. Place order for Home Delivery Customer" << std::endl;
        std::cout << "3. Place order for Dine-in Customer" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> option;

        switch (option) {
            case 1: { // Show Menu
                std::cout << "==============================" << std::endl;
                std::cout << "Menu" << std::endl;
                for (int i = 0; i < 4; ++i) {
                    std::cout << i + 1 << ". " << myburgerShop->burgerName[i] << " - " << myburgerShop->price[i] << " RS/_" << std::endl;
                }
                std::cout << "==============================" << std::endl;
                break;
            }

            case 2: { // Place order for Home Delivery Customer
                std::cout << "Enter your phone number: ";
                std::string phoneNumber;
                std::cin >> phoneNumber;

                if (phoneNumber == registeredPhoneNumber) {
                    std::cout << "Phone number registered!" << std::endl;

                    if (!discountApplied) {
                        discountApplied = true;
                        std::cout << "Congratulations! You've been granted a 10% discount." << std::endl;
                    }
                } else {
                    std::cout << "Phone number not registered for discount." << std::endl;
                }

                std::cout << "Available delivery locations: " << std::endl;
                for (int i = 1; i <= 5; i++) {
                    std::cout << i << ". " << deliveryPoints[i] << std::endl;
                }
                 int deliveryLocation;
                std::cout << "Enter your delivery location (1-5): ";
                std::cin >> deliveryLocation;

                std::vector<int> distanceFromShop = dijkstra(0); // As Zero is our Source Node
                int distanceToDeliveryLocation = distanceFromShop[deliveryLocation];

                std::string name;
                int age, quantity, burgerIndex;
                double bill;

                std::cout << "Enter the name of the customer: ";
                std::cin >> name;
                std::cout << "Enter the age of the customer: ";
                std::cin >> age;
                std::cout << "Enter the quantity of the burger: ";
                std::cin >> quantity;
                std::cout << "Enter the option for the burger: ";
                std::cin >> burgerIndex;

                int deliveryChargesPerKM = 50;
                int deliveryCharges = deliveryChargesPerKM * distanceToDeliveryLocation;

                if (discountApplied) {
                    bill = (quantity * myburgerShop->price[burgerIndex - 1]) * 0.9 + deliveryCharges;
                } else {
                    bill = quantity * myburgerShop->price[burgerIndex - 1] + deliveryCharges;
                }

                std::cout << "Your order has been placed, " << name << ". ";
                std::cout << "Your total bill (including delivery charges) is: " << bill << " RS/_" << std::endl;
                std::cout << "Estimated delivery distance: " << distanceToDeliveryLocation << " KM" << std::endl;
                std::cout << "Delivery charges: " << deliveryCharges << " RS/_" << std::endl;
                break;
            }

            case 3: { // Place order for Dine-in Customer
                // Order placement logic for dine-in...
                std::cout << "Available dine-in locations: " << std::endl;
                for (int i = 1; i <= 3; i++) {
                    std::cout << i << ". " << deliveryPoints[i] << std::endl;
                }

                int dineInLocation;
                std::cout << "Enter your dine-in location (1-3): ";
                std::cin >> dineInLocation;

                std::string name;
                int age, quantity, burgerIndex;
                double bill;

                std::cout << "Enter the name of the customer: ";
                std::cin >> name;
                std::cout << "Enter the age of the customer: ";
                std::cin >> age;
                std::cout << "Enter the quantity of the burger: ";
                std::cin >> quantity;
                std::cout << "Enter the option for the burger: ";
                std::cin >> burgerIndex;

                bill = quantity * myburgerShop->price[burgerIndex - 1];

                std::cout << "Your dine-in order has been placed, " << name << ". ";
                std::cout << "Your total bill is: " << bill << " RS/_" << std::endl;
                std::cout << "Please enjoy your meal at " << deliveryPoints[dineInLocation] << "." << std::endl;
                break;
            }

            case 0: // Exit
                std::cout << "Exiting the program. Thank you!" << std::endl;
                break;

            default:
                std::cout << "Invalid option. Please try again." << std::endl;
                break;
        }
    } while (option != 0);

    delete myburgerShop;

    return 0;
}
