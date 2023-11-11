#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

double media(vector<double> &data) {
    double total = 0.0;
    for (const auto &n : data) {
        total += n;
    }
    return total / data.size();
}
double desvioPadrao(vector<double> &data) {
    double vMedia = media(data);
    double soma = 0.0;

    for (const auto &elem : data) {
        soma += (elem - vMedia) * (elem - vMedia);
    }

    double variacao = soma / data.size();
    return sqrt(variacao);
}


int main() {

    ifstream arquivo("Tempo algoritmo fatorial recursivo em calda.txt"); // Substitua "exemplo.txt" pelo nome do seu arquivo

    vector<double> x;
    vector<double> y;
    double valor;

    while (arquivo >> valor) {
        x.push_back(valor);
        if (arquivo.peek() == ' ' || arquivo.peek() == '\n') {
            arquivo.ignore();
        }

        if (arquivo >> valor) {
            y.push_back(valor);
        }
    }

    double desvio = desvioPadrao(y);
    double m = media(y);
    ofstream outputFile("outputFatorial.txt");
    if (!outputFile) {
        cerr << "Erro ao criar o arquivo de saída." <<endl;
        return 1;
    }
    outputFile << "Desvio padrão: " << desvio << endl;
    outputFile << "media: " << m << endl;
    double dif;

    for (const auto &n:y){
        dif = n-m;
        if(dif<0){
            dif*=-1;
        }

        if(dif*2>desvio){
            outputFile << n <<" "<< dif << endl;
        }else{
            outputFile << n <<" não" << endl;
        }
    }

    outputFile.close();

    arquivo.close();
    return 0;
}
