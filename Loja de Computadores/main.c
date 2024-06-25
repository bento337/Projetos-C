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

Pc Padrao[3]=
{
	{"Intel i5 10400F", "GeForce GTX 1650", "Biostar H510MH/E", 8, 1, "Fonte Duex 500FSE++", "Gabinete Gamer Ninja Hades", 2459} ,
	{"Intel Core i7 10700k", "NVIDIA GeForce RTX 4070 Ti", "Biostar H510MH/E", 16, 2, "Kyber SuperFrame, 850w", "SuperFrame Strider, Mid Tower", 7559} ,
	{"Intel Core i9 13900KF", "NVIDIA GeForce RTX 4090", "Gigabyte B760M Aorus Elite", 32, 5, "Kyber SuperFrame, 850w", "NZXT H7 Mid Tower", 20496.50} 
};

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int r, a, i, controle, d, e;
	Pc novop[a];

	
	printf("Digite 1 para entrar na loja, e 2 para sair:\n\n");
	 scanf("%d", &controle);
	 
	 
	while(controle!=1 && controle!=2)
	 {
	 	printf("Opção inválida! \n");
	 	printf("Digite 1 para entrar na loja, e 2 para sair:\n");
	      scanf("%d", &controle);    
	 } 	 
	 
	 	printf("---------Loja de Computadores---------\n");

    while(controle==1){
    	
	printf("Deseja vender(Digite 1), ou comprar(DIGITE 2):\n");
	 scanf("%d", &r);
	 
	 while(r!=1 && r!=2)
	 {
	 	printf("Opção inválida! \n");
	 	printf("Deseja vender(Digite 1), ou comprar(DIGITE 2):\n");
	      scanf("%d", &r);    
	 }
	 
       	 if(r==1)
       	 {
       	 	e=Menu1(r);
       	 	
            	if(e==1)
            	{	
				   d=Registrar(a, novop)+3;
		    	} else if(e==2)
			    {
			        cliente c;
				    Total(c, 2);			    	
				}	 
				 	 	
		 }else if(r==2)
	     {
	     	r = Menu2();
	     	a=r;
	        if(a==1){
	     		Produtos(d, Padrao, novop);
			 }
	         else if(a==2)
	         {
	         	Comprar(novop, Padrao);
			 }
	          
		 }
	      	
		  
		  for(i=0; i<8; i++)
		   printf("\n");
		  
	 printf("Digite 1 para entrar na loja, e 2 para sair:\n");
	   scanf("%d", &controle);	    	
	}

    return 0;

}
