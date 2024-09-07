#include "adresse2tete.h"

int main() {
    char premierePartie[9], deuxiemePartie[9], troisiemePartie[9], quatriemePartie[9];
    char premiereM[9], deuxiemeM[9], troisiemeM[9], quatriemeM[9];
    
    char valiny1[9], valiny2[9], valiny3[9], valiny4[9];
    
    int A = 0, B = 0, C = 0, D = 0;
    int M1 = 0, M2 = 0, M3 = 0, M4 = 0;

    // Entrer les valeurs
    entrez_ip(premierePartie, deuxiemePartie, troisiemePartie, quatriemePartie, &A, &B, &C, &D);
     entre_MSR( premiereM,  deuxiemeM, troisiemeM,  quatriemeM,
                 &M1, &M2,  &M3,  &M4) ;
    calcul_reseau(premierePartie,  deuxiemePartie, troisiemePartie,  quatriemePartie, 
                    premiereM,  deuxiemeM,  troisiemeM, quatriemeM,
                    valiny1,  valiny2,  valiny3,  valiny4);
     affichage_reseau_Decimale(valiny1, valiny2, valiny3, valiny4) ;     
     affichage_brodkast (valiny1, valiny2, valiny3, valiny4);         
                    
        return 0;
	}
 
	
	void entrez_ip(char* premierePartie, char* deuxiemePartie, char* troisiemePartie, char* quatriemePartie, 
                int* A, int* B, int* C, int* D) {
    printf("Entrez l'adresse IP (format xxx.xxx.xxx.xxx) : ");
    scanf("%d.%d.%d.%d", A, B, C, D);

    // Convertir chaque octet en chaîne binaire
    for (int i = 7; i >= 0; i--) {
        premierePartie[7 - i] = (*A & (1 << i)) ? '1' : '0';
        deuxiemePartie[7 - i] = (*B & (1 << i)) ? '1' : '0';
        troisiemePartie[7 - i] = (*C & (1 << i)) ? '1' : '0';
        quatriemePartie[7 - i] = (*D & (1 << i)) ? '1' : '0';
    }
    premierePartie[8] = '\0';
    deuxiemePartie[8] = '\0';
    troisiemePartie[8] = '\0';
    quatriemePartie[8] = '\0';
}

// Fonction pour entrer le Mask Sous Réseau
void entre_MSR(char* premiereM, char* deuxiemeM, char* troisiemeM, char* quatriemeM,
                int* M1, int* M2, int* M3, int* M4) {
    printf("Entrez le Mask Sous Réseau (format xxx.xxx.xxx.xxx) : ");
    scanf("%d.%d.%d.%d", M1, M2, M3, M4);

    // Convertir chaque octet en chaîne binaire
    for (int i = 7; i >= 0; i--) {
        premiereM[7 - i] = (*M1 & (1 << i)) ? '1' : '0';
        deuxiemeM[7 - i] = (*M2 & (1 << i)) ? '1' : '0';
        troisiemeM[7 - i] = (*M3 & (1 << i)) ? '1' : '0';
        quatriemeM[7 - i] = (*M4 & (1 << i)) ? '1' : '0';
    }
    premiereM[8] = '\0';
    deuxiemeM[8] = '\0';
    troisiemeM[8] = '\0';
    quatriemeM[8] = '\0';
}

// Fonction pour calculer le réseau
void calcul_reseau(char* premierePartie, char* deuxiemePartie, char* troisiemePartie, char* quatriemePartie, 
                   char* premiereM, char* deuxiemeM, char* troisiemeM, char* quatriemeM,
                   char* valiny1, char* valiny2, char* valiny3, char* valiny4) {
    for (int i = 0; i < 8; i++) {
        valiny1[i] = (premierePartie[i] == '1' && premiereM[i] == '1') ? '1' : '0';
        valiny2[i] = (deuxiemePartie[i] == '1' && deuxiemeM[i] == '1') ? '1' : '0';
        valiny3[i] = (troisiemePartie[i] == '1' && troisiemeM[i] == '1') ? '1' : '0';
        valiny4[i] = (quatriemePartie[i] == '1' && quatriemeM[i] == '1') ? '1' : '0';
    }
    valiny1[8] = '\0';
    valiny2[8] = '\0';
    valiny3[8] = '\0';
    valiny4[8] = '\0';
}

// Fonction pour convertir une chaîne binaire en décimal
int binaire_en_decimal(const char* binaire) {
    int decimal = 0;
    while (*binaire) {
        decimal = (decimal << 1) + (*binaire++ - '0');
    }
    return decimal;
}

// Fonction pour afficher le réseau en décimal
void affichage_reseau_Decimale(char* valiny1, char* valiny2, char* valiny3, char* valiny4) {
    int decimal1 = binaire_en_decimal(valiny1);
    int decimal2 = binaire_en_decimal(valiny2);
    int decimal3 = binaire_en_decimal(valiny3);
    int decimal4 = binaire_en_decimal(valiny4);

    printf("adresse reseau : %d.%d.%d.%d\n", decimal1, decimal2, decimal3, decimal4);
}

void affichage_brodkast ( char* valiny1, char* valiny2, char* valiny3, char* valiny4)
{
	  int decimal1 = binaire_en_decimal(valiny1);
    int decimal2 = binaire_en_decimal(valiny2);
    int decimal3 = binaire_en_decimal(valiny3);
    int decimal4 = binaire_en_decimal(valiny4);
	
	void change( int *value )
	{
		if ( *value == 0 )
		{
			*value = 255 ;
			}
		
		}
	change (&decimal1);
	change (&decimal2);
	change (&decimal3);
	change (&decimal4);
	
	    printf("adresse brodcast : %d.%d.%d.%d\n", decimal1, decimal2, decimal3, decimal4);

	}

