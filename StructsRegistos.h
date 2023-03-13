/*****************************************************************//**
 * \file   StructsRegistos.h
 * \brief  estruturas de armazenamento dos dados dos gestores, clientes e 
 * meios de mobilidade.
 * 
 * \author julia
 * \date   March 2023
 *********************************************************************/

#pragma once


typedef struct {
	char nome[20];
	int nif;
	char morada[100];
	float saldo; //montante disponível para cada cliente

}cliente;

typedef struct {
	char tipo[10];
	float carga; // carga de energia disponivel 
	float custo;

}meioMob;
