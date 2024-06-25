#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "auuuuuuuu.h"


int Menu1(int r)
{
	printf("\t\t\t\t\t----------Menu----------\n");
	printf("Digite 1 = Registrar Produtos\nDigite 2 = Total de Vendas\n\n");
	scanf("%d", &r);
	
	 while(r!=1 && r!=2)
	 {
	 	printf("Opção inválida! \n");
	 	printf("Digite 1 = Registrar Produtos\nDigite 2 = Total de Vendas\n\n");
	      scanf("%d", &r);    
	 }	
	 
	   return r;
}

int Registrar(int a, Pc novop[a]){
	int i, aux=4;
	
	  printf("Deseja registrar quantos computadores ?\n");
	       scanf("%d", &a);
	    

	       fflush(stdin);
	 for(i=3; i<a+3; i++)
	 {
    	printf("\n\nPC %d\n", i+1);
    	printf("Informe a CPU: \n");
    	 gets(novop[i].cpu);
    	 fflush(stdin);
		printf("Informe a GPU: \n");
    	 gets(novop[i].gpu);
    	  fflush(stdin);	 
    	printf("Informe Gabinete: \n");
    	 gets(novop[i].cpu); 	  	     	 
    	 fflush(stdin);
    	printf("Informe o preço: \n");
    	 scanf("%d", &novop[i].price);
    	 printf("\n");
		 fflush(stdin);	      	
	 }
	 
	 printf("Computadores Registrados:\n\n");
	 
	for(i=3; i<a+3; i++)
	 {
    	printf("Computador  %d\n", i+1);
    	printf("CPU: %s \n", novop[i].cpu);
    	printf("GPU: %s \n", novop[i].gpu);
    	printf("Fonte: 800w \n");  	 
    	printf("Gabinete: %s\n", novop[i].cpu); 	
    	printf("Preço: %d \n\n", novop[i].price);	      	
	 }
	 
	 return a;
}




//Cliente ---------------------------------------------------------------------------------------------------------------


int Menu2()
{
	int i;
	printf("\t\t\t\t\t----------Menu----------\n");
	printf("Digite 1 = Ver Produtos\nDigite 2 = Comprar\n\n");
	scanf("%d", &i);
	
   return i;
}

void Produtos(int r, Pc Padrao[], Pc novop[]){
	int i, aux=3;
	 printf("Computadores Disponíveis:\n\n");
	 
	for(i=0; i<3; i++)
	 {
    	printf("Computador  %d\n", i+1);
    	printf("CPU: %s \n", Padrao[i].cpu);
    	printf("GPU: %s \n", Padrao[i].gpu);
    	printf("Fonte: %s \n", Padrao[i].fonte);  	 
    	printf("Gabinete: \n", Padrao[i].cpu); 	
    	printf("Preço: %d \n\n", Padrao[i].price);	      	
	 }	 
	 
	for(i=3; i<r; i++)
	 {
    	printf("Computador  %d\n", i+1);
    	printf("CPU: %s \n", novop[i].cpu);
    	printf("GPU: %s \n", novop[i].gpu);
    	printf("Fonte: %s \n", novop[i].fonte);  	 
    	printf("Gabinete: \n", novop[i].cpu); 	
    	printf("Preço: %d \n\n", novop[i].price);	      	
	 }
}


int Comprar(Pc novop[], Pc Padrao[]){
	int r, y;
	cliente c;
	
	printf("\n\nQual computador deseja comprar ?\n");
	 scanf("%d", &r);
	 
	 c.comp=r;
	 
	 
	 if(r>3)
	  c.preco= novop[r-1].price;
	 else if(r<3)
	  c.preco= Padrao[r-1].price;
	 
	 Total(c, 1);
	 
	 fflush(stdin);
	printf("\nDados do Cliente:\n\nInforme seu nome:\n");
	 gets(c.Nome);
	  fflush(stdin);
	printf("\nInforme seu email: \n");
	 gets(c.Email);	
	  fflush(stdin);
	printf("\nInforme seu Telefone:\n");
	 gets(c.Telefone);
	  fflush(stdin);
	printf("\nInforme seu CEP:\n");
	 gets(c.Cep);	 
	  fflush(stdin);
	printf("\nInforme seu CPF:\n");
	 gets(c.cpf);	 
	  fflush(stdin);
	 
	printf("\n\nCompra realizada!\n Valor: R$%f\n", c.preco);
	fflush(stdin);
    printf("Deseja emitir nota fiscal ? (1 para sim, 2 para não)\n");
     scanf("%d", &r);
     
      fflush(stdin);
     
     if(r==1){
     	Nota(c);
	 } else if(r==2)
	  return 0;
}

 Nota(cliente c){
   FILE *arquivo;
    arquivo = fopen("dados_cliente.txt", "w"); // "a" para abrir o arquivo em modo de anexação

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Nome: %s\n", c.Nome);
    fprintf(arquivo, "Email: %s\n", c.Email);
    fprintf(arquivo, "Telefone: %s\n", c.Telefone);
    fprintf(arquivo, "CEP: %s\n", c.Cep);
    fprintf(arquivo, "CPF: %s\n", c.cpf);
    fprintf(arquivo, "Computador Comprado: %d\n", (int)c.comp);
    fprintf(arquivo, "Valor da Compra: R$%.2f\n", c.preco);

    fprintf(arquivo, "---------------------------------\n");

    fclose(arquivo);
}


Total(cliente c, int aux){
	float total=0;
	
	if(aux==1)
	 total+=c.preco;
	else if (aux==2)
	 printf("Você tem %.2f reais de saldo", total);
}
