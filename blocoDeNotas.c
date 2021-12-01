#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <strings.h>
#include <windows.h>
#include <sys/types.h>
#include <dirent.h>

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);		//Comando para as cores

void vermelho()
{
	SetConsoleTextAttribute(hStdOut, (FOREGROUND_RED));
}

void azul()
{
	SetConsoleTextAttribute(hStdOut, (FOREGROUND_BLUE));
}

void verde()
{
	SetConsoleTextAttribute(hStdOut, (FOREGROUND_GREEN));
}

void branco()
{
	SetConsoleTextAttribute(hStdOut, (FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED));
}


int main(void)	
{
	setlocale(LC_ALL,"");
	
	
	int OP, NUM_NOTAS=0, NUM_NOTAS_USER=0;						//Opção, número de anotações, número de notas do usuario atual;
	int I, K=0;								//Contadores, K é para os reports
	char NOME[50], NOME_NOTA[50], TEXTO[100];	//Nome digitado para criar usuario e nome que fica registrado para usuario já ficar criado
	char relat[10] = "relatorio";
	FILE *nota;
	
	do
	{
		system("cls");
		printf("========MENU DE OPÇÕES========\n");
		printf("1. Cadastrar um usuário\n");
		printf("2. Excluir um usuário\n");
		printf("3. Escrever uma anotação para um usuário\n");
		printf("4. Excluir a anotação de um usuário\n");
		printf("5. Ler um anotação\n");
		printf("6. Mostrar todos usuários\n");
		printf("7. Gerar um relatório sobre os usuários\n");
		printf("8. Sair\n");
		printf("==============================\n");
		printf("\nDigite sua opção: ");
		scanf("%d%*c",&OP);
		
		switch (OP)
		{
			case 1:
				chdir("contas");
				
				I=0;
					DIR *dp;	//INICIO DA LISTAGEM DOS ARQUIVOS DO USUARIO
					struct dirent *ep;     
					dp = opendir ("./");
				
					if (dp != NULL)
					{
						azul();
						printf("\nLista de usuários já cadastrados: \n\n");
						branco();
						while (ep = readdir (dp))
						{
							if (I == 2)
							{
								puts (ep->d_name);
							}
							else
							{
								I++;
							}
						}
							
						(void) closedir (dp);
					}
					else
				    	perror ("Não foi possível abrir o diretório...");	//FIM DA LISTAGEM DOS ARQUIVOS (ANOTAÇÕES) DO USUARIO
				printf("\nDigite o nome do usuário que você deseja criar: ");
				gets(NOME);
				
				if (CreateDirectory(NOME,NULL) == 0)
				{
					vermelho();
					printf("Não foi possível criar o usuário...\n");
					printf("OBS: Verifique se este usuário já está cadastrado!");
					branco();
				}
				else 
				{
					CreateDirectory(NOME,NULL);
					verde();	
					printf("Usuário criado com sucesso!\n");
					branco();
				}
				chdir("..");
				getch();
				break;
			case 2:
				chdir("contas");
				vermelho();
				printf("ATENÇÃO: A pasta do usuário deve estar vazia para que o usuário seja excluído!\n");
				branco();
				I=0;  
				dp = opendir ("./");
			
				if (dp != NULL)
				{
					azul();
					printf("\nLista de usuários já cadastrados: \n\n");
					branco();
					while (ep = readdir (dp))
					{
						if (I == 2)
						{
							puts (ep->d_name);
						}
						else
						{
							I++;
						}
					}
						
					(void) closedir (dp);
				}
				else
			    	perror ("Não foi possível abrir o diretório...");	//FIM DA LISTAGEM DOS ARQUIVOS (ANOTAÇÕES) DO USUARIO
				printf("\nDigite o usuário a ser excluido: ");
				gets(NOME);
				if (RemoveDirectory(NOME) == 0)
				{
					vermelho();
					printf("\nNão foi possível excluir o usuário...\n");
					printf("Verifique se o nome digitado está correto!\n");
					printf("Verifique se não há nenhum arquivo na pasta do usuário!\n");
					branco();
				}
					
				else
				{
					verde();
					printf("Usuário excluido com sucesso!");
					RemoveDirectory(NOME);
					branco();
				}
				printf("\nPressione qualquer tecla para continuar.");
				chdir("..");
				getch();
				break;
			case 3:
				chdir("contas");
				
				I=0;   
				dp = opendir ("./");
			
				if (dp != NULL)
				{
					azul();
					printf("\nLista de usuários já cadastrados: \n\n");
					branco();
					while (ep = readdir (dp))
					{
						if (I == 2)
						{
							puts (ep->d_name);
						}
						else
						{
							I++;
						}
					}
						
					(void) closedir (dp);
				}
				else
			    	perror ("Não foi possível abrir o diretório...");	//FIM DA LISTAGEM DOS ARQUIVOS (ANOTAÇÕES) DO USUARIO
				
				printf("\nDigite qual usuário você deseja escrever uma anotação: ");
				gets(NOME);
				if (chdir(NOME) != 0)
				{
					vermelho();
					printf("Erro ao abrir usuário!\n");
					printf("Verifique se ele está cadastrado.");
					branco();
				}
				else
				{
					chdir(NOME);
					vermelho();
					printf("ATENÇÃO: Anotações com mesmo nome serão sobescritas.\n");
					printf("ATENÇÃO: Não é necessário adicionar \".txt\" no final do nome do arquivo!\n");
					branco();
					printf("Digite o nome do arquivo da anotação: ");
					gets(NOME_NOTA);
					strcat(NOME_NOTA,".txt");
					nota = fopen(NOME_NOTA,"w+");
					printf("Digite o que você deseja gravar na anotação: ");
					gets(TEXTO);
					fprintf(nota,"%s",TEXTO);
					fclose(nota);
					verde();
					printf("Nota salva com sucesso!");
					branco();
					chdir("..");
				}
				printf("\nPressione qualquer tecla para continuar.");
				chdir("..");
				getch();
				break;
			case 4:
				chdir("contas");
				
				I=0;
				dp = opendir ("./");
			
				if (dp != NULL)
				{
					azul();
					printf("\nLista de usuários já cadastrados: \n\n");
					branco();
					while (ep = readdir (dp))
					{
						if (I == 2)
						{
							puts (ep->d_name);
						}
						else
						{
							I++;
						}
					}
						
					(void) closedir (dp);
				}
				else
			    	perror ("Não foi possível abrir o diretório...");	//FIM DA LISTAGEM DOS ARQUIVOS (ANOTAÇÕES) DO USUARIO
				
				printf("\nDigite qual usuário você deseja excluir uma anotação: ");
				gets(NOME);
				if (chdir(NOME ) != 0)
				{
					vermelho();
					printf("Erro ao abrir usuário!\n");
					printf("Verifique se ele está cadastrado.");
					branco();
				}
				else
				{
					chdir(NOME);
					I=0;
					DIR *dp;	//INICIO DA LISTAGEM DOS ARQUIVOS DO USUARIO
					struct dirent *ep;     
					dp = opendir ("./");
				
					if (dp != NULL)
					{
						azul();
						printf("\nLista de anotações deste usuário: \n\n");
						branco();
						while (ep = readdir (dp))
						{
							if (I == 2)
							{
								puts (ep->d_name);
							}
							else
							{
								I++;
							}
						}
							
						(void) closedir (dp);
					}
					else
				    	perror ("Não foi possível abrir o diretório...");	//FIM DA LISTAGEM DOS ARQUIVOS (ANOTAÇÕES) DO USUARIO
				    
				    vermelho();
					printf("\nATENÇÃO: Não é necessário adicionar \".txt\" no final do nome do arquivo!\n");
					branco();
					printf("\nDigite o nome da anotação que deseja excluir: ");
					gets(NOME_NOTA);
					strcat(NOME_NOTA,".txt");
					if (remove(NOME_NOTA) == 0)
					{
						verde();
						printf("A anotação \"%s\" foi excluída com sucesso!", NOME_NOTA);
						branco();
						chdir("..");
					}
					else
					{
						vermelho();
						printf("Falha ao excluir anotação!\n");
						printf("Verifique se o nome da anotação foi digitado corretamente!");
						branco();
//						chdir("..");
					}
				}
				chdir("..");
				printf("\nPressione qualquer tecla para continuar.");
				getch();
				break;
			case 5:
				chdir("contas");
				
				I=0;   
					dp = opendir ("./");
				
					if (dp != NULL)
					{
						azul();
						printf("\nLista de usuários já cadastrados: \n\n");
						branco();
						while (ep = readdir (dp))
						{
							if (I == 2)
							{
								puts (ep->d_name);
							}
							else
							{
								I++;
							}
						}
							
						(void) closedir (dp);
					}
					else
				    	perror ("Não foi possível abrir o diretório...");	//FIM DA LISTAGEM DOS ARQUIVOS (ANOTAÇÕES) DO USUARIO
				
				printf("\nDigite o nome de qual usuário você deseja ler uma anotação: ");
				gets(NOME);
				if (chdir(NOME) != 0)
				{
					vermelho();
					printf("Erro ao abrir usuário!\n");
					printf("Verifique se ele está cadastrado na opção 6.");
					branco();
				}
				else
				{
					chdir(NOME);
					I = 0;
					
					DIR *dp;	//INICIO DA LISTAGEM DOS ARQUIVOS DO USUARIO
					struct dirent *ep;     
					dp = opendir ("./");
				
					if (dp != NULL)
					{
						azul();
						printf("\nLista de anotações deste usuário: \n\n");
						branco();
						while (ep = readdir (dp))
						{
							if (I == 2)
							{
								puts (ep->d_name);
							}
							else
							{
								I++;
							}
						}
							
						(void) closedir (dp);
					}
					else
				    	perror ("Não foi possível abrir o diretório...");	//FIM DA LISTAGEM DOS ARQUIVOS (ANOTAÇÕES) DO USUARIO
				    
				    vermelho();
				    printf("\nATENÇÃO: Não é necessário adicionar \".txt\" no final do nome do arquivo!\n");
				    branco();
					printf("Digite a anotação que você deseja ler: ");
					gets(NOME_NOTA);
					strcat(NOME_NOTA,".txt");
					nota = fopen(NOME_NOTA,"r");
					if (fopen(NOME_NOTA,"r") == NULL)
					{
						vermelho();
						printf("Erro ao ler a anotação\n");
						printf("Verifique se o nome digitado está correto!");
						branco();
					}
					else
					{
						fgets(TEXTO,100,nota);
						system("cls");
						azul();
						printf("Anotação: %s\n\n",NOME_NOTA);
						branco();
						printf("%s",TEXTO);
						fclose(nota);
						chdir("..");
					}
				}
				chdir("..");
				printf("\n\nPressione qualquer tecla para retornar ao menu.");
				getch();
				break;
			case 6:
				chdir("contas");    
				dp = opendir ("./");
			
				if (dp != NULL)
				{
					I = 0;
					NUM_NOTAS_USER = 0;
					azul();
					printf("\nLista de usuários cadastrados: \n\n");
					branco(); 
					while (ep = readdir (dp))
					{
						if (I==2)
						{
							puts (ep->d_name);
							NUM_NOTAS_USER++;
						}
						else
						{
							I++;
						}
					}
					
					printf("\nNúmero total de usuários: ");
					azul();
					printf("%d",NUM_NOTAS_USER);
					branco(); 
					(void) closedir (dp);
				}
				else
			    	perror ("Não foi possível abrir o diretório...");
			    	
			    printf("\nPressione qualquer tecla para continuar.");
			    chdir("..");
				getch();
				break;
			case 7:
				chdir("reports");
				I = 0;
				NUM_NOTAS_USER = 0;
				strcat(relat,".txt");
				nota = fopen(relat,"w");
				chdir("..");
				chdir("contas");
				DIR *d;
				struct dirent *dir;
				d = opendir(".");
				if (d)
				{
					fprintf(nota,"====================\n");
					fprintf(nota,"|     USUÁRIOS     |\n");
					fprintf(nota,"====================\n");
					while ((dir = readdir(d)) != NULL)
					{
						if (I == 2)
						{
							fprintf(nota, "%9s\n",dir->d_name);
							NUM_NOTAS_USER++;
							K++;
						}
						else
							I++;
					}
					fprintf(nota,"\n\nNÚMERO TOTAL DE USUÁRIOS: %3d",NUM_NOTAS_USER);
					closedir(d);
				}
				fclose(nota);
				verde();
				printf("\nRelatório gerado com sucesso!\n");
				branco();
				printf("Pressione qualquer tecla para continuar");
				getch();
				chdir("..");
				break;
			case 8:
				system("cls");
				vermelho();
				printf("Encerrando...");
				branco();
				break;
		}
		
	} while (OP != 8);
	
	