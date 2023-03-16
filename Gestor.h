#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include <ctype.h>
#ifndef Gestor_H_INCLUDED
#define Gestor_H_INCLUDED

typedef struct Cliente{ //Definir a estrutura do Cliente
	int ID; //ID de identificação do Cliente
    char Nome[20]; // Nome do Cliente
    char Morada[20]; // Morada do Cliente
    int NIF; //NIF do Cliente
    int Saldo; //Saldo do Cliente
    char Pass[20]; //Pass do Cliente
    struct Cliente* seguinte;
}cliente;

typedef struct Gestor{ //Definir a estrutura do Gestor
	int ID; //ID de identificação do Gestor
    char Nome[20]; // Nome do Gestor
    char Morada[20]; // Morada do Gestor
    char Pass[20]; //Pass do gestor
    struct Gestor* seguinte;
}gestor;

typedef struct MME{ //Definir a estrutura dos Meios de Mobilidade Eletrica
	int ID; //ID de identificação dos Meios de Mobilidade Eletrica
    char Marca[20]; // Marca dos Meios de Mobilidade Eletrica
    char Modelo[20]; // Modelo dos Meios de Mobilidade Eletrica
    int Autonomia; // Autonomia dos Meios de Mobilidade Eletrica
    int Localizacao; // Localização dos Meios de Mobilidade Eletrica
    int Custo; // Localização dos Meios de Mobilidade Eletrica
    struct MME* seguinte;
}mme;

typedef struct Aluguer{ //Definir a estrutura dos Meios de Mobilidade Eletrica
	int IDcliente; //ID de identificação do cliente
    int IDmme; // ID de identificação dos Meios de Mobilidade Eletrica
    int Aativo;
    struct Aluguer* seguinte;
}aluguer;

cliente* InserirCliente (cliente* inicioC, int ID, char Nome[], char Morada[], int NIF, int Saldo, char Pass[]);

gestor* InserirGestor (gestor* inicio, int ID, char Nome[], char Morada[], char Pass[]);

mme* InserirMME (mme* inicio, int ID, char Marca[], char Modelo[], int Autonomia, int Localizacao, int Custo);

aluguer* InserirAluguer (aluguer* inicio, int IDcliente, int IDmme, int Aativo);

cliente* AdicionarCliente(cliente* inicioC); 

gestor* AdicionarGestor(gestor* inicioG);

mme* AdicionarMME(mme* inicioM);

aluguer* AlugarMME(int Acessor, mme* inicioM, aluguer* inicioA, cliente* inicioC);

cliente* RemoverClientes(cliente* inicioC,int numero);

mme* RemoverMME(mme* inicioM);

gestor* RemoverGestor(gestor* inicioG);

void VisualizarClientes(cliente* inicioC);

void VisualizarGestor(gestor* inicioG);

void VisualizarMME(mme* inicioM);

void atualizarCliente(cliente* inicioC, int Acessor);

void atualizarGestor(gestor* inicioG, int Acessor);

void atualizarMME(mme* inicioM);

void AtualizarEstadoAluguer(aluguer* inicioA, int Acessor);

void DecrescenteAutonomia(mme* inicioM);

void PesquisaPorLocalizacao(mme* inicioM);

void CarregarSaldo(cliente* inicioC, int Acessor);

void HistoricoCliente(int Acessor, mme* inicioM, aluguer* inicioA);

void MMEsemAluguer(mme* inicioM, aluguer* inicioA);

void HistoricoAluguerMME(aluguer* inicioA ,mme* inicioM, cliente* inicioC);

void PercentagemMMEAlugados(aluguer* inicioA ,mme* inicioM);

#endif 
