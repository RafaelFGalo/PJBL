#include "contex.h"


void cleanBuffer(){ 
    int cl;
    while( (cl = fgetc(stdin)) != EOF && cl != '\n' ){} 
}

bool verificacao(int args) {
  if (args < 1) {
    puts("O arquivo não foi passado como parâmetro.");
    return false;
  } else if (args == 2) {
    puts("Não há parâmetros o suficiente.");
    return false;
  } else if (args > 3) {
    puts("Informe somento dois parâmentros.");
    return false;
  }

  return true;
}

bool gravarBin(char *arquivo, type_const *data, int total) {
  FILE *file;
  file = fopen(arquivo, "wb");

  if (file == NULL) {
    puts("Não foi possível abrir o arquivo.");
    return false;
  }

  if (fwrite(&total, sizeof(int), 1, file) != 1)
    return false;

  if (fwrite(data, sizeof(type_const), total, file) != total)
    return false;

  if (fclose(file) == EOF)
    return false;

  return true;
}

bool lerTxt(char *arquivo, type_const *vet) {
  FILE *file;
  file = fopen(arquivo, "r");

  if (file == NULL) {
    puts("Arquivo não pode ser aberto!");
    return false;
  }
  char *query = "%lf, %20[^,], %20[^,], %20[^,], %d\n";
  int read = 0;
  int indice = 0;
  while (indice < 20) {
    read = fscanf(file, query, &vet[indice].graus_quadrados, &vet[indice].estrela, &vet[indice].nome, &vet[indice].apelido, &vet[indice].conjunto);

    if (read == 5) {
      indice++;
    }
  }

  if (fclose(file) == EOF) return false;
  return true;
}

type_const *lerBin(char *arquivo, int *total) {
  FILE *file;
  file = fopen(arquivo, "rb");

  if (file == NULL) {
    return NULL;
  }

  if (fread(total, sizeof(int), 1, file) != 1) {
    return NULL;
  }

  type_const *data = malloc(sizeof(type_const) * *total);

  if (fread(data, sizeof(type_const), *total, file) != *total) {
    free(data);
    return NULL;
  }

  if (fclose(file) == EOF) {
    free(data);
    return NULL;
  }

  return data;
}

bool gravarTxt(char *arquivo, type_const *data, int total) {
  FILE *file;
  file = fopen(arquivo, "w");

  if (file == NULL) {
    puts("Erro ao criar o arquivo!");
    return false;
  }

  for (int i = 0; i < total; i++) {
    fprintf(file, "%lf, %s, %s, %s, %d\n", data[i].graus_quadrados, data[i].estrela, data[i].nome, data[i].apelido, data[i].conjunto);

    if (ferror(file)) {
      puts("Erro ao escrever arquivo.\n");
      return false;
    }
  }

  fclose(file);
  
  return true;
}

void mainStar(type_const *vet) {

  int escolha=0;
  int i=0;
  puts("ESCOLHA A CONSTELACAO"); 
    for (int i = 0; i < 20; i++) {
      printf("%d. %s - %s\n",i+1, vet[i].nome, vet[i].apelido);
	}
  puts("0. Voltar");

  puts("\nEscolha: ");
  scanf("%d", &escolha);
  cleanBuffer();
	
	if (0 < escolha < 21) {
		system("cls || clear");
		puts("A estrela principal desta constelacao é:");
		printf("%s", vet[escolha-1].estrela);
		puts("\n\n");
		i++;
	} else if (escolha == 0 ) {
		system("cls || clear");
	} else {
		system("cls || clear");
		printf("\nEscolha invalida, digite novamente.\n\n");
	}
}

double media(double a[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++)
      sum += a[i];

  return (double)sum / n;
}

void medConst(type_const *vet) {
  double d_vet[20];
  int escolha, n;
  double med;
  
  puts("MEDIA DOS CONJUNTOS");
  puts("1. Zodiaco");
  puts("2. Outros");
  puts("3. Todos");
  puts("0. Voltar");

  puts("\nEscolha: ");
  scanf("%d", &escolha);
  cleanBuffer();
  
  switch (escolha) {
    case 0:
      system("cls || clear");
      break;
    case 1:
      system("cls || clear");
      for (int i = 0; i < 12; i++) {
        d_vet[i] = vet[i].graus_quadrados;
      }
      med = media(d_vet, 12);
      printf("Media de graus das constealções do Zodiaco e: %.1lf graus quadrados", med);
      puts("\n\n");
      break;
    case 2:
      system("cls || clear");
      for (int i = 12; i < 20; i++) {
        d_vet[i-12] = vet[i].graus_quadrados;
      }
      med = media(d_vet, 8);
      printf("Media de graus das outras constelacoes e: %.1lf graus quadrados", med);
      puts("\n\n");
      break;
    case 3:
      system("cls || clear");
      for (int i = 0; i < 20; i++) {
        d_vet[i] = vet[i].graus_quadrados;
      }
      med = media(d_vet, 20);
      printf("Media de graus de todas as constelacoes e: %.1lf graus quadrados", med);
      puts("\n\n");
      break;
    default:
      system("cls || clear");
      printf("\nEscolha invalida, digite novamente.\n\n");
      break;
  }
}