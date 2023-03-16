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
	struct Cliente* proximo;
}Cliente; 

typedef struct {
	int id;
	char tipo[20];
	float carga; // carga de energia disponivel 
	float autonomia;
	float custo;
	char localizacao[40];
	struct MeioMob* proximo;
}MeioMob; 

typedef struct {
	int id;
	char nome[50];
}Gestor;
