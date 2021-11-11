#include <iostream>
#include <cpr/cpr.h>
#include <fstream>
#include "color.hpp"

void checker(std::string name_to_post) {
    cpr::Response r = cpr::Post(cpr::Url{ "https://linktr.ee/validate/username" },
        cpr::Payload{ {"username", name_to_post} });
    std::string response = r.text;
    std::string error = "fail";
    std::string available = "success";
    if (strstr(response.c_str(), error.c_str()))
    {
        std::cout << dye::red("[UNAVAILABLE] - ") << name_to_post + "\n";
    }
    else if (strstr(response.c_str(), available.c_str())) 
    {
        std::cout << dye::green("[AVAILABLE] - ") << name_to_post + "\n";
    }
}

int main() {
    std::ifstream file("list.txt");
    std::string line;
    while (std::getline(file, line)) {
        checker(line);
    }

}