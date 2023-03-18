/*****************************************************************//**
 * \file   StructsRegistos.h
 * \brief  Asssinatura de todas estruturas de armazenamento dos dados 
 * dos gestores, clientes e meios de mobilidade.
 * 
 * \author julia
 * \date   March 2023
 *********************************************************************/

#pragma once


typedef struct {
	int id;
	char nome[50];
	int nif;
	char morada[100];
	float saldo; //montante disponível para cada cliente
	struct Cliente* proximo; //ponteiro para o próximo nó da lista
}Cliente; 

typedef struct {
	int id;
	char tipo[20];
	float carga; // carga de energia disponivel 
	float autonomia;
	float custo;
	char localizacao[40];
	struct MeioMob* proximo; //ponteiro para o próximo nó da lista
}MeioMob; 

typedef struct {
	int id;
	char nome[50];
}Gestor;

typedef struct {
	int id; //identificacao do aluguer
	int idMeio; //identificacao do meio alugado
	int idCliente; //identificacao do locatário
	//char nome [50]; //nome do locatário
	float custo; //custo do aluguer
	struct Aluguer* proximo; //ponteiro para o próximo nó da lista
}Aluguer;