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

#pragma region Cliente

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
Cliente* criarCliente(Cliente* inicio, int id, char nome[], int nif, char morada[], float saldo)
{
	Cliente* c = (Cliente*)malloc(sizeof(Cliente));
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
		printf("Erro ao abrir o arquivo!");
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
 * Fun��o que recebe a lista de clientes como par�metro e a salva em ficheiro de texto e bin�rio, assim como lista na tela.
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
		printf("% d; % s; % d; % s; % f\n", aux->id, aux->nome, aux->nif, aux->morada, aux->saldo);
		aux = aux->proximo;
	}
	fclose(fp);
	guardarClienteBin(inicio, "Clientes.bin");
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
/**
 * Fun��o para ler ficheiro de texto e alocar em lista.
 * 
 * \param inicio
 * \param arquivo
 * \return 
 */
Cliente* lerFicheiroCliente(Cliente* inicio) {
	FILE* fp;
	fp = fopen("Clientes.txt", "r");
	int id;
	char nome[50];
	int nif;
	char morada[100];
	float saldo;


	if (fp == NULL)
	{
		printf("Erro ao abrir arquivo");
		exit(1);
	}
	Cliente* cliente = NULL;
	while (!feof(fp) != NULL)
	{

		fscanf(fp, "%d;%50[^;];%d;%100[^;];%f\n", &id, nome, &nif, morada, &saldo);
		
		criarCliente(cliente, id, nome, nif, morada, saldo);
		
		
	}

	fclose(fp);
	return inicio;
}

#pragma endregion

#pragma region Meio

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
MeioMob* criarMeio(MeioMob* inicio, int id, char tipo[], float carga, float autonomia, float custo, char localizacao[])
{
	MeioMob* m = (MeioMob*)malloc(sizeof(MeioMob));
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
		printf("Erro ao abrir o arquivo");
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
 * Fun��o que recebe a lista de meios de mobilidade como par�metro e a salva em ficheiro de texto e bin�rio, assim como lista na tela.
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
		printf("%d; %s; %f	; %f; %f; %s\n", aux->id, aux->tipo, aux->carga, aux->autonomia, aux->custo, aux->localizacao);
		aux = aux->proximo;
	}
	fclose(fp);
	guardarMeioMobBin(inicio, "MeiosMob.bin");
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
 * Fun��o recursiva para buscar um n� na lista de meios de mobilidade.
 *
 * \param inicio
 * \param identificador
 * \return
 */
MeioMob* buscarMeioMob(MeioMob* inicio, int identificador) {
	MeioMob* atual = inicio;

	while (atual != NULL) {
		if (atual->id == identificador) {
			return atual;
		}
		atual = atual->proximo;
	}
	return NULL;
}
/**
 * Fun��o que altera os dados da struct MeioMob dentro da lista.
 *
 * \param inicio
 * \param identificador
 * \param id
 * \param tipo
 * \param carga
 * \param autonomia
 * \param custo
 * \param localizacao
 */
void alterarMeioMob(MeioMob* inicio, int identificador, int id, char tipo[], float carga, float autonomia, float custo, char localizacao[]) {

	MeioMob* meio = buscarMeioMob(inicio, identificador);
	if (meio != NULL) {
		meio->id = id;
		strcpy(meio->tipo, tipo);
		meio->carga = carga;
		meio->autonomia = autonomia;
		meio->custo = custo;
		strcpy(meio->localizacao, localizacao);
	}
}
/**
 * Fun��o que ordena os meios de mobilidade em ordem decresente e salva na mem�ria.
 *
 * \param inicio
 */
void ordenarMeioMob(MeioMob* inicio) {
	MeioMob* atual;
	MeioMob* seguinte;
	int troca = 1;

	while (troca) {
		troca = 0;
		atual = inicio;

		while (atual->proximo != NULL) {
			seguinte = atual->proximo;
			if (atual->autonomia < seguinte->autonomia) {
				float aux = atual->autonomia;
				atual->autonomia = seguinte->autonomia;
				seguinte->autonomia = aux;
				troca = 1;
			}
			atual = atual->proximo;
		}
	}
}

#pragma endregion

#pragma region Aluguer

/**
 * Fun��o para criar um novo aluguel e ao final alterar o saldo do cliente locat�rio.
 *
 * \param inicioC
 * \param inicioA
 * \param id
 * \param idMeio
 * \param idCliente
 * \param custo
 * \return
 */
Aluguer* criarAluguer(Cliente* inicioC, Aluguer* inicioA, int id, int idMeio, int idCliente, float custo)
{
	Aluguer* novoAluguer = (Aluguer*)malloc(sizeof(Aluguer));

	if (novoAluguer == NULL) return NULL;
	novoAluguer->proximo = NULL;

	novoAluguer->id = id;
	novoAluguer->idMeio = idMeio;
	novoAluguer->idCliente = idCliente;
	novoAluguer->custo = custo;

	if (inicioA == NULL) {
		inicioA = novoAluguer;
	}
	else {
		novoAluguer->proximo = inicioA;
		inicioA = novoAluguer;
	}

	Cliente* clienteUtente = buscarCliente(inicioC, idCliente);
	int identificador = clienteUtente->id;
	float novoSaldo = clienteUtente->saldo - novoAluguer->custo;

	alterarCliente(inicioC, identificador, clienteUtente->id, clienteUtente->nome, clienteUtente->nif, clienteUtente->morada, novoSaldo);

	return novoAluguer;
}
/**
 * Fun��o para guardar a lista de alugueres em um ficheiro bin�rio.
 *
 * \param inicio
 * \param arquivo
 */
void guardarAluguerBin(Aluguer* inicio, char arquivo[]) {
	FILE* fp = fopen("Aluguer.bin", "wb");
	if (fp == NULL)
	{
		printf("Erro ao abrir o arquivo!");
		return;
	}

	Aluguer* atual = inicio;
	while (atual != NULL)
	{
		Aluguer aux = *atual;
		aux.proximo = NULL;
		fwrite(&aux, sizeof(Aluguer), 1, fp);
		atual = atual->proximo;
	}
	fclose(fp);
}
/**
 * Fun��o que lista os alugueres em mem�ria na tela e em um ficheiro de texto e bin�rio.
 *
 * \param inicio
 */
void listarAlugueres(Aluguer* inicio)
{
	FILE* fp = fopen("Aluguer.txt", "a");
	Aluguer* aux = inicio;

	if (fp == NULL) {
		printf("Erro ao abrir arquivo");
		return;
	}
	while (aux != NULL)
	{
		fprintf(fp, "%d; %d; %d; %f\n", aux->id, aux->idMeio, aux->idCliente, aux->custo);
		printf("% d; % d; % d; % f\n", aux->id, aux->idMeio, aux->idCliente, aux->custo);
		aux = aux->proximo;
	}
	fclose(fp);
	guardarAluguerBin(inicio, "Aluguer.bin");
}

#pragma endregion

/**
 * Fun��o que cria gestor.
 *
 * \param inicio
 * \param id
 * \param nome
 * \return
 */
Gestor* criarGestor(Gestor* inicio, int id, char nome[])
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



//fun��es a serem implementadas
/*
int existeCliente(Cliente* inicio, int id) {

	while (inicio != NULL)
	{
		if (inicio->id == id) return 1;
		inicio = inicio->proximo;
	}
	return(0);
}
*/

