#include <vector>
#include <iostream>
#include <unordered_map>

// O(n)
//Do it for O(n) time and O(1) space
// with hash map
std::vector<std::pair<int,int>> getSymmetricPairs(std::vector<std::pair<int,int>> & pairs) {
    std::vector<std::pair<int,int>> symmetricPairs;
    std::unordered_map<int, int> map;

    for (const auto &item: pairs) {
        if (map.find(item.second) != map.end()) {
            if (map[item.second] == item.first) {
                symmetricPairs.emplace_back(item);
            }
        } else {
            map[item.first] = item.second;
        }
    }
}

int main() {
    std::vector<std::pair<int, int>> pairs;
    pairs.emplace_back(1, 2);
    pairs.emplace_back(2, 3);
    pairs.emplace_back(3, 4);
    pairs.emplace_back(4, 3);
    pairs.emplace_back(3, 2);

    std::vector<std::pair<int, int>> symmetricPairs = getSymmetricPairs(pairs);

    for (const auto &item: symmetricPairs) {
        std::cout << item.first << " " << item.second << std::endl;
    }
}