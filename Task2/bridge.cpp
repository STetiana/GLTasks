#include <iostream>
#include <sstream> // для std::stringstream
 
int main(int argc, char *argv[]){
        if(argc != 3){
                std::cerr << "Only two arguments are acceptable\n"; 
        } else{
                int number_of_spans; //N - total number of spans the Magical Bridge has
                double distance; // D - distance between the spans
                std::stringstream(argv[1]) >> number_of_spans;
                std::stringstream(argv[2]) >> distance;
                std::cout << number_of_spans*distance*(number_of_spans+1)/2 << std::endl; //calculating the total length of the cables 
 
        }
        return 0;
}
