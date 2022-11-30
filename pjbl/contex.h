#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  Zodiaco,
  Nao
} pertence;

typedef struct {
  double graus_quadrados;
  char estrela[20];
  char nome[20];
  char apelido[20];
  pertence conjunto;
} type_const;

double media(double a[], int n);
void medConst(type_const *arr);
void mainStar(type_const *arr);
void cleanBuffer();
bool verificacao(int args);
bool lerTxt(char *filename, type_const *arr);
bool gravarBin(char *filename, type_const *data, int total);
type_const *lerBin(char *filename, int *total);
bool gravarTxt(char *filename, type_const *data, int total);