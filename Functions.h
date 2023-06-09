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

//Fun��o para listar meios de mobilidade em um ficheiro de texto
void listarMeiosMob(MeioMob* inicio);

//fun��o para remover um n� da lista de clientes
Cliente* removerCliente(Cliente* inicio, int id);

//fun��o para remover um n� da lista de clientes
MeioMob* removerMeioMob(MeioMob* inicio, int id);

//fun��o recursiva que encontra um n� na lista atrav�s do id
Cliente* buscarCliente(Cliente* inicio, int identificador);

//fun��o para alterar dados de uma struct dentro de uma lista
void alterarCliente(Cliente* inicio, int identificador, int novoid, char novonome[], int novonif, char novamorada[], float novosaldo);

//fun��o recursiva que encontra um n� na lista atrav�s do id
MeioMob* buscarMeioMob(MeioMob* inicio, int identificador);

//fun��o para alterar dados de uma struct dentro de uma lista
void alterarMeioMob(MeioMob* inicio, int identificador, int id, char tipo[], float carga, float autonomia, float custo, char localizacao[]);

//fun��o para ordenar 
void ordenarMeioMob(MeioMob* inicio);

//Fun��o para criar novo aluguer
Aluguer* criarAluguer(Cliente* inicioC, Aluguer* inicioA, int id, int idMeio, int idCliente, float custo);

//Fun��o que guarda os alugu�is em um arquivo bin�rio
void guardarAluguerBin(Aluguer* inicio, char arquivo[]); 

//Fun��o para listar meios de mobilidade em um ficheiro de texto
void listarAlugueres(Aluguer* inicio);

//fun��o que l� um ficheiro de texto e insere os dados em uma lista
Cliente* lerFicheiroCliente(Cliente* inicio);


/*
void inserirCliente(Cliente* inicio, int id, char nome[], int nif, char morada[], float saldo);
*/

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
/*bool existeCliente(Cliente* clientes[], int aux, int n);*/