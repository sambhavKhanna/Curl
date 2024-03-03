#include <iostream>
#include <string>
#include <sstream>
#include <regex>

int main() {
    std::string s;
    std::istream& in = std::cin;
    std::regex pattern("content=\"(https://.*?)\"");
    std::string prefix = "content=";

    while(getline(in, s)) {
        std::istringstream iss{s};
        std::string word;
        while(iss >> word) {
            std::smatch match;
            if (std::regex_search(word, match, pattern)) {
                if (match.size() > 1) {
                    std::cout << match[1] << std::endl;
                }
            }
        }
    }
}