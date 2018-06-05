#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define lim 20 // Constante limite que informa o número máximo para cadastro de restaurantes e pratos
FILE *restaurante; // Ponteiro do tipo FILE (arquivo)
FILE *prato; // Ponteiro do tipo FILE (arquivo)

int num; // Variável que armazena a opção digitada pelo usuário no menu principal
char vet[lim][100];

char vetp[lim][100];

void menu(void);
void menuvolte(void);
void consulta_restaurante(void);
void consulta_prato(void);
void pesquisa_restaurante(void);
void pesquisa_prato(void);
void menuadm(void);
void cadastrar_restaurante(void);
void cadastrar_prato(void);
void excluir_restaurante(void);
void excluir_prato(void);
void editar_restaurante(void);
void editar_prato(void);
void restaurante_vazio(void);
void prato_vazio(void);
void consulta_rest_vazio(void);
void consulta_prato_vazio(void);
void editar_rest_vazio(void);
void editar_prato_vazio(void);
void ler_restaurante(void);
void ler_prato(void);
void escrever_restaurante(void);
void escrever_prato(void);
void edicao_restaurante(void);
void edicao_prato(void);

// Função principal
int main() {
	setlocale(LC_ALL,"");
	ler_restaurante();
	ler_prato();
	while (num != 6) {
		menu();
		scanf("%i",&num);
		switch (num) {
			case 1:
				pesquisa_restaurante();
				break;
			case 2:
				pesquisa_prato();
				break;
			case 3:
				consulta_rest_vazio();
				break;
			case 4:
				consulta_prato_vazio();
				break;
			case 5:
				menuadm();
				break;
			default:
				system("cls");
				break;
		}
	}

	if (num == 6) {
		system("cls");
		menuvolte();
	}

	system("pause");
	return 0;
}

// Função que fará a leitura do arquivo restaurante.txt e armazenará as informações em variáveis
void ler_restaurante(void) {
	int c;

	restaurante = fopen("restaurante.txt", "r");
	if (restaurante == NULL) {
		printf("\n Arquivo 'restaurante.txt' não encontrado!\n\n");
		system("pause");
		exit(0);
	}
	for (c=0; c<lim; c++) {
		fscanf(restaurante, " %[^\n]", vet[c]);
	}
	fclose(restaurante);
	return;
}

// Função que fará a leitura do arquivo prato.txt e armazenará as informações em variáveis
void ler_prato(void) {
	int c;

	prato = fopen("prato.txt", "r");
	if (prato == NULL) {
		printf("\n Arquivo 'prato.txt' não encontrado!\n\n");
		system("pause");
		exit(0);
	}
	for (c=0; c<lim; c++) {
		fscanf(prato, " %[^\n]", vetp[c]);
	}
	fclose(prato);
	return;
}

// Função do menu principal
void menu(void) {
	printf ("-----------------------------------------------------------------------------------------------------------------------\n");
	printf ("                                        SISTEMA DE CADASTRO DE RESTAURANTES                                            \n");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n\n");
	printf("        0000\n");
	printf("        00_0\n");
	printf("        0_00\n");
	printf("        00000                                     (  )   (   )  )                     _ . - - -- .. _\n");
	printf("       0_____0                                     ) (   )  (  (                  .-'   o  _  O   () `'-_\n");
	printf("      00_____00                                    ( )  (    ) )                 (   o    (_)    o   0   )\n");
	printf("     00~~0000000      _____                        ____________                  |`' °°° __    __ °°° ''`|\n");
	printf("     00~~0000000     |'.-.'|                      <____________> ___             |  o      `````.     () |\n");
	printf("     0~~~~~~~~~0     |`````|                      |            |/ _ |            | O  . ()   o     O  .  |\n");
	printf("     0~~~~~~~~~0     |     |                      |              | | |       ,.--|              ()       |--.,\n");
	printf("     0~~~~~~~~~0      `-.-'           ____        |              |_| |    .'`    ;   o '  0         0  o ;     `'.\n");
	printf("     0~~~~~~~~~0        |    --     .'   //     __|            _____/    '.       `'  °°° __    __°°°  '´        .'\n");
	printf("     000~0000000      __|__  |K----;    |  |   |  |___________|   |        `'-..__         `````           __..-'`\n");
	printf("     00000000000     `-----` --     '.___//    |__________________|               `''---,,,_______,,,---''`\n\n");
	printf (" 1 - Pesquisar Restaurante\n");
	printf (" 2 - Pesquisar Prato\n");
	printf (" 3 - Consultar Restaurante\n");
	printf (" 4 - Consultar Prato\n");
	printf (" 5 - Acesso Administrativo\n");
	printf (" 6 - Sair\n\n");
	printf (" Opção: ");
	return;
}

// Função para realizar a pesquisa de restaurantes pela primeira letra do nome
void pesquisa_restaurante(void) {
	int c,enc;
	char op,letra[2],str[14],nome[14] = "Restaurante ";

	system("cls");
	enc = 0;
	printf ("-----------------------------------------------------------------------------------------------------------------------\n");
	printf ("                                               PESQUISA RESTAURANTE                                                    \n");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n\n");

	printf ("Informe a primeira letra do nome (Maiúscula): ");
	scanf ("%s", letra);
	strcat(nome, letra);

	for (c=0; c<lim; c++) {
		if (strlen(vet[c]) != 0) {
			strncpy(str, vet[c], 13);
			if (strcmp(str,nome) == 0) {
				printf("\n %i - ", c+1);
				printf("%s", vet[c]);
				enc = 1;
			}
		}
	}

	if (enc == 0) {
		printf ("\n ---------------------------------\n");
		printf ("    RESTAURANTE NÃO ENCONTRADO!   \n");
		printf (" ---------------------------------");
	}

	printf ("\n\n Deseja pesquisar mais restaurantes? [s/n]: ");
	scanf ("%s",&op);
	system("cls");

	if (op == 's') {
		pesquisa_restaurante();
	}
	return;
}

// Função para realizar a pesquisa de pratos pela primeira letra do nome
void pesquisa_prato(void) {
	int c,enc;
	char op,letra[2],str[8],nome[8] = "Prato ";

	system("cls");
	enc = 0;
	printf ("-----------------------------------------------------------------------------------------------------------------------\n");
	printf ("                                                  PESQUISA PRATO                                                       \n");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n\n");

	printf ("Informe a primeira letra do nome (Maiúscula): ");
	scanf ("%s", letra);
	strcat(nome, letra);

	for (c=0; c<lim; c++) {
		if (strlen(vetp[c]) != 0) {
			strncpy(str, vetp[c], 7);
			if (strcmp(str,nome) == 0) {
				printf("\n %i - ", c+1);
				printf("%s", vetp[c]);
				enc = 1;
			}
		}
	}

	if (enc == 0) {
		printf ("\n ---------------------------\n");
		printf ("    PRATO NÃO ENCONTRADO!   \n");
		printf (" ---------------------------");
	}

	printf ("\n\n Deseja pesquisar mais pratos? [s/n]: ");
	scanf ("%s",&op);
	system("cls");

	if (op == 's') {
		pesquisa_prato();
	}
	return;
}

// Função para realizar a consulta de restaurantes
void consulta_restaurante(void) {
	int op,c;
	system("cls");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n");
	printf ("                                                    RESTAURANTES                                                       \n");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n\n");

	for (c=0; c<lim; c++) {
		if (strlen(vet[c]) != 0) {
			printf("\n %i - ",c+1);
			printf("%s",vet[c]);
		}
	}

	printf("\n\n [1] - Voltar: ");
	scanf("%i",&op);
	if (op == 1) {
		system("cls");
	} else {
		consulta_restaurante();
	}
	return;
}

// Função que verifica se há algum restaurante cadastrado no menu principal
void consulta_rest_vazio(void) {
	int c, vazio = 0;
	char op;

	for (c=0; c<lim; c++) {
		if (strlen(vet[c]) == 0) {
			vazio += 1;
		}
	}
	if (vazio == lim) {
		printf("\n Não há restaurantes");
		printf("\n Deseja cadastrar algum restaurante? [s/n]: ");
		scanf("%s",&op);
		if (op == 's') {
			system("cls");
			cadastrar_restaurante();
		} else {
			system("cls");

		}
	} else {
		consulta_restaurante();
	}
	return;
}

// Função para realizar a consulta de pratos
void consulta_prato(void) {
	int op,c;
	system("cls");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n");
	printf ("                                                      PRATOS                                                           \n");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n\n");

	for (c=0; c<lim; c++) {
		if (strlen(vetp[c]) != 0) {
			printf("\n %i - ",c+1);
			printf("%s",vetp[c]);
		}
	}

	printf("\n\n [1] - Voltar: ");
	scanf("%i",&op);
	if (op == 1) {
		system("cls");
	} else {
		consulta_prato();
	}
	return;
}

// Função que verifica se há algum prato cadastrado no menu principal
void consulta_prato_vazio(void) {
	int c, vazio = 0;
	char op;

	for (c=0; c<lim; c++) {
		if (strlen(vetp[c]) == 0) {
			vazio += 1;
		}
	}
	if (vazio == lim) {
		printf("\n Não há pratos");
		printf("\n Deseja cadastrar algum prato? [s/n]: ");
		scanf("%s",&op);
		if (op == 's') {
			system("cls");
			cadastrar_prato();
		} else {
			system("cls");
		}
	} else {
		consulta_prato();
	}
	return;
}

// Função que exibe 'volte sempre' ao encerrar o programa
void menuvolte(void) {
	printf ("-----------------------------------------------------------------------------------------------------------------------\n");
	printf ("                                                    VOLTE SEMPRE!                                                      \n");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n");
	return;
}

// Função que exibe o menu administrativo
void menuadm(void) {
	int op;
	system("cls");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n");
	printf ("                                                ACESSO ADMINISTRATIVO                                                  \n");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n\n");
	printf (" 1 - Cadastrar Restaurante\n");
	printf (" 2 - Cadastrar Prato\n");
	printf (" 3 - Excluir Restaurante\n");
	printf (" 4 - Excluir Prato\n");
	printf (" 5 - Editar Restaurante\n");
	printf (" 6 - Editar Prato\n");
	printf (" 7 - Voltar\n\n");
	printf (" Opção: ");
	scanf("%i",&op);

	switch (op) {
		case 1:
			cadastrar_restaurante();
			break;
		case 2:
			cadastrar_prato();
			break;
		case 3:
			restaurante_vazio();
			break;
		case 4:
			prato_vazio();
			break;
		case 5:
			editar_rest_vazio();
			break;
		case 6:
			editar_prato_vazio();
			break;
		case 7:
			system("cls");
			break;
		default:
			menuadm();
			break;
	}
	return;
}

// Função para cadastro de restaurantes
void cadastrar_restaurante(void) {
	int c;
	char nome[20], numero[20], tel[20], nomec[100] = "Restaurante ", resp;

	system("cls");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n");
	printf ("                                              CADASTRO DE RESTAURANTES                                                 \n");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n\n");

	printf(" Nome do restaurante: ");
	scanf(" %[^\n]", nome);
	printf("\n Número do restaurante: ");
	scanf("%s", numero);
	printf("\n Telefone do restaurante: ");
	scanf(" %[^\n]", tel);

	strcat(nomec, nome);
	strcat(nomec, ", ");
	strcat(nomec, numero);
	strcat(nomec, " Tel: ");
	strcat(nomec, tel);

	for (c=0; c<lim; c++) {
		if (strlen(vet[c]) == 0) {
			strncpy(vet[c], nomec,100);
			printf ("\n --------------------------\n");
			printf ("   RESTAURANTE ADICIONADO   \n");
			printf (" --------------------------\n\n");
			restaurante = fopen("restaurante.txt", "a");
			fprintf(restaurante, "\n");
			fprintf(restaurante, vet[c]);
			fclose(restaurante);
			c = lim;
		}
	}

	printf(" Deseja cadastrar mais restaurantes? [s/n]: ");
	scanf ("%s",&resp);
	if (resp == 's') {
		system("cls");
		cadastrar_restaurante();
	} else {
		system("cls");
		menuadm();
	}
	return;
}

// Função para cadastro de pratos
void cadastrar_prato(void) {
	int c;
	char nome[20], preco[20], nomec[100] = "Prato ", resp;

	system("cls");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n");
	printf ("                                               CADASTRO DE PRATOS                                                      \n");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n\n");

	printf(" Nome do prato: ");
	scanf(" %[^\n]", nome);
	printf("\n Preço do prato R$: ");
	scanf("%s", preco);

	strcat(nomec, nome);
	strcat(nomec, ", por R$ ");
	strcat(nomec, preco);

	for (c=0; c<lim; c++) {
		if (strlen(vetp[c]) == 0) {
			strncpy(vetp[c], nomec,100);
			printf ("\n -------------------\n");
			printf ("   PRATO ADICIONADO   \n");
			printf (" -------------------\n\n");
			prato = fopen("prato.txt", "a");
			fprintf(prato, "\n");
			fprintf(prato, vetp[c]);
			fclose(prato);
			c = lim;
		}
	}

	printf(" Deseja cadastrar mais pratos? [s/n]: ");
	scanf ("%s",&resp);
	if (resp == 's') {
		system("cls");
		cadastrar_prato();
	} else {
		system("cls");
		menuadm();
	}
	return;
}

// Função para excluir um restaurante
void excluir_restaurante(void) {
	int c,c1,resp;
	char op;
	system("cls");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n");
	printf ("                                                  EXCLUIR RESTAURANTE                                                  \n");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n\n");

	for (c=0; c<lim; c++) {
		if (strlen(vet[c]) != 0) {
			printf("\n %i - ",c+1);
			printf("%s",vet[c]);
		}
	}

	printf ("\n\nDeseja excluir qual restaurante? ");
	scanf ("%i",&resp);

	for (c=0; c<lim; c++) {
		if (resp  == c) {
			strcpy(vet[c-1], "");
			printf ("\n --------------------------\n");
			printf ("    RESTAURANTE EXCLUÍDO   \n");
			printf (" --------------------------\n\n");
			escrever_restaurante();
		}
	}

	printf(" Deseja excluir mais restaurantes? [s/n]: ");
	scanf ("%s",&op);

	if (op == 's') {
		restaurante_vazio();
	} else {
		system("cls");
		menuadm();
	}
	return;
}

// Função que faz a escrita dos dados referente aos restaurantes no arquivo restaurante.txt
void escrever_restaurante(void) {
	int c;

	restaurante = fopen("restaurante.txt", "w");
	for (c=0; c<lim; c++) {
		if (strlen(vet[c]) != 0) {
			fprintf(restaurante, "\n");
			fprintf(restaurante, vet[c]);			
		}
	}
	fclose(restaurante);
	return;
}

// Função que faz a escrita dos dados referente aos pratos no arquivo prato.txt
void escrever_prato(void) {
	int c;

	prato = fopen("prato.txt", "w");
	for (c=0; c<lim; c++) {
		if (strlen(vetp[c]) != 0) {
			fprintf(prato, "\n");
			fprintf(prato, vetp[c]);			
		}
	}
	fclose(prato);
	return;
}

// Função que verifica se há algum restaurante cadastrado no menu administrativo
void restaurante_vazio(void) {
	int c, vazio = 0;
	char op;

	for (c=0; c<lim; c++) {
		if (strlen(vet[c]) == 0) {
			vazio += 1;
		}
	}
	if (vazio == lim) {
		printf("\n Não há restaurantes");
		printf("\n\n Deseja cadastrar algum restaurante? [s/n]: ");
		scanf("%s",&op);
		if (op == 's') {
			system("cls");
			cadastrar_restaurante();
		} else {
			system("cls");
			menuadm();
		}
	} else {
		excluir_restaurante();
	}
	return;
}

// Função para excluir um prato
void excluir_prato(void) {
	int c,resp;
	char op;
	system("cls");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n");
	printf ("                                                    EXCLUIR PRATO                                                      \n");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n\n");

	for (c=0; c<lim; c++) {
		if (strlen(vetp[c]) != 0) {
			printf("\n %i - ",c+1);
			printf("%s",vetp[c]);
		}
	}

	printf ("\n\n Deseja excluir qual prato? ");
	scanf ("%i",&resp);

	for (c=0; c<lim; c++) {
		if (resp  == c) {
			strcpy(vetp[c-1], "");
			printf ("\n --------------------\n");
			printf ("    PRATO EXCLUÍDO   \n");
			printf (" --------------------\n\n");
			escrever_prato();
		}
	}

	printf(" Deseja excluir mais pratos? [s/n]: ");
	scanf ("%s",&op);

	if (op == 's') {
		prato_vazio();
	} else {
		system("cls");
		menuadm();
	}
	return;
}

// Função que verifica se há algum prato cadastrado no menu administrativo
void prato_vazio(void) {
	int c, vazio = 0;
	char op;

	for (c=0; c<lim; c++) {
		if (strlen(vetp[c]) == 0) {
			vazio += 1;
		}
	}
	if (vazio == lim) {
		printf("\n Não há pratos");
		printf("\n\n Deseja cadastrar algum prato? [s/n]: ");
		scanf("%s",&op);
		if (op == 's') {
			system("cls");
			cadastrar_prato();
		} else {
			system("cls");
			menuadm();
		}
	} else {
		excluir_prato();
	}
	return;
}

// Função que edita um restaurante
void editar_restaurante(void) {
	int c, op;
	char nome[20], numero[20], tel[20], nomec[100] = "Restaurante ", resp;

	system("cls");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n");
	printf ("                                                 EDITAR RESTAURANTE                                                    \n");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n");

	for (c=0; c<lim; c++) {
		if (strlen(vet[c]) != 0) {
			printf("\n %i - ",c+1);
			printf("%s",vet[c]);
		}
	}

	printf("\n\n Deseja editar qual restaurante? ");
	scanf ("%i",&op);

	for (c=0; c<lim; c++) {
		if (op - 1 == c) {
			printf("\n Novo nome do restaurante: ");
			scanf(" %[^\n]", nome);
			printf("\n Novo número do restaurante: ");
			scanf("%s", numero);
			printf("\n Novo telefone do restaurante: ");
			scanf(" %[^\n]", tel);

			strcat(nomec, nome);
			strcat(nomec, ", ");
			strcat(nomec, numero);
			strcat(nomec, " Tel: ");
			strcat(nomec, tel);

			strncpy(vet[c], nomec,100);
			printf ("\n ----------------\n");
			printf ("   EDIÇÃO FEITA   \n");
			printf (" ----------------\n\n");
			edicao_restaurante();			
		}
	}
	printf(" Deseja editar mais restaurantes? [s/n]: ");
	scanf ("%s",&resp);

	if (resp == 's') {
		system("cls");
		editar_restaurante();
	} else {
		system("cls");
		menuadm();
	}
	return;
}

// Função que escreve os dados editados no arquivo restaurante.txt
void edicao_restaurante(void) {
	int c;

	restaurante = fopen("restaurante.txt", "w");
	for (c=0; c<lim; c++) {
		if (strlen(vet[c]) != 0) {
			fprintf(restaurante, "\n");
			fprintf(restaurante, vet[c]);			
		}
	}
	fclose(restaurante);
	return;
}

// Função que verifica se há algum restaurante para ser editado no menu administrativo
void editar_rest_vazio(void) {
	int c, vazio = 0;
	char op;

	for (c=0; c<lim; c++) {
		if (strlen(vet[c]) == 0) {
			vazio += 1;
		}
	}
	if (vazio == lim) {
		printf("\n Não há restaurantes");
		printf("\n\n Deseja cadastrar algum restaurante? [s/n]: ");
		scanf("%s",&op);
		if (op == 's') {
			system("cls");
			cadastrar_restaurante();
		} else {
			system("cls");
			menuadm();
		}
	} else {
		editar_restaurante();
	}
	return;
}

// Função que edita um prato
void editar_prato(void) {
	int c, op;
	char nome[20], preco[20], nomec[100] = "Prato ", resp;

	system("cls");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n");
	printf ("                                                  EDITAR PRATO                                                         \n");
	printf ("-----------------------------------------------------------------------------------------------------------------------\n");

	for (c=0; c<lim; c++) {
		if (strlen(vetp[c]) != 0) {
			printf("\n %i - ",c+1);
			printf("%s",vetp[c]);
		}
	}

	printf("\n\n Deseja editar qual prato? ");
	scanf ("%i",&op);

	for (c=0; c<lim; c++) {
		if (op - 1 == c) {
			printf("\n Novo nome do prato: ");
			scanf(" %[^\n]", nome);
			printf("\n Novo preço do prato R$: ");
			scanf("%s", preco);

			strcat(nomec, nome);
			strcat(nomec, ", por R$ ");
			strcat(nomec, preco);

			strncpy(vetp[c], nomec,100);
			printf ("\n ----------------\n");
			printf ("   EDIÇÃO FEITA   \n");
			printf (" ----------------\n\n");
			edicao_prato();
		}
	}
	printf(" Deseja editar mais pratos? [s/n]: ");
	scanf ("%s",&resp);

	if (resp == 's') {
		system("cls");
		editar_prato();
	} else {
		system("cls");
		menuadm();
	}
	return;
}

// Função que escreve os dados editados no arquivo prato.txt
void edicao_prato(void) {
	int c;

	prato = fopen("prato.txt", "w");
	for (c=0; c<lim; c++) {
		if (strlen(vetp[c]) != 0) {
			fprintf(prato, "\n");
			fprintf(prato, vetp[c]);			
		}
	}
	fclose(prato);
	return;
}

// Função que verifica se há algum prato para ser editado no menu administrativo
void editar_prato_vazio(void) {
	int c, vazio = 0;
	char op;

	for (c=0; c<lim; c++) {
		if (strlen(vetp[c]) == 0) {
			vazio += 1;
		}
	}

	if (vazio == lim) {
		printf("\n Não há pratos");
		printf("\n\n Deseja cadastrar algum prato? [s/n]: ");
		scanf("%s",&op);
		if (op == 's') {
			system("cls");
			cadastrar_prato();
		} else {
			system("cls");
			menuadm();
		}
	} else {
		editar_prato();
	}
	return;
}
