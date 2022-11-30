#include "contex.h"

int main(int argc, char *argv[]) {

    if (!verificacao(argc)) return 1;

	char *in_line = argv[1];
	char *out_line = argv[2];


	int total = 0;
	type_const *dados;

	dados = lerBin(in_line, &total);

	if (dados == NULL) {
		printf("Nao foi possivel ler este arquivo.\n", in_line);
		return 1;
	}
	printf("Leitura concluida com sucesso.\n", in_line);


	if (gravarTxt(out_line, dados, 20)) {
		printf("Escrita concluida com sucesso.\n", in_line);
	} else {
		printf("Nao foi possivel escrever este arquivo.\n", in_line);
		return 1;
	}
	
	
	int escolha;
	bool finalizar = false;

	do{
		puts("MENU:");
		puts(" 1. Mostrar Estrela Principal.");
		puts(" 2. Media Aritmetica de graus.");
		puts(" 0. Sair do programa.");

		puts("\nEscolha ");
		scanf("%d", &escolha);
		cleanBuffer();

		switch(escolha) {
		case 0:
			system("cls || clear");
			finalizar = true;
			break;
		case 1:
			system("cls || clear");
			mainStar(dados);
			break;
		case 2:
			system("cls || clear");
			medConst(dados);
			break;
		default:
			system("cls || clear");
			printf("\nEscolha invalida, digite novamente.\n\n");
		}
	}
	while (!finalizar);

	puts("\nPrograma encerrado.\n");

	free(dados); 
	return 0;
}