#include <stdio.h>
#include "lib.h"


void clear_buffer() {
int x;
while ((x = getchar()) != '\n' && x != EOF) {
   }
}
 
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
  printf("4. Filtrar por prioridade\n");
  printf("5. Filtrar por estado\n");
  printf("6. Filtrar por Categoria\n");
  printf("7. Filtrar por Prioridade e Categoria\n");
  printf("0. Sair\n");
  printf("Opção: ");
  scanf("%d", opcao);
}


//filtros
void filtrar_por_prioridade(lista_tarefa *lt, int prioridade) {
  for (int x = 0; x < lt->qtnd; x++) {
    if (lt->tarefa[x].prioridade == prioridade) {
      printf("Tarefa %d\n", x);
      printf("\tDescrição: %s\n", lt->tarefa[x].descricao);
      printf("\tCategoria: %s\n", lt->tarefa[x].categoria);
      printf("\tPrioridade: %d\n", lt->tarefa[x].prioridade);
      printf("\tEstado: %s\n\n", lt->tarefa[x].estado);
    }
  }
}

void filtro_prioridade(lista_tarefa *lt) {

  int prioridade;
  int cont = 0;
  printf("Digite a prioridade desejada: ");
  scanf("%d", &prioridade);

  for (int x = 0; x < lt->qtnd; x++) {
    // Loop que passa por todas as tarefas. Se a prioridade existir aparece, se não, aparece uma mensagem mostrando que não existe.
    if (lt->tarefa[x].prioridade == prioridade) {
      printf("Tarefa %d\n", x);
      printf("\tDescrição: %s\n", lt->tarefa[x].descricao);
      printf("\tCategoria: %s\n", lt->tarefa[x].categoria);
      printf("\tPrioridade: %d\n", lt->tarefa[x].prioridade);
      printf("\tEstado: %s\n\n", lt->tarefa[x].estado);
      cont += 1;
    }
  }
  if (cont == 0) {
    printf("\tNão há tarefas com a prioridade %d.\n\n", prioridade);
  }
}

void filtrar_estado(
    lista_tarefa *lt) { // filtra pelo estado da tarefa: Completo, em andamento ou nao iniciada
  char estado[15];
  printf("\n");
  printf(
      "Escolha o estado (completo|em andamento|nao iniciado): "); // O usuario escolhe qual vai ser a prioridade que deseja ver
  scanf(" %[^\n]", estado);
  clear_buffer();
  int verificar = 0;

  for (int x = 0; x < lt->qtnd; x++) {
    if (strcmp(lt->tarefa[x].estado, estado) == 0) {
      // logica de comparação para ver o estado que as tarefas estão
      printf("\nEstado: %s\n", lt->tarefa[x].estado);
      printf("Descricao: %s\n", lt->tarefa[x].descricao);
      printf("Categoria: %s\n", lt->tarefa[x].categoria);
      printf("Prioridade: %d\n", lt->tarefa[x].prioridade);
      printf("\n");

      verificar = 1;
    }
  }
  if (!verificar) {
    printf("\nNão existe tarefa com esse estado.\n\n");
  }
}


void filtrar_categoria(
    lista_tarefa *lt) { // Filtrar pelo tipo de categoria e listar por ordem de
                        // prioridade (do mais importante para o menos).
  char categoria[50];
  char categorias_impressas[100][50];
  int num_categorias_impressas = 0;

  printf("Categorias disponiveis: ");
  // função de printar as categorias existentes para pessoa conseguir escolher
  for (int x = 0; x < lt->qtnd; x++) {
    int categoria_repetida = 0;
    for (int y = 0; y < num_categorias_impressas; y++) {
      if (strcmp(lt->tarefa[x].categoria, categoria) == 0) {
        categoria_repetida = 1;
        break;
      }
    }

    if (!categoria_repetida) {
      printf("%s, ", lt->tarefa[x].categoria);
      strcpy(categorias_impressas[num_categorias_impressas],
             lt->tarefa[x].categoria);
      num_categorias_impressas++;
    }
  }

  printf("\nEscolha a categoria: "); // O usuario vai poder escolher qual vai ser a categoria escolhida para o filtro
  scanf(" %[^\n]", categoria);
  printf("\n");
  clear_buffer();
  tarefa tarefas_filtro[100];
  int contar = 0;

  for (int x = 0; x < lt->qtnd; x++) {
    if (strcmp(lt->tarefa[x].categoria, categoria) == 0) {
      tarefas_filtro[contar] = lt->tarefa[x];
      contar++;
    }
  }

  qsort(tarefas_filtro, contar, sizeof(tarefa),
        compara_tarefas); // Função de ordenar do maior numero para o menor pela <stdlib.h>
  exibe_array(tarefas_filtro,contar); // Exibi a tarefa ordenado da forma pedida pelo usuário
}


void filtrar_prioridade_e_categoria(lista_tarefa *lt) { // filtrar por categoria e prioridade. Se não existir tarefa que tenha a categoria e prioridade aparece mensagem falando que n existe
  char categoria[50];
  int prioridade;

  printf("Categorias disponiveis: ");

  char categorias_impressas[100][50];
  int num_categorias_impressas = 0;

  // função de printar as categorias existentes
  for (int x = 0; x < lt->qtnd; x++) {
    int categoria_repetida = 0;
    for (int y = 0; y < num_categorias_impressas; y++) {
      if (strcmp(lt->tarefa[x].categoria, categorias_impressas[y]) == 0) {
        categoria_repetida = 1;
        break;
      }
    }

    if (!categoria_repetida) {
      printf("%s, ", lt->tarefa[x].categoria);
      strcpy(categorias_impressas[num_categorias_impressas],lt->tarefa[x].categoria);
      num_categorias_impressas++;
    }
  }

  printf("\nEscolha a categoria: ");
  scanf(" %[^\n]", categoria);

  printf("Escolha a prioridade (0 a 10): ");
  clear_buffer();
  scanf("%d", &prioridade);
  printf("\n");
  int verificar = 0;

  for (int x = 0; x < lt->qtnd; x++) {
    if (lt->tarefa[x].prioridade == prioridade && strcmp(lt->tarefa[x].categoria, categoria) == 0) { // logica de comparação da prioridade e categoria para mostrar ao usuário
      printf("Categoria: %s\n", lt->tarefa[x].categoria);
      printf("Prioridade: %d\n", lt->tarefa[x].prioridade);
      printf("Descricao: %s\n", lt->tarefa[x].descricao);
      printf("Estado: %s\n", lt->tarefa[x].estado);
      printf("\n");

      verificar = 1;
    }
  }
  if (!verificar) {
    printf("Não existe essa tarefa\n");
  }
}

=======
void alterar_tarefa(lista_tarefa *lt) {
  int tarefa;
  int opcao;
  char alteracao[301];

  listar_tarefa(lt); // mostra todas as tarefas para pessoa conseguir escolher e saber qual tarefa ela quer alterar
  printf("\n");
  printf("Digite o número da tarefa que deseja alterar: "); // escolha de qual tarefa ela quer mudar
  scanf("%d", &tarefa);
  printf("\n");
  printf("Tarefa: %d\n", tarefa);
  printf("Descrição: %s\n", lt->tarefa[tarefa].descricao);
  printf("Categoria: %s\n", lt->tarefa[tarefa].categoria);
  printf("Prioridade: %d\n", lt->tarefa[tarefa].prioridade);
  printf("Estado: %s\n", lt->tarefa[tarefa].estado);
  // mostra as informações da tarefa escolhida

  printf("Escolha o campo que deseja alterar: \n");
  printf("1. Descrição\n");
  printf("2. Categoria\n");
  printf("3. Prioridade\n");
  printf("4. Estado\n");

  printf("Opção: ");
  scanf("%d", &opcao); // escolha do campo que ela quer alterar para começar o if para ver qual opção a pessoa escolheu
  if (opcao == 1) {
    printf("Digite a nova descrição: ");
    clear_buffer();
    scanf("%[^\n]", alteracao);
    strcpy(lt->tarefa[tarefa].descricao,
           alteracao); // função para substiruir a informação dada pelo usuário
  } else if (opcao == 2) {
    printf("Digite a nova categoria: ");
    scanf("%[^\n]", alteracao);
    strcpy(lt->tarefa[tarefa].categoria, alteracao);
  } else if (opcao == 3) {
    printf("Digite a nova prioridade: ");
    scanf("%d", &opcao);
    lt->tarefa[tarefa].prioridade = opcao;
  } else if (opcao == 4) {
    printf("Digite a novo estado (completo|em andamento|nao iniciado): ");
    clear_buffer();
    scanf("%[^\n]", alteracao);
    strcpy(lt->tarefa[tarefa].estado, alteracao);
  }
  printf("Tarefa alterada com sucesso!\n\n");
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
