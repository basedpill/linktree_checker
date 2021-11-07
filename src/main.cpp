#include <iostream>
#include <cpr/cpr.h>
#include <fstream>

void check(std::string url){
    cpr::Response r = cpr::Get(cpr::Url{url});
        if(r.status_code == 200){
            std::cout << url << " is valid!";}
        else{
            std::cout << url << " is invalid!";}
}


int main(){
    system("title linktr.ee checker by basedpill");
    std::string base_url = "https://linktr.ee/";
    std::ifstream file("list.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::string append_line = line;
        std::string final_line = base_url + append_line;
        std::cout << final_line;
}

}