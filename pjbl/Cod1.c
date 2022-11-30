#include "contex.h"

int main(int argc, char *argv[]) {
	
   	if (!verificacao(argc)) return 1;
	char *in_line = argv[1];
	char *out_line = argv[2];
	type_const *pont_const;
	pont_const = malloc(sizeof(type_const) * 20);

  if (lerTxt(in_line, pont_const)) {
		printf("Leitura concluida com sucesso.\n", in_line);
	}
  else {
		printf("Nao foi possivel ler este arquivo.\n");
		return 1;
	}
	if (gravarBin(out_line, pont_const, 20)) {
		printf("Escrita concluida com sucesso.\n", in_line, out_line);
	}
  else {
		printf("Nao foi possivel escrever este arquivo.\n");
		return 1;
	}
	free(pont_const);
	return 0;
}