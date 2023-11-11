#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    ifstream file("data.csv");

    if (!file.is_open())
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    vector<vector<int>> data;

    string line;
    while (getline(file, line))
    {
        vector<int> linha;
        stringstream lineStream(line);
        int cel;

        while (lineStream >> cel)
        {
            linha.push_back(cel);

            if (lineStream.peek() == ',')
                lineStream.ignore();
        }
        data.push_back(linha);
    }

    file.close();

    int numCol = data[0].size();

    vector<double> somaCol(numCol, 0.0); 

    for (const auto &linha : data)
    {
        for (int i = 0; i < numCol; ++i)
        {
            somaCol[i] += linha[i];
        }
    }

    vector<double> mediaCol(numCol);

    for (int i = 0; i < numCol; ++i)
    {
        mediaCol[i] = somaCol[i] / data.size();
    }


    for (int i = 0; i < numCol; ++i)
    {
        cout << setprecision(2) << fixed << mediaCol[i] << ",";
    }

    return 0;
}
