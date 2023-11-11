#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

double media(vector<double> &data) {
    double total = 0.0;
    for (const auto &n : data) {
        total += n;
    }
    return total / data.size();
}

double calculateSlope(vector<double> &x, vector<double> &y, double xMedia, double Ymedia) {
    double numerador = 0.0;
    double denominador = 0.0;
    for (size_t i = 0; i < x.size(); i++) {
        numerador += (x[i] - xMedia) * (y[i] - Ymedia);
        denominador += (x[i] - xMedia) * (x[i] - xMedia);
    }
    return numerador / denominador;
}

double calculateIntercept(double xMedia, double Ymedia, double slope) {
    return Ymedia - slope * xMedia;
}

int main() {

    ifstream arquivo("busca_linear.txt"); // Substitua "exemplo.txt" pelo nome do seu arquivo

    vector<double> x;
    vector<double> y;
    vector<double> yRegress;
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
    
    double xMedia=media(x);
    double yMedia=media(y);

    double slope = calculateSlope(x, y, xMedia, yMedia);
    double intercept = calculateIntercept(xMedia, yMedia, slope);

    cout << "Intercept: " << intercept << endl;
    cout << "Slope: " << slope << endl;

    
    for (const auto& n : x) {
        double aux=intercept + slope * n;
        yRegress.push_back(aux);
        cout<<aux<<endl;
    }
    cout << endl;

    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Erro ao criar o arquivo de saída." <<endl;
        return 1;
    }

    // Escrevendo os valores de x e os valores estimados de y no arquivo
    for (size_t i = 0; i < x.size(); i++) {
        outputFile << x[i] << " " << yRegress[i] << endl;
    }

    // Fechando o arquivo
    outputFile.close();

    arquivo.close();
    return 0;
}
