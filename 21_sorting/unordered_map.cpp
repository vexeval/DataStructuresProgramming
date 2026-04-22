// #include <iostream>
// #include <unordered_map> // Hash Table
// #include <vector>
// #include <string>

// class HashExamples {
// public:
//     template <typename T>
//     static void countFrequency(const std::vector<T>& v) {
//         std::unordered_map<T, int> freq;
//         for (const T& i : v) {
//             freq[i]++;
//         }
//         for (const auto& f : freq) {
//             std::cout << f.first << " : " << f.second << std::endl;
//         }
//     }
    
//     template <typename T>
//     static bool hasDuplicates(const std::vector<T>& v) {
//         std::unordered_map<T, int> vals;
//         for (const T& i : v) {
//             vals[i]++;
//         }
        
//         for (const auto& i : vals) {
//             if (i.second > 1) {
//                 return true;
//             }
//         }
        
//         return false;
//     }
// private:

// };


// int main() {
//     std::unordered_map<std::string, int> grades;

//     // Insert
//     grades["Michael"] = 90;
//     grades["Anna"] = 95;
//     grades["John"] = 76;

//     // Iterate through the table
//     for (const auto& grade : grades) {
//         std::cout << grade.first << " : " << grade.second << std::endl;
//     }
    
//     // Search (find method)
//     auto it = grades.find("John");
    
//     if (it == grades.end()) {
//         std::cout << "Not found\n";
//     }
//     else {
//         std::cout << "Found:\n";
//         std::cout << it->first << " : " << it->second << std::endl;
//     }

//     std::cout << "Count Frequency...\n";
//     std::vector<int> v {1, 2, 3, 4, 1, 2, 2, 2, 5, 5, 12};
//     HashExamples::countFrequency(v);
    
    
//     std::cout << "Check duplicates...\n";
//     std::vector<std::string> s {"hello", "apple", "banana", "hey", "ban", "apple"};
//     std::cout << HashExamples::hasDuplicates(s) << std::endl;


//     return 0;
// }
