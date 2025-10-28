#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

class Car{
    public:
        float mass;
        float cLA;
        float cD;
        float mu;
        float v_max;
        float max_power;
        float max_torque;
        int n_velocites;
        std::vector<float> hardpoints;
        std::vector<float> velocities;
        float g = 9.82;

        struct state
        {
            std::vector<float> velocity;
            std::vector<float> position;
            std::vector<float> acceleration;
        };
        
        Car(const std::string &filename){
            load_data(filename);
            
            // v^2 = 2 * Fd / cDA*rho
            // Fd = max_power / v
            // v^2 = 2*max_power/ v*cDA*rho
            v_max = std::pow(2*max_power*1000/(1.225*cD), (float) 1/3);
            for (int i = 0; i < n_velocites; i++){
                velocities.push_back((float) i / v_max);
            }

        }
        
    int load_data(const std::string &filename){
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

                else if (str_var == "cLA"){
                    cLA = val;
                }

                else if (str_var == "cD"){
                    cD = val;
                } 

                else if (str_var == "mu"){
                    mu = val;
                }

                else if (str_var == "power"){
                    max_power = val;
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
        // Vill jag ha dessa som vector/array?
        float Fn;
        float Fx;
        float Fy;

        for (int i = 0; i< 10; i++){

            // Normal forces
            Fn = mass*g + cLA*velocities;
            
            //Maximum longitudinal
            
            //Maximum lateral
            
        }
        

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
    Car TestCar("example.txt");


    return 0;
}