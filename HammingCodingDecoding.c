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

int main(int argc, char **argv)
{
	int i, j, k, m, n;
	i = j = k = m = n = 0;
	int keep = 0;
	int stop = 0;
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
			printf ("Inserire 1 o 2\n");
		
		else if(operation == 1)
		{
			system("cls");
			
			printf("===================\n");
			printf("CODIFICA DI HAMMING\n");
			printf("===================\n");
			
			while(1)
			{
				printf("\nScegliere il valore di m, compreso tra 3 e 7: ");
				scanf("%d", &m);
				
				if(m < 3 || m > 7)
					printf ("Inserire un valore di m valido.\n");
				else break;
			}
			
			if(m == m3)
			{
				for(n = 0; n < n3; n++)
					codedmessage[n] = 0;
		
				for(k = 0; k < k3; k++)
					message[k] = 0;
			
				printf("\nIl messaggio da codificare dovra\' essere lungo %d bit.\n\n", k3);
				for(k = 0; k < k3; k++)
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
			
				printf("\nLa parola di messaggio da cofidicare e\':\nm[%d] = [", k3);
				for(k = 0; k < k3; k++)
				{
					printf("%d", message[k]);
					if (k != k3-1)
						printf("\t");
				}
				printf("]");
			
				printf("\n\nLa matrice generatrice che verra\' utilizzata sara\' la matrice G[%d][%d]:\n", k3, n3);
				for (k = 0; k < k3; k++)
    			{
    				printf("[");
    	
    				for (n = 0; n < n3; n++)
   		 			{
    					printf("%d", G_3[k][n]);
    					if (n != n3-1)
							printf("\t");
						if (n == k3-1)
							printf("||");
					}
			
					printf("]");
					printf("\n");
				}
			
				for(n = 0; n < n3; n++)
				{
					for(k = 0; k < k3; k++)
					{
						codedmessage[n] ^= message[k] * G_3[k][n];
					}
				}
			
				printf("\nIl prodotto m[%d]*G[%d][%d] da\' come risultato la parola di codice:\nc[%d] = [", k3, k3, n3, n3);
				for(n = 0; n < n3; n++)
				{
					printf("%d", codedmessage[n]);
					if (n != n3-1)
						printf("\t");
				}
				printf("]");
				
				printf("\n\n");
				system("PAUSE");
			}
	
			else if(m == m4)
			{
				for(n = 0; n < n4; n++)
					codedmessage[n] = 0;
		
				for(k = 0; k < k4; k++)
					message[k] = 0;
			
				printf("\nIl messaggio da codificare dovra\' essere lungo %d bit.\n\n", k4);
				for(k = 0; k < k4; k++)
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
			
				printf("\nLa parola di messaggio da cofidicare e\':\nm[%d] = [", k4);
				for(k = 0; k < k4; k++)
				{
					printf("%d", message[k]);
					if (k != k4-1)
						printf("\t");
				}
				printf("]");
			
				printf("\n\nLa matrice generatrice che verra\' utilizzata sara\' la matrice G[%d][%d]:\n", k4, n4);
				for (k = 0; k < k4; k++)
    			{
    				printf("[");
    	
    				for (n = 0; n < n4; n++)
    				{
    					printf("%d", G_4[k][n]);
    					if (n != n4-1)
							printf("\t");
						if (n == k4-1)
							printf("||");
					}
		
					printf("]");
					printf("\n");
				}
			
				for(n = 0; n < n4; n++)
				{
					for(k = 0; k < k4; k++)
					{
						codedmessage[n] ^= message[k] * G_4[k][n];
					}
				}
			
				printf("\nIl prodotto m[%d]*G[%d][%d] da\' come risultato la parola di codice:\nc[%d] = [", k4, k4, n4, n4);
				for(n = 0; n < n4; n++)
				{
					printf("%d", codedmessage[n]);
					if (n != n4-1)
						printf("\t");
				}
				printf("]");
				
				printf("\n\n");
				system("PAUSE");
			}
		
			else if(m == m5)
			{
				for(n = 0; n < n5; n++)
					codedmessage[n] = 0;
		
				for(k = 0; k < k5; k++)
					message[k] = 0;
			
				printf("\nIl messaggio da codificare dovra\' essere lungo %d bit.\n\n", k5);
				for(k = 0; k < k5; k++)
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
			
				printf("\nLa parola di messaggio da cofidicare e\':\nm[%d] = [", k5);
				for(k = 0; k < k5; k++)
				{
					printf("%d", message[k]);
					if (k != k5-1)
						printf("\t");
				}
				printf("]");
			
				printf("\n\nLa matrice generatrice che verra\' utilizzata sara\' la matrice G[%d][%d]:\n", k5, n5);
				for (k = 0; k < k5; k++)
    			{
    				printf("[");
    	
    				for (n = 0; n < n5; n++)
    				{
    					printf("%d", G_5[k][n]);
    					if (n != n5-1)
							printf("\t");
						if (n == k5-1)
							printf("||");
					}
		
					printf("]");
					printf("\n");
				}
			
				for(n = 0; n < n5; n++)
				{
					for(k = 0; k < k5; k++)
					{
						codedmessage[n] ^= message[k] * G_5[k][n];
					}
				}
			
				printf("\nIl prodotto m[%d]*G[%d][%d] da\' come risultato la parola di codice:\nc[%d] = [", k5, k5, n5, n5);
				for(n = 0; n < n5; n++)
				{
					printf("%d", codedmessage[n]);
					if (n != n5-1)
						printf("\t");
				}
				printf("]");
				
				printf("\n\n");
				system("PAUSE");
			}
		
			else if(m == m6)
			{
				for(n = 0; n < n6; n++)
					codedmessage[n] = 0;
		
				for(k = 0; k < k6; k++)
					message[k] = 0;
			
				printf("\nIl messaggio da codificare dovra\' essere lungo %d bit.\n\n", k6);
				for(k = 0; k < k6; k++)
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
			
				printf("\nLa parola di messaggio da cofidicare e\':\nm[%d] = [", k6);
				for(k = 0; k < k6; k++)
				{
					printf("%d", message[k]);
					if (k != k6-1)
						printf("\t");
				}
				printf("]");
			
				printf("\n\nLa matrice generatrice che verra\' utilizzata sara\' la matrice G[%d][%d]:\n", k6, n6);
				for (k = 0; k < k6; k++)
    			{
    				printf("[");
    	
    				for (n = 0; n < n6; n++)
   		 			{
    					printf("%d", G_6[k][n]);
    					if (n != n6-1)
							printf("\t");
						if (n == k6-1)
							printf("||");
					}
			
					printf("]");
					printf("\n");
				}
			
				for(n = 0; n < n6; n++)
				{
					for(k = 0; k < k6; k++)
					{
						codedmessage[n] ^= message[k] * G_6[k][n];
					}
				}
			
				printf("\nIl prodotto m[%d]*G[%d][%d] da\' come risultato la parola di codice:\nc[%d] = [", k6, k6, n6, n6);
				for(n = 0; n < n6; n++)
				{
					printf("%d", codedmessage[n]);
					if (n != n6-1) printf("\t");
				}
				printf("]");
				
				printf("\n\n");
				system("PAUSE");
			
			}
	
			else if(m == m7)
			{
				for(n = 0; n < n7; n++)
					codedmessage[n] = 0;
		
				for(k = 0; k < k7; k++)
					message[k] = 0;
			
				printf("\nIl messaggio da codificare dovra\' essere lungo %d bit.\n\n", k7);
				for(k = 0; k < k7; k++)
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
			
				printf("\nLa parola di messaggio da cofidicare e\':\nm[%d] = [", k7);
				for(k = 0; k < k7; k++)
				{
					printf("%d", message[k]);
					if (k != k7-1)
						printf("\t");
				}
				printf("]");
			
				printf("\n\nLa matrice generatrice che verra\' utilizzata sara\' la matrice G[%d][%d]:\n", k7, n7);
				for (k = 0; k < k7; k++)
   				{
   					printf("[");
   	
    				for (n = 0; n < n7; n++)
		 			{
  						printf("%d", G_7[k][n]);
   						if (n != n7-1)
							printf("\t");
						if (n == k7-1)
							printf("||");
					}
			
					printf("]");
					printf("\n");
				}
			
				for(n = 0; n < n7; n++)
				{
					for(k = 0; k < k7; k++)
					{
						codedmessage[n] ^= message[k] * G_7[k][n];
					}
				}
			
				printf("\nIl prodotto m[%d]*G[%d][%d] da\' come risultato la parola di codice:\nc[%d] = [", k7, k7, n7, n7);
				for(n = 0; n < n7; n++)
				{
					printf("%d", codedmessage[n]);
					if (n != n7-1)
						printf("\t");
				}
				printf("]");
				
				printf("\n\n");
				system("PAUSE");
			}
		}
		
		else if(operation == 2)
		{
			system("cls");
			
			printf("=====================\n");
			printf("DECODIFICA DI HAMMING\n");
			printf("=====================\n");
			
			if(m != 0)
			{
				while(1)
				{
					n = pow(2, m) - 1;
					k = pow(2, m) - 1 - m;
					printf("\nE\' presente la parola di codice c[%d] in memoria.\nc[%d] : [", n, n);
					for(i = 0; i < n; i++)
					{
						printf("%d", codedmessage[i]);
						if (i != n-1)
							printf("\t");
					}
					printf("]");
				
					printf("\n\nContinuare ad utilizzare c[%d] come parola di codice\?\n", n);
					
					printf("\n1) Decodificare c[%d]\n", n);
					printf("2) Decodificare una nuova parola di codice\n");
				
					printf("\nScegliere l\'operazione da effettuare: ");
					scanf("%d", &keep);
				
					if(keep != 1 && keep != 2)
						printf ("Inserire 1 o 2\n");
					
					else if(keep == 1)
					{
						printf("\nIl messaggio di codice che e\' stato trasmesso e\':\nm[%d] : [", k);
						for(i = 0; i < k; i++)
						{
							printf("%d", message[i]);
							if (i != k-1)
								printf("\t");
						}
						printf("]");
						
						printf("\n\nI bit di parita\' sono:\np[%d] : [", n-k);
						for(i = n-m; i < n; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != n-1)
								printf("\t");
						}
						printf("]\n");
					}
					
					else if(keep == 2)
						break;
				}
			}
			
			while(1)
			{
				printf("\nScegliere un valore di n tra: %d, %d, %d, %d e %d: ", n3, n4, n5, n6, n7);
				scanf("%d", &n);
				
				if(n != n3 && n != n4 && n != n5 && n != n6 && n != n7)
					printf ("Inserire un valore di k valido.\n");
				else break;
			}
			
			if(n == n3)
			{
				for(n = 0; n < n3; n++)
					codedmessage[n] = 0;
		
				for(k = 0; k < k3; k++)
					message[k] = 0;
					
				for(m = 0; m < m3; m++)
					syndrome[m] = 0;
					
				for(n = 0; n < n3; n++)
					error[n] = 0;
					
				printf("\nIl messaggio da decodificare dovra\' essere lungo %d bit.\n\n", n3);
				for(n = 0; n < n3; n++)
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
			
				printf("\nLa parola di codice da decofidicare e\':\nc[%d] = [", n3);
				for(n = 0; n < n3; n++)
				{
					printf("%d", codedmessage[n]);
					if (n != n3-1)
						printf("\t");
				}
				printf("]");
				
				//Verificare che c[n3] sia effettivamente una parola di codice
				for(n = 0; n < n3; n++)
				{
					if(codedmessage[n] == 1)
						onecount++;
				}
				
				if(onecount == 0 || onecount == n3)
				{
					onecount = 0;
					
					printf("\n\nLa parola di codice c[%d] ricevuta e\' una parola di codice valida.\n", n3);
					
					printf("\nIl messaggio di codice che e\' stato trasmesso e\':\nm[%d] : [", k3);
						for(i = 0; i < k3; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != k3-1)
								printf("\t");
						}
						printf("]");
						
						printf("\n\nI bit di parita\' sono:\np[%d] : [", n3-k3);
						for(i = n3-m3; i < n3; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != n3-1)
								printf("\t");
						}
						printf("]");
						
						printf("\n\n");
						system("PAUSE");
				}
				
				else if(onecount < m3)
				{
					printf("\n\nLa parola di codice c[%d] ricevuta non e\' una parola di codice valida, in quanto ha un peso di Hamming W_h_min < 3.\n", n3);
					printf("\nE\' dunque possibile che sia stato commesso piu\' di un errore durante la trasmissione o la ricezione di c[%d].\n", n3);
					printf("\nMediante l\'utilizzo della codifica di Hamming e\' possibile correggere un solo errore sulla parola di codice ricevuta.", n3);
				}
				
				else
				{
					stop = 0;
					onecount = 0;
					syndcount = 0;
					syndromeindex = 0;
					
					printf("\n\nLa parola di codice c[%d] ricevuta potrebbe presentare un errore.\n", n3);
					printf("\nSe presente, e\' possibile correggere questo errore mediante l\'utilizzo della matrice di controllo di parita\' H[%d][%d]", n3, n3, m3);
					printf("\n\nSi tenta la correzione della parola di codice c[%d].\n", n3);
					
					printf("\nLa trasposta della matrice di controllo di parita\' che verra\' utilizzata per la correzione e\' la matrice H[%d][%d]:\n", n3, m3);
					for (n = 0; n < n3; n++)
    				{
    					printf("[");
    					for (m = 0; m < m3; m++)
   		 				{
    						printf("%d", Ht_3[n][m]);
    						if(m != m3-1)
								printf("\t");
						}
						printf("]");
						printf("\n");
					}
					
					//Calcolo della sindrome[m3], come codedmessage[n3]*Ht_3[n3][m3]
					for(m = 0; m < m3; m++)
					{
						for(n = 0; n < n3; n++)
						{
							syndrome[m] ^= codedmessage[n] * Ht_3[n][m];
						}
						
						if(syndrome[m] == 0)
							syndcount++;
						
						if(syndcount == m3)
							stop = 1;
					}

					printf("\nDal prodotto c[%d]*H[%d][%d] si ottiene il vettore sindrome: \ns[%d] = [", n3, n3, m3, m3);
					for(m = 0; m < m3; m++)
					{
						printf("%d", syndrome[m]);
						if (m != m3-1)
							printf("\t");
					}
					printf("]");
					
					if(stop == 1)
					{
						printf("\n\nIl vettore sindrome s[%d] risulta essere nullo.\n", m3);
						printf("\nLa parola di codice c[%d] non presenta alcun errore, quindi e\' una parola di codice valida.\n", n3);
						
						printf("\nIl messaggio di codice che e\' stato trasmesso senza errore e\':\nm[%d] : [", k3);
						for(i = 0; i < k3; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != k3-1)
								printf("\t");
						}
						printf("]");
						
						printf("\n\nI bit di parita\' sono:\np[%d] : [", n3-k3);
						for(i = n3-m3; i < n3; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != n3-1)
								printf("\t");
						}
						printf("]");
						printf("\n\n");
						
						break;
					}
					
					for(n = 0; n < n3; n++)
					{
						for(m = 0; m < m3; m++)
						{
							if((syndrome[m] ^ Ht_3[n][m]) == 0)
								zerocount++;
						}
						
						syndromeindex = n;
						
						if(zerocount == m3)
							break;
						else
							zerocount = 0;
					}
					
					for(n = 0; n < n3; n++)
						if(n == syndromeindex)
							error[n] = 1;
						else
							error[n] = 0;
							
					printf("\n\nIl vettore di errore e[%d] ottenuto e\':\ne[%d] = [", n3, n3);
					for(n = 0; n < n3; n++)
					{
						printf("%d", error[n]);
						if (n != n3-1)
							printf("\t");
					}
					printf("]");
					
					for(n = 0; n < n3; n++)
						correctedcodedmessage[n] = codedmessage[n];
					
					for(n = 0; n < n3; n++)
					{
						if(n == syndromeindex)
							correctedcodedmessage[n] ^= error[n];
					}
					
					printf("\n\nLa parola di codice c[%d], prima della correzione, e\':\nc[%d] = [", n3, n3);
					for(n = 0; n < n3; n++)
					{
						printf("%d", codedmessage[n]);
						if (n != n3-1)
							printf("\t");
					}
					printf("]");
					
					printf("\n\nLa parola di codice c[%d], dopo la correzione, e\':\nc_c[%d] = [", n3, n3);
					for(n = 0; n < n3; n++)
					{
						printf("%d", correctedcodedmessage[n]);
						if (n != n3-1)
							printf("\t");
					}
					printf("]");
					
					printf("\n\nIl messaggio di codice che e\' stato trasmesso senza errore e\':\nm[%d] : [", k3);
					for(i = 0; i < k3; i++)
					{
						printf("%d", correctedcodedmessage[i]);
						if (i != k3-1)
							printf("\t");
					}
					printf("]");
						
					printf("\n\nI bit di parita\' sono:\np[%d] : [", n3-k3);
					for(i = n3-m3; i < n3; i++)
					{
						printf("%d", correctedcodedmessage[i]);
						if (i != n3-1)
							printf("\t");
					}
					printf("]");
				}
			}
			
			if(n == n4)
			{
				for(n = 0; n < n4; n++)
					codedmessage[n] = 0;
		
				for(k = 0; k < k4; k++)
					message[k] = 0;
					
				for(m = 0; m < m4; m++)
					syndrome[m] = 0;
					
				for(n = 0; n < n4; n++)
					error[n] = 0;
					
				printf("\nIl messaggio da decodificare dovra\' essere lungo %d bit.\n\n", n4);
				for(n = 0; n < n4; n++)
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
			
				printf("\nLa parola di codice da decofidicare e\':\nc[%d] = [", n4);
				for(n = 0; n < n4; n++)
				{
					printf("%d", codedmessage[n]);
					if (n != n4-1)
						printf("\t");
				}
				printf("]");
				
				//Verificare che c[n4] sia effettivamente una parola di codice
				for(n = 0; n < n4; n++)
				{
					if(codedmessage[n] == 1)
						onecount++;
				}
				
				if(onecount == 0 || onecount == n4)
				{
					onecount = 0;
					
					printf("\n\nLa parola di codice c[%d] ricevuta e\' una parola di codice valida.\n", n4);
					
					printf("\nIl messaggio di codice che e\' stato trasmesso e\':\nm[%d] : [", k4);
						for(i = 0; i < k4; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != k4-1)
								printf("\t");
						}
						printf("]");
						
						printf("\n\nI bit di parita\' sono:\np[%d] : [", n4-k4);
						for(i = n4-m4; i < n4; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != n4-1)
								printf("\t");
						}
						printf("]\n");
				}
				
				else if(onecount < m4)
				{
					printf("\n\nLa parola di codice c[%d] ricevuta non e\' una parola di codice valida, in quanto ha un peso di Hamming W_h_min < 3.\n", n4);
					printf("\nE\' dunque possibile che sia stato commesso piu\' di un errore durante la trasmissione o la ricezione di c[%d].\n", n4);
					printf("\nMediante l\'utilizzo della codifica di Hamming e\' possibile correggere un solo errore sulla parola di codice ricevuta.", n4);
				}
				
				else
				{
					stop = 0;
					onecount = 0;
					syndcount = 0;
					syndromeindex = 0;
					
					printf("\n\nLa parola di codice c[%d] ricevuta potrebbe presentare un errore.\n", n4);
					printf("\nSe presente, e\' possibile correggere questo errore mediante l\'utilizzo della matrice di controllo di parita\' H[%d][%d]", n4, n4, m4);
					printf("\n\nSi tenta la correzione della parola di codice c[%d].\n", n4);
					
					printf("\nLa trasposta della matrice di controllo di parita\' che verra\' utilizzata per la correzione e\' la matrice H[%d][%d]:\n", n4, m4);
					for (n = 0; n < n4; n++)
    				{
    					printf("[");
    					for (m = 0; m < m4; m++)
   		 				{
    						printf("%d", Ht_4[n][m]);
    						if(m != m4-1)
								printf("\t");
						}
						printf("]");
						printf("\n");
					}
					
					//Calcolo della sindrome[m4], come codedmessage[n4]*Ht_4[n4][m4]
					for(m = 0; m < m4; m++)
					{
						for(n = 0; n < n4; n++)
						{
							syndrome[m] ^= codedmessage[n] * Ht_4[n][m];
						}
						
						if(syndrome[m] == 0)
							syndcount++;
						
						if(syndcount == m4)
							stop = 1;
					}

					printf("\nDal prodotto c[%d]*H[%d][%d] si ottiene il vettore sindrome: \ns[%d] = [", n4, n4, m4, m4);
					for(m = 0; m < m4; m++)
					{
						printf("%d", syndrome[m]);
						if (m != m4-1)
							printf("\t");
					}
					printf("]");
					
					if(stop == 1)
					{
						printf("\n\nIl vettore sindrome s[%d] risulta essere nullo.\n", m4);
						printf("\nLa parola di codice c[%d] non presenta alcun errore, quindi e\' una parola di codice valida.\n\n", n4);
						
						printf("\nIl messaggio di codice che e\' stato trasmesso senza errore e\':\nm[%d] : [", k4);
						for(i = 0; i < k4; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != k4-1)
								printf("\t");
						}
						printf("]");
						
						printf("\n\nI bit di parita\' sono:\np[%d] : [", n4-k4);
						for(i = n4-m4; i < n4; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != n4-1)
								printf("\t");
						}
						printf("]");
						printf("\n\n");
						
						break;
					}
					
					for(n = 0; n < n4; n++)
					{
						for(m = 0; m < m4; m++)
						{
							if((syndrome[m] ^ Ht_4[n][m]) == 0)
								zerocount++;
						}
						
						syndromeindex = n;
						
						if(zerocount == m4)
							break;
						else
							zerocount = 0;
					}
					
					for(n = 0; n < n4; n++)
						if(n == syndromeindex)
							error[n] = 1;
						else
							error[n] = 0;
							
					printf("\n\nIl vettore di errore e[%d] ottenuto e\':\ne[%d] = [", n4, n4);
					for(n = 0; n < n4; n++)
					{
						printf("%d", error[n]);
						if (n != n4-1)
							printf("\t");
					}
					printf("]");
					
					for(n = 0; n < n4; n++)
						correctedcodedmessage[n] = codedmessage[n];
					
					for(n = 0; n < n4; n++)
					{
						if(n == syndromeindex)
							correctedcodedmessage[n] ^= error[n];
					}
					
					printf("\n\nLa parola di codice c[%d], prima della correzione, e\':\nc[%d] = [", n4, n4);
					for(n = 0; n < n4; n++)
					{
						printf("%d", codedmessage[n]);
						if (n != n4-1)
							printf("\t");
					}
					printf("]");
					
					printf("\n\nLa parola di codice c[%d], dopo la correzione, e\':\nc_c[%d] = [", n4, n4);
					for(n = 0; n < n4; n++)
					{
						printf("%d", correctedcodedmessage[n]);
						if (n != n4-1)
							printf("\t");
					}
					printf("]");
					
					printf("\n\nIl messaggio di codice che e\' stato trasmesso senza errore e\':\nm[%d] : [", k4);
					for(i = 0; i < k4; i++)
					{
						printf("%d", correctedcodedmessage[i]);
						if (i != k4-1)
							printf("\t");
					}
					printf("]");
						
					printf("\n\nI bit di parita\' sono:\np[%d] : [", n4-k4);
					for(i = n4-m4; i < n4; i++)
					{
						printf("%d", correctedcodedmessage[i]);
						if (i != n4-1)
							printf("\t");
					}
					printf("]");
				}
			}
			
			if(n == n5)
			{
				for(n = 0; n < n5; n++)
					codedmessage[n] = 0;
		
				for(k = 0; k < k5; k++)
					message[k] = 0;
					
				for(m = 0; m < m5; m++)
					syndrome[m] = 0;
					
				for(n = 0; n < n5; n++)
					error[n] = 0;
					
				printf("\nIl messaggio da decodificare dovra\' essere lungo %d bit.\n\n", n5);
				for(n = 0; n < n5; n++)
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
			
				printf("\nLa parola di codice da decofidicare e\':\nc[%d] = [", n5);
				for(n = 0; n < n5; n++)
				{
					printf("%d", codedmessage[n]);
					if (n != n5-1)
						printf("\t");
				}
				printf("]");
				
				//Verificare che c[n5] sia effettivamente una parola di codice
				for(n = 0; n < n5; n++)
				{
					if(codedmessage[n] == 1)
						onecount++;
				}
				
				if(onecount == 0 || onecount == n5)
				{
					onecount = 0;
					
					printf("\n\nLa parola di codice c[%d] ricevuta e\' una parola di codice valida.\n", n5);
					
					printf("\nIl messaggio di codice che e\' stato trasmesso e\':\nm[%d] : [", k5);
						for(i = 0; i < k5; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != k5-1)
								printf("\t");
						}
						printf("]");
						
						printf("\n\nI bit di parita\' sono:\np[%d] : [", n5-k5);
						for(i = n5-m5; i < n5; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != n5-1)
								printf("\t");
						}
						printf("]\n");
				}
				
				else if(onecount < m5)
				{
					printf("\n\nLa parola di codice c[%d] ricevuta non e\' una parola di codice valida, in quanto ha un peso di Hamming W_h_min < 3.\n", n5);
					printf("\nE\' dunque possibile che sia stato commesso piu\' di un errore durante la trasmissione o la ricezione di c[%d].\n", n5);
					printf("\nMediante l\'utilizzo della codifica di Hamming e\' possibile correggere un solo errore sulla parola di codice ricevuta.", n5);
				}
				
				else
				{
					stop = 0;
					onecount = 0;
					syndcount = 0;
					syndromeindex = 0;
					
					printf("\n\nLa parola di codice c[%d] ricevuta potrebbe presentare un errore.\n", n5);
					printf("\nSe presente, e\' possibile correggere questo errore mediante l\'utilizzo della matrice di controllo di parita\' H[%d][%d]", n5, n5, m5);
					printf("\n\nSi tenta la correzione della parola di codice c[%d].\n", n5);
					
					printf("\nLa trasposta della matrice di controllo di parita\' che verra\' utilizzata per la correzione e\' la matrice H[%d][%d]:\n", n5, m5);
					for (n = 0; n < n5; n++)
    				{
    					printf("[");
    					for (m = 0; m < m5; m++)
   		 				{
    						printf("%d", Ht_5[n][m]);
    						if(m != m5-1)
								printf("\t");
						}
						printf("]");
						printf("\n");
					}
					
					//Calcolo della sindrome[m5], come codedmessage[n5]*Ht_5[n5][m5]
					for(m = 0; m < m5; m++)
					{
						for(n = 0; n < n5; n++)
						{
							syndrome[m] ^= codedmessage[n] * Ht_5[n][m];
						}
						
						if(syndrome[m] == 0)
							syndcount++;
						
						if(syndcount == m5)
							stop = 1;
					}

					printf("\nDal prodotto c[%d]*H[%d][%d] si ottiene il vettore sindrome: \ns[%d] = [", n5, n5, m5, m5);
					for(m = 0; m < m5; m++)
					{
						printf("%d", syndrome[m]);
						if (m != m5-1)
							printf("\t");
					}
					printf("]");
					
					if(stop == 1)
					{
						printf("\n\nIl vettore sindrome s[%d] risulta essere nullo.\n", m5);
						printf("\nLa parola di codice c[%d] non presenta alcun errore, quindi e\' una parola di codice valida.\n\n", n5);
						
						printf("\nIl messaggio di codice che e\' stato trasmesso senza errore e\':\nm[%d] : [", k5);
						for(i = 0; i < k5; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != k5-1)
								printf("\t");
						}
						printf("]");
						
						printf("\n\nI bit di parita\' sono:\np[%d] : [", n5-k5);
						for(i = n5-m5; i < n5; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != n5-1)
								printf("\t");
						}
						printf("]");
						printf("\n\n");
						
						break;
					}
					
					for(n = 0; n < n5; n++)
					{
						for(m = 0; m < m5; m++)
						{
							if((syndrome[m] ^ Ht_5[n][m]) == 0)
								zerocount++;
						}
						
						syndromeindex = n;
						
						if(zerocount == m5)
							break;
						else
							zerocount = 0;
					}
					
					for(n = 0; n < n5; n++)
						if(n == syndromeindex)
							error[n] = 1;
						else
							error[n] = 0;
							
					printf("\n\nIl vettore di errore e[%d] ottenuto e\':\ne[%d] = [", n5, n5);
					for(n = 0; n < n5; n++)
					{
						printf("%d", error[n]);
						if (n != n5-1)
							printf("\t");
					}
					printf("]");
					
					for(n = 0; n < n5; n++)
						correctedcodedmessage[n] = codedmessage[n];
					
					for(n = 0; n < n5; n++)
					{
						if(n == syndromeindex)
							correctedcodedmessage[n] ^= error[n];
					}
					
					printf("\n\nLa parola di codice c[%d], prima della correzione, e\':\nc[%d] = [", n5, n5);
					for(n = 0; n < n5; n++)
					{
						printf("%d", codedmessage[n]);
						if (n != n5-1)
							printf("\t");
					}
					printf("]");
					
					printf("\n\nLa parola di codice c[%d], dopo la correzione, e\':\nc_c[%d] = [", n5, n5);
					for(n = 0; n < n5; n++)
					{
						printf("%d", correctedcodedmessage[n]);
						if (n != n5-1)
							printf("\t");
					}
					printf("]");
					
					printf("\n\nIl messaggio di codice che e\' stato trasmesso senza errore e\':\nm[%d] : [", k5);
					for(i = 0; i < k5; i++)
					{
						printf("%d", correctedcodedmessage[i]);
						if (i != k5-1)
							printf("\t");
					}
					printf("]");
						
					printf("\n\nI bit di parita\' sono:\np[%d] : [", n5-k5);
					for(i = n5-m5; i < n5; i++)
					{
						printf("%d", correctedcodedmessage[i]);
						if (i != n5-1)
							printf("\t");
					}
					printf("]");
				}
			}
			
			if(n == n6)
			{
				for(n = 0; n < n6; n++)
					codedmessage[n] = 0;
		
				for(k = 0; k < k6; k++)
					message[k] = 0;
					
				for(m = 0; m < m6; m++)
					syndrome[m] = 0;
					
				for(n = 0; n < n6; n++)
					error[n] = 0;
					
				printf("\nIl messaggio da decodificare dovra\' essere lungo %d bit.\n\n", n6);
				for(n = 0; n < n6; n++)
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
			
				printf("\nLa parola di codice da decofidicare e\':\nc[%d] = [", n6);
				for(n = 0; n < n6; n++)
				{
					printf("%d", codedmessage[n]);
					if (n != n6-1)
						printf("\t");
				}
				printf("]");
				
				//Verificare che c[n6] sia effettivamente una parola di codice
				for(n = 0; n < n6; n++)
				{
					if(codedmessage[n] == 1)
						onecount++;
				}
				
				if(onecount == 0 || onecount == n6)
				{
					onecount = 0;
					
					printf("\n\nLa parola di codice c[%d] ricevuta e\' una parola di codice valida.\n", n6);
					
					printf("\nIl messaggio di codice che e\' stato trasmesso e\':\nm[%d] : [", k6);
						for(i = 0; i < k6; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != k6-1)
								printf("\t");
						}
						printf("]");
						
						printf("\n\nI bit di parita\' sono:\np[%d] : [", n6-k6);
						for(i = n6-m6; i < n6; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != n6-1)
								printf("\t");
						}
						printf("]\n");
				}
				
				else if(onecount < m6)
				{
					printf("\n\nLa parola di codice c[%d] ricevuta non e\' una parola di codice valida, in quanto ha un peso di Hamming W_h_min < 3.\n", n6);
					printf("\nE\' dunque possibile che sia stato commesso piu\' di un errore durante la trasmissione o la ricezione di c[%d].\n", n6);
					printf("\nMediante l\'utilizzo della codifica di Hamming e\' possibile correggere un solo errore sulla parola di codice ricevuta.", n6);
				}
				
				else
				{
					stop = 0;
					onecount = 0;
					syndcount = 0;
					syndromeindex = 0;
					
					printf("\n\nLa parola di codice c[%d] ricevuta potrebbe presentare un errore.\n", n6);
					printf("\nSe presente, e\' possibile correggere questo errore mediante l\'utilizzo della matrice di controllo di parita\' H[%d][%d]", n6, n6, m6);
					printf("\n\nSi tenta la correzione della parola di codice c[%d].\n", n6);
					
					printf("\nLa trasposta della matrice di controllo di parita\' che verra\' utilizzata per la correzione e\' la matrice H[%d][%d]:\n", n6, m6);
					for (n = 0; n < n6; n++)
    				{
    					printf("[");
    					for (m = 0; m < m6; m++)
   		 				{
    						printf("%d", Ht_6[n][m]);
    						if(m != m6-1)
								printf("\t");
						}
						printf("]");
						printf("\n");
					}
					
					//Calcolo della sindrome[m6], come codedmessage[n6]*Ht_6[n6][m6]
					for(m = 0; m < m6; m++)
					{
						for(n = 0; n < n6; n++)
						{
							syndrome[m] ^= codedmessage[n] * Ht_6[n][m];
						}
						
						if(syndrome[m] == 0)
							syndcount++;
						
						if(syndcount == m6)
							stop = 1;
					}

					printf("\nDal prodotto c[%d]*H[%d][%d] si ottiene il vettore sindrome: \ns[%d] = [", n6, n6, m6, m6);
					for(m = 0; m < m6; m++)
					{
						printf("%d", syndrome[m]);
						if (m != m6-1)
							printf("\t");
					}
					printf("]");
					
					if(stop == 1)
					{
						printf("\n\nIl vettore sindrome s[%d] risulta essere nullo.\n", m6);
						printf("\nLa parola di codice c[%d] non presenta alcun errore, quindi e\' una parola di codice valida.\n\n", n6);
						
						printf("\nIl messaggio di codice che e\' stato trasmesso senza errore e\':\nm[%d] : [", k6);
						for(i = 0; i < k6; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != k6-1)
								printf("\t");
						}
						printf("]");
						
						printf("\n\nI bit di parita\' sono:\np[%d] : [", n6-k6);
						for(i = n6-m6; i < n6; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != n6-1)
								printf("\t");
						}
						printf("]");
						printf("\n\n");
						
						break;
					}
					
					for(n = 0; n < n6; n++)
					{
						for(m = 0; m < m6; m++)
						{
							if((syndrome[m] ^ Ht_6[n][m]) == 0)
								zerocount++;
						}
						
						syndromeindex = n;
						
						if(zerocount == m6)
							break;
						else
							zerocount = 0;
					}
					
					for(n = 0; n < n6; n++)
						if(n == syndromeindex)
							error[n] = 1;
						else
							error[n] = 0;
							
					printf("\n\nIl vettore di errore e[%d] ottenuto e\':\ne[%d] = [", n6, n6);
					for(n = 0; n < n6; n++)
					{
						printf("%d", error[n]);
						if (n != n6-1)
							printf("\t");
					}
					printf("]");
					
					for(n = 0; n < n6; n++)
						correctedcodedmessage[n] = codedmessage[n];
					
					for(n = 0; n < n6; n++)
					{
						if(n == syndromeindex)
							correctedcodedmessage[n] ^= error[n];
					}
					
					printf("\n\nLa parola di codice c[%d], prima della correzione, e\':\nc[%d] = [", n6, n6);
					for(n = 0; n < n6; n++)
					{
						printf("%d", codedmessage[n]);
						if (n != n6-1)
							printf("\t");
					}
					printf("]");
					
					printf("\n\nLa parola di codice c[%d], dopo la correzione, e\':\nc_c[%d] = [", n6, n6);
					for(n = 0; n < n6; n++)
					{
						printf("%d", correctedcodedmessage[n]);
						if (n != n6-1)
							printf("\t");
					}
					printf("]");
					
					printf("\n\nIl messaggio di codice che e\' stato trasmesso senza errore e\':\nm[%d] : [", k6);
					for(i = 0; i < k6; i++)
					{
						printf("%d", correctedcodedmessage[i]);
						if (i != k6-1)
							printf("\t");
					}
					printf("]");
						
					printf("\n\nI bit di parita\' sono:\np[%d] : [", n6-k6);
					for(i = n6-m6; i < n6; i++)
					{
						printf("%d", correctedcodedmessage[i]);
						if (i != n6-1)
							printf("\t");
					}
					printf("]");
				}
			}
			
			if(n == n7)
			{
				for(n = 0; n < n7; n++)
					codedmessage[n] = 0;
		
				for(k = 0; k < k7; k++)
					message[k] = 0;
					
				for(m = 0; m < m7; m++)
					syndrome[m] = 0;
					
				for(n = 0; n < n7; n++)
					error[n] = 0;
					
				printf("\nIl messaggio da decodificare dovra\' essere lungo %d bit.\n\n", n7);
				for(n = 0; n < n7; n++)
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
			
				printf("\nLa parola di codice da decofidicare e\':\nc[%d] = [", n7);
				for(n = 0; n < n7; n++)
				{
					printf("%d", codedmessage[n]);
					if (n != n7-1)
						printf("\t");
				}
				printf("]");
				
				//Verificare che c[n7] sia effettivamente una parola di codice
				for(n = 0; n < n7; n++)
				{
					if(codedmessage[n] == 1)
						onecount++;
				}
				
				if(onecount == 0 || onecount == n7)
				{
					onecount = 0;
					
					printf("\n\nLa parola di codice c[%d] ricevuta e\' una parola di codice valida.\n", n7);
					
					printf("\nIl messaggio di codice che e\' stato trasmesso e\':\nm[%d] : [", k7);
						for(i = 0; i < k7; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != k7-1)
								printf("\t");
						}
						printf("]");
						
						printf("\n\nI bit di parita\' sono:\np[%d] : [", n7-k7);
						for(i = n7-m7; i < n7; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != n7-1)
								printf("\t");
						}
						printf("]\n");
				}
				
				else if(onecount < m7)
				{
					printf("\n\nLa parola di codice c[%d] ricevuta non e\' una parola di codice valida, in quanto ha un peso di Hamming W_h_min < 3.\n", n7);
					printf("\nE\' dunque possibile che sia stato commesso piu\' di un errore durante la trasmissione o la ricezione di c[%d].\n", n7);
					printf("\nMediante l\'utilizzo della codifica di Hamming e\' possibile correggere un solo errore sulla parola di codice ricevuta.", n7);
				}
				
				else
				{
					stop = 0;
					onecount = 0;
					syndcount = 0;
					syndromeindex = 0;
					
					printf("\n\nLa parola di codice c[%d] ricevuta potrebbe presentare un errore.\n", n7);
					printf("\nSe presente, e\' possibile correggere questo errore mediante l\'utilizzo della matrice di controllo di parita\' H[%d][%d]", n7, n7, m7);
					printf("\n\nSi tenta la correzione della parola di codice c[%d].\n", n7);
					
					printf("\nLa trasposta della matrice di controllo di parita\' che verra\' utilizzata per la correzione e\' la matrice H[%d][%d]:\n", n7, m7);
					for (n = 0; n < n7; n++)
    				{
    					printf("[");
    					for (m = 0; m < m7; m++)
   		 				{
    						printf("%d", Ht_7[n][m]);
    						if(m != m7-1)
								printf("\t");
						}
						printf("]");
						printf("\n");
					}
					
					//Calcolo della sindrome[m7], come codedmessage[n7]*Ht_7[n7][m7]
					for(m = 0; m < m7; m++)
					{
						for(n = 0; n < n7; n++)
						{
							syndrome[m] ^= codedmessage[n] * Ht_7[n][m];
						}
						
						if(syndrome[m] == 0)
							syndcount++;
						
						if(syndcount == m7)
							stop = 1;
					}

					printf("\nDal prodotto c[%d]*H[%d][%d] si ottiene il vettore sindrome: \ns[%d] = [", n7, n7, m7, m7);
					for(m = 0; m < m7; m++)
					{
						printf("%d", syndrome[m]);
						if (m != m7-1)
							printf("\t");
					}
					printf("]");
					
					if(stop == 1)
					{
						printf("\n\nIl vettore sindrome s[%d] risulta essere nullo.\n", m7);
						printf("\nLa parola di codice c[%d] non presenta alcun errore, quindi e\' una parola di codice valida.\n", n7);
						
						printf("\nIl messaggio di codice che e\' stato trasmesso senza errore e\':\nm[%d] : [", k7);
						for(i = 0; i < k7; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != k7-1)
								printf("\t");
						}
						printf("]");
						
						printf("\n\nI bit di parita\' sono:\np[%d] : [", n7-k7);
						for(i = n7-m7; i < n7; i++)
						{
							printf("%d", codedmessage[i]);
							if (i != n7-1)
								printf("\t");
						}
						printf("]");
						printf("\n\n");
						
						break;
					}
					
					for(n = 0; n < n7; n++)
					{
						for(m = 0; m < m7; m++)
						{
							if((syndrome[m] ^ Ht_7[n][m]) == 0)
								zerocount++;
						}
						
						syndromeindex = n;
						
						if(zerocount == m7)
							break;
						else
							zerocount = 0;
					}
					
					for(n = 0; n < n7; n++)
						if(n == syndromeindex)
							error[n] = 1;
						else
							error[n] = 0;
							
					printf("\n\nIl vettore di errore e[%d] ottenuto e\':\ne[%d] = [", n7, n7);
					for(n = 0; n < n7; n++)
					{
						printf("%d", error[n]);
						if (n != n7-1)
							printf("\t");
					}
					printf("]");
					
					for(n = 0; n < n7; n++)
						correctedcodedmessage[n] = codedmessage[n];
					
					for(n = 0; n < n7; n++)
					{
						if(n == syndromeindex)
							correctedcodedmessage[n] ^= error[n];
					}
					
					printf("\n\nLa parola di codice c[%d], prima della correzione, e\':\nc[%d] = [", n7, n7);
					for(n = 0; n < n7; n++)
					{
						printf("%d", codedmessage[n]);
						if (n != n7-1)
							printf("\t");
					}
					printf("]");
					
					printf("\n\nLa parola di codice c[%d], dopo la correzione, e\':\nc_c[%d] = [", n7, n7);
					for(n = 0; n < n7; n++)
					{
						printf("%d", correctedcodedmessage[n]);
						if (n != n7-1)
							printf("\t");
					}
					printf("]");
					
					printf("\n\nIl messaggio di codice che e\' stato trasmesso senza errore e\':\nm[%d] : [", k7);
					for(i = 0; i < k7; i++)
					{
						printf("%d", correctedcodedmessage[i]);
						if (i != k7-1)
							printf("\t");
					}
					printf("]");
						
					printf("\n\nI bit di parita\' sono:\np[%d] : [", n7-k7);
					for(i = n7-m7; i < n7; i++)
					{
						printf("%d", correctedcodedmessage[i]);
						if (i != n7-1)
							printf("\t");
					}
					printf("]");
					
					printf("\n\n");
				}
			}
			
			printf("\n\n");
			system("PAUSE");
		}
	}
	
	system("PAUSE");
	return 0;
}
