#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class Car{
    public:
        float mass;
        float cL;
        float cD;
        float mu;
        std::vector<float> hardpoints;
        
    void load_data(const std::string& filename){
        std::ifstream file(filename);
        std::string line;

        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string item;
            std::vector<std::string> row;

            while (std::getline(ss, item, ',')) {
                row.push_back(item);
            }

            for (const auto& cell : row) {
                std::cout << cell << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main(){


    return 0;
}