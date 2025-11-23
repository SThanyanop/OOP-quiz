#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct OrderItem {
    string name;
    char size;
    double price;
};

struct OrderSummary {
    vector<OrderItem> items;
    double total_price;
};

class Beverage {
protected:
    string name;
    char size;
    double base_price;
    
public:
    Beverage(string n, char s) : name(n), size(s), base_price(0) {}
    
    double getPrice() {
        double multiplier = 1.0;
        if (size == 'S') multiplier = 0.8;
        else if (size == 'L') multiplier = 1.3;
        return base_price * multiplier;
    }
    
    string getName() { return name; }
    char getSize() { return size; }
    double getBasePrice() { return base_price; }
};

class Coffee : public Beverage {
private:
    bool has_milk;
    
public:
    Coffee(char s = 'M') : Beverage("Coffee", s), has_milk(false) {
        base_price = 50;
    }
    
    void addMilk() {
        has_milk = true;
        name = "Coffee with Milk";
        base_price += 10;
    }
    
    bool hasMilk() { return has_milk; }
};

class Tea : public Beverage {
public:
    Tea(char s = 'M') : Beverage("Tea", s) {
        base_price = 35;
    }
};

class Juice : public Beverage {
private:
    string fruit_type;
    
public:
    Juice(string fruit = "Orange", char s = 'M') 
        : Beverage(fruit + " Juice", s), fruit_type(fruit) {
        base_price = 40;
    }
    
    string getFruitType() { return fruit_type; }
};

OrderSummary processOrder(char coffee_size, bool add_milk, char tea_size,  string juice_fruit, char juice_size) {
    OrderSummary summary;
    
    Coffee coffee(coffee_size);
    if (add_milk) {
        coffee.addMilk();
    }
    OrderItem coffee_item = {coffee.getName(), coffee.getSize(), coffee.getPrice()};
    summary.items.push_back(coffee_item);
    
    Tea tea(tea_size);
    OrderItem tea_item = {tea.getName(), tea.getSize(), tea.getPrice()};
    summary.items.push_back(tea_item);
    
    Juice juice(juice_fruit, juice_size);
    OrderItem juice_item = {juice.getName(), juice.getSize(), juice.getPrice()};
    summary.items.push_back(juice_item);
    
    summary.total_price = 0;
    for (const auto& item : summary.items) {
        summary.total_price += item.price;
    }
    
    return summary;
}

struct PriceBreakdown {
    double coffee_price;
    double tea_price;
    double juice_price;
    double total;
};

PriceBreakdown calculatePrices(char coffee_size, bool add_milk,char tea_size,string juice_fruit, char juice_size) {
    PriceBreakdown prices;
    
    Coffee coffee(coffee_size);
    if (add_milk) coffee.addMilk();
    prices.coffee_price = coffee.getPrice();
    
    Tea tea(tea_size);
    prices.tea_price = tea.getPrice();
    
    Juice juice(juice_fruit, juice_size);
    prices.juice_price = juice.getPrice();
    
    prices.total = prices.coffee_price + prices.tea_price + prices.juice_price;
    
    return prices;
}

int main() {
    OrderSummary order = processOrder('L', true, 'M', "Orange", 'S');
    
    PriceBreakdown prices = calculatePrices('L', true, 'M', "Orange", 'S');
    
    for (const auto& item : order.items) {
        cout << item.name << " (Size " << item.size << "): " << item.price << " baht" << endl;
    }

    cout << "Coffee Price: " << prices.coffee_price << " baht" << endl;
    cout << "Tea Price: " << prices.tea_price << " baht" << endl;
    cout << "Juice Price: " << prices.juice_price << " baht" << endl;
    cout << "Total: " << prices.total << " baht" << endl;
    
    return 0;
}