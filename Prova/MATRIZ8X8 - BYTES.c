#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

unsigned char formarByte(char c[8]){
  unsigned char byte = 0;
  unsigned short n;
  for(n=0; n<8; n++) {
  	byte = byte | c[n] << (7 - n);
  }

  return byte;
}

int main(){
  int i;
  unsigned int x;
  unsigned char *px;

  printf(" Imprimindo \n");
  unsigned char linha[8];

  linha[0] = 1;
  linha[1] = 0;
  linha[2] = 0;
  linha[3] = 1;
  linha[4] = 1;
  linha[5] = 0;
  linha[6] = 0;
  linha[7] = 1;

  unsigned char matrix[8][8];
  unsigned char vetor[8];
  int l = 0;

  int j;
  for(i = 0; i < 8; i++) {
  	for(j = 0; j < 8; j++) {
  		matrix[i][j] = (rand() % 2);
  	}
  }

  for(l = 0; l < 8; l++) {
  	vetor[l] = formarByte(matrix[l]);
  }

  for(l = 0; l < 8; l++) {
  	for(i = 0; i < 8; i++) {
  		printf("%d ", matrix[l][i]);
	}
  	printf(" = %d \n", vetor[l]);
  }

  unsigned char byte;
  byte = formarByte(linha);
  printf("\n byte: %d\n", byte);

  return 0;
}
