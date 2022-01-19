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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>


static uint32_t minka[8] = {
			0x00,0x00,0xa,0x04,0x11,0xe,0x00,0x00
};
static uint32_t krzyzyk[8] = {
			0x11,0x0a,0xa,0x04,0x4,0xa,0x0a,0x11
};
static uint32_t serduszko[8] = {
			0x0,0x0a,0x15,0x11,0x11,0xa,0x04,0x0
};
static uint32_t paski[8] = {
			0x4,0x0a,0x11,0x4,0xa,0x11,0x04,0xa
};
static uint32_t szachownica[8] = {
			0x15,0x0a,0x15,0xa,0x15,0xa,0x15,0xa
};

static uint32_t wygrana_sym[8] = {
			0x4C91,0x5C91,0x5491,0x5491,0x5491,0x5491,0x7495,0x749B
};
static uint32_t mapa[8] ; 									//tablica w której beda umieszczone 3 sklejone ze soba symbole do wyswietlenia
static uint32_t *tablica_symboli[5];			  //tablica w której znajduja sie mozliwe symbole z których mozemy wybierac
static uint32_t *wylosowane[3]; 						//tablica w której zapisywane sa poszczególne wylosowane symbole
static uint16_t czas; 											//zmienna do której zczytywane jest wartosc licznika wykorzystywana jako seed do generatora liczb losowych
static int odczekaj=0,wygrana=0; 						//zmienne pomocnicze 
static int blokuj=0;												//zmienna która umozliwia zablokowanie mozliwosci losowania przed koncem wyswietlania poprzednego wyniku
