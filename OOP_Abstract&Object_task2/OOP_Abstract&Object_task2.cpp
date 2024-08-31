#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

class Address {
private:
    std::string city;
    std::string street;
    std::string house;
    std::string flat;
public:
    Address(std::string city, std::string street, std::string house, std::string flat) {
        this->city = city;
        this->street = street;
        this->house = house;
        this->flat = flat;
    };

    std::string get_output_address() {
        return city + ", " + street + ", " + house + ", " + flat;
    }
};


void bubble_sort(std::string* addresses, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (addresses[j] > addresses[j + 1]) {
               std::string temp= addresses[j];
                addresses[j] = addresses[j + 1];
                addresses[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    std::ifstream infile("in.txt");
  

    int address_count = 0;
    infile >> address_count;

    std::string* addresses = new std::string[address_count];

    std::string city, street, house, flat;
    for (int i = 0; i < address_count; i++) {
        infile >> city >> street >> house >> flat;
        
        Address address(city, street, house, flat);
        addresses[i] = address.get_output_address();
    }

    infile.close();


    std::ofstream outfile("out.txt");
    bubble_sort(addresses, address_count);

    outfile << address_count << std::endl;
    for (int i = 0; i < address_count; i++) {
        outfile << addresses[i] << std::endl;
    }

    delete[] addresses;
   
    outfile.close();

    return 0;
}
