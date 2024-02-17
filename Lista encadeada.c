#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	int valor;
	struct no *proximo;
}No;

void inserir_no_inicio(No **lista, int num)
{
	No *novo = malloc(sizeof(No));
	
	if(novo)
	{
		novo->valor = num;
		novo->proximo = *lista;
		*lista = novo;
	}
	else
	{
		printf("Falha ao alocar memoria");
	}
}

void inserir_no_fim(No **lista, int num)
{
	No *placeholder, *novo = malloc(sizeof(No));
	int i;
	
	if(novo)
	{
		novo->valor = num;
		novo->proximo = NULL;
		
		if(*lista == NULL)
		{
			*lista = novo;
		}
		else
		{
			placeholder = *lista;
			while(placeholder->proximo)
			{
				placeholder = placeholder->proximo;
			}
			placeholder->proximo = novo;
		}
	}
	else
	{
		printf("Falha ao alocar memoria");
	}
}

void inserir_no_meio(No **lista, int num, int anterior)
{
	No *placeholder, *novo = malloc(sizeof(No));
	
	if(novo)
	{
		novo->valor = num;
		
		if(*lista == NULL)
		{
			novo->proximo = NULL;
			*lista = novo;
		}
		else
		{
			placeholder = *lista;
			
			while(placeholder->valor != anterior && placeholder->proximo != NULL)
			{
				placeholder = placeholder->proximo;
			}
			novo->proximo = placeholder->proximo;
			placeholder->proximo = novo;
		}
	}
	else
	{
		printf("Erro ao alocar memoria");
	}
}

void inserir_ordenado(No **lista, int num)
{
	No *placeholder, *novo = malloc(sizeof(No));
	
	if(novo)
	{
		novo->valor = num;
		if(*lista == NULL)
		{
			novo->proximo = NULL;
			*lista = novo;
		}
		else if(novo->valor < (*lista)->valor)
		{
			novo->proximo = *lista;
			*lista = novo;
		}
		else
		{
			placeholder = *lista;
			while(placeholder->proximo && novo->valor > placeholder->proximo->valor)
			{
				placeholder = placeholder->proximo;
			}
			novo->proximo = placeholder->proximo;
			placeholder->proximo = novo;
		}
	}
	else
	{
		printf("Erro ao alocar memoria");
	}
}

void imprimir(No *no)
{
	printf("=======LISTA=======\n");
	
	while(no)
	{
		printf("%d ", no->valor);
		no = no->proximo;
	}
	printf("\n=======FIM========\n");
}

No* remover_item(No **lista, int num)
{
	No *remover = NULL, *placeholder;
	
	if(*lista)
	{
		if((*lista)->valor == num)
		{
			remover =  *lista;
			*lista = remover->proximo;	
		}
		else
		{
			placeholder = *lista;
			
			while(placeholder->proximo && placeholder->proximo->valor != num)
			{
				placeholder = placeholder->proximo;
			}
			
			if(placeholder->proximo)
			{
				remover = placeholder->proximo;
				placeholder->proximo = remover->proximo;
			}
		}
	}
	
	return remover;
}

No *buscar(No **lista, int num)
{
	No *no = NULL, *placeholder;
	
	placeholder = *lista;
	while(placeholder && placeholder->valor != num)
	{
		placeholder = placeholder->proximo;
	}
	
	if(placeholder)
	{
		no = placeholder;
	}
	
	return no;
}

int main(void)
{
	int opcao, valor, anterior;
	No *lista = NULL, *remover;
	
	do
	{
		system("cls");
		printf("[0] - Sair\t\t[1] - Inserir(inicio)\n[2] - Inserir(meio)\t[3] - Inserir(fim)\n[4] - Imprimir\t\t[5] - Inserir Ordenado\n[6] - Remover\t\t[7] - Buscar valor");
		printf("\nDigite o valor desejado: ");
		scanf("%d", &opcao);
		
		if(opcao != 0 && opcao != 4)
		{
			printf("Digite um valor: ");
			scanf("%d", &valor);
		}
		
		switch(opcao)
		{
			case 0:
				return 0;
			break;
			
			case 1:
				inserir_no_inicio(&lista, valor);
			break;
			
			case 2:
				imprimir(lista);
				
				printf("Digite o valor que está depois da posicao onde voce deseja inserir: ");
				scanf("%d", &anterior);
				
				inserir_no_meio(&lista, valor, anterior);
			break;
			
			case 3:
				inserir_no_fim(&lista,valor);
			break;
			
			case 4:
				imprimir(lista);
				printf("\n\n");
				system("pause");
			break;
			
			case 5:
				inserir_ordenado(&lista, valor);
			break;
			
			case 6:
				remover = remover_item(&lista, valor);
				free(remover);
			break;
			
			case 7:
				system("cls");
				remover = buscar(&lista, valor);
				if(remover)
				{
					printf("Valor encontrado: %d\n\n", valor);
				}
				else
				{
					printf("O valor %d nao foi encontrado\n\n", valor);
				}
				
				system("pause");
			break;
		}
	}while(opcao);

}
