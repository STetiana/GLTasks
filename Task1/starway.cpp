#include <iostream>
#include <sstream> // для std::stringstream
 
int main(int argc, char *argv[]){
        if(argc != 3){
                std::cerr << "Only two arguments are acceptable\n"; 
        } else{
                int stairs, th_stair; //stairs =  N; th_stairs = K
                std::stringstream(argv[1]) >> stairs;
                std::stringstream(argv[2]) >> th_stair;
                std::cout << (stairs-1)/(th_stair+1)+1 << std::endl; // calculating the total number of stairs the Giant steps
 
        }
        return 0;
}
