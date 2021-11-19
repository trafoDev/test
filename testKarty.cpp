#include "pch.h"
#include <iostream>


long sumaWyrazow(long start, long stop)
{
    if (start >= stop) return stop;
    return ((float)(start + stop)/2) * (stop - start + 1);
}


int main()
{
    long long liczbaIn;
    long long silnia=1;
    long long liczba;
    long long *table;

    std::cin >> liczbaIn;
    std::cout << "Liczę dla liczby art ->" << liczbaIn << "\n\r";
    liczba = liczbaIn - 1;

    for (int i = 1; i <= liczba; i++) {
        silnia *= i;
    }

    long long result = 0;
    long counter = 0;
    long minus = liczba;

    table = new long long[liczba];
    for (int i = 0; i < liczba; i++) {
        long dzielnik = (liczba - i > 0 ? liczba - i : 1);
        table[i] = silnia / dzielnik * sumaWyrazow(i+1, liczba);
        std::cout << "Table:" << table[i] << "!\n";
    }

    for (long x = 0; x <= liczba; x++) {
        counter = 1;
        std::cout << "iteracja:" << x << " dotychczasowa suma:" << result << "!\n";
        std::cout << "odejmuję:" << minus << "!\n";

        for (long y = 0; y < x; y++) {
            long dzielnik = (liczba - counter + 1 > 0 ? liczba - counter + 1 : 1);
            std::cout << "Dodaję (no minus):" << silnia / dzielnik * sumaWyrazow(counter, liczba) << "---" << table[counter < liczba ? counter -1 : liczba - 1] << "!!!!!!\n";
            result += table[counter < liczba ? counter - 1: liczba - 1];
            counter++;
        }

        if (x < liczba - 1) {
            for (long y = 1; y <= liczba + 1; y++) {
                long dzielnik = (liczba - counter + 1 > 0 ? liczba - counter + 1 : 1);
                std::cout << "Dodaję:" << silnia / dzielnik * sumaWyrazow(counter, liczba) - minus << "---" << table[counter < liczba ? counter - 1 : liczba - 1] - minus << "!!!!!!\n";
                result += table[counter < liczba ? counter - 1: liczba - 1] - minus;
                counter++;
            }
        }
        minus *= (liczba - x);
    }
    std::cout << "wynik " << result;
}

/*
int main()
{
    long long liczbaIn;
    long long silnia = 1;
    long long liczba;

    std::cin >> liczbaIn;
    std::cout << "Liczę dla liczby art ->" << liczbaIn << "\n\r";
    liczba = liczbaIn - 1;

    for (int i = 1; i <= liczba; i++) {
        silnia *= i;
    }

    long long result = 0;
    long counter = 0;
    long minus = liczba;

    for (long x = 0; x <= liczba; x++) {
        counter = 1;
        std::cout << "iteracja:" << x << " dotychczasowa suma:" << result << "!\n";
        std::cout << "odejmuję:" << minus << "!\n";


        for (long y = 0; y < x; y++) {
            long dzielnik = (liczba - counter + 1 > 0 ? liczba - counter + 1 : 1);
            std::cout << "Dodaję:" << silnia / dzielnik * sumaWyrazow(counter, liczba);
            result += silnia / dzielnik * sumaWyrazow(counter, liczba);
            std::cout << counter << "-" << y << "iii" << result << "Hello World!\n";
            counter++;

        }

        if (x < liczba - 1) {
            for (long y = 1; y <= liczba + 1; y++) {
                long dzielnik = (liczba - counter + 1 > 0 ? liczba - counter + 1 : 1);
                std::cout << "Dodaję:" << silnia / dzielnik * sumaWyrazow(counter, liczba) - minus;
                result += silnia / dzielnik * sumaWyrazow(counter, liczba) - minus;
                std::cout << counter << "-" << y << "iii" << result << "Hello World!\n";
                counter++;

            }
        }
        minus *= (liczba - x);
    }

    std::cout << "wynik " << result;
}
*/
