#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Product {
public:
    int id;
    string name;
    double price;
    int quantity;

    Product() {
        id = 0;
        name = "";
        price = 0;
        quantity = 0;
    }

    Product(int i, string n, double p, int q) {
        id = i;
        name = n;
        price = p;
        quantity = q;
    }
};

class Cart {
private:
    Product* items;
    int size;
    int capacity;
    double total;
    string discountTrail;

    // Increase array capacity
    void resize() {
        capacity = capacity * 2;

        Product* newItems = new Product[capacity];

        for (int i = 0; i < size; i++) {
            newItems[i] = items[i];
        }

        delete[] items;
        items = newItems;
    }

    void calculateTotal() {
        total = 0;

        for (int i = 0; i < size; i++) {
            total += items[i].price * items[i].quantity;
        }
    }

