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
#include "Funkcje.h"

void init_tablica(){												//funckja zapelniajaca tablice symboli
	tablica_symboli[0]=minka;
	tablica_symboli[1]=krzyzyk;
	tablica_symboli[2]=serduszko;
	tablica_symboli[3]=paski;
	tablica_symboli[4]=szachownica;

};


void losuj(){																//funkcja wywolywana w przerwaniu od przycisniecia przycisku 
	int los;																	
	srand (czas);															//za seed dla generatora przyjmujemy wartosc licznika w momencie wywolania przerwania
	for(int i=0;i<3;i++){											//trzykrotnie losujemy liczbe z zakresu od 0 do 5 
		los = (rand() % (4 - 0 + 1)) + 0;			
		wylosowane[i]=tablica_symboli[los];			// po czym wstawiamy wybieramy z tablicy symboli korespondujacy symbol i wstawiamy go do tablicy wyosowanych
	}

};
void sprawdz_wynik(){													//prosta funkcja która instrukcja if sprawdza czy wszystkie wylosowane symbole sa takie same i jesli tak to ustawai odpowiednia flage

		if(wylosowane[0]==wylosowane[2] && wylosowane[1]==wylosowane[0])
			wygrana=1;
		else
			wygrana=0;
};

void merge(uint32_t symbol1[],uint32_t symbol2[],uint32_t symbol3[]){ //funkcja laczaca 3 symbole w jedna tablice gotowa do wyswietlania
 		uint64_t pom1,pom2;											//zmienne pomocnicze
		for(int i =0;i<8;i++){									//w petli odpowiednio przesuwamy kolejne symbole o odpowiednio 5 oraz 10 bitów tak aby wyjsciowo otrzymac 15 bitowy znak i 
			pom1= symbol2[i]<<5;									// umiescic go na odpowiednim miejscu 
			pom1 |= symbol1[i];
			pom2 =symbol3[i]<<10;
			pom2 |= pom1;
			mapa[i]=pom2;
		}
}
