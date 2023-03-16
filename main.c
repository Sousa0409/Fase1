#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include "Gestor.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	cliente* inicioC=NULL;
    gestor* inicioG=NULL;
    mme* inicioM=NULL;
    aluguer* inicioAl=NULL;
    cliente* auxC=NULL;
    gestor* auxG=NULL;
    
 	FILE *Fclientes;
 	FILE *Fgestor;
 	FILE *Fmme;
 	FILE *Faluguer;
 	
	char Nome[20], Morada[20], Marca[20], Modelo[20], Pass[20];
   	int ID, IDcliente, IDmme, NIF, Saldo, Autonomia, Localizacao, Custo, Aativo;
   	int Acessor=0,aux=0;
   	
   	////////////////////////////////////////////////////////////// 
   	/*
	Fclientes=fopen("Gestao de Clientes.txt","a+"); //Abre o arquivo somente para leitura (se não existir é criado)

	while(fscanf(Fclientes,"%d ; %[^;] %[^;] %d ; %d ; %[^;]", &ID, Nome, Morada, &NIF, &Saldo, Pass)!= EOF){ //Enquanto ainda existir caracteres no arquivo ele:
		inicioC=InserirCliente(inicioC, ID, Nome, Morada, NIF, Saldo, Pass);
    }
    fclose(Fclientes); //Fecha o arquivo                   
 */
 
 	Fclientes=fopen("Gestao de Clientes.txt","r"); //Abre o arquivo somente para leitura (se não existir é criado)

	while(fscanf(Fclientes,"%d ; %[^;]; %[^;]; %d ; %d ; %s", &ID, Nome, Morada, &NIF, &Saldo, Pass)!= EOF){ //Enquanto ainda existir caracteres no arquivo ele:
    	inicioC=InserirCliente(inicioC, ID, Nome, Morada, NIF, Saldo, Pass);
	}
	fclose(Fclientes); //Fecha o arquivo

	Fgestor=fopen("Gestao de Gestores.txt","a+"); //Abre o arquivo somente para leitura (se não existir é criado)
	while(fscanf(Fgestor,"%d ; %[^;]; %[^;]; %s", &ID, Nome, Morada, Pass)!= EOF){ //Enquanto ainda existir caracteres no arquivo ele:
		inicioG=InserirGestor(inicioG, ID, Nome, Morada, Pass);
	}
	fclose(Fgestor); //Fecha o arquivo

	Fmme=fopen("Gestao de Meios de Mobilidade Eletrica.txt","a+"); //Abre o arquivo somente para leitura (se não existir é criado)
	while(fscanf(Fmme,"%d ; %[^;]; %[^;]; %d ; %d ; %d", &ID, Marca, Modelo, &Autonomia, &Localizacao, &Custo)!= EOF){ //Enquanto ainda existir caracteres no arquivo ele:
		inicioM=InserirMME(inicioM, ID, Marca, Modelo, Autonomia, Localizacao, Custo);
	}
	fclose(Fmme); //Fecha o arquivo

	Faluguer=fopen("Gestao de Aluguer de Meios de Mobilidade Eletrica.txt","a+"); //Abre o arquivo somente para leitura (se não existir é criado)                 
	while(fscanf(Faluguer,"%d ; %d ; %d", &IDcliente, &IDmme, &Aativo)!= EOF){ //Enquanto ainda existir caracteres no arquivo ele:
		inicioAl=InserirAluguer(inicioAl, IDcliente, IDmme, Aativo);
	}
	fclose(Faluguer); //Fecha o arquivo

	////////////////////////////////////////////////////////////// 
     
    auxC=inicioC;
    auxG=inicioG;
    
  	while(aux==0){
  		
  	inicioG=auxG;
  	inicioC=auxC;
	printf("\n              =========            ");
	printf("\n  ============|=Login=|============");
    printf("\n  =================================\n"
		   "                         \n");
    printf("  ->       ID : ");
    scanf("%d", &ID);
    setbuf(stdin, NULL);
    printf("             \n");
	printf("  ->       Pass : ");
    scanf("%s", &Pass);
    setbuf(stdin, NULL);
    
	while (inicioC != NULL && aux==0){ //Atraves do ciclo for conseguimos visualizar todos os colaboradores por ordem de inscrição

    	if (inicioC->ID == ID && strcmp(inicioC->Pass, Pass)==0){
			Acessor=inicioC->ID; 
			inicioC=auxC;  
			while(aux==0){	
			system("cls");
			printf("\n                                            ========                                          ");
			printf("\n  ==========================================|=Menu=|==========================================");
    		printf("\n  ============================================================================================\n"
		   "  **|                                                                                      |**\n");
    		printf("  **|		     =======(A)  Alugar um Meio de Mobilidade Eletrica                     |**\n"
		   "  **|                =======(B)  Carregar Saldo da Conta                                   |**\n"
		   "  **|                =======(C)  Consultar Saldo                                           |**\n"
		   "  **|                =======(D)  Consultar Dados                                           |**\n"
	       "  **|                =======(E)  Alterar Dados da Conta                                    |**\n"
		   "  **|                =======(F)  Verificar Meios de Mobilidade Eletrica Disponiveis        |**\n"
		   "  **|                =======(G)  Consultar Historico de Aluguer                            |**\n"
		   "  **|                =======(H)  Remover Conta                                             |**\n"
		   "  **|                =======(I)  Terminar Aluguer                                          |**\n"
		   "  **|                =======(J)  Verificar por Ordem Decrescente de Autonomia              |**\n"
		   "  **|                =======(K)  Pesquisar Meios de Mobilidade Eletrica por Localizacao    |**\n"
		   "  **|                =======(S)  Sair                                                      |**\n"
		   "  **|                                                                                      |**\n"
		   "  ============================================================================================\n\n");
		   
			char opcao;
			printf("\nOpcao escolhida: ");
			scanf("%c", &opcao);
			switch (opcao){
        		case 'A':
            		system("cls");
                	inicioAl=AlugarMME(Acessor,inicioM,inicioAl,inicioC); //Chamada da Sub-Rotina de Adicionar um novo colaborador
					break;
            
            	case 'B':
            		system("cls");
                	CarregarSaldo(inicioC, Acessor); //Chamada da Sub-Rotina de Adicionar um novo colaborador
             	   	break;
            	
           	 	case 'C':
            		system("cls");
            		auxC=inicioC;
 					while (inicioC != NULL){
						if(Acessor == inicioC->ID){ // Comparamos o auxiliar (estado do covid do numero que esta a ser verificado) com o que pretende-mos selecionar 
							printf("O seu Saldo e: %d \n",inicioC->Saldo);
							Sleep(1000);
						}
						inicioC=inicioC->seguinte;
					}
					system("PAUSE");
					inicioC=auxC;
            		break;
                
	            case 'D':
    	        	system("cls");
    	        	auxC=inicioC;
        	    	while (inicioC != NULL){
						if(Acessor == inicioC->ID){
        	    			printf("ID: %d\n", inicioC->ID);
        					printf("Nome: %s\n", inicioC->Nome);
	        				printf("Morada: %s\n", inicioC->Morada);
    	    				printf("NIF: %d\n", inicioC->NIF);
       		 				printf("Saldo: %d\n", inicioC->Saldo); 
       		 			}
						inicioC=inicioC->seguinte;
					}
        			system("PAUSE");
        			inicioC=auxC;
        			break;
            	
	            case 'E':
    	        	system("cls");
        	    	atualizarCliente(inicioC, Acessor);
            		break;
            	
	            case 'F':
    	        	system("cls");
        	    	MMEsemAluguer(inicioM, inicioAl);
            		system("PAUSE");
            		break;
            
    	        case 'G':
        	    	system("cls");
            		HistoricoCliente(Acessor, inicioM, inicioAl);
            		system("PAUSE");
            		break;
            	
	            case 'H':
	            	system("cls");
 		           	inicioC=RemoverClientes(inicioC, Acessor);
  		          	aux=1;
    	        	break;
            	
       		     case 'I':
            		system("cls");
            		AtualizarEstadoAluguer(inicioAl, Acessor);
            		break;
            
             	case 'J':
            		system("cls");
            		DecrescenteAutonomia(inicioM);
            		system("PAUSE");
            		break;
            	
             	case 'K':
            		system("cls");
					PesquisaPorLocalizacao(inicioM);
					system("PAUSE");
            		break;
            	
            	case 'S':
            		system("cls");
            		printf("\nSaindo...");
            		printf("\nObrigado Pela Preferencia");
                	Sleep(1000);
                	aux=1;
                	break;
        	}
    		}	
			
		}
		if(aux!=1){
		inicioC=inicioC->seguinte;
		}
	}
	
	while (inicioG != NULL && aux==0){ //Atraves do ciclo for conseguimos visualizar todos os colaboradores por ordem de inscrição
    	system("PAUSE");
		if((inicioG->ID == ID ) && strcmp(inicioG->Pass, Pass)==0){
			Acessor=inicioG->ID;
			inicioG=auxG;
			inicioC=auxC;	   
			while(aux==0){	
				system("cls");
				printf("\n                                            ========                                          ");
				printf("\n  ==========================================|=Menu=|==========================================");
    			printf("\n  ============================================================================================\n"
		   		"  **|                                                                                      |**\n");
    			printf("  **|		     =======(A)   Adicionar Gestor                                         |**\n"
		  	 	"  **|                =======(B)   Adicionar Cliente                                        |**\n"
		   		"  **|                =======(C)   Adicionar Meio de Mobilidade Eletrica                    |**\n"
		   		"  **|                =======(D)   Consultar Clientes                                       |**\n"
	       		"  **|                =======(E)   Consultar Meio de Mobilidade Eletrica                    |**\n"
		   		"  **|                =======(F)   Consultar Gestores                                       |**\n"
				"  **|                =======(G)   Alterar Dados de Gestor                                  |**\n"
		   		"  **|                =======(H)   Alterar Dados de Cliente                                 |**\n"
		  	 	"  **|                =======(I)   Alterar Dados de Meio de Mobilidade Eletrica             |**\n"
		   		"  **|                =======(J)   Remover Gestor                                           |**\n"
		   		"  **|                =======(K)  Remover Cliente                                           |**\n"
		   		"  **|                =======(L)  Remover Meio de Mobilidade Eletrica                       |**\n"
		   		"  **|                =======(M)  Historico de Aluger de Meio de Mobilidade Eletrica        |**\n"
		   		"  **|                =======(N)  Percentagem de Meio de Mobilidade Eletrica Alugados       |**\n"
		   		"  **|                =======(S)  Sair                                                      |**\n"
		   		"  **|                                                                                      |**\n"
		   		"  ============================================================================================\n\n");	   
				int clientepre = 0;
				char opcao;
				printf("\nOpcao escolhida: ");
				scanf("%c", &opcao);
				setbuf(stdin, NULL);
				switch (opcao){
        			case 'A':
            			system("cls");
                		inicioG=AdicionarGestor(inicioG);
                		break;
            
            		case 'B':
            			system("cls");
                		inicioC=AdicionarCliente(inicioC); 
                		break;
            	
           			case 'C':
            			system("cls");
            			inicioM=AdicionarMME(inicioM);
            			break;
                
            		case 'D':
            			system("cls");
            			VisualizarClientes(inicioC);
        				system("PAUSE");
        				break;
            	
            		case 'E':
            			system("cls");
            			VisualizarMME(inicioM);
            			system("PAUSE");
            			break;
            		
            		case 'F':
            			system("cls");
            			VisualizarGestor(inicioG);
            			system("PAUSE");
            			break;
            	
            		case 'G':
            			system("cls");
            			atualizarGestor(inicioG, Acessor);
            			break;
            
            		case 'H':
            			system("cls");
						printf("Introduza o ID do Cliente a ser atualizado: ");
						scanf("%d", &clientepre);
						auxC=inicioC;
						while (inicioC != NULL){
       						if(inicioC->ID==clientepre){
								atualizarCliente(inicioC, clientepre);
							}	
							inicioC=inicioC->seguinte;		
						}	
						inicioC=auxC;
            			break;
            	
            		case 'I':
            			system("cls");
            			atualizarMME(inicioM);
            			break;
            	
            		case 'J':
            			system("cls");
            			RemoverGestor(inicioG);
            			break;
            	
           			case 'K':
            			system("cls");
            			int numero = 0;
						printf("Introduza o ID do Cliente a ser eliminado: ");
						scanf("%d", &numero);
            			inicioC=RemoverClientes(inicioC, numero);
            			break;
            
            		case 'L':
            			system("cls");
            			inicioM=RemoverMME(inicioM);
            			break;
            
            		case 'M':
            			system("cls");
            			HistoricoAluguerMME(inicioAl, inicioM, inicioC);
            			system("PAUSE");
            			break;
            
            		case 'N':
            			system("cls");
            			PercentagemMMEAlugados(inicioAl, inicioM);
            			system("PAUSE");
            			break;
            	
            		case 'S':
            			system("cls");
            			printf("\nSaindo...");
            			printf("\nObrigado Pela Preferencia");	
                		aux=1;
                		break;  
        		}
    		}
		}
		if(aux!=1){
		inicioG=inicioG->seguinte;
		}
	}
	if(aux==0){
		printf("Nome ou Palavra Pass errados\n");
		Sleep(2000);
		system("cls");
	}
}    
	//////////////////////////////////////////////////////////////   	

	Fclientes=fopen("Gestao de Clientes.txt","w"); //Abre o arquivo somente para escrita (se já existir, apaga seu conteúdo)
	while (inicioC != NULL){
    	fprintf(Fclientes,"%d ; %s; %s; %d ; %d ; %s\n",
            inicioC->ID,
            inicioC->Nome, 
            inicioC->Morada, 
            inicioC->NIF, 
            inicioC->Saldo, 
            inicioC->Pass );
    		inicioC=inicioC->seguinte;
	}
	fclose(Fclientes);

	Fgestor=fopen("Gestao de Gestores.txt","w"); //Abre o arquivo somente para escrita (se não existir é criado ou truncado)
	while (inicioG != NULL){
    	fprintf(Fgestor,"%d ; %s; %s; %s\n",
        	inicioG->ID, 
        	inicioG->Nome, 
        	inicioG->Morada, 
        	inicioG->Pass);
   		 	inicioG=inicioG->seguinte;
	}
	fclose(Fgestor);
				
	Fmme=fopen("Gestao de Meios de Mobilidade Eletrica.txt","w"); //Abre o arquivo para escrita (se não existir é criado)
	while (inicioM != NULL){
		fprintf(Fmme,"%d ; %s; %s; %d ; %d ; %d\n",
			inicioM->ID, 
			inicioM->Marca, 
			inicioM->Modelo, 
			inicioM->Autonomia, 
			inicioM->Localizacao, 
			inicioM->Custo);
			inicioM=inicioM->seguinte;
	}
	fclose(Fmme);

	Faluguer=fopen("Gestao de Aluguer de Meios de Mobilidade Eletrica.txt","w"); //Abre o arquivo para escrita (se não existir é criado)
	while (inicioAl != NULL){
		fprintf(Faluguer,"%d ; %d ; %d\n",
			inicioAl->IDcliente,
			inicioAl->IDmme,
			inicioAl->Aativo );
			inicioAl=inicioAl->seguinte;
	}							
	fclose(Faluguer);       
	
	return 0;
}
