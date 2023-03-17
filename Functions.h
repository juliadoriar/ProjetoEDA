/*****************************************************************//**
 * \file   Functions.h
 * \brief  Assinatura para todas as fun��es do programa.
 * 
 * \author julia
 * \date   March 2023
 *********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Structs.h"

#pragma once

/*bool existeCliente(Cliente* clientes[], int aux, int n);*/

//Fun��o para criar novo cliente
Cliente* criarCliente(Cliente* inicio, int id, char nome[], int nif, char morada[], float saldo);

//Fun��o para criar novo meio de mobilidadade
MeioMob* criarMeio(MeioMob* inicio, int id, char tipo[], float carga, float autonomia, float custo, char localizacao[]);

//Fun��o para criar um novo gestor com id e nome
Gestor* criarGestor(Gestor* inicio, int id, char nome[]);

//Fun��o auxiliar para verificar exist�ncia de um cliente a partir do seu id
int existeCliente(Cliente* inicio, int id);

//Fun��o de inser��o de novo cliente na lista
Cliente* inserirCliente(Cliente* inicio, int id, char nome, int nif, char morada, float saldo);

void listarClientes(Cliente* inicio);

int guardarCliente(Cliente* inicio);

/*Cliente* lerFicheiro();*/

/*

Cliente* inserirCliente(Cliente* listaClientes, int id, char nome[], int nif, char morada[], float saldo);



void removerCliente(Cliente** listaClientes, Cliente* id);
*/
/*

int inserirMeio();
int removeCliente();
int removeMeio();*/
