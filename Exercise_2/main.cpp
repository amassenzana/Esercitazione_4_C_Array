#include <fstream>
#include <iomanip>
using namespace std;

void extractPair(ifstream& data, char& c, double& d){
    string s="";
    data >> s;
    c = s[0];

    size_t pos = s.find(';',0);
    d = stod(s.substr(pos+1, string::npos));
}

void extractVec(ifstream& data, double& v1, double& v2){
    string s = "";
    data >> s;

    size_t pos = s.find(';', 0);
    v1 = stod(s.substr(0,pos));
    v2 = stod(s.substr(pos+1, string::npos));
}



int main(){

    ifstream data("data.csv");
    ofstream result("result.txt");
    string s="";
    double S, n;
    char c1, c2;


    extractPair(data, c1, S);    // Prende S,1000
    result << fixed << setprecision(2) << c1 << " = " << S; // Stampa S = 1000.00

    extractPair(data, c1, n);    // Prende n = 8
    result << defaultfloat << ", " << c1 << " = " << int(n) << endl; // Stampa n = 8

    data >> s;
    c1 = s[0];   // salvo il carattere w
    c2 = s[2];  // salvo il carattere r


    // Dichiaro i vettori variabili
    double* v1 = new double[int(n)];
    double* v2 = new double[int(n)];

    // Salvo i due vettori e inizio stampando il primo su file
    result << c1 << " = [";
    for(size_t i = 0; i < n; i++){
        extractVec(data, v1[i], v2[i]);
        result << " " << v1[i];
    }



    // Stampo il secondo su file + calcolo dei risultati
    result << " ]\n" << c2 << " = [";

    double res = 0, rate = 0;

    for(size_t i = 0; i < n; i++){
        result << " " << v2[i];
        res += (1+v2[i])*S*v1[i];
        rate += v1[i]*v2[i];
    }
    result << " ]" << endl;



    // Stampa dei risultati
    result << defaultfloat << setprecision(6);
    result << "Rate of return of the portfolio: " << rate << endl;
    result << fixed << setprecision(2) << "V: " << res << endl;




    delete[] v1;
    delete[] v2;
    data.close();
    result.close();
    return 0;
}

