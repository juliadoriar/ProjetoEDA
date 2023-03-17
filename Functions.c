/*****************************************************************//**
 * \file   FunctionsStorage.c
 * \brief  Implementação das funções recursivas e diretivas a serem usadas no main.c
 * 
 * \author julia
 * \date   March 2023
 *********************************************************************/
#include "Functions.h"
#include "Structs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//Funções para criar Clientes, Meios e Gestores e alocar na memória
/**
 * .
 * 
 * \param inicio
 * \param id
 * \param nome
 * \param nif
 * \param morada
 * \param saldo
 * \return 
 */
Cliente* criarCliente(Cliente * inicio, int id, char nome[], int nif, char morada[], float saldo)
{
	Cliente * c = (Cliente*) malloc(sizeof(Cliente)); 
	if (c != NULL) 
	{
		c->id = id;
		strcpy(c->nome, nome);
		c->nif = nif;
		strcpy(c->morada, morada);
		c->saldo = saldo;
		c->proximo = inicio;

		return c;
	}
	else return(inicio);
}
/**
 * .
 * 
 * \param inicio
 * \param id
 * \param tipo
 * \param carga
 * \param autonomia
 * \param localizacao
 * \return 
 */
MeioMob* criarMeio(MeioMob * inicio, int id, char tipo[], float carga, float autonomia, float custo, char localizacao[])
{
	MeioMob* m = malloc(sizeof(MeioMob));
	if (m != NULL)
	{
		m->id = id;
		strcpy(m->tipo, tipo);
		m->carga = carga;
		m->autonomia = autonomia;
		m->custo = custo;
		strcpy(m->localizacao, localizacao);
		m->proximo = inicio;

		return m;
	}
	else return(inicio); 
}
/**
 * .
 * 
 * \param inicio
 * \param id
 * \param nome
 * \return 
 */
Gestor* criarGestor(Gestor * inicio, int id, char nome[])
{
	Gestor* g = malloc(sizeof(Gestor));
	if (g != NULL)
	{
		g->id = id;
		strcpy(g->nome, nome);
		
		return g;
	}
	else return(inicio);
}
/**
 * Função para verificar se já existem clientes com o mesmo id.
 * 
 * \param inicio
 * \param id
 * \return 
 */
int existeCliente(Cliente* inicio, int id) {

	while (inicio != NULL)
	{	if (inicio->id == id) return 1;
		inicio = inicio->proximo;
	}
	return(0);
}
/**
 * .Função para inserir um novo cliente na lista
 * 
 * \param inicio
 * \param id
 * \param nome
 * \param nif
 * \param morada
 * \param saldo
 * \return 
 */
Cliente* inserirCliente(Cliente* inicio, int id, char nome, int nif, char morada, float saldo)
{
	if (!existeCliente(inicio, id))
	{
		Cliente* novoCliente = malloc(sizeof(Cliente));
		if (novoCliente != NULL) {
			novoCliente->id = id;
			strcpy(novoCliente->nome, nome);
			novoCliente->nif = nif;
			strcpy(novoCliente->morada, morada);
			novoCliente->saldo = saldo;
			novoCliente->proximo = inicio; //aponta para a struct Cliente que se encontra no início da lista

			return novoCliente;
		}
	} else return(inicio);

}
/**
 * Função para listar na tela os clientes cadastrados.
 * 
 * \param inicio
 */
void listarClientes(Cliente* inicio)
{
	while (inicio != NULL)
	{
		printf("%d; %s; %d; %s; %f\n", inicio->id, inicio->nome, inicio->nif, inicio->morada, inicio->saldo);
		inicio = inicio->proximo;
	}
}
/**
 * Função para guardar clientes no ficheiro de texto.
 * 
 * \param inicio
 * \return 
 */
int guardarCliente(Cliente* inicio)
{
	FILE* fp;
	fp = fopen("Clientes.txt", "a+");
	if (fp != NULL)
	{
		Cliente* ptr = inicio;
		while (ptr != NULL)
		{
			fprintf(fp, "%d; %s; %d; %s; %f\n", ptr->id, ptr->nome, ptr->nif, ptr->morada, ptr->saldo);
			ptr = ptr->proximo;
		}
		fclose(fp);
		return(1);
	}
	else return(0);
}




//Funções para inserir nas listas os novos clientes e meios criados

/*
 * .
 *
 * \param listaClientes
 * \param id
 * \param nome
 * \param nif
 * \param morada
 * \param saldo
 * \return
 */


/**
 * .
 * 
 * \param c
 * \return 
 */ /*
Cliente* lerFicheiro(Cliente* c)
{
	FILE* fp = fopen("Clientes.txt", "r");

	if (fp == NULL)
	{
		exit(1);
	}
	Cliente* listaClientes= (Cliente*)malloc(sizeof(Cliente));

	while (!feof(fp))
	{
		fscanf(fp, "%d;%50[^;];%d;%100[^;];%f \n", &(c->id), &c->nome, &(c->nif), &c->morada, (c->saldo));
		listaClientes= InsereCliente(&listaClientes, c);
	}

	fclose(fp);
	return listaClientes;
}
*/

/*
Cliente* removerCliente(Cliente* listaClientes, int id);
{
	Cliente* noAtual = *listaClientes;
	Cliente* noAnterior = NULL;

	if (noAtual == NULL) { return; }

	while (noAtual != NULL && noAtual != id) {
		noAnterior = noAtual;
		noAtual = noAtual->proximo;
	}

	if (noAnterior == NULL) {
		*listaClientes = noAtual->proximo;
	}

	else {
		noAnterior->proximo = noAtual->proximo;
	}

	free(noAtual);
}*/
