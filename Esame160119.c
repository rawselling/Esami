#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define MAX 100 //Massimo valore 100 
typedef struct { // Scheletro struttura dati 
		int codice; //Codice evento
		float prezzo; //Prezzo 
		char data[10]; //Data (In teoria 00/00/0000) 
		char descrizione[MAX]; //Descrizione massimo 100 caratteri
		char luogo[20]; //Luogo 
		int posti; //Posti massimi di un evento e posti da prenotare
	} Roselli; //Nome scheletro della struttura
Roselli evento[MAX]; //Eventi 
Roselli prenot[MAX]; //Prenotazioni
int X=0; //Contatore eventi
int Y=0; //Contatore prenotazioni
int indicev=0;
int trovato;
void Rosy(){ //Funzione inutile che stampa la Roselli
	printf("\nyshddmdhyhddhhhhhssyhhhhdhddhdmdhdhsdddm\n");
	printf("yyddmmmdhddmdyssyhhhyhhdhhyyyhddmmysydmm\n");
	printf("syhdmmddhdhsoyhhhysyysoyhdhs++sddmhyhhdm\n");
	printf("yyhhdmhhdy+oyyys+/+::+ossyss+//+yddhdhsd\n");
	printf("hyhdhdhds/+++//---.-///++ooo+oo++oddhysh\n");
	printf("hyhmdhhs////:----.-::::://++++os++smdyyy\n");
	printf("hhhdhdh+://::-:-------::://+++o++o+hdhyd\n");
	printf("ddhddds//o/////::-......-:/+osssss+sdddh\n");
	printf("dhhhdho+oo/+oo///:--..--:/+/+ssyssoshddh\n");
	printf("dmhddyssssoooooso///+/+o/+ooooosyysosddh\n");
	printf("dmddhyyyyyysoo+///+ooooso+////+osyo++syd\n");
	printf("ddddhyhhyhyso//////+o++oo/::///+o/://+ys\n");
	printf("ddddyyhsosooo+/::-:///:///:-::/++/:---yy\n");
	printf("hmmho+s+:+/os+/:-:///:::///:::/+s/:--:+y\n");
	printf("ddmh/:o//shhs+/:::++/:://++:-:/oh+:-://d\n");
	printf("ddmy//+++sddho/:-:///:::::::::+hy+::+o/h\n");
	printf("dddy+/ososhdhso+///::---:://+ohds+:+osod\n");
	printf("mdhhoosysyhyho++++++//::/++oshoho+/osoyd\n");
	printf("mmdyyyhyyyysss////////////+sydss+//o+ydd\n");
	printf("dddhyhyyyyyyoo+:::::::--:/oohds+/+/ooddh\n");
	printf("ddhyyyyyyyyhs++/::------:/+syo+ooo+ohddo\n");
	printf("hyssyyysyhyhh+/+/::----:///+sydhoooshhdo\n");
	printf("yssooosssysydy/+/:::--:///ohddhsoosshdds\n");
	printf("yyyyyssoosyyddsoo+/:-::+//hmddy+++soydd/\n");
	printf("hhhdddyoosdhmmdy++++///++ymdhyo+ososyddo\n");
	printf("mmmddhrosellimmmho//++++sdmdddysyy+yydh+\n");
	printf("ddmmdhdhyyhdmmmmmds+++ossddddmhsydyyydds\n");
	printf("ddmy//+++sddho/:-:///:::::::::+hy+::+o/h\n");
	printf("ddmy//+++sddho/:-:///:::::::::+hy+::+o/h\n");
	} // DI sotto invece le funzioni utili
void inserimento(); //Per l'inserimento
void trovaevento(); //Per trovare evento da codice evento
void ordina(); //Per ordinare i valori
void stampa(); //Per stampare i valori
int main(){
		int menu;
		do{Rosy(); 
		printf("Inserire:\n 1) Per inserire un evento o una prenotazione\n 2) Per ordinare gli eventi in base al codice e stamparli\n 3) Esci\n[>]"); 
		scanf("%d", &menu); 
		switch (menu){
			case 1:
			inserimento();
			break;
			case 2:
			ordina();
			stampa();
			break; 
			case 3:
			Rosy(); 
			//system("PAUSE"); //Disabilitato
			return 0; //Esce dal programma
			break;} }while((menu<1) | (menu>3));
	}
void inserimento(){
	int inse; 
	do{	Rosy();
	printf("Inserire:\n 1) Per inserire un evento\n 2) Per inserire una prenotazione\n 3) Per tornare indietro\n[>]"); 
	scanf("%d", &inse); 
	switch (inse){
		case 1: 
			printf("\nInserisci codice evento: "); 
			scanf("%d", &evento[X].codice);
			printf("\nInserisci prezzo evento: "); 
			scanf("%f", &evento[X].prezzo);
			printf("\nInserisci data evento: "); 
			scanf("%s", evento[X].data);
			printf("\nInserisci luogo evento: "); 
			scanf("%s", evento[X].luogo);
			printf("\nInserisci descrizione evento: "); 
			scanf("%s", evento[X].descrizione);
			printf("\nInserisci posti evento: ");
			scanf("%d", &evento[X].posti);
			X++; 
			main();
		break;
		case 2: 
			if(X==0){
				printf("\n\n\n [RICHIESTA RIFIUTATA]: non ci sono eventi! ");
				main();}
			printf("\nInserisci codice evento: "); 
			scanf("%d", &prenot[Y].codice);
			printf("\nInserisci data evento: "); 
			scanf("%s", prenot[Y].data);
			printf("\nInserisci luogo evento: "); 
			scanf("%s", prenot[Y].luogo);
			printf("\nInserisci posti da prenotare: ");
			scanf("%d", &prenot[Y].posti);
			trovaevento();
			if(trovato==999){
				printf("\n\n\n [RICHIESTA RIFIUTATA]: l'evento non esiste! ");
				main();}
			if(prenot[Y].posti>evento[indicev].posti){
				printf("\n\n\n [RICHIESTA RIFIUTATA]: non ci sono posti disponibili ");
				printf("\n Ci sono %d posti massimo", evento[indicev].posti);
				main();}	
			printf("\n\n\n [RICHIESTA ACCETTATA]: prenotazione effettuata con successo ");
			Y++;
			evento[indicev].posti=evento[indicev].posti-prenot[Y].posti;
			main();
		break; 
		case 3: 
			main(); 
		break; 
		}  }while((inse<1) | (inse>3));
	}
void trovaevento(){
	trovato=999; 
	int i=0;
	for(i=0; i<X; i++){
		if(prenot[Y].codice==evento[i].codice){
			indicev=i;
			trovato=666;}}
	}
void ordina(){
	int zig=0;  //Contatore 1
    int zag=0;  //Contatore 2
	Roselli tmp;
    for(zig=0; zig<X; zig++){
        for(zag=0; zag<X-1; zag++){
            if(evento[zag].codice>evento[zag+1].codice){  //Scambio valori attraverso babol sort
                tmp=evento[zag];
                evento[zag]=evento[zag+1];
                evento[zag+1]=tmp;
			}}}}
void stampa(){ //stampa in ordine 
	int z=0;
	char mano[1]; 
	for(z=0; z<X; z++){
		printf("\n|COD:%d|PREZZO:%f|DATA:%s|DESCRIZIONE:%s|LUOGO:%s|POSTI:%d|", evento[z].codice, evento[z].prezzo, evento[z].data, evento[z].descrizione, evento[z].luogo, evento[z].posti);
		printf("\n\n\n");}	
	printf("\nInserire un qualsiasi valore per continuare\n [>]");
	scanf("%s", mano); 
	main(); 
	}


