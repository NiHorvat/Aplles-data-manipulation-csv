#include <iostream>
#include <string>
#include <fstream> 
#include <string.h>
#include <map>
#include <iomanip>



using namespace std;

#define KOLIKO 1000000


#include <iostream>
#include <random>
#include <chrono>

using namespace std;

double generateRandomDecimal() {
    // Use the current time as a seed for random number generation
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    // Mersenne Twister PRNG
    mt19937 gen(seed);
    // Distribution to get numbers in the desired range
    uniform_real_distribution<double> dis(-5.0, 5.0);

    // Generate a random decimal number with 9 digits after the decimal dot
    double randomDecimal = dis(gen);
    return randomDecimal;
}


int main(void){


    

    ofstream ramadan("random.csv");
    if(!ramadan.is_open()){
        return -1;
    }
    srand(2);

    string buff;

    for(long long int i = 1; i < KOLIKO; i++){


        ramadan << i << setprecision(10) << "," << generateRandomDecimal()<< "," << generateRandomDecimal()
        << "," << generateRandomDecimal()
        << "," << generateRandomDecimal()
        << "," << generateRandomDecimal()
        << "," << generateRandomDecimal()
        << "," << generateRandomDecimal() << ",";

        if((rand() % 2) == 0){
            ramadan << "good";
        }else{
            ramadan << "bad";
        }
        ramadan << endl;
    }
    
    cout <<"done";


    ramadan.close();

    return 0;
}