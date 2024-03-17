#include <stdio.h>

int main()
{
	int n, v[100], lista[100], tamanho = 0, sum = 0, acumulado = 0, tamanho_lista = 0;
	while (scanf("%d", &n) && n != 0)
	{
		v[tamanho] = n;
		tamanho++;
	}
	scanf("%d", &sum);

	for (int i = 0; i < tamanho; i++)
	{
		acumulado += v[i];
		if (acumulado > sum)
		{
			lista[tamanho_lista] = v[i];
			tamanho_lista++;
			acumulado = 0;
		}
	}
	for (int i = tamanho_lista - 1; i >= 0; i--)
	{
		printf("%d\n", lista[i]);
	}
	return 0;
}