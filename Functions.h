/*****************************************************************//**
 * \file   Functions.h
 * \brief  Assinatura para todas as funções do programa.
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

//Função para criar novo cliente
Cliente* criarCliente(Cliente *inicio, int id, char nome[], int nif, char morada[], float saldo);

//Função para criar novo meio de mobilidadade
MeioMob* criarMeio(MeioMob* inicio, int id, char tipo[], float carga, float autonomia, float custo, char localizacao[]);

//Função para criar um novo gestor com id e nome
Gestor* criarGestor(Gestor* inicio, int id, char nome[]);

//Função recursiva para salvar lista de clientes em ficheiro binário
void guardarClienteBin(Cliente* c, char arquivo[]);

//Função para listar clientes ao final de um ficheiro de texto
void listarClientes(Cliente* inicio);

Cliente* removerCliente(Cliente* inicio, int id);

/*

//Função auxiliar para verificar existência de um cliente a partir do seu id
int existeCliente(Cliente* inicio, int id);

//Função de inserção de novo cliente na lista
Cliente* inserirCliente(Cliente* inicio, int id, char nome, int nif, char morada, float saldo);




Cliente* inserirCliente(Cliente* listaClientes, int id, char nome[], int nif, char morada[], float saldo);



void removerCliente(Cliente** listaClientes, Cliente* id);
*/
/*

int inserirMeio();
int removeCliente();
int removeMeio();*/
