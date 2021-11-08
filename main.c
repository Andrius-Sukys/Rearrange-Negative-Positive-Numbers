/* Andrius Šukys (2110636), 2 Užduotis, 12 Variantas; 2021-10-24

12. Įvesti sveiką skaičių N. Įvesti N sveikų skaičių. Pertvarkyti juos taip, kad pradžioje
būtų visi neigiami elementai, o po jų neneigiami (pradinė neigiamų ir neneigiamų tvarka turi būti išsaugota), ir išvesti.

Įtraukiama reikalinga biblioteka nuskaitymui ir rašymui */

#include <stdio.h>

#define MAX_CAPACITY 1000

/* Aprašomos programoje naudojamos funkcijos */
void scan_input(int n, int input_array[]);
void rearrange_numbers(int n, int input_array[], int results_array[]);
void print_results(int n, int results_array[]);

int main()
{
    int array[MAX_CAPACITY]; /* Aprašomas įvedamas masyvas su talpa MAX_CAPACITY */
    int results[MAX_CAPACITY]; /* Aprašomas rezultatų masyvas su talpa MAX_CAPACITY */

    int n; /* Aprašomas kintamasis N - sveikųjų skaičių kiekis */

    printf("The program will rearrange integers so that all negative elements are followed by non-negative elements.\n"); /* Išspausdinamas pirmasis pranešimas, nurodantis, ką programa atlieka */
    printf("Enter the integer N:\n"); /* Išspausdinamas antrasis pranešimas, nurodantis, kad reikia įvesti sveiką skaičių N */

    scanf("%d", &n); /* Iš klaviatūros nuskaitoma N reikšmė */

    printf("Enter N integers:\n"); /* Išspausdinamas trečiasis pranešimas, nurodantis įvesti N sveikų skaičių */

    scan_input(n, array); /* Kreipinys į nuskaitymo į masyvą funkciją */
    rearrange_numbers(n, array, results); /* Kreipinys į masyvo pertvarkymo funkciją */
    print_results(n, results); /* Kreipinys į rezultatų masyvo išvedimo funckiją */

    return 0;
}

/* Funkcija, skirta masyvo reikšmėms nuskaityti */
void scan_input(int n, int input_array[])
{
    int i; /* Įvedama i reikšmė, reikalinga ciklui */
    for(i = 0; i < n; ++i)
    {
        scanf("%d", &input_array[i]); /* Dešimtainiai skaičiai, įvedami vartotojo, nuskaitomi į masyvą */
    }
}

/* Funkcija, skirta pradinio masyvo reikšmėms surūšiuoti*/
void rearrange_numbers(int n, int input_array[], int results_array[])
{
    int i, number_of_elements = 0;  /* Įvedama i reikšmė, reikalinga ciklui ir elementų skaičiaus reikšmė, reikalinga naujo masyvo elementų indeksams */

    for(i = 0; i < n; ++i)
    {
        if(input_array[i] < 0) /* Tikrinama, ar įvestame masyve reikšmė yra mažesnė už 0 */
        {
            results_array[number_of_elements] = input_array[i]; /* Jeigu taip, į rezultatų masyvą įrašoma įvesto masyvo reikšmė */
            number_of_elements++; /* Rezultatų masyvo elementų kiekis padidinamas vienetu */
        }
    }
    for(i = 0; i < n; i++)
    {
        if(input_array[i] >= 0) /* Tikrinama, ar įvestame masyve reikšmė yra neneigiama */
        {
            results_array[number_of_elements] = input_array[i]; /* Jeigu taip, į rezultatų masyvą įrašoma įvesto masyvo reikšmė */
            number_of_elements++; /* Rezultatų masyvo elementų kiekis padidinamas vienetu */
        }
    }
}

/* Funkcija, skirta rezultatų masyvo spausdinimui */
void print_results(int n, int results_array[])
{
    int i; /* Įvedama i reikšmė, reikalinga ciklui */

    printf("Rearranged result is:\n"); /* Atspausdinamas rezultato pranešimas */

    for(i = 0; i < n; i++)
    {
        printf("%d ", results_array[i]); /* Rezultatų masyvas atspausdinamas ekrane */
    }
}
