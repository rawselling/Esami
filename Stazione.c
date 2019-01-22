#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
typedef struct {
	int cod_treno;
	char citpa [MAX]; // Città partenza
	char citar [MAX]; // Città di arrivo
	int num1c; // Numero posti di prima classe
	int onu1c; // Posti occupati prima classe
	int num2c; // Numero Posti di seconda classe
	int onu2c; // Posti occupati di seconda classe
	} Roselli;  //Scheletro struttura
int tre=0; //Indice treno 
int pre=0; //Indice preno
Roselli treno[MAX];
Roselli preno[MAX];
int tresalv=-1; //Indice del treno da salvare per l'ordinamento 
void reqr();
void inserisciTreno(); 
void inserisciPreno(); 
void trovaTreno(); 
void ordinaStampa(); 
int main(){
	int menu;
	tresalv=-1;  
	do{printf("Inserisci: \n 1) Per inserire i treni\n 2) Per inserire le prenotazioni \n 3) Stampa tabella aggiornata \n 4) Esci\n\n [>] ");
	scanf("%d", &menu); 
	switch (menu){
		case 1:
		inserisciTreno();
		break; 
		case 2: 
		inserisciPreno();  
		break; 
		case 3: 
		ordinaStampa();
		break; 
		case 4: 
		return 0; 
		break; 
		}}while(menu << 1 | menu >> 4); 
		main();
	
	}
void inserisciTreno(){
	printf("\nInserisci codice treno: ");
	scanf("%d", &treno[tre].cod_treno); 
	printf("\nInserisci città di partenza: ");
	scanf("%s", treno[tre].citpa); 
	printf("\nInserisci città di arrivo: ");
	scanf("%s", treno[tre].citar); 
	printf("\nInserisci numero posti prima classe:");
	scanf("%d", &treno[tre].num1c); 
	printf("\nInserisci numero posti occupati prima classe");
	scanf("%d", &treno[tre].onu1c); 
	printf("\nInserisci codice posti seconda classe: ");
	scanf("%d", &treno[tre].num2c); 
	printf("\nInserisci codice posti occupati seconda classe: ");
	scanf("%d", &treno[tre].onu2c); 
	int s=tre; 
	if (treno[s].num1c < treno[s].onu1c) {
		reqr();}
	if (treno[s].num2c < treno[s].onu2c) {
		reqr();}		
	tre++;
	main(); 	
}
void inserisciPreno(){
	printf("\nInserisci codice treno da prenotare: ");
	scanf("%d", &preno[pre].cod_treno); 
	printf("\nInserisci numero posti prima classe da prenotare:");
	scanf("%d", &preno[pre].num1c); 
	printf("\nInserisci codice posti seconda classe da prenotare: ");
	scanf("%d", &preno[pre].num2c); 
	int z=pre;
	trovaTreno(); 
	if (tresalv==-1) {
		printf("\n\n Non esiste questo treno \n\n");
		reqr();}
	if (preno[z].num1c > (treno[tresalv].num1c - treno[tresalv].onu1c)) {
		printf("\n\n Non ci sonon posti disponibili\n\n"); 
		printf("I posti disponibili sono %d \n\n\n",  (treno[tresalv].num1c - treno[tresalv].onu1c)); 
		reqr();}	
	if (preno[z].num1c > (treno[tresalv].num2c - treno[tresalv].onu2c)) {
		printf("\n\n Non ci sonon posti disponibili\n\n"); 
		printf("I posti disponibili sono %d \n\n\n",  (treno[tresalv].num2c - treno[tresalv].onu2c)); 
		reqr();}	
	treno[tresalv].onu2c=treno[tresalv].onu2c+preno[z].num2c; 
	treno[tresalv].onu1c=treno[tresalv].onu1c+preno[z].num1c;
	pre++;
	main(); }
void reqr(){
	printf("\n\n RICHIESTA RIFIUTATA \n\n"); 
	main(); }
void trovaTreno(){
	int i; 
	for(i=0; i<tre; i++){
		if (preno[pre].cod_treno==treno[i].cod_treno){
			tresalv=i;}}}
void ordinaStampa(){
	int x, k; 
	Roselli temp; 
	for (x=0; x<tre; x++){
		for (k=0; k<tre-1; k++){
			if (treno[k].num1c>treno[k+1].num1c){
			temp=treno[k];
			treno[k]=treno[k+1]; 
			treno[k+1]=temp;  
			}}}
	printf("\n |codice treno|citta di partenza|citta di arrivo|numero posti prima classe|posti occupati 1 classe|numero posti 2 classe|posti occupati 2 classe|\n"); 
	int t=0; 
	for (t=0; t<tre; t++){
	printf("\n |%d|%s|%s|%d|%d||%d|%d|\n\n\n", treno[t].cod_treno, treno[t].citar, treno[t].citpa, treno[t].num1c, treno[t].onu1c, treno[t].num2c, treno[t].onu2c); 
	}
	main();
}
