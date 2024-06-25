#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct{
	char Nome[30]; 
	char Email[30]; 
	char Telefone[30];
	char cpf[30];
	char Cep[30];
	int comp;
	float preco;
	
}cliente;

typedef struct{
	char cpu[30]; 
	char gpu[30]; 
	char motherb[30]; 
	int ram; 
	int rom;
	char fonte[30]; 
	char gabinete[30]; 
	int price;
}Pc;


int Menu1(int r);
int Registrar(int a, Pc novop[a]);
int Menu2();
void Produtos(int r, Pc Padrao[], Pc novop[]);
int Comprar(Pc novop[], Pc Padrao[]);
void Nota(cliente c);
void Total(cliente c, int aux);

