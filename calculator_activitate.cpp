//Calculator de incertitudine a activitatii unei surse date de formula A = N / (t * I * epsilon)
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    //Declararea variabilelor

    unsigned int N, t;  //N=arie, t=timp de achizitie
    float sigma_N, sigma_t, I, sigma_I, epsilon, sigma_epsilon;  //I=intensitatea de emisie a gamei [%], epsilon=eficacitatea de detectie [%]

    cout << "Introduceti aria picului si incertitudinea ariei: " << endl;
    cout << "N = "; cin >> N;
    cout << "sigma_N = "; cin >> sigma_N;

    cout << "Introduceti timpul de achizitie si incertitudinea timpului, in [s]: " << endl;
    cout << "t = "; cin >> t;
    cout << "sigma_t = "; cin >> sigma_t;

    cout << "Introduceti intensitatea de emisie a gamei si incertitudinea intensitatii, in [%]: " << endl;
    cout << "I = "; cin >> I;
    cout << "sigma_I = "; cin >> sigma_I;

    cout << "Introduceti eficacitatea de detectie si incertitudinea eficacitatii, in [%]: " << endl;
    cout << "epsilon = "; cin >> epsilon;
    cout << "sigma_epsilon = "; cin >> sigma_epsilon;
    cout << endl;



    //Calcularea incertitudinii activitatii

    float arie, intensitate, eficacitate, timp;  //componentele de arie, intensitate etc. din formula propagarii erorilor
    float A, sigma_A;  //A=activitatea sursei

    arie = (sigma_N * sigma_N) / (t * t * I * I * epsilon * epsilon);
    intensitate = (N * N * sigma_I * sigma_I) / (t * t * pow(I,4) * epsilon * epsilon);
    eficacitate = (N * N * sigma_epsilon * sigma_epsilon) / (t * t * I * I * pow(epsilon,4));
    timp = (N * N * sigma_t * sigma_t) / (pow(t,4) * I * I * epsilon * epsilon);

    sigma_A = sqrt(arie + intensitate + eficacitate + timp);
    A = N / (t * I * epsilon);

    cout << "******** Rezultat final *********" << endl << endl;
    cout << "Activitatea = " << A << " [Bq]" << endl;
    cout << "Incertitudinea = +/- " << sigma_A << " [Bq]" << endl << endl;
    cout << "*********************************" << endl;

    return 0;
}
