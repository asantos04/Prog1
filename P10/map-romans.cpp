#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;



unsigned roman_to_arab(const string& roman) {
    vector<pair<char, unsigned>> roman_to_int = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
    };
    unsigned result = 0;
    unsigned last_value = 0;
    for (auto it = roman.rbegin(); it != roman.rend(); ++it) { // itera a string do fim para o início com pointers
        for (auto& p : roman_to_int) { // iterar pelos pares do vector
            if (*it == p.first) { //se o caractere da string igual ao numero romano
                if (p.second >= last_value) { // se for maior do que o valor anterior
                    result += p.second; //adicionar normalmente
                } else { //se for menor
                    result -= p.second; //subtrair o valor ao resultado
                }
                last_value = p.second; //atualizar o valor anterior
                break;
            }
        }
    }
    return result;
}