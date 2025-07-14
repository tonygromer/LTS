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
        float v_max;
        float max_power;
        float max_torque;
        std::vector<float> hardpoints;
        
    int load_data(const std::string& filename){
        std::string line;
        std::ifstream myfile;
        myfile.open(filename);
        
        if (myfile.is_open()){
            while (getline(myfile, line)){
                std::string str_var = line.substr(0, line.find(","));
                std::string str_val = line.substr(line.find(",")+1, line.length());
                float val = atof(str_val.c_str());

                if (str_var == "mass"){
                    mass = val;
                }

                else if (str_var == "cL"){
                    cL = val;
                }

                else if (str_var == "cD"){
                    cD = val;
                } 

                else if (str_var == "mu"){
                    mu = val;
                }
            }
        }
        else{
            std::cout << "Unable to open file.";
        }
        
        myfile.close();

        return 0;
    }

    std::vector<float> calculate_ggv(){
        std::vector<float> ggv_diagram;

        

        return ggv_diagram;
    }
    
};

class Track{
    public:
        float length;

    int load_data(const std::string& filename){
        std::string line;
        std::ifstream myfile;
        myfile.open(filename);
        
        if (myfile.is_open()){
            while (getline(myfile, line)){
                std::cout << line;
            }
        }
        else{
            std::cout << "Unable to open file.";
        }
        
        myfile.close();

        return 0;
    }
};

int write_data(const std::string& filename){
        std::ofstream myfile;
        myfile.open(filename);
        myfile << "Writing to file.\n";
        myfile.close();

        return 0;
    }

int main(){
    Car TestCar;
    TestCar.load_data("example.txt");

    return 0;
}