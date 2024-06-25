#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define DIM 3
int vez, vit1=0, vit2=0, x=0, p=0;

char jog1[20], jog2[20];
 
int menu(void);
void clear(void);
void jogar(int tabuleiro[][DIM]);
void zeraTabuleiro(int tabuleiro[][DIM]);
void exibeTabuleiro(int tabuleiro[][DIM]);
void jogada(int tabuleiro[][DIM]);
int checaLocal(int tabuleiro[][DIM], int linha, int coluna);
int checaColuna(int tabuleiro[][DIM]);
int checaEmpate(int tabuleiro[][DIM]);
int checaLinha(int tabuleiro[][DIM]);
int checaDiagonal(int tabuleiro[][DIM]);
int checaTermino(int tabuleiro[][DIM], int vez);


int main(void)
{
	system("Color 1F");
    int tabuleiro[DIM][DIM], continuar;
 
    do
    {
        vez=1;
        continuar = menu();
        if(continuar == 1)
        {      	 
        	jogar(tabuleiro);
		}
            
 
    }while(continuar);

    putchar('\n'); 
    printf("\nResumo das partidas:\n%s: %d vitórias\nBOT: %d vitórias\n %d empates.\n\n", jog1, vit1, vit2, x);
    system("pause");
}
 
int menu(void)
{
	setlocale(LC_ALL, "Portuguese");
    int opcao;
 
        printf("\t\tNosso Primeiro Jogo -- Jogo da Velha\n");
        printf("\n1.\tJogar uma partida \n");
        printf("0.\tSair\n");
        printf("\nOpcao: ");
 
        scanf("%d", &opcao);
        
        if(opcao==1 && p==0)
        {
        	printf("\nInforme o nome do jogador 1: \n");
        	 scanf("%s", &jog1);       	
		}
 
        switch(opcao)
        {
           case 1: 
           case 0:
                break;
           default:
                clear();
                printf("Opcao invalida. Tente de novo!\n");
        }
 
    return opcao;
}
 
void clear(void)
{
    int count=0;
 
    while(count != 100)
    {
        putchar('\n');
        count++;
    }
}

void jogar(int tabuleiro[][DIM])
{
    int continua;
    zeraTabuleiro(tabuleiro);
 
    do
    {
        clear();
        exibeTabuleiro(tabuleiro);
        jogada(tabuleiro);
 
    }while(checaTermino(tabuleiro, vez) != 1);//(checaTermino(tabuleiro, vez) != 1);
}

void zeraTabuleiro(int tabuleiro[][DIM])
{
    int linha, coluna;
    for(linha = 0 ; linha < DIM ; linha++)
        for(coluna = 0 ; coluna < DIM ; coluna++)
            tabuleiro[linha][coluna] = 0;
}
 
void exibeTabuleiro(int tabuleiro[][DIM])
{
    int linha, coluna;
    putchar('\n');
 
    for(linha = 0 ; linha < DIM ; linha++)
    {
        for(coluna = 0 ; coluna < DIM ; coluna++)
        {
            if(tabuleiro[linha][coluna] == 0)
                printf("    ");
            else
                if(tabuleiro[linha][coluna] == 1)
                    printf("  X ");
                else
                    printf("  O ");
 
            if(coluna != (DIM-1))
                printf("|");
        }
        putchar('\n');
    }
    putchar('\n');
}
 
void jogada(int tabuleiro[][DIM])
{
    int linha, coluna;
    vez++;
    if((vez % 2) + 1==1)
    {
       printf("\n--> %s \n", jog1);	
    do
    {
        printf("Linha: ");
        scanf("%d", &linha);
        linha--;
 
        printf("Coluna: ");
        scanf("%d", &coluna);
        coluna--;
 
        if(checaLocal(tabuleiro, linha, coluna) == 0)
            printf("Posicao ocupada ou inexistente, escolha outra.\n");
 	
    } while(checaLocal(tabuleiro, linha, coluna) == 0);//(checaLocal(tabuleiro, linha, coluna) == 0);       
	} else
	{
		do{
		srand(time(NULL));
     	int numero = 1 + rand() % 3;
        linha=numero;
        
        linha--;
        numero = 1 + rand() % 3;
        coluna= numero;
        coluna--;		
        
		} while(checaLocal(tabuleiro, linha, coluna) == 0);
		printf("\n--> BOT \n");
		printf("Linha: %d\n", linha);
		printf("Coluna: %d", coluna);
	}
    	
 
    if(vez%2)
        tabuleiro[linha][coluna] = -1;
    else
        tabuleiro[linha][coluna] = 1;
}

int checaLocal(int tabuleiro[][DIM], int linha, int coluna)
{
	if(linha > DIM || coluna > DIM || tabuleiro[linha][coluna] != 0 || linha < 0 || coluna < 0 )
	 return 0;
	else 
	  return 1;
}

int checaLinha(int tabuleiro[][DIM])
{
	int soma= 0, j, linha, coluna;
	for (linha=0; linha<DIM; linha++)
	{
		for(coluna=0; coluna<DIM; coluna++)
		{
			soma= soma + tabuleiro[linha][coluna];
		}
		if(soma== -3 || soma== 3)
			return 1;
	    else
	        soma =0;			
	}
	  return 0; 
}

int checaColuna(int tabuleiro[][DIM])
{
	int soma= 0, j, linha, coluna;
	for (linha=0; linha<DIM; linha++)
	{
		for(coluna=0; coluna<DIM; coluna++)
		{
			soma= soma + tabuleiro[coluna][linha];
		}
		if(soma== -3 || soma== 3)
			return 1;
	    else
	        soma =0;			
	}
	  return 0; 
}

int checaDiagonal(int tabuleiro[][DIM])
{
	int soma= 0, j=DIM-1, i;
	
	for(int diagonal1=0; diagonal1 < DIM; diagonal1++)
	{
		soma= soma + tabuleiro[diagonal1][diagonal1];
	}
	
		if(soma== -3 || soma== 3)
			return 1;
	    else
	    {
	    	soma =0;
             for(i=0; i<DIM; i++)
             {
            	soma= soma + tabuleiro[i][j];
                	j--;
	         }
	
	        	if(soma== -3 || soma== 3)
		        	return 1;
	            else
	                return 0;	    	
		}
}

int checaEmpate(int tabuleiro[][DIM])
{
    if(checaLinha(tabuleiro) == 0 && checaColuna(tabuleiro) == 0 && checaDiagonal(tabuleiro) == 0 && vez>9) 
       return 1;
    else 
       return 0;
}

int checaTermino(int tabuleiro[][DIM], int vez) 
{
	if(checaLinha(tabuleiro)==1 || checaColuna(tabuleiro)==1 || checaDiagonal(tabuleiro)==1)
	{
		    if((vez % 2) + 1==1)
            {
              printf("\nJogo encerrado. %s venceu!\n\n", jog1);
               vit1++;
               p++;
	        } else
	        {
	        	printf("\nJogo encerrado. O Computador venceu!\n\n");	
	        	vit2++;
	        	p++;
			}
		
		exibeTabuleiro(tabuleiro);
		return 1;
	} else if(checaEmpate(tabuleiro)==1)
	{
		 printf("\nJogo encerrado. Houve um empate\n\n");
		 x++;
		 p++;
		exibeTabuleiro(tabuleiro);
		return 1;
	}
}

