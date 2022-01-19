/*
		Projekt z przedmiotu Programowanie mikrokontrolerów ARM w jezyku C/C++
		Kierunek:				Teleinformatyka S2/Elektronika i Komunikacja S2
		Sklad sekcji:		Rafal Wilk				TI
										Michal Naziomek		TI
										Mateusz Rubin			EIT
										
		Temat Projektu: Jednoreki Bandyta
		Opis Tematu:		Celem projektu jest stworzenie programu dzialajacego jak dzialajacy automat do gier typu Jednoreki bandyta
										Do tego celu wykorzystano plytke STM32Discovery oraz wyswietlacz oparty na matrycy LED.
										
		Opis polaczen:	Wyprowadzenia na porcie D od PD0 do PD7 zostaly podlaczone do korespondujacym im numerom wierszy matrycy LED
										natomiast wyprowadzenia od PC0 do PC14 zostaly podlaczone do odpowienich kolumn. Doprowadzono równierz zalsilanie oraz GND do odpowienio oznaczonych wyprowadzen na plytce
										

*/
#include "Zmienne.h"

void init_tablica(void);
void merge(uint32_t symbol1[],uint32_t symbol2[],uint32_t symbol3[]);
void sprawdz_wynik(void);
void losuj(void);
