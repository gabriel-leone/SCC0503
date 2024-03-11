
int main()
{
  // Abre o arquivo indicado como parâmetro no terminal
  FILE *file = fopen("grafo.txt", "r");
  if (file == NULL)
  {
    printf("Erro ao abrir o arquivo\n");
    return 1;
  }

  // Lê o número de vértices
  int vertices;
  fscanf(file, "%d", &vertices);

  // Aloca a matriz de adjacência
  int **matriz = (int **)malloc(vertices * sizeof(int *));
  for (int i = 0; i < vertices; i++)
  {
    matriz[i] = (int *)malloc(vertices * sizeof(int));
  }

  // Inicializa a matriz com 0
  for (int i = 0; i < vertices; i++)
  {
    for (int j = 0; j < vertices; j++)
    {
      matriz[i][j] = 0;
    }
  }

  // Lê as arestas, linha por linha até o final do arquivo
  int origem, destino;
  while (fscanf(file, "%d %d", &origem, &destino) != EOF)
  {
    matriz[origem][destino] = 1;
    matriz[destino][origem] = 1;
  }

  // Fecha o arquivo
  fclose(file);

  // Imprime a matriz de adjacência
  for (int i = 0; i < vertices; i++)
  {
    for (int j = 0; j < vertices; j++)
    {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  // Libera a memória alocada

  for (int i = 0; i < vertices; i++)
  {
    free(matriz[i]);
  }

  free(matriz);

  return 0;
}