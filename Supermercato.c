#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define MAX 100
typedef struct {
	char nomeresp[MAX]; 
	char cognresp[MAX]; 
	char via[MAX]; 
	char citta[MAX]; 
	int numd; 
	int fatt; 	
	} roselli; 
roselli supermer[MAX]; 
int Z=0; 
void caricadati();
void visualdati(); 
void trovanome(int zmong); 
void supermagg();
int main(){
	int menu=0; 
	do{printf("\n Inserire: \n 1) Per caricare i dati \n 2) Visualizzare dati (da città o da nome) \n 3) Stampa il supermercato con maggior numero di dipendenti \n 4) Per uscire \n [>]"); 
	scanf("%d", &menu);
	switch (menu){
		case 1:
		caricadati();
		break; 
		case 2: 
		visualdati();
		break; 
		case 3: 
		supermagg(); 
		break; 
		case 4: 
		return 0; 
		break; }
	}while((menu<1) | (menu>4));
}
void caricadati() {
	printf("\n\n\n Inserisci nome responsabile: "); 
	scanf("%s", supermer[Z].nomeresp); 
	printf("\n\n\n Inserisci cognome responsabile: "); 
	scanf("%s", supermer[Z].cognresp); 
	printf("\n\n\n Inserisci città supermercato: "); 
	scanf("%s", supermer[Z].citta); 
	printf("\n\n\n Inserisci via responsabile: "); 
	scanf("%s", supermer[Z].via); 
	printf("\n\n\n Inserisci numero di dipendenti: "); 
	scanf("%d", &supermer[Z].numd); 
	printf("\n\n\n Inserisci fatturato dell'ultimo anno: "); 
	scanf("%d", &supermer[Z].fatt);
	if (supermer[Z].numd<0) {
		printf("\n Richiesta RIfiutata \n\n"); 
		main();}
	if (supermer[Z].fatt<0) {
		printf("\n Richiesta RIfiutata \n\n"); 
		main();}
	Z++;
	main();}
void visualdati(){
	int vismenu; 
	do{printf("\n\n Inserisci: \n 1) Per nome \n 2) Per citta \n 3) Per tornare indietro \n [»] \n"); 
	scanf("%d", &vismenu); 
	switch(vismenu){
		case 1:
		trovanome(1); 
		break;  
		case 2:
		trovanome(2);
		break;  
		case 3: 
		main();
		break;}}while((vismenu<1) | (vismenu>3));
	
	}
void trovanome(int zmong){
	char nomer[MAX];
	int S=MAX+1;
	int i=0;
	int j=0; 
	int s=zmong;
	if (s==1){
		printf("\n\n Inserisci nome: ");
		scanf("%s", nomer); 
		for (i=0; i<Z; i++){
			for (j=0; j<MAX; j++){
				if(nomer[j]==supermer[i].nomeresp[j]){
				S=i;}}}}
	if (s==2){
		printf("\n\n Inserisci citta: ");
		scanf("%s", nomer);
		for (i=0; i<Z; i++){
			for (j=0; j<MAX; j++){
				if(nomer[j]==supermer[i].nomeresp[j]){
				S=i;}}}}
	if (S==-1){
			printf("\n\n Non e stato trovato \n\n\n");
			main();}
	
	printf("|%s|%s|%s|%s|%d|%d|", supermer[S].nomeresp, supermer[S].cognresp, supermer[S].via, supermer[S].citta, supermer[S].numd, supermer[S].fatt);
	main(); }
void supermagg(){
	int rr=0; 
	int rora=0; 
	int xxx=0;
	for (rr=0; rr<Z; rr++){
		if (supermer[rr].numd>rora){
			rora=supermer[rr].numd;
			xxx=rr;}}
	printf("|%s|%s|%s|%s|%d|%d|", supermer[xxx].nomeresp, supermer[xxx].cognresp, supermer[xxx].via, supermer[xxx].citta, supermer[xxx].numd, supermer[xxx].fatt);
	main();
}
