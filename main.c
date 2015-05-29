#include <stdio.h>
#include <stdlib.h>

#include "rubricaRagazze.h"

int main(int argc, char** argv) {
    char scelta[] = "s";
    ragazza letta; // record impiegato per la lettura dell'input
    ragazza *elencoRagazze; // elenco delle ragazze lette
    int dimensioneCorrente = 2; // Spazio allocato
    int nElementi = 0; // Numero degli elementi effettivamente memorizzati
    int i=0;
    
    elencoRagazze = (ragazza *)malloc(dimensioneCorrente *sizeof(ragazza));
    if(elencoRagazze == NULL) {
        fprintf(stderr, "Impossibile allocare memoria per elenco (%d byte)\n", dimensioneCorrente *sizeof(ragazza));
        exit(1);
    }
    
    while(!strcmp(scelta, "s")) {
        printf("\nInserisci il nome (max %d caratteri): ", NOME_MAXLEN);
        scanf("\n%[^\n]", letta.nome);
        printf("Inserisci il cognome (max %d caratteri): ", COGNOME_MAXLEN);
        scanf("\n%[^\n]", letta.cognome);
        printf("Inserisci ilcellulare (max %d caratteri): ", CELLULARE_MAXLEN);
        scanf("%s", letta.cellulare);
        printf("Inserisci eta': ");
        scanf("%d", &(letta.eta));
        printf("Inserisci indice di gradimento (4 - massimo; 0 - minimo): ");
        scanf("%d", &(letta.indiceGradimento));
        

        if(i == dimensioneCorrente) {
            elencoRagazze = rialloca(elencoRagazze, dimensioneCorrente);
            dimensioneCorrente *= 2;
            if(elencoRagazze == NULL) {
                fprintf(stderr, "Impossibile allocare memoria per elenco (%d byte)\n", dimensioneCorrente *sizeof(ragazza));
                exit(2);
            }
        }
        
        elencoRagazze[i] = letta;
        i++;
        
        printf("\nVuoi aggiungere un'altra ragazza? (s/n) ");
        scanf("%s", scelta);
        
    }
    
    nElementi = i;
    
    /*
     * E' possibile ordinare tutti gli elementi insieme, sebbene l'elenco contenga
     * sia maschi che femmine. Infatti, se l'insimee è ordinato, anche un suo
     * qualsiasi sottoinsieme è ordinato.
     */
    ordina(elencoRagazze, nElementi);
    
    scriviCSV(elencoRagazze, nElementi, "daevitare.csv", "daripetere.csv");
    return (EXIT_SUCCESS);
}

