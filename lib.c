#include <stdio.h>
#include "lib.h"

void cadastra_tarefa(lista_tarefa  *lt) {
  char descricao[300];
  char categoria[100];
  int prioridade;
  tarefa tarefa;
  
  printf("Digite a descricao da tarefa %d: ", lt->qtnd);
  scanf("%s", descricao);
  printf("\nDescrição cadastrada com sucesso.\n");
  strcpy(tarefa.descricao, descricao); // copia a string descrição para a variável descricao dentro do struct tarefa
  
  printf("Digite a categoria da tarefa: ");
  scanf("%s", categoria);
  printf("\nCategoria cadastrada com sucesso.\n", categoria);
  strcpy(tarefa.categoria, categoria); // copia a string categoria para a variável categoria do struct tarefa
  
  printf("Por fim, digite a priorirade da tarefa: ");
  scanf("%d", &prioridade);
  printf("\nPrioridade cadastrada com sucesso.\n");
  tarefa.prioridade = prioridade; // atribui à variável prioridade dentro do struct tarefa o inteiro digitado pelo usuário
  
  lt->tarefa[lt->qtnd] = tarefa; // adiciona o struct tarefa preenchido com os dados na variável tarefa[100] do struct lista_tarefa
  lt->qtnd += 1; // faz a variável apontar para a próxima posição do array de tarefas
}

void listar_tarefa(lista_tarefa *lt) {
  for (int x = 0; x < lt->qtnd; x++) { 
    // loop que itera sobre as tarefas dentro do array de struct tarefa[100] e exibe cada informação até chegar na última tarefa através do lt->qtnd
    printf("Tarefa %d\n", x);
    printf("\tDescrição: %s\n", lt->tarefa[x].descricao);
    printf("\tCategoria: %s\n", lt->tarefa[x].categoria);
    printf("\tPrioridade: %d\n", lt->tarefa[x].prioridade);
  }
}

void deleta_tarefa(lista_tarefa *lt, int tarefa) {

  printf("Digite o número da tarefa para deletá-la: ");
  scanf("%d", &tarefa);

  for (; tarefa < lt->qtnd; tarefa++) { 
    // loop que itera a partir da posição da tarefa dentro do array tarefa[100] do struct lista_tarefa que o usuário quer deletar.
    // o loop sobrescreve as variáveis dentro do struct tarefa com as variáveis da próxima tarefa a partir da posição que o usuário digitar
    strcpy(lt->tarefa[tarefa].descricao, lt->tarefa[tarefa + 1].descricao);
    strcpy(lt->tarefa[tarefa].categoria, lt->tarefa[tarefa + 1].categoria);
    lt->tarefa[tarefa].prioridade = lt->tarefa[tarefa].prioridade;
  }
  lt->qtnd -= 1; // diminui o lt->qtnd para a variável apontar para a última tarefa
  printf("Tarefa deletada com sucesso!");
}

void exibe_menu(int *opcao) {

  // função exibe várias opções e pede ao usuário escolher dentre as opções
  printf("Selecione uma das opções abaixo:\n");
  printf("1. Criar tarefa\n");
  printf("2. Deletar tarefa\n");
  printf("3. Listar tarefa\n");
  printf("0. Sair\n");
  printf("Opção: ");
  scanf("%d", opcao);
}

int le_arquivo(lista_tarefa *lt) {

  FILE *f = fopen("tarefas", "rb");
  
  if (f == NULL) {
    return 1; // verifica se existe o arquivo "tarefas". Se não existir, o arquivo será criado ao finalizar o programa.
  }
  else {
    fread(lt, sizeof(lista_tarefa), 1, f); // Caso exista, atualiza as informações presentes no código. Por exemplo o lt->qtnd que sempre se inicia com 0, mas ao abrir o arquivo, o valor pode mudar.
    fclose(f);
  }
  return 0;
}

int escreve_arquivo(lista_tarefa *lt) {

  FILE *f = fopen("tarefas", "wb");

  if (f == NULL) {
    return 1; // verifica se existe o arquivo "tarefas". Se não existir, o arquivo será criado pela função escreve_arquivo.
  }
  else {
    fwrite(lt, sizeof(lista_tarefa), 1, f); // Coloca os dados do struct lista_tarefa no arquivo. Caso o arquivo não existam, essa linha cria o arquivo.
    fclose(f);
  }
}