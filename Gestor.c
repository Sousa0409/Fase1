#include "Gestor.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include <ctype.h>

cliente* InserirCliente (cliente* inicioC, int ID, char Nome[], char Morada[], int NIF, int Saldo, char Pass[]){
	
		cliente* novo = malloc(sizeof(struct Cliente));
		if (novo != NULL)
		{
			novo->ID=ID;
			strcpy(novo->Nome,Nome);
			strcpy(novo->Morada,Morada);
			novo->NIF=NIF;
			novo->Saldo=Saldo;
			strcpy(novo->Pass,Pass);
			novo->seguinte=inicioC;}
			return(novo);		
}
	
	//////////////////////////////////////////////////////////////
	
gestor* InserirGestor (gestor* inicio, int ID, char Nome[], char Morada[], char Pass[]){

		gestor* novo = malloc(sizeof(struct Gestor));
		if (novo != NULL)
		{
			novo->ID=ID;
			strcpy(novo->Nome,Nome);
			strcpy(novo->Morada,Morada);
			strcpy(novo->Pass,Pass);
			novo->seguinte=inicio;}
			return(novo);	
}

	//////////////////////////////////////////////////////////////	
	
mme* InserirMME (mme* inicio, int ID, char Marca[], char Modelo[], int Autonomia, int Localizacao, int Custo){

		mme* novo = malloc(sizeof(struct MME));
		if (novo != NULL)
		{
			novo->ID=ID;
			strcpy(novo->Marca,Marca);
			strcpy(novo->Modelo,Modelo);
			novo->Autonomia=Autonomia;
			novo->Localizacao=Localizacao;
			novo->Custo=Custo;
			novo->seguinte=inicio;}
			return(novo);
}

	//////////////////////////////////////////////////////////////
	
aluguer* InserirAluguer (aluguer* inicio, int IDcliente, int IDmme, int Aativo){

		aluguer* novo = malloc(sizeof(struct Aluguer));
		if (novo != NULL)
		{
			novo->IDcliente=IDcliente;
			novo->IDmme=IDmme;
			novo->Aativo=Aativo;
			novo->seguinte=inicio;}
			return(novo);
}

	//////////////////////////////////////////////////////////////
	
cliente* AdicionarCliente(cliente* inicioC){ //Sub-Rotina para Adicionar um novo Cliente
	
	int ID,NIF,Saldo,inserirnovo=0;
	char Nome[20];
	char Morada[20];
	char Pass[20];
	cliente* final; 
	cliente* auxC=inicioC;
	
    printf("ID: \n");
    scanf("%d", &ID); // Adicionar novo ID na struct
    setbuf(stdin, NULL);

	while (inicioC != NULL){
       	if(inicioC->ID==ID){
       		printf("ID ja existe\n");
       		Sleep(1000);
       		inserirnovo=1;
		}	
		inicioC=inicioC->seguinte;		
	}				
    final=auxC;
    inicioC=auxC;
    if(inserirnovo==0){
    printf("Nome: \n");
    scanf("%[^\n]s", Nome); // Adicionar novo Nome na struct
    setbuf(stdin, NULL);
       
    printf("Morada: \n");
    scanf("%[^\n]s", Morada); // Adicionar nova Morada na struct
    
     printf("NIF: \n");
    scanf("%d", &NIF); // Adicionar novo ID na struct
    
     printf("Saldo: \n");
    scanf("%d", &Saldo); // Adicionar novo ID na struct
    setbuf(stdin, NULL);
    
    printf("Pass: \n");
    scanf("%[^\n]s", &Pass); // Adicionar novo ID na struct
    
    final=InserirCliente (inicioC, ID, Nome, Morada, NIF, Saldo, Pass);
    }
    return(final);
}
   
    ////////////////////////////////////////////////////////////// 
    
gestor* AdicionarGestor(gestor* inicioG){ //Sub-Rotina para Adicionar um novo Gestor
	
	int ID, inserirnovo=0;
	char Nome[20];
	char Morada[20];
	char Pass[20];
	gestor* final;
	gestor* auxG=inicioG;
	
    printf("ID: \n");
    scanf("%d", &ID); // Adicionar novo ID na struct
    setbuf(stdin, NULL);
    
	while (inicioG != NULL){
       	if(inicioG->ID==ID){
       		printf("ID ja existe\n");
       		Sleep(1000);
       		inserirnovo=1;
		}	
		inicioG=inicioG->seguinte;		
	}		
    final=auxG;
    inicioG=auxG;
    if(inserirnovo==0){
    	printf("Nome: \n");
    	scanf("%[^\n]s", Nome); // Adicionar novo Nome na struct
    	setbuf(stdin, NULL);
    
    	printf("Morada: \n");
    	scanf("%[^\n]s", Morada); // Adicionar nova Morada na struct
    
    	printf("Pass: \n");
    	scanf("%[^\n]s", &Pass); // Adicionar novo ID na struct
    
    	final=InserirGestor (inicioG, ID, Nome, Morada, Pass);	
	}
	return (final);
}
   
    //////////////////////////////////////////////////////////////    
    
mme* AdicionarMME(mme* inicioM){ //Sub-Rotina para Adicionar novos Meios de Mobilidade Eletrica
	
	int ID, Autonomia, Localizacao, Custo, inserirnovo=0;
	char Marca[20];
	char Modelo[20];
	mme* final;
	mme* auxM=inicioM;
	
    printf("ID: \n");
    scanf("%d", &ID); // Adicionar novo ID na struct
    
    while (inicioM != NULL){
       	if(inicioM->ID==ID){
       		printf("ID ja existe\n");
       		Sleep(1000);
       		inserirnovo=1;
		}	
		inicioM=inicioM->seguinte;		
	}		
    final=auxM;
    inicioM=auxM;
    if(inserirnovo==0){
    	printf("Marca: \n");
    	scanf("%s", Marca); // Adicionar novo Nome na struct
    	setbuf(stdin, NULL);
    
    	printf("Modelo: \n");
    	scanf("%s", Modelo); // Adicionar nova Morada na struct
    	setbuf(stdin, NULL);
    
    	printf("Autonomia: \n");
    	scanf("%d", &Autonomia); // Adicionar novo ID na struct
    
    	printf("Localizacao: \n");
    	scanf("%d", &Localizacao); // Adicionar novo ID na struct
    
    	printf("Custo: \n");
    	scanf("%d", &Custo); // Adicionar novo ID na struct
    
    	final=InserirMME (inicioM, ID, Marca, Modelo, Autonomia, Localizacao, Custo);
	}
    return (final);
}

	//////////////////////////////////////////////////////////////
	
aluguer* AlugarMME(int Acessor, mme* inicioM, aluguer* inicioA, cliente* inicioC){ //Chamada da Sub-Rotina de Adicionar um novo colaborador
	
	aluguer* memoA;
	aluguer* aux;
	aux=inicioA;
	int ID, reservado=0, estado=1;
	while(reservado!=1){
	reservado=0;
	printf("ID do Meio de Mobilidade Eletrica: ");
    scanf("%d", &ID); 
    while (inicioM != NULL){//Atraves do ciclo for conseguimos visualizar todos os colaboradores por ordem de inscrição
        if (inicioM->ID==ID){
        	while (inicioA != NULL){
        		if (inicioA->Aativo ==1 && inicioA->IDmme==ID){
        			reservado=2;
        		}
        		inicioA=inicioA->seguinte;
        	}
			if (reservado=2){
				memoA=InserirAluguer (aux, Acessor, ID, estado);
				while (inicioC != NULL){ //Atraves do ciclo for conseguimos visualizar todos os colaboradores por ordem de inscrição
        			if (inicioC->ID==Acessor){
        				inicioC->Saldo=inicioC->Saldo - inicioM->Custo;
        			}
        			inicioC=inicioC->seguinte;	
      			}
				printf("Aluguer realizado com sucesso\n");
        		reservado=1;
        		system("PAUSE");
			}
		}
	inicioM=inicioM->seguinte;		
	}
	if (reservado!=1){	
		system("cls");
    	printf("ID do Meio de Mobilidade Eletrica Nao Existe ou Ja Alugado");
    	Sleep(1000);
    	system("cls");
	}
	}
	return(memoA);
}
	
	//////////////////////////////////////////////////////////////
	
cliente* RemoverClientes(cliente* inicioC,int numero) { //Sub-Rotina para remover um colaborador
	
	cliente *anterior=inicioC, *atual=inicioC, *aux;

 	if (atual==NULL){
 		return(NULL); // lista ligada vazia
	 } 
	else if (atual->ID == numero){ // remoÃ§Ã£o do 1Âº registo
 		aux = atual->seguinte;
  		free(atual);
  		return(aux);
 	}
 	else{
 		while ((atual!=NULL)&&(atual->ID!=numero)){
  			anterior = atual;
   			atual = atual->seguinte;
  		}
  		if (atual==NULL){
  			return(inicioC);
		}
  		else{
	  		anterior->seguinte = atual->seguinte;
   			free(atual);
   			return(inicioC);
  		}
 	}
}
	
	//////////////////////////////////////////////////////////////
	
mme* RemoverMME(mme* inicioM) { //Sub-Rotina para remover um colaborador
	
	int numero = 0;
	printf("Introduza o ID do Meio de Mobilidade Eletrico a ser eliminado: ");
	scanf("%d", &numero);
	mme *anterior=inicioM, *atual=inicioM, *aux;

 	if (atual==NULL){
 		return(NULL); // lista ligada vazia
	 } 
	else if (atual->ID == numero){ // remoÃ§Ã£o do 1Âº registo
 		aux = atual->seguinte;
  		free(atual);
  		return(aux);
 	}
 	else{
 		while ((atual!=NULL)&&(atual->ID!=numero)){
  			anterior = atual;
   			atual = atual->seguinte;
  		}
  		if (atual==NULL){
  			return(inicioM);
		}
  		else{
	  		anterior->seguinte = atual->seguinte;
   			free(atual);
   			return(inicioM);
  		}
 	}
}

	//////////////////////////////////////////////////////////////
	
gestor* RemoverGestor(gestor* inicioG){
	
	int numero = 0;
	printf("Introduza o ID do Gestor a ser eliminado: ");
	scanf("%d", &numero);
	gestor *anterior=inicioG, *atual=inicioG, *aux;

 	if (atual==NULL){
 		return(NULL); // lista ligada vazia
	 } 
	else if (atual->ID == numero){ // remoÃ§Ã£o do 1Âº registo
 		aux = atual->seguinte;
  		free(atual);
  		return(aux);
 	}
 	else{
 		while ((atual!=NULL)&&(atual->ID!=numero)){
  			anterior = atual;
   			atual = atual->seguinte;
  		}
  		if (atual==NULL){
  			return(inicioG);
		}
  		else{
	  		anterior->seguinte = atual->seguinte;
   			free(atual);
   			return(inicioG);
  		}
 	}
}
	
	//////////////////////////////////////////////////////////////
	
void VisualizarClientes(cliente* inicioC){ //Sub-Rotina para vizualizar colaboradores já previamente inseridos
    while (inicioC != NULL){
       	printf("ID: %d\t"
		"Nome: %s\t"
		"Morada: %s\t\t"
		"NIF: %d\t"
		"Saldo: %d\t"
		"Pass: %s\n", inicioC->ID, inicioC->Nome, inicioC->Morada, inicioC->NIF, inicioC->Saldo, inicioC->Pass);
        printf("\n");
        inicioC=inicioC->seguinte;
	}
}

	//////////////////////////////////////////////////////////////
	
void VisualizarGestor(gestor* inicioG){ //Sub-Rotina para vizualizar colaboradores já previamente inseridos
    while (inicioG != NULL){
       	printf("ID: %d\t"
		"Nome: %s\t"
		"Morada: %s\t"
		"Pass: %s\n", inicioG->ID, inicioG->Nome, inicioG->Morada, inicioG->Pass);
        printf("\n");
        inicioG=inicioG->seguinte;
	}
}

	//////////////////////////////////////////////////////////////
	
void VisualizarMME(mme* inicioM){ //Sub-Rotina para vizualizar colaboradores já previamente inseridos
   while (inicioM != NULL){
       	printf("ID: %d\t"
		"Marca: %s\t"
		"Modelo: %s\t"
		"Autonomia: %d\t"
		"Localizacao: %d\t\t"
		"Custo: %d\t", inicioM->ID, inicioM->Marca, inicioM->Modelo, inicioM->Autonomia, inicioM->Localizacao, inicioM->Custo);
        printf("\n");
        inicioM=inicioM->seguinte;
	}
}

	//////////////////////////////////////////////////////////////
	
void atualizarCliente(cliente* inicioC, int Acessor){ //Sub-Rotina para atualizar os colaboradores já inscritos
    
    while (inicioC != NULL){
       	if(inicioC->ID==Acessor){
       		printf("Nome: %s\n", inicioC->Nome);
       		printf("Morada: ");
    		scanf("%s", inicioC->Morada);
    		printf("NIF: %d\n", inicioC->NIF);
    		printf("Saldo: ");
    		scanf("%d", &inicioC->Saldo);
    		printf("Pass: ");
    		scanf("%s", &inicioC->Pass);
		   }
		inicioC=inicioC->seguinte;
}    
}

	//////////////////////////////////////////////////////////////	
	
void atualizarGestor(gestor* inicioG, int Acessor){ //Sub-Rotina para atualizar os colaboradores já inscritos
  
   	while (inicioG != NULL){
       	if(inicioG->ID==Acessor){
			printf("Nome: %s\n", inicioG->Nome);
			printf("Morada: ");
    		scanf("%s", inicioG->Morada);
   			printf("Pass: ");
   			scanf("%s", &inicioG->Pass);
   		}
   		inicioG=inicioG->seguinte;
	}
}

	//////////////////////////////////////////////////////////////	
	
void atualizarMME(mme* inicioM){ //Sub-Rotina para atualizar os colaboradores já inscritos
  
  	int numero=0;
	printf("Introduza o ID do Meio de Mobilidade Eletrica a ser atualizado: ");
	scanf("%d", &numero);
	while (inicioM != NULL){
       	if(inicioM->ID==numero){
			printf("Marca: %s\n", inicioM->Marca);
			printf("Modelo: %s\n", inicioM->Modelo);
			printf("Autonomia: ");
    		scanf("%d", &inicioM->Autonomia);
    		printf("Localizacao: ");
    		scanf("%d", &inicioM->Localizacao);
    		printf("Custo: ");
    		scanf("%d", &inicioM->Custo);
			}
		inicioM=inicioM->seguinte;
	}
}    

	//////////////////////////////////////////////////////////////
	
void AtualizarEstadoAluguer(aluguer* inicioA, int Acessor) { //Sub-Rotina para remover um colaborador
	
	int aux=0;
	while (inicioA != NULL){
		if (Acessor==inicioA->IDcliente && inicioA->Aativo==1){
			inicioA->Aativo=0;
			printf("Terminado com Sucesso");
			Sleep(1000);
			aux=1;
		}
		inicioA=inicioA->seguinte;
	}
	if (aux==0){
		printf("Nenhum Aluguer Correspondente Encontrado");
		Sleep(1000);
	}	
}

	//////////////////////////////////////////////////////////////
	
void DecrescenteAutonomia(mme* inicioM) {
	
	mme *mme1 = inicioM;
	mme *inicio;
	
	while (mme1 != NULL){
    	mme *mme2 = mme1->seguinte;
    	inicio = mme2;
    	while (mme2 != NULL){
        	if (mme1->Autonomia < mme2->Autonomia){ //se maior troca o conteudo das duas pessoas
            	int temp = mme1->Autonomia; 
            	char aux[20];
            	mme1->Autonomia = mme2->Autonomia;
            	mme2->Autonomia = temp;
            	
            	strcpy(aux,mme2->Marca);
            	strcpy(mme1->Marca,mme2->Marca);
            	strcpy(mme2->Marca,aux);
            	
            	strcpy(aux,mme2->Modelo);
            	strcpy(mme1->Modelo,mme2->Modelo);
            	strcpy(mme2->Modelo,aux);
            	
            	temp=mme1->Localizacao;
            	mme1->Localizacao = mme2->Localizacao;
            	mme2->Localizacao= temp;
            	
				temp=mme1->Custo;
            	mme1->Custo = mme2->Custo;
            	mme2->Custo= temp;

        	}
        	mme2 = mme2->seguinte;
    	}
 		mme1 = mme1->seguinte;
	}
	while (inicioM != NULL){
       	printf("ID: %d\t"
		"Marca: %s\t"
		"Modelo: %s\t"
		"Autonomia: %d\t"
		"Localizacao: %d\t\t"
		"Custo: %d\t", inicioM->ID, inicioM->Marca, inicioM->Modelo, inicioM->Autonomia, inicioM->Localizacao, inicioM->Custo);
        printf("\n");
        inicioM=inicioM->seguinte;
	}
}

	//////////////////////////////////////////////////////////////
	
void PesquisaPorLocalizacao(mme* inicioM){ //Sub-Rotina para vizualizar por estado dos colaboradores
    
	int local=0,aux=0;
    printf("Localizacao pertendida: \n");
    scanf("%d", &local);
    system("cls");
    while (inicioM != NULL){
		if(local == inicioM->Localizacao){ // Comparamos o auxiliar (estado do covid do numero que esta a ser verificado) com o que pretende-mos selecionar 
		printf("ID: %d\n", inicioM->ID);
        printf("Marca: %s\n", inicioM->Marca);
        printf("Modelo: %s\n", inicioM->Modelo);
        printf("Autonomia: %d\n", inicioM->Autonomia);
        printf("Localizacao: %d\n", inicioM->Localizacao);
        printf("Custo: %d\n", inicioM->Custo);
    	printf("\n\n");
    	aux=1;
		}
	inicioM=inicioM->seguinte;
	}
	if(aux==0){
		printf("Nenhum Meio de Mobilidade Eletrica Encontrado na Localizacao Pretendida\n\n");
	}
}

	//////////////////////////////////////////////////////////////
	
void CarregarSaldo(cliente* inicioC, int Acessor){ //Chamada da Sub-Rotina de Adicionar um novo colaborador
	
	int dinheiro=0;
	printf("Montante a carregar: ");
    scanf("%d", &dinheiro);
	while (inicioC != NULL){
		if(Acessor == inicioC->ID){ // Comparamos o auxiliar (estado do covid do numero que esta a ser verificado) com o que pretende-mos selecionar 
			inicioC->Saldo= dinheiro + inicioC->Saldo;
			printf("O seu Saldo e: %d",inicioC->Saldo);
			Sleep(1000);
		}
		inicioC=inicioC->seguinte;
	}
}

	//////////////////////////////////////////////////////////////
	
void HistoricoCliente(int Acessor, mme* inicioM, aluguer* inicioA){
	
	mme* auxM=inicioM;
	while (inicioA != NULL){
		if(inicioA->IDcliente == Acessor){
			inicioM=auxM;
			while (inicioM != NULL){
				if(inicioA->IDmme == inicioM->ID){
        			printf("ID: %d\n", inicioM->ID);
        			printf("Marca: %s\n", inicioM->Marca);
        			printf("Modelo: %s\n", inicioM->Modelo);
        			printf("Custo: %d\n", inicioM->Custo);
        			if (inicioA->Aativo==1){
        				printf("Aluguer Ativo \n");
					}
					else{
						printf("Aluguer Desativo \n");
					}
        			printf("\n\n");
				}
				inicioM=inicioM->seguinte;
			}
		}
		inicioA=inicioA->seguinte;
	}
}

	//////////////////////////////////////////////////////////////
	
void MMEsemAluguer(mme* inicioM, aluguer* inicioA){
	
	aluguer* auxA=inicioA;
	int ID=0, aux=0;
	while (inicioM != NULL){
		ID=inicioM->ID;
		inicioA=auxA;
		while (inicioA != NULL){
			if (inicioA->IDmme==ID && inicioA->Aativo==1){
				aux=1;
			}
			inicioA=inicioA->seguinte;
		}
		if (aux==0){
			printf("ID: %d\n", inicioM->ID);
        	printf("Marca: %s\n", inicioM->Marca);
        	printf("Modelo: %s\n", inicioM->Modelo);
        	printf("Autonomia: %d\n", inicioM->Autonomia);
        	printf("Localizacao: %d\n", inicioM->Localizacao);
        	printf("Custo: %d\n", inicioM->Custo);
        	printf("\n\n");	
		}
		aux=0;
		inicioM=inicioM->seguinte;
	}
}

	//////////////////////////////////////////////////////////////

void HistoricoAluguerMME(aluguer* inicioA ,mme* inicioM, cliente* inicioC){
	
	cliente* auxC=inicioC;
	mme* auxM=inicioM;
	char estado[20];
	while (inicioA != NULL){
		inicioC=auxC;
		while (inicioC != NULL){
			if(inicioA->IDcliente==inicioC->ID){
				printf("ID: %d\t"
				"Nome: %s\t"
				"Morada: %s\t"
				"NIF: %d\t\t"
				"Saldo: %d\t"
				"Pass: %d\n", inicioC->ID, inicioC->Nome, inicioC->Morada, inicioC->NIF, inicioC->Saldo, inicioC->Pass);
        		printf("\n");
			}
			inicioC=inicioC->seguinte;
		}
		inicioM=auxM;
		while (inicioM != NULL){
			if(inicioA->IDmme==inicioM->ID){
				printf("ID: %d\t"
				"Marca: %s\t"
				"Modelo: %s\t"
				"Autonomia: %d\t"
				"Localizacao: %d\t\t"
				"Custo: %d\t", inicioM->ID, inicioM->Marca, inicioM->Modelo, inicioM->Autonomia, inicioM->Localizacao, inicioM->Custo);
        		printf("\n");
			}
			inicioM=inicioM->seguinte;
		}
		if(inicioA->Aativo==1){
			strcpy(estado, "Ativo");
		}
		else{
			strcpy(estado, "Desativo");
		}
	printf("\nEstado: (%s)\n",estado);
	printf("========================================================================================================================\n\n");
	inicioA=inicioA->seguinte;
	}
}

	//////////////////////////////////////////////////////////////
	
void PercentagemMMEAlugados(aluguer* inicioA ,mme* inicioM){
	
	int contagem=0,percentagem=0,totalM=0;
	while (inicioA != NULL){
		if(inicioA->Aativo==1){
			contagem ++;
		}
		inicioA=inicioA->seguinte;
	}
	while (inicioM != NULL){
		totalM++;
		inicioM=inicioM->seguinte;
	}
	
	percentagem=contagem*100/totalM;
	printf("A Percentagem de Meios de Mobilidade Eletrica Alugados e: %d\n", percentagem);
}

