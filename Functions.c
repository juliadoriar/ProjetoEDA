/*****************************************************************//**
 * \file   FunctionsStorage.c
 * \brief  Implementa��o das fun��es recursivas e diretivas a serem usadas no main.c
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

/**
 * Fun��o que cria o cliente novo e insere na lista.
 * 
 * \param inicio
 * \param id
 * \param nome
 * \param nif
 * \param morada
 * \param saldo
 * \return 
 */
Cliente* criarCliente(Cliente *inicio, int id, char nome[], int nif, char morada[], float saldo)
{
	Cliente * c = (Cliente*) malloc(sizeof(Cliente)); 
	if (c == NULL) return NULL;
		c->proximo = NULL;
	
		c->id = id;
		strcpy(c->nome, nome);
		c->nif = nif;
		strcpy(c->morada, morada);
		c->saldo = saldo;
		
		if (inicio == NULL) {
			inicio = c;
		}
		else {
			c->proximo = inicio;
			inicio = c;
		}

		return c;
	
	}
/**
 * Fun��o que cria novo meio de mobilidade e insere na lista.
 * 
 * \param inicio
 * \param id
 * \param tipo
 * \param carga
 * \param autonomia
 * \param localizacao
 * \return 
 */
MeioMob* criarMeio(MeioMob *inicio, int id, char tipo[], float carga, float autonomia, float custo, char localizacao[])
{
	MeioMob * m = (MeioMob*) malloc(sizeof(MeioMob));
	if (m == NULL) return NULL;
		m->proximo = NULL;
	
		m->id = id;
		strcpy(m->tipo, tipo);
		m->carga = carga;
		m->autonomia = autonomia;
		m->custo = custo;
		strcpy(m->localizacao, localizacao);
		
		if (inicio == NULL) {
			inicio = m;
		}
		else {
			m->proximo = inicio;
			inicio = m;
		}

		return m;

}
/**
 * Fun��o que cria gestor.
 * 
 * \param inicio
 * \param id
 * \param nome
 * \return 
 */
Gestor* criarGestor(Gestor *inicio, int id, char nome[])
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
 * Fun��o recursiva para guardar clientes da lista em um ficheiro bin�rio.
 * 
 * \param inicio
 * \return 
 */
void guardarClienteBin(Cliente* inicio, char arquivo[])
{
	FILE* fp = fopen("Clientes.bin", "wb"); 
	if (fp == NULL)
	{
		return;
	}

	Cliente* atual = inicio;
	while (atual != NULL)
	{
		Cliente aux = *atual;
		aux.proximo = NULL;
		fwrite(&aux, sizeof(Cliente), 1, fp);
		//fwrite(&(atual->id),&(atual->nome),&(atual->nif),&(atual->morada),&(atual->saldo), aux, sizeof(Cliente), 1, fp);
		atual = atual->proximo;
	}

	fclose(fp);

	}
/**
 *  * Fun��o recursiva para guardar os meios de mobilidade da lista em um ficheiro bin�rio.
 * 
 * \param inicio
 * \param arquivo
 */
void guardarMeioMobBin(MeioMob* inicio, char arquivo[])
{
	FILE* fp = fopen("MeiosMob.bin", "wb");
	if (fp == NULL)
	{
		return;
	}

	MeioMob* atual = inicio;
	while (atual != NULL)
	{
		MeioMob aux = *atual;
		aux.proximo = NULL;
		fwrite(&aux, sizeof(MeioMob), 1, fp);
		atual = atual->proximo;
	}

	fclose(fp);

}
/**
 * Fun��o que recebe a lista de clientes como par�metro e a salva em ficheiro de texto e bin�rio.
 * 
 * \param inicio
 */
void listarClientes(Cliente* inicio)
{
	FILE* fp = fopen("Clientes.txt", "a");
	Cliente* aux = inicio;

	if (fp == NULL) {
		printf("Erro ao abrir arquivo");
		return;
	}
	while (aux != NULL)
	{
		fprintf(fp, "%d; %s; %d; %s; %f\n", aux->id, aux->nome, aux->nif, aux->morada, aux->saldo);
		aux = aux->proximo;
	}
	fclose(fp);
	guardarClienteBin(inicio, "Clientes.bin");
}
/**
 * Fun��o que recebe a lista de meios de mobilidade como par�metro e a salva em ficheiro de texto e bin�rio.
 *
 * \param inicio
 */

void listarMeiosMob(MeioMob* inicio)
{
	FILE* fp = fopen("MeiosMob.txt", "a");
	MeioMob* aux = inicio;

	if (fp == NULL) {
		printf("Erro ao abrir arquivo");
		return;
	}
	while (aux != NULL)
	{
		fprintf(fp, "%d; %s; %f	; %f; %f; %s\n", aux->id, aux->tipo, aux->carga, aux->autonomia, aux->custo, aux->localizacao);
		aux = aux->proximo;
	}
	fclose(fp);
	guardarMeioMobBin(inicio, "MeiosMob.bin");
}


/**
 * Fun��o para remo��o de uma struct Cliente da lista atrav�s do seu id.
 * 
 * \param inicio
 * \param identificador
 * \return 
 */
Cliente* removerCliente(Cliente* inicio, int identificador)
{
	Cliente* atual = inicio;
	Cliente* anterior = NULL;

	//remover o primeiro n� da lista
	if (atual != NULL && atual->id == identificador) { 
		inicio = atual->proximo;
		free(atual);
		return (inicio);
	}
	//percorrer a lista para navegar todos os n�s e remover o que foi passado no par�metro
	while (atual != NULL && atual->id != identificador) {
		anterior = atual;
		atual = atual->proximo;
	}

	//no caso do n� n�o ser encontrado na lista, retorna a lista
	if (atual == NULL) {
		return inicio;
	}

	//sendo encontrado o n� ele � removido, e sua mem�ria liberada
	else {
		anterior->proximo = atual->proximo;
		free(atual);
	}

	return (inicio);
}
/**
 * Fun��o para remo��o de uma struct MeioMob da lista atrav�s do seu id.
 *
 * \param inicio
 * \param identificador
 * \return
 */
MeioMob* removerMeioMob(MeioMob* inicio, int identificador)
{
	MeioMob* atual = inicio;
	MeioMob* anterior = NULL;

	//remover o primeiro n� da lista
	if (atual != NULL && atual->id == identificador) {
		inicio = atual->proximo;
		free(atual);
		return (inicio);
	}
	//percorrer a lista para navegar todos os n�s e remover o que foi passado no par�metro
	while (atual != NULL && atual->id != identificador) {
		anterior = atual;
		atual = atual->proximo;
	}
		//no caso do n� n�o ser encontrado na lista, retorna a lista
	if (atual == NULL) {
		return inicio;
	}
		//sendo encontrado o n� ele � removido, e sua mem�ria liberada
	else {
		anterior->proximo = atual->proximo;
		free(atual);
	}
	return (inicio);
}
/**
 * Fun��o recursiva para buscar um n� na lista de clientes.
 * 
 * \param inicio
 * \param identificador
 * \return 
 */
Cliente* buscarCliente(Cliente* inicio, int identificador) {
	Cliente* atual = inicio;

	while (atual != NULL) {
		if (atual->id == identificador) {
			return atual;
		}
		atual = atual->proximo;		
	}
	return NULL;
}
/**
 * fun��o que altera os dados da struct Cliente dentro da lista.
 * 
 * \param inicio
 * \param identificador
 * \param novoid
 * \param novonome
 * \param novonif
 * \param novamorada
 * \param novosaldo
 */
void alterarCliente(Cliente* inicio, int identificador, int novoid, char novonome[], int novonif, char novamorada[], float novosaldo) {
 
		Cliente* cliente = buscarCliente(inicio, identificador);
		if (cliente != NULL) {
			cliente->id = novoid;
			strcpy(cliente->nome, novonome);
			cliente->nif = novonif;
			strcpy(cliente->morada, novamorada);
			cliente->saldo = novosaldo;

		}
	}


/*

int existeCliente(Cliente* inicio, int id) {

	while (inicio != NULL)
	{
		if (inicio->id == id) return 1;
		inicio = inicio->proximo;
	}
	return(0);
}

/*
Cliente* inserirCliente(Cliente* inicio, int id, char nome[], int nif, char morada[], float saldo)
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
			novoCliente->proximo = inicio; //aponta para a struct Cliente que se encontra no in�cio da lista

			return novoCliente;
		}
	}
	else return(inicio);

}
*/

 /*
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


