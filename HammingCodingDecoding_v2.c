#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "HammingMatrix.h"

//G_3[4][7] = G[k][n] matrix with m=n-k=3, n=(2^m)-1=7, k=(2^m)-1-m=4
//Ht_3 [7][3] = Ht[n][m] matrix with m=n-k=3, n=(2^m)-1=7, k=(2^m)-1-m=4

int m3 = 3;
int k3 = 4;
int n3 = 7;

//G_4[11][15] = G[k][n] matrix with m=n-k=4, n=(2^m)-1=15, k=(2^m)-1-m=11
//Ht_4 [15][4] = Ht[n][m] matrix with m=n-k=4, n=(2^m)-1=15, k=(2^m)-1-m=11

int m4 = 4;
int k4 = 11;
int n4 = 15;

//G_5[26][31] = G[k][n] matrix with m=n-k=5, n=(2^m)-1=31, k=(2^m)-1-m=26
//Ht_5 [31][5] = Ht[n][m] matrix with m=n-k=5, n=(2^m)-1=31, k=(2^m)-1-m=26

int m5 = 5;
int k5 = 26;
int n5 = 31;

//G_6[57][63] = G[k][n] matrix with m=n-k=6, n=(2^m)-1=63, k=(2^m)-1-m=57
//Ht_6 [63][6] = Ht[n][m] matrix with m=n-k=6, n=(2^m)-1=63, k=(2^m)-1-m=57

int m6 = 6;
int k6 = 57;
int n6 = 63;

//G_7[120][127] = G[k][n] matrix with m=n-k=7, n=(2^m)-1=127, k=(2^m)-1-m=120
//Ht_7 [127][7] = Ht[n][m] matrix with m=n-k=7, n=(2^m)-1=127, k=(2^m)-1-m=120

int m7 = 7;
int k7 = 120;
int n7 = 127;

int HammingCoding (int indexm);
int HammingDecoding (int indexn);

int main(int argc, char **argv)
{
	int i, j, k, m, n;
	i = j = k = m = n = 0;
	int keep = 0;
	int stop = 0;
	int decoding = 0;
	int onecount = 0;
	int zerocount = 0;
	int syndcount = 0;
	int operation = 0;
	int syndromeindex = 0;
	int message[k7], codedmessage[n7], syndrome[m7], error[n7], correctedcodedmessage[n7];
	
	while(1)
	{
		system("cls");
		
		printf("==============================\n");
		printf("CODIFICA/DECODIFICA DI HAMMING\n");
		printf("==============================\n");
		
		printf("\n1) Codifica di Hamming\n");
		printf("2) Decodifica di Hamming\n");
		
		printf("\nScegliere l\'operazione da effettuare: ");
		scanf("%d", &operation);
		
		if(operation != 1 && operation != 2)
			printf ("Inserire 1 o 2.\n");
		
		else if(operation == 1)
		{
			system("cls");
			
			printf("===================\n");
			printf("CODIFICA DI HAMMING\n");
			printf("===================\n");
			
			while(1)
			{
				//Si sceglie il valore di m
				printf("\nScegliere il valore di m, compreso tra 3 e 7: ");
				scanf("%d", &m);
				
				if(m < 3 || m > 7)
					printf ("Inserire un valore di m valido.\n");
				else break;
			}
			
			//Si effettua la codifica
			HammingCoding(m);
			
			printf("\n\n");
			system("PAUSE");
		}
		
		else if(operation == 2)
		{
			system("cls");
			
			printf("=====================\n");
			printf("DECODIFICA DI HAMMING\n");
			printf("=====================\n");

			while(1)
			{
				//Si sceglie il valore di n
				printf("\nScegliere un valore di n tra: %d, %d, %d, %d e %d: ", n3, n4, n5, n6, n7);
				scanf("%d", &n);
				
				if(n != n3 && n != n4 && n != n5 && n != n6 && n != n7)
					printf ("Inserire un valore di k valido.\n");
				else break;
			}
			
			//Si effettua la decodifica
			HammingDecoding(n);
			
			printf("\n\n");
			system("PAUSE");
		}
	}
	
	system("PAUSE");
	return 0;
}

int HammingCoding(int indexm)
{
	int i, j;
	int k = 0;
	int m = 0;
	int n = 0;
	int indexk = 0;
	int indexn = 0;
	
	if(indexm == m3)
	{
		indexn = n3;
		indexk = k3;
	}
	
	else if(indexm == m4)
	{
		indexn = n4;
		indexk = k4;
	}
	
	else if(indexm == m5)
	{
		indexn = n5;
		indexk = k5;
	}
	
	else if(indexm == m6)
	{
		indexn = n6;
		indexk = k6;
	}
	
	else if(indexm == m7)
	{
		indexn = n7;
		indexk = k7;
	}
	
	int message[indexk];
	int codedmessage[indexn];
	int G_indexm[indexk][indexn];
	
	//Si inizializzano tutti i vettori e le matrici che verranno utilizzate
	
	for(n = 0; n < indexn; n++)
		codedmessage[n] = 0;
		
	for(k = 0; k < indexk; k++)
		message[k] = 0;
		
	for(k = 0; k < indexk; k++)	
		for(n = 0; n < indexn; n++)
			G_indexm[k][n] = 0;
	
	if(indexm == m3)
		for(k = 0; k < indexk; k++)	
			for(n = 0; n < indexn; n++)
				G_indexm[k][n] = G_3[k][n];
	
	else if(indexm == m4)
		for(k = 0; k < indexk; k++)	
			for(n = 0; n < indexn; n++)
				G_indexm[k][n] = G_4[k][n];
	
	else if(indexm == m5)
		for(k = 0; k < indexk; k++)	
			for(n = 0; n < indexn; n++)
				G_indexm[k][n] = G_5[k][n];
	
	else if(indexm == m6)
		for(k = 0; k < indexk; k++)	
			for(n = 0; n < indexn; n++)
				G_indexm[k][n] = G_6[k][n];
	
	else if(indexm == m7)
		for(k = 0; k < indexk; k++)	
			for(n = 0; n < indexn; n++)
				G_indexm[k][n] = G_7[k][n];
	
	//Si inseriscono i bit del messaggio da codificare
	printf("\nIl messaggio da codificare dovra\' essere lungo %d bit.\n\n", indexk);
	for(k = 0; k < indexk; k++)
	{
		while(1)
		{
			printf("Inserire il bit di posto [%d]: ", k+1);
			scanf("%d", &message[k]);
			if(message[k] > 1)
				printf("Inserire un valore per il bit valido (0 o 1).\n");
			else break;
		}
	}
		
	//Si stampa il messaggio m[indexk]
	printf("\nLa parola di messaggio da cofidicare e\':\nm[%d] = [", indexk);
	for(k = 0; k < indexk; k++)
	{
		printf("%d", message[k]);
		if (k != indexk-1)
			printf("\t");
	}
	printf("]");
	
	//Si stampa la matrice generatrice G_indexm[indexk][indexn] che verrà utilizzata
	printf("\n\nLa matrice generatrice che verra\' utilizzata sara\' la matrice G[%d][%d]:\n", indexk, indexn);
	for (k = 0; k < indexk; k++)
	{
		printf("[");
    	
		for (n = 0; n < indexn; n++)
   		{
    		printf("%d", G_indexm[k][n]);
    		if (n != indexn-1)
				printf("\t");
			if (n == indexk-1)
				printf("||");
		}
			
		printf("]");
		printf("\n");
	}
	
	//Si genera la parola di codice come XOR del prodotto m[indexk]*G_indexm[indexk][indexn]
	for(n = 0; n < indexn; n++)
	{
		for(k = 0; k < indexk; k++)
		{
			codedmessage[n] ^= message[k] * G_indexm[k][n];
		}
	}
	
	//Si stampa la parola di codice codedmessage[indexn] ottenuta
	printf("\nIl prodotto m[%d]*G[%d][%d] da\' come risultato la parola di codice:\nc[%d] = [", indexk, indexk, indexn, indexn);
	for(n = 0; n < indexn; n++)
	{
		printf("%d", codedmessage[n]);
		if (n != indexn-1)
			printf("\t");
	}
	printf("]");
}

int HammingDecoding(int indexn)
{
	int i, j;
	int k = 0;
	int m = 0;
	int n = 0;
	int stop = 0;
	int decoding = 0;
	int onecount = 0;
	int zerocount = 0;
	int syndcount = 0;
	int syndromeindex = 0;
	int indexk = 0;
	int indexm = 0;
	
	if(indexn == n3)
	{
		indexm = m3;
		indexk = k3;
	}
	
	else if(indexn == n4)
	{
		indexm = m4;
		indexk = k4;
	}
	
	else if(indexn == n5)
	{
		indexm = m5;
		indexk = k5;
	}
	
	else if(indexn == n6)
	{
		indexm = m6;
		indexk = k6;
	}
	
	else if(indexn == n7)
	{
		indexm = m7;
		indexk = k7;
	}
	
	//Si inizializzano tutti i vettori e le matrici che verranno utilizzate
	
	int correctedcodedmessage[indexn];
	int codedmessage[indexn];
	int message[indexk];
	int syndrome[indexm];
	int error[indexm];
	int Ht_indexm[indexn][indexm];
	
	for(n = 0; n < indexn; n++)
		correctedcodedmessage[n] = 0;
	
	for(n = 0; n < indexn; n++)
		codedmessage[n] = 0;
		
	for(k = 0; k < indexk; k++)
		message[k] = 0;
					
	for(m = 0; m < indexm; m++)
		syndrome[m] = 0;
		
	for(n = 0; n < indexn; n++)
		error[n] = 0;
		
	if(indexn == n3)
		for(n = 0; n < indexn; n++)	
			for(m = 0; m < indexm; m++)
				Ht_indexm[n][m] = Ht_3[n][m];
				
	if(indexn == n4)
		for(n = 0; n < indexn; n++)	
			for(m = 0; m < indexm; m++)
				Ht_indexm[n][m] = Ht_4[n][m];
				
	if(indexn == n5)
		for(n = 0; n < indexn; n++)	
			for(m = 0; m < indexm; m++)
				Ht_indexm[n][m] = Ht_5[n][m];
				
	if(indexn == n6)
		for(n = 0; n < indexn; n++)	
			for(m = 0; m < indexm; m++)
				Ht_indexm[n][m] = Ht_6[n][m];
				
	if(indexn == n7)
		for(n = 0; n < indexn; n++)	
			for(m = 0; m < indexm; m++)
				Ht_indexm[n][m] = Ht_7[n][m];
	
	while(1)
	{
		//Si sceglie il tipo di decodifica, se di tipo soft o di tipo hard
		printf("\nScegliere se effettuare una decodifica soft oppure hard:\n");
		
		printf("\n1) Soft demapping\n");
		printf("2) Hard demapping\n");
		
		printf("\nScegliere l\'operazione da effettuare: ");
		scanf("%d", &decoding);
				
		if(decoding != 1 && decoding != 2)
			printf ("Inserire 1 o 2.\n");
		else break;
	}
	
	if(decoding == 1)
	{
		//Nel caso di decodifica soft, se il valore immesso è minore od uguale a zero, il bit sarà pari a zero; se il valore immesso è maggiore di zero, il bit sarà pari ad uno;
		printf("\nIl messaggio da decodificare dovra\' essere lungo %d valori, del campo dei numeri razionali.\n\n", indexn);
		for(n = 0; n < indexn; n++)
		{
			printf("Inserire il valore di posto [%d]: ", n+1);
			scanf("%d", &codedmessage[n]);
			if(codedmessage[n] <= 0)
				codedmessage[n] = 0;
			else if(codedmessage[n] > 0)
				codedmessage[n] = 1;
		}
	}
	
	else if(decoding == 2)
	{
		//Nel caso di decodifica hard, il valore immesso sarà pari proprio al bit della parola di codice da decodificare
		printf("\nIl messaggio da decodificare dovra\' essere lungo %d bit.\n\n", indexn);
		for(n = 0; n < indexn; n++)
		{
			while(1)
			{
				printf("Inserire il bit di posto [%d]: ", n+1);
				scanf("%d", &codedmessage[n]);
				if(codedmessage[n] > 1)
					printf("Inserire un valore per il bit valido (0 o 1).\n");
				else break;
			}
		}
	}
	
	//Si stampa la parola di codice codedmessage[indexn] da decodificare
	printf("\nLa parola di codice da decofidicare e\':\nc[%d] = [", indexn);
	for(n = 0; n < indexn; n++)
	{
		printf("%d", codedmessage[n]);
		if (n != indexn-1)
			printf("\t");
	}
	printf("]");
				
	//Si verifica che la parola di codice codedmessage[indexn] sia effettivamente una parola di codice
	for(n = 0; n < indexn; n++)
	{
		if(codedmessage[n] == 1)
			onecount++;
	}
	
	if(onecount == 0 || onecount == indexn)
	{
		//Se la parola di codice codedmessage[indexn] è formata soltanto da uno o soltanto da zero, la parola di codice è sicuramente valida
		onecount = 0;
					
		printf("\n\nLa parola di codice c[%d] ricevuta e\' una parola di codice valida.\n", indexn);
		
		//Si stampano i primi k bit di della parola di codice codedmessage[indexn] che rappresentano la parola di messaggio message[indexk]
		printf("\nIl messaggio di codice che e\' stato trasmesso e\':\nm[%d] : [", indexk);
		for(i = 0; i < indexk; i++)
		{
			printf("%d", codedmessage[i]);
			if (i != indexk-1)
				printf("\t");
		}
		printf("]");
			
		//Si stampano gli ultimi m bit di della parola di codice codedmessage[indexn] che rappresentano i bit di parità
		printf("\n\nI bit di parita\' sono:\np[%d] : [", indexn-indexk);
		for(i = indexn-indexm; i < indexn; i++)
		{
			printf("%d", codedmessage[i]);
			if (i != indexn-1)
				printf("\t");
		}
		printf("]");
	}
				
	else if(onecount < 3)
	{
		//Se la parola di codice codedmessage[indexn] ha un numero di uno minore di 3, cioè del peso di Hamming minimo pari a 3, sicuramente non è una parola di codice valida, oppure è stato commesso più di un errore sulla parola di codice
		printf("\n\nLa parola di codice c[%d] ricevuta non e\' una parola di codice valida, in quanto ha un peso di Hamming W_h_min < 3.\n", indexn);
		printf("\nE\' dunque possibile che sia stato commesso piu\' di un errore durante la trasmissione o la ricezione di c[%d].\n", indexn);
		printf("\nMediante l\'utilizzo della codifica di Hamming e\' possibile correggere un solo errore sulla parola di codice ricevuta.", indexn);
	}
			
	else
	{
		stop = 0;
		onecount = 0;
		syndcount = 0;
		syndromeindex = 0;
		
		//Se la parola di codice codedmessage[indexn] ha un numero di uno uguale o maggiore di 3, cioè del peso di Hamming minimo pari a 3, allora la parola di codice potrebbe essere una parola di codice valida
		printf("\n\nLa parola di codice c[%d] ricevuta potrebbe presentare un errore.\n", indexn);
		printf("\nSe presente, e\' possibile correggere questo errore mediante l\'utilizzo della matrice di controllo di parita\' H[%d][%d]\n", indexn, indexn, indexm);
		printf("\nSi tenta la correzione della parola di codice c[%d].\n", indexn);
		
		//Si stampa la trasposta della matrice di controllo di parità Ht_indexm[indexn][indexm] che verrà utilizzata per la correzione della parola di codice codedmessage[indexn]
		printf("\nLa trasposta della matrice di controllo di parita\' che verra\' utilizzata per la correzione e\' la matrice H[%d][%d]:\n", indexn, indexm);
		for (n = 0; n < indexn; n++)
   		{
    		printf("[");
    		for (m = 0; m < indexm; m++)
   			{
    			printf("%d", Ht_indexm[n][m]);
    			if(m != indexm-1)
					printf("\t");
			}
			printf("]");
			printf("\n");
		}
					
		//Si calcolo il vettore della sindrome syndrome[indexm], come prodotto codedmessage[indexn]*Ht_indexm[indexn][indexm]
		for(m = 0; m < indexm; m++)
		{
			for(n = 0; n < indexn; n++)
			{
				syndrome[m] ^= codedmessage[n] * Ht_indexm[n][m];
			}
						
			if(syndrome[m] == 0)
				syndcount++;
			
			//Nel caso in cui il vettore sindrome syndrome[indexm] sia uguale al vettore nullo, si interrompe la tentata correzione, visto che la parola di codice codedmessage[indexn] non presenta alcun errore
			if(syndcount == indexm)
				stop = 1;
		}
		
		//Si stampa il vettore della sindrome syndrome[indexm]
		printf("\nDal prodotto c[%d]*H[%d][%d] si ottiene il vettore sindrome: \ns[%d] = [", indexn, indexn, indexm, indexm);
		for(m = 0; m < indexm; m++)
		{
			printf("%d", syndrome[m]);
			if (m != indexm-1)
				printf("\t");
		}
		printf("]");
					
		if(stop == 1)
		{
			//Nel caso in cui il vettore sindrome syndrome[indexm] sia uguale al vettore nullo, la parola di codice codedmessage[indexn] non presenta alcun errore
			printf("\n\nIl vettore sindrome s[%d] risulta essere nullo.\n", indexm);
			printf("\nLa parola di codice c[%d] non presenta alcun errore, quindi e\' una parola di codice valida.\n", indexn);
			
			//Si stampano i primi k bit di della parola di codice codedmessage[indexn] che rappresentano la parola di messaggio message[indexk]
			printf("\nIl messaggio di codice che e\' stato trasmesso senza errore e\':\nm[%d] : [", indexk);
			for(i = 0; i < indexk; i++)
			{
				printf("%d", codedmessage[i]);
				if (i != indexk-1)
					printf("\t");
			}
			printf("]");
			
			//Si stampano gli ultimi m bit di della parola di codice codedmessage[indexn] che rappresentano i bit di parità
			printf("\n\nI bit di parita\' sono:\np[%d] : [", indexn-indexk);
			for(i = indexn-indexm; i < indexn; i++)
			{
				printf("%d", codedmessage[i]);
				if (i != indexn-1)
					printf("\t");
			}
			printf("]");
						
			return 0;
		}
		
		//Nel caso in cui il vettore sindrome syndrome[indexm] non sia identicamente nullo, si identifica la riga della trasposta della matrice di controllo di parità Ht_indexm[indexn][indexm] che corrisponde al vettore sindrome
		for(n = 0; n < indexn; n++)
		{
			for(m = 0; m < indexm; m++)
			{
				if((syndrome[m] ^ Ht_indexm[n][m]) == 0)
					zerocount++;
			}
						
			syndromeindex = n;
						
			if(zerocount == indexm)
				break;
			else
				zerocount = 0;
		}
		
		//Si crea il vettore errore error[indexn] con un solo uno posto in corrispondenza dell'indice della riga della trasposta della matrice di controllo di parità Ht_indexm[indexn][indexm] che corrisponde al vettore sindrome
		for(n = 0; n < indexn; n++)
			if(n == syndromeindex)
				error[n] = 1;
			else
				error[n] = 0;
		
		//Si stampa il vettore errore error[indexn]
		printf("\n\nIl vettore di errore e[%d] ottenuto e\':\ne[%d] = [", indexn, indexn);
		for(n = 0; n < indexn; n++)
		{
			printf("%d", error[n]);
			if (n != indexn-1)
				printf("\t");
		}
		printf("]");
		
		for(n = 0; n < indexn; n++)
			correctedcodedmessage[n] = codedmessage[n];
		
		//Si corregge l'errore tramite XOR tra la parola di codice codedmessage[indexn] ed il vettore errore error[indexn]
		for(n = 0; n < indexn; n++)
		{
			if(n == syndromeindex)
				correctedcodedmessage[n] ^= error[n];
		}
		
		//Si stampa la parola di codice codedmessage[indexn] prima della correzione 
		printf("\n\nLa parola di codice c[%d], prima della correzione, e\':\nc[%d] = [", indexn, indexn);
		for(n = 0; n < indexn; n++)
		{
			printf("%d", codedmessage[n]);
			if (n != indexn-1)
				printf("\t");
		}
		printf("]");
		
		//Si stampa la parola di codice codedmessage[indexn] dopo la correzione
		printf("\n\nLa parola di codice c[%d], dopo la correzione, e\':\nc_c[%d] = [", indexn, indexn);
		for(n = 0; n < indexn; n++)
		{
			printf("%d", correctedcodedmessage[n]);
			if (n != indexn-1)
				printf("\t");
		}
		printf("]");
		
		//Si stampano i primi k bit di della parola di codice codedmessage[indexn] che rappresentano la parola di messaggio message[indexk]
		printf("\n\nIl messaggio di codice che e\' stato trasmesso senza errore e\':\nm[%d] : [", indexk);
		for(i = 0; i < indexk; i++)
		{
			printf("%d", correctedcodedmessage[i]);
			if (i != indexk-1)
				printf("\t");
		}
		printf("]");
		
		//Si stampano gli ultimi m bit di della parola di codice codedmessage[indexn] che rappresentano i bit di parità
		printf("\n\nI bit di parita\' sono:\np[%d] : [", indexn-indexk);
		for(i = indexn-indexm; i < indexn; i++)
		{
			printf("%d", correctedcodedmessage[i]);
			if (i != indexn-1)
				printf("\t");
		}
		printf("]");
	}
}

