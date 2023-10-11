
#include <stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

char lista[][100] = {};
int tamanho = -1;

void remover_item(int n){
	strcpy(lista[n], "");
	
	int i;
	for(i = n; i<=tamanho; i++){
		strcpy(lista[i], lista[i+1]);
	}
}

void inserirItem(){
	
	system("cls");
	
	char frase[100];
	printf("Insira o Item que deseja Inserir: ");
	gets(frase);
	fflush(stdin);
	
	strcpy(lista[tamanho + 1], frase);
	tamanho++;
	
	printf("\nItem Inserido com Sucesso!!!\n\n");
	system("pause");
	funcoes();
}

void removerItem(){
	
	system("cls");
	
	int item_rem;
	printf("Qual Item você deseja remover: ");
	scanf("%i", &item_rem);
	fflush(stdin);
	remover_item(item_rem -1);
	tamanho--;
	printf("\nItem Removido com Sucesso!!!\n\n");
	system("pause");
	funcoes();
}

void apresentarLista(){
	
	if(tamanho == -1){
		system("cls");
		printf("A lista está vazia, favor inserir os itens antes de apresentá-los...\n\n");
		system("pause");
		funcoes();
	}
	
	
	system("cls");
	printf("_____________Lista______________\n\n");
	printf("--------------------------------\n");
	int i;
	for(i=0; i<=tamanho; i++){
		printf("%i - %s\n", i+1, lista[i]);
		printf("--------------------------------\n\n");
	}

	
	
	
	system("pause");
	funcoes();
}


int funcoes() {
	system("cls");
	int valor;
	printf("Insira o Valor da função desejada: \n\n" , setlocale(LC_ALL,""));
	printf("\n--------------------------------\n");
	printf("1 - Inserir Item\n");
	printf("2 - Remover Item\n");
	printf("3 - Exibir Lista\n");
	printf("4 - Sair\n");
	printf("--------------------------------\n");
	
	printf("\nFunção desejada: ");
	scanf("%i", &valor );
	fflush(stdin);
	if (valor == 1){
		inserirItem();
	}
	if (valor == 2){
		removerItem();
	}
	if (valor == 3){
		apresentarLista();
	}
	if (valor == 4){
		exit(0);
	}
	if (valor != 1 || valor != 2 || valor != 3 || valor != 4){
		system("cls");
		printf("Insira um valor correspondente às funções (1-4)...\n\n");
		system("pause");
		funcoes();
	}
	return valor;
	
}

int main() { 
	
	funcoes();
	return 0;
}
