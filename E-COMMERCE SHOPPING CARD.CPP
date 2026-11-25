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
    public:
    Cart() {
        size = 0;
        capacity = 2;
        total = 0;

        items = new Product[capacity];
        discountTrail = "No discount applied";
    }

    Cart& operator+=(Product p) {
        if (size == capacity) {
            resize();
        }

        items[size] = p;
        size++;

        calculateTotal();
        return *this;
    }
    
     Cart& operator-=(int id) {
        bool found = false;

        for (int i = 0; i < size; i++) {
            if (items[i].id == id) {
                for (int j = i; j < size - 1; j++) {
                    items[j] = items[j + 1];
                }

                size--;
                found = true;
                break;
            }
        }

    