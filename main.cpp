#include <iostream>
#include <string>
#include <fstream> 
#include <string.h>
#include <map>


#define NUM_OF_ATR 7


using namespace std;


class apple_o{

    public:
        int A_id;
        double Size;
        double Weight;
        double Sweetness;
        double Crunchiness;
        double Juiciness;
        double Ripeness;
        double Acidity;
        string Quality;
};


string garbagge_s;
char smece;


/*
csv file kak ide po redu

A_id,Size,Weight,Sweetness,Crunchiness,Juiciness,Ripeness,Acidity,Quality

*/


void data_sort(int *good, int *bad, string file_name, double *avg_a){

    ifstream file(file_name);
    apple_o instance;
    double temp;

    // za avgove
    int num_el = 0;
    double avg_size = 0;
    double avg_weight = 0;
    double avg_sweetnes = 0;
    double avg_crunhines = 0;
    double avg_juicines = 0;
    double avg_ripenes = 0;
    double avg_acidity = 0;




    if(!file.is_open()){
        cout << "Error, file not open 1" << endl;
    }else{
        while(file >> instance.A_id){
            file >> smece;
            file >> instance.Size;
            file >> smece;
            file >> instance.Weight;
            file >> smece;
            file >> instance.Sweetness;
            file >> smece;
            file >> instance.Crunchiness;
            file >> smece;
            file >> instance.Juiciness;
            file >> smece;
            file >> instance.Ripeness;
            file >> smece;
            file >> instance.Acidity;
            file >> smece;
            getline(file,instance.Quality,'\n');

            // dobro lose
            if(instance.Quality.compare("good") == 0){
                *good = *good + 1;
            }else{
                *bad = *bad + 1;
            }
            // test print cout << instance.A_id << " "<< instance.Quality << endl;

            // avg za sve
            avg_size += instance.Size;
            avg_weight+= instance.Weight;
            avg_sweetnes += instance.Sweetness;
            avg_crunhines += instance.Crunchiness;
            avg_juicines += instance.Juiciness;
            avg_ripenes += instance.Ripeness;
            avg_acidity += instance.Acidity;

            num_el++;
        }

        
            avg_size /= num_el;
            avg_weight /= num_el;
            avg_sweetnes /= num_el;
            avg_crunhines /= num_el;
            avg_juicines /= num_el;
            avg_ripenes /= num_el;
            avg_acidity /= num_el;

        avg_a[0] = avg_size;
        avg_a[1] = avg_weight;
        avg_a[2] = avg_sweetnes;
        avg_a[3] = avg_crunhines;
        avg_a[4] = avg_juicines;
        avg_a[5] = avg_ripenes;
        avg_a[6] = avg_acidity;
    }

    file.close();

}



void above_avg(string file_name, double *avg_a){

    ifstream file(file_name);
    apple_o instance;

    ofstream ab_six("above_six.cvs");
    ofstream ab_five("above_five.cvs");
    ofstream ab_four("above_four.cvs");
    ofstream ab_three("above_three.cvs");

  


    int score = 0;

    if(!file.is_open() && ! ab_six.is_open()){
        cout << "Error opening file 2" << endl;
    }else{

    while(file >> instance.A_id){
            file >> smece;
            file >> instance.Size;
            file >> smece;
            file >> instance.Weight;
            file >> smece;
            file >> instance.Sweetness;
            file >> smece;
            file >> instance.Crunchiness;
            file >> smece;
            file >> instance.Juiciness;
            file >> smece;
            file >> instance.Ripeness;
            file >> smece;
            file >> instance.Acidity;
            file >> smece;
            getline(file,instance.Quality,'\n');

        score = 0;

        if(instance.Size > avg_a[0]){
            score++;
        }
        if(instance.Weight > avg_a[1]){
            score++;
        }
        if(instance.Sweetness > avg_a[2]){
            score++;
        }
        if(instance.Crunchiness > avg_a[0]){
            score++;
        }
        if(instance.Juiciness > avg_a[0]){
            score++;
        }
        if(instance.Acidity > avg_a[0]){
            score++;
        }    


        switch (score)
        {
        case 6:
            ab_six << instance.A_id << ","<< instance.Size << ","<< instance.Weight << ","<< instance.Sweetness << ","
            << instance.Crunchiness << ","<< instance.Juiciness << ","<< instance.Acidity << ","<< instance.Ripeness << "\n";        
            break;
        case 5:
            ab_five << instance.A_id << ","<< instance.Size << ","<< instance.Weight << ","<< instance.Sweetness << ","
            << instance.Crunchiness << ","<< instance.Juiciness << ","<< instance.Acidity << ","<< instance.Ripeness << "\n";  
        case 4:
            ab_four << instance.A_id << ","<< instance.Size << ","<< instance.Weight << ","<< instance.Sweetness << ","
            << instance.Crunchiness << ","<< instance.Juiciness << ","<< instance.Acidity << ","<< instance.Ripeness << "\n"; 
        case 3:
            ab_three << instance.A_id << ","<< instance.Size << ","<< instance.Weight << ","<< instance.Sweetness << ","
            << instance.Crunchiness << ","<< instance.Juiciness << ","<< instance.Acidity << ","<< instance.Ripeness << "\n";         
        default:
            break;
        }


        }

        file.close();
        ab_six.close();    
        ab_five.close();    
        ab_four.close();    
        ab_three.close();    

    }
}


int main()
{

    int good_apple = 0;
    int bad_apple = 0;
    string ime_fajl = "apple_quality.csv";

    double avg_a[NUM_OF_ATR];


    /*

    avg arr kako elemnti idu po redu
    
    */
    data_sort(&good_apple,&bad_apple,ime_fajl,avg_a);

    // bejsikli dictionary za razlicite elemente
   map<string, double> avg_m;

   avg_m["avg_size"] = avg_a[0];
   avg_m["avg_weight"] = avg_a[1];
   avg_m["avg_sweet"] = avg_a[2];
   avg_m["avg_crunch"] = avg_a[3];
   avg_m["avg_juicinest"] = avg_a[4];
   avg_m["avg_ripeness"] = avg_a[5];
   avg_m["avg_acidity"] = avg_a[6];



    above_avg(ime_fajl,avg_a);

    /*

    print metadata

    */
    cout << "List of avgs for all the atributes\n" << endl;
    cout << "Num of good: " << good_apple << endl;
    cout << "Num of bad: " << bad_apple << endl;
    map<string, double>::iterator it = avg_m.begin();
    while (it != avg_m.end()) {
        cout << it->first << ": " << it->second << endl;
        ++it;
    }


    


    return 0;
}