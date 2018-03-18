#include <iostream>

using namespace std;


void Max_Heapify(int aray[], int raiz, int tamanho) // "Tornar heap"
{
    int filhoEsq = 2*raiz + 1;  // Filho esquerdo (2i + 1)
    int filhoDir = 2*raiz + 2;  // Filho direito (2i + 2)
    int maior = raiz;  // Inicia o maior como sendo a raiz...


    if (filhoEsq < tamanho && aray[filhoEsq] > aray[maior]) // Verifica se o filho esquerdo existe e se ele for maior que a raiz ocorre a troca..
        maior = filhoEsq;


    if (filhoDir < tamanho && aray[filhoDir] > aray[maior]) // Verifica se o filho direito existe e se ele for maior que a raiz ocorre a troca..
        maior = filhoDir;

    // Se houve troca do valor de "maior" durane os ifs, significa que a raiz não era o maior elemento, então temos que achar heapify para arrumar o resto...
    if (maior != raiz)
    {
        swap(aray[raiz], aray[maior]); // troca os elementos da raiz inicial com o maior elemento apos o 1 heapify.

        Max_Heapify(aray, maior, tamanho); // chama denovo o heapify para arrumar o resto do heap.
    }
}

void HeapSort(int aray[], int tamanho)
{
    // O primeiro passo é criar um heap maximo, para isso vamos utilizar o metodo heapify, nao vamos chamar nas folhas pois ja estao "ordenadas"...
    for (int i = ((tamanho / 2) - 1); i >= 0; i--)
        Max_Heapify(aray, i, tamanho);

    for (int i=(tamanho-1); i>=0; i--)
    {
        // Troca a raiz com o ultimo elemento do heap...
        swap(aray[0], aray[i]);

        // Chama o Max_heapify para tornar o heap novamente num MAX_HEAP...
        Max_Heapify(aray, 0, i);
    }
}

int main()
{
    int aray[] = {5,1,5,8,9,3,1,8,58,582,84,85,1,0,14,5,888};
    int tamanho = sizeof(aray)/sizeof(aray[0]);

   cout << "Antes de ordenar: \n";
    for (int i=0; i<tamanho; ++i)
        cout << aray[i] << " ";
    cout << "\n";;

    HeapSort(aray, tamanho);

    cout << "Depois de ordenar: \n";
    for (int i=0; i<tamanho; ++i)
        cout << aray[i] << " ";
    cout << "\n";;

    return 0;
}



