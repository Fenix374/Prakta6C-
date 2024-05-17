#include <iostream>
#include <vector>
#include <string>

class Motorcycle {
public:
    int id;
    std::string brand;
    std::string model;
    int year;
    double price;

    Motorcycle(int id, std::string brand, std::string model, int year, double price) {
        this->id = id;
        this->brand = brand;
        this->model = model;
        this->year = year;
        this->price = price;
    }

    void print_info() const {
        std::cout << "ID: " << id << "\n";
        std::cout << "Brand: " << brand << "\n";
        std::cout << "Model: " << model << "\n";
        std::cout << "Year: " << year << "\n";
        std::cout << "Price: " << price << "\n\n";
    }
};

class Client {
public:
    int id;
    std::string first_name;
    std::string last_name;
    std::string phone;
    std::string email;

    Client(int id, std::string first_name, std::string last_name, std::string phone, std::string email)  {
        this->id = id;
        this->first_name = first_name;
        this->last_name = last_name;
        this->phone = phone;
        this->email = email;
    }

    void print_info() const  {
        std::cout << "ID: " << id << "\n";
        std::cout << "First Name: " << first_name << "\n";
        std::cout << "Last Name: " << last_name << "\n";
        std::cout << "Phone: " << phone << "\n";
        std::cout << "Email: " << email << "\n\n";
    }
};

// Класс Заказ
class Order {
public:
    int id;
    int motorcycle_id;
    int client_id;
    std::string date;

    Order(int id, int motorcycle_id, int client_id, std::string date) {
        this->id = id;
        this->motorcycle_id = motorcycle_id;
        this->client_id = client_id;
        this->date = date;
    }

    void print_info() const {
        std::cout << "ID: " << id << "\n";
        std::cout << "Motorcycle ID: " << motorcycle_id << "\n";
        std::cout << "Client ID: " << client_id << "\n";
        std::cout << "Date: " << date << "\n\n";
    }
};

void create_motorcycle(std::vector<Motorcycle>& motorcycles) {
    int id;
    std::string brand;
    std::string model;
    int year;
    double price;

    std::cout << "Enter motorcycle ID: ";
    std::cin >> id;
    std::cout << "Enter motorcycle brand: ";
    std::cin.ignore();
    std::getline(std::cin, brand);
    std::cout << "Enter motorcycle model: ";
    std::getline(std::cin, model);
    std::cout << "Enter motorcycle year: ";
    std::cin >> year;
    std::cout << "Enter motorcycle price: ";
    std::cin >> price;

    motorcycles.push_back(Motorcycle(id, brand, model, year, price));
}

void delete_motorcycle(std::vector<Motorcycle>& motorcycles) {
    int id;
    std::cout << "Enter motorcycle ID to delete: ";
    std::cin >> id;

    for (size_t i = 0; i < motorcycles.size(); ++i) {
        if (motorcycles[i].id == id) {
            motorcycles.erase(motorcycles.begin() + i);
            return;
        }
    }

    std::cout << "Motorcycle with ID " << id << " not found\n";
}

void update_motorcycle(std::vector<Motorcycle>& motorcycles) {
    int id;
    std::cout << "Enter motorcycle ID to update: ";
    std::cin >> id;

    for (size_t i = 0; i < motorcycles.size(); ++i) {
        if (motorcycles[i].id == id) {
            std::string brand;
            std::string model;
            int year;
            double price;

            std::cout << "Enter new motorcycle brand: ";
            std::cin.ignore();
            std::getline(std::cin, brand);
            std::cout << "Enter new motorcycle model: ";
            std::getline(std::cin, model);
            std::cout << "Enter new motorcycle year: ";
            std::cin >> year;
            std::cout << "Enter new motorcycle price: ";
            std::cin >> price;

            motorcycles[i].brand = brand;
            motorcycles[i].model = model;
            motorcycles[i].year = year;
            motorcycles[i].price = price;

            return;
        }
    }

    std::cout << "Motorcycle with ID " << id << " not found\n";
}

int main() {
    std::vector<Motorcycle> motorcycles;
    std::vector<Client> clients;
    std::vector<Order> orders;

    int choice;
    while (true) {
        std::cout << "1. Print shop info\n";
        std::cout << "2. Create motorcycle\n";
        std::cout << "3. Delete motorcycle\n";
        std::cout << "4. Update motorcycle\n";
        std::cout << "5. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            for (const Motorcycle& m : motorcycles) {
                m.print_info();
            }
            for (const Client& c : clients) {
                c.print_info();
            }
            for (const Order& o : orders) {
                o.print_info();
            }
        }
        else if (choice == 2) {
            create_motorcycle(motorcycles);
        }
        else if (choice == 3) {
            delete_motorcycle(motorcycles);
        }
        else if (choice == 4) {
            update_motorcycle(motorcycles);
        }
        else if (choice == 5) {
            break;
        }
        else {
            std::cout << "Invalid choice\n";
        }
    }

    return 0;
}
