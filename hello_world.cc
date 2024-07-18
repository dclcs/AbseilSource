#include <iostream>
#include <string>
#include <vector>
#include "absl/strings/str_join.h"
#include "absl/container/flat_hash_set.h"
#include "absl/container/flat_hash_map.h"


int main() {
    std::vector<std::string> v = {"foo","bar","baz"};
    std::string s = absl::StrJoin(v, "-");
    std::cout << "Joined string: " << s << "\n";


    absl::flat_hash_set<std::string> set1; // default allocator
    absl::flat_hash_map<int, std::string> map1;
    absl::flat_hash_set<std::string> set2 = {{"huery", "dewey", "louie"}};
    absl::flat_hash_map<int, std::string> map2 = {{1, "huey"}, {2, "dewey"}, {3, "louie"},};

    absl::flat_hash_set<std::string> set3(set2);
    absl::flat_hash_map<int, std::string>map3(map2);

    absl::flat_hash_set<std::string> set4;
    set4 = set3;
    absl::flat_hash_map<int, std::string> map4;
    map4 = map3;

    absl::flat_hash_set<std::string> set5(std::move(set4));
    absl::flat_hash_map<int, std::string> map5(std::move(map4));

    absl::flat_hash_set<std::string> set6;
    set6 = std::move(set5);
    absl::flat_hash_map<int, std::string> map6;
    map6 = std::move(map5);

    std::vector<std::string> va = {"a", "b"};
    absl::flat_hash_set<std::string> set7(va.begin(), va.end());

    std::vector<std::pair<int, std::string>> vb = {{1, "a"}, {2, "b"}};
    absl::flat_hash_map<int, std::string> map7(vb.begin(), vb.end());
}
