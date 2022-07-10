#include <iostream>
#include <functional>
#include <list>
#include <map>

struct billionaire {
    std::string name;
    double dollars;
    std::string country;
};



int main()
{
    std::list<billionaire> billionaires{
        {"ELON MUSK", 219, "USA"},
        {"Jeff Bezos", 171, "USA"},
        {"Bill Gates", 129, "USA"},
        {"Warren Baffet", 118, "USA"},
        {"Mukesh Ambani", 90.7, "India"},
        {"Zhong Shanshan", 65.7, "China"},
        {"Amancio Ortega", 59.6, "Spain"}
    };
    std::map < std::string, std::pair <const billionaire, size_t>> m;
    for (const auto& b : billionaires) {
        auto [iterator, success] = m.try_emplace(b.country, b, 1);
        if (!success) {
            iterator->second.second += 1;
        }
    }
    for (const auto& [key, value] : m) {
        const auto& [b, count] = value;
        std::cout << b.country << " : " << count
            << " billionaires. Richest is "
            << b.name << " with " << b.dollars
            << " B$\n";
    }
}