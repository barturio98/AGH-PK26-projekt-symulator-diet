/* --------------------------
Sekcja dokumentacji
Plik: AGH-PK26-projekt
Autor: Bartosz Urbanek
Temat: Projekt 2. Symulator Diet
----------------------------- */
/* ------------------------------
Sekcja dokumentywy preprocesora
--------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

/* ------------------------------
Sekcja definicji globalnych
--------------------------- */

/* ------------------------------
Sekcja fukcji
--------------------------- */
// 1. Program ma pobierać od użytkownika dane w postaci: płeć, wiek, 
//    informacje o trybie życia (siedzący tryb życia, niska aktywność fizyczna, średnia aktywność fizyczna, wysoka aktywność fizyczna), 
//    wzrost, waga, ile kilogramów chce stracić i w ciągu jakiego okresu.
// 2. Na tej podstawie powinien być określany miesięczny jadłospis zbilansowany pod względem zapotrzebowania na składniki odżywcze.
// 3. Program powinien umożliwiać wypisywanie jadłospisu na dowolny okres(dzień, dwa dni, tydzień, miesiąc, itd.).
// 4. Należy wybrać jedną z dostępnych zbilansowanych diet i podać w projekcie źródło.
int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	char name[50];
	char lifestyle_text[100];
	int sex, age, height, period, lifestyle;
	float weight, weight_optimal, weight_diff;
	
	printf("Jak masz na imię?: ");
	scanf_s("%s", name, (unsigned)sizeof(name));

	printf("Podaj płeć, wpisz numer [1: kobieta, 2: mężczyzna]: ");
	scanf_s("%d", &sex);

	printf("Podaj wiek: ");
	scanf_s("%d", &age);

	printf("Podaj wzrost w cm: ");  
	scanf_s("%d", &height);

	printf("Podaj wagę w kg: ");
	scanf_s("%f", &weight);

	printf("Podaj swoją wymarzoną wagę w kg: ");
	scanf_s("%f", &weight_optimal);

	printf("Podaj preferowany okres diety w dniach: ");
	scanf_s("%d", &period);

	printf("Podaj tryb życia, wpisz numer [1: siedzący, 2: niska aktywność fizyczna, 3: średnia aktywność fizyczna, 4: wysoka aktywność fizyczna]: ");
	scanf_s("%d", &lifestyle);
	switch (lifestyle) {
	case 1:
		strcpy_s(lifestyle_text, sizeof(lifestyle_text), "siedzący");
		break;
	case 2:
		strcpy_s(lifestyle_text, sizeof(lifestyle_text), "niska aktywność fizyczna");
		break;
	case 3:
		strcpy_s(lifestyle_text, sizeof(lifestyle_text), "średnia aktywność fizyczna");
		break;
	case 4:
		strcpy_s(lifestyle_text, sizeof(lifestyle_text), "wysoka aktywność fizyczna");
		break;
	default:
		strcpy_s(lifestyle_text, sizeof(lifestyle_text), "brak danych");
		printf("Wprowadzono niewłaściwy numer dla trybu życia.\n");
	}

	weight_diff = weight - weight_optimal;
	float BMI = 0;

	printf("\nOto twoje dane:\nimię = %s | płeć = %d | wiek = %d | wzrost = %d | waga = %.1f | waga docelowa = %.1f | okres = %d | styl życia = %s", 
		name, sex, age, height, weight, weight_optimal, period, lifestyle_text);
	printf("\n");

	if (weight_diff > 0) {
		printf("Aby osiągnąć wymarzoną wagę musisz schudnąć o %.1f kg. Zabierajmy się do pracy!", fabs(weight_diff));
	} else if (weight_diff == 0) {
		printf("Aby osiągnąć wymarzoną wagę musisz schudnąć o %.1f kg? Chwila, już jest perfekcyjnie! No to cześć!", fabs(weight_diff));
    } else {
		printf("Aby osiągnąć wymarzoną wagę musisz przytyć o %.1f kg. Do boju!", fabs(weight_diff));
	}
	printf("\n");

	return 0;
}

