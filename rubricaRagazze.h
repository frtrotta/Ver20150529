#ifndef RUBRICARAGAZZE_H
#define	RUBRICARAGAZZE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_MAXLEN 25
#define COGNOME_MAXLEN 25
#define CELLULARE_MAXLEN 13

struct s_ragazza {
    char nome[NOME_MAXLEN+1];
    char cognome[COGNOME_MAXLEN+1];
    char cellulare[CELLULARE_MAXLEN+1];
    int eta;
    int indiceGradimento;
};

typedef struct s_ragazza ragazza;

ragazza * rialloca(ragazza * elencoCorrente, int dimensioneCorrente);

/**
 * Ordina l'elenco delle ragazze in base al cognome.
 * @param elenco
 * @param dimensione
 */
void ordina(ragazza elenco[], int dimensione);

int scriviCSV(ragazza *elenco, int dimensione, char nomeFileDaEvitare[], char nomeFileDaRipetere[]);

/**
 * Scrive l'intestazione (prima riga) del file CSV
 * @param f
 */
void scriviIntestazioneCSV(FILE *f);

/**
 * Scrive tutte le ragazze con indice di gradimento da IGmin a IGmax inclusi
 * @param f file
 * @param IGmin indice di gradimento minimo
 * @param IGmax indice di gradimento massimo
 * @param elenco
 * @param dimensione
 * @return Il numero di studenti scritti nel file.
 */
int scriviIGCSV(FILE *f, int IGmin, int IGmax, ragazza elenco[], int dimensione);

/**
 * Scrive una singola ragazza nel file in formato CSV
 * @param f
 * @param r
 */
void scriviRagazzaCSV(FILE *f, ragazza r);


#endif	/* RUBRICARAGAZZE_H */

