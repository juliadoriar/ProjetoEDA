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
Cliente* criarCliente(Cliente *inicio, int id, char nome[], int nif, char morada[], float saldo);

//Fun��o para criar novo meio de mobilidadade
MeioMob* criarMeio(MeioMob* inicio, int id, char tipo[], float carga, float autonomia, float custo, char localizacao[]);

//Fun��o para criar um novo gestor com id e nome
Gestor* criarGestor(Gestor* inicio, int id, char nome[]);

//Fun��o recursiva para salvar lista de clientes em ficheiro bin�rio
void guardarClienteBin(Cliente* c, char arquivo[]);

//Fun��o recursiva para salvar lista de meios de mobilidade em ficheiro bin�rio
void guardarMeioMobBin(MeioMob* m, char arquivo[]);

//Fun��o para listar clientes ao final de um ficheiro de texto
void listarClientes(Cliente* inicio);

//Fun��o para listar meios de mobilidade ao final de um ficheiro de texto
void listarMeiosMob(MeioMob* inicio);

//fun��o para remover um n� da lista de clientes
Cliente* removerCliente(Cliente* inicio, int id);

//fun��o para remover um n� da lista de clientes
MeioMob* removerMeioMob(MeioMob* inicio, int id);

//fun��o recursiva que encontra um n� na lista atrav�s do id
Cliente* buscarCliente(Cliente* inicio, int identificador);

//fun��o para alterar dados de uma struct dentro de uma lista
void alterarCliente(Cliente* inicio, int identificador, int novoid, char novonome[], int novonif, char novamorada[], float novosaldo);

/*

//Fun��o auxiliar para verificar exist�ncia de um cliente a partir do seu id
int existeCliente(Cliente* inicio, int id);

//Fun��o de inser��o de novo cliente na lista
Cliente* inserirCliente(Cliente* inicio, int id, char nome, int nif, char morada, float saldo);




Cliente* inserirCliente(Cliente* listaClientes, int id, char nome[], int nif, char morada[], float saldo);



void removerCliente(Cliente** listaClientes, Cliente* id);
*/
/*

int inserirMeio();
int removeCliente();
int removeMeio();*/
