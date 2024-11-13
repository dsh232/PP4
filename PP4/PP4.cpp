#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> ifWordInFile(vector<vector<char>> matrix, vector<char> line) {
    vector<string> result;
    bool ishor = false;
    bool isvec = false;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.at(i).size(); j++) {
            if ((matrix.at(i).size() - j) >= line.size() && matrix.at(i).at(j) == line.at(0)) {
                bool flag = true;
                ishor = true;
                string horisontalWord = to_string(i) + ' ' + to_string(j);
                horisontalWord += " hor ";
                for (int k = 0; k < line.size() && flag; k++ ) {
                        if (matrix.at(i).at(k + j) != line.at(k))
                            flag = false;            
                }
                if (flag) {
                    result.push_back(horisontalWord);
                }
            }
            if (matrix.size() - i >= line.size() && matrix.at(i).at(j) == line.at(0)) {
                bool flag = true;
                isvec = true;
                string horisontalWord = to_string(i) + ' ' + to_string(j);
                horisontalWord += " ver ";
                for (int k = 0; k < line.size() && flag; k++) { 
                    if (matrix.at(i + k).size() > j)
                    {
                        if (matrix.at(i + k).at(j) != line.at(k))
                            flag = false;
                    }
                    else flag = false;
                }
                if (flag) {
                    result.push_back(horisontalWord);
                }
            }
        }
    }

    return result;
    
}

int main()
{
    vector<vector<char>> matrix;
    ifstream file("C:\\Users\\Lenovo\\Documents\\ВУЗ ЛАБЫ\\ПП\\PP4\\pp4.txt");
    ofstream fileFinal("C:\\Users\\Lenovo\\Documents\\ВУЗ ЛАБЫ\\ПП\\PP4\\end.txt");
    
    if (file.is_open())
    {
        
        char symbol;
        vector<char> arr;
        while (file.get(symbol)) {
            if (symbol == '\n') {
                matrix.push_back(arr);  
                arr.erase(arr.begin(), arr.end());    //обнуляем вектор с новой строки
            }
            else arr.push_back(symbol);         
        }
        vector<string> result;
        while (result.size() == 0) {
            matrix.push_back(arr);
            vector<char> line;
            string c;
            cout << "enter your word: ";
            cin >> c;
            for (int i = 0; i < c.size(); i++) {
                line.push_back(c[i]);
            }

            result = ifWordInFile(matrix, line);
            if (result.size() == 0) {
                cout << "Word is not found. Try again. " << endl;
            }
            else
                for (int i = 0; i < result.size(); i++) {
                    cout << result.at(i);
                }
            line.clear();
        }

        ostream_iterator<string> output_iterator(fileFinal, "\n");  //вывод результата  в файл
        std::copy(result.begin(), result.end(), output_iterator);
        result.clear();
        
    }
    else
    {
        cout << "file is not found.";
    }
    matrix.clear();
    file.close();
    fileFinal.close();
}

