#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {

    int n_p; // Profundidade
    int n_l; // Linhas
    int n_c;  // Colunas

    printf(" Digite o tamanho da matriz 3D(Profundidade, linhas, colunas) ");
    printf("\nProfundidade: ");
    scanf("%d",&n_p);
    printf("\nLinhas: ");
    scanf("%d",&n_l);
    printf("\nColunas: ");
    scanf("%d",&n_c);

    int ***m = (int***) calloc((2 * n_p + 1),sizeof(int**));

    //alocando memoria
	printf("\nAlocando memoria ... \n");

    for(int p = 0; p < (2 * n_p + 1); p++){
        m[p] = (int**) calloc((2 * n_l + 1),sizeof(int*));
        for(int l = 0; l < (2 * n_l + 1); l++){
            m[p][l] = (int*) calloc((2 * n_c + 1),sizeof(int));
        }
    }

	printf("Preenchendo a matriz ... \n");

	// X2 / a2 + y2 / b2 + z2 / c2 <= 1 EQUA��O DA ELIPSOIDE
    for(int p = 0; p < (2 * n_p  + 1); p++){
        for(int l = 0; l < (2 * n_l + 1); l++){
            for(int c = 0; c < (2 * n_c + 1); c++){
            	double x = (double) (p - n_p);
            	double a = (double) n_p;
            	double y = (double) (l-n_l);
            	double b = (double) n_l;
            	double z = (double) (c-n_c);
            	double cz = (double) n_c;

				double valor = (x * x)/(a * a) + (y * y)/(b * b)+ (z * z)/(cz * cz);
				//Mostrar resultado do calc
				//printf("%lf ", valor);

				if (valor <= 1) {
					m[p][l][c] = 1;
				} else {
					m[p][l][c] = 0;
				}
			}
        }
    }

	int indice; // Qual parte do corte da elipse
	char plano; // Plano x,y,z

    printf("\nInforme o plano (x, y ou z) : ");
    scanf("%s",&plano);
    printf("\nInforme indice : ");
    scanf("%d",&indice);

	if(plano == 'x') {
        for(int y = 0; y < (2 * n_l + 1); y++){
            for(int z = 0; z < (2 * n_c + 1); z++){
            	printf("%d ", m[indice][y][z]);
			}
			printf("\n");
        }
	} else if (plano == 'y') {
		for(int x = 0; x < (2 * n_p + 1); x++){
            for(int z = 0; z < (2 * n_c + 1); z++){
            	printf("%d ", m[x][indice][z]);
			}
			printf("\n");
        }
	} else {
		for(int x = 0; x < (2 * n_p + 1); x++){
            for(int y = 0; y < (2 * n_l + 1); y++){
            	printf("%d ", m[x][y][indice]);
			}
			printf("\n");
        }
	}

	printf("\n Finalizando ....");

	return 0;
}
