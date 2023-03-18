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


 
//Função para criar novo cliente
Cliente* criarCliente(Cliente *inicio, int id, char nome[], int nif, char morada[], float saldo);

//Função para criar novo meio de mobilidadade
MeioMob* criarMeio(MeioMob* inicio, int id, char tipo[], float carga, float autonomia, float custo, char localizacao[]);

//Função para criar um novo gestor com id e nome
Gestor* criarGestor(Gestor* inicio, int id, char nome[]);

//Função recursiva para salvar lista de clientes em ficheiro binário
void guardarClienteBin(Cliente* c, char arquivo[]);

//Função recursiva para salvar lista de meios de mobilidade em ficheiro binário
void guardarMeioMobBin(MeioMob* m, char arquivo[]);

//Função para listar clientes ao final de um ficheiro de texto
void listarClientes(Cliente* inicio);

//Função para listar meios de mobilidade em um ficheiro de texto
void listarMeiosMob(MeioMob* inicio);

//função para remover um nó da lista de clientes
Cliente* removerCliente(Cliente* inicio, int id);

//função para remover um nó da lista de clientes
MeioMob* removerMeioMob(MeioMob* inicio, int id);

//função recursiva que encontra um nó na lista através do id
Cliente* buscarCliente(Cliente* inicio, int identificador);

//função para alterar dados de uma struct dentro de uma lista
void alterarCliente(Cliente* inicio, int identificador, int novoid, char novonome[], int novonif, char novamorada[], float novosaldo);

//função recursiva que encontra um nó na lista através do id
MeioMob* buscarMeioMob(MeioMob* inicio, int identificador);

//função para alterar dados de uma struct dentro de uma lista
void alterarMeioMob(MeioMob* inicio, int identificador, int id, char tipo[], float carga, float autonomia, float custo, char localizacao[]);

//função para ordenar 
void ordenarMeioMob(MeioMob* inicio);

//Função para criar novo aluguer
Aluguer* criarAluguer(Cliente* inicioC, Aluguer* inicioA, int id, int idMeio, int idCliente, float custo);

//Função que guarda os aluguéis em um arquivo binário
void guardarAluguerBin(Aluguer* inicio, char arquivo[]); 

//Função para listar meios de mobilidade em um ficheiro de texto
void listarAlugueres(Aluguer* inicio);

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
/*bool existeCliente(Cliente* clientes[], int aux, int n);*/