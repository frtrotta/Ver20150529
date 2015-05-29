#include "rubricaRagazze.h"

ragazza * rialloca(ragazza * elencoCorrente, int dimensioneCorrente) {
    int nuovaDimensione;
    ragazza * elencoNuovo;
    int i;
    
    nuovaDimensione = 2 * dimensioneCorrente;
    elencoNuovo = (ragazza *)malloc(nuovaDimensione * sizeof(ragazza));
    if(elencoNuovo != NULL) {
        for(i=0; i<dimensioneCorrente; i++) {
            elencoNuovo[i] = elencoCorrente[i];
        }
        free(elencoCorrente);
    }
    return elencoNuovo;
}

void ordina(ragazza elenco[], int dimensione) {
    ragazza temp;
    int indiceMinore;
    int i, j;
    
    indiceMinore = 0;
    for(i=0; i<(dimensione-1); i++) {
        indiceMinore = i;
        for(j=i+1; j<dimensione; j++) {
            if(strcmp(elenco[j].cognome, elenco[indiceMinore].cognome) < 0) {
                indiceMinore = j;
            }
        }
        if(indiceMinore != i) {
            temp = elenco[indiceMinore];
            elenco[indiceMinore] = elenco[i];
            elenco[i] = temp;
        }
    }
    return;
}

int scriviCSV(ragazza *elenco, int dimensione, char nomeFileDaEvitare[], char nomeFileDaRipetere[]) {
    FILE *daEvitare;
    FILE *daRipetere;
    
    int returnCode = 0;
    
    daEvitare = fopen(nomeFileDaEvitare, "w");
    daRipetere = fopen(nomeFileDaRipetere, "w");
    
    if(daEvitare != NULL && daRipetere != NULL) {
        scriviIntestazioneCSV(daEvitare);
        scriviIntestazioneCSV(daRipetere);

        scriviIGCSV(daEvitare, 0, 1, elenco, dimensione);
        scriviIGCSV(daRipetere, 2, 4, elenco, dimensione);

        fclose(daEvitare);
        fclose(daRipetere);
    }
    else {
        returnCode = -1;
        if(daEvitare == NULL)
            fprintf(stderr, "Impossibile aprire il file \"%s\"\n", nomeFileDaEvitare);
        if(daRipetere == NULL)
            fprintf(stderr, "Impossibile aprire il file \"%s\"\n", nomeFileDaRipetere);
    }
    
    return returnCode;
}

void scriviIntestazioneCSV(FILE *f) {
    fprintf(f, "nome;cognome;cellulare;eta;indice di gradimento\n");
}

int scriviIGCSV(FILE *f, int IGmin, int IGmax, ragazza elenco[], int dimensione) {
    int i;
    
    for(i=0; i<dimensione; i++) {
        if((elenco[i].indiceGradimento >= IGmin) && (elenco[i].indiceGradimento <= IGmax)) {
            scriviRagazzaCSV(f, elenco[i]);
        }
    }
    return i;
}

void scriviRagazzaCSV(FILE *f, ragazza r) {
    fprintf(f, "%s;%s;%s;%d;%d\n", r.nome, r.cognome, r.cellulare, r.eta, r.indiceGradimento);
}
