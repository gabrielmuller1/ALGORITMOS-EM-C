#include <stdio.h>
#include <string.h>
typedef struct letras{
    char letras[3];
 }Letras;

void quickSortMain(char items[][100], int count);
void quickSort(char items[][100], int left, int right);
void aleatorio(Letras vet[]) {
    int i;
    for (i = 0; i < 100; i++) {
        vet[i].letras[0] = (char) (65 + (rand() % 26));
        vet[i].letras[1] = (char) (65 + (rand() % 26));
        vet[i].letras[2] ='\0';
    }
}

int main(void) {
    Letras vet[100];
    int a;
    char str[][100] = {
        "PH", "QG", "HU", "ME", "AY", "LN", "LF", "DX", "FI", 
        "RC", "VS", "CX", "GG", "BW", "KF", "NQ", "DU", "XW", 
        "FN", "FO", "ZV", "SR", "TK", "JP", "RE", "PG", "GX", 
        "RP", "NR", "VY", "ST", "MW", "CY", "SY", "YC", "QP", 
        "EV", "IK", "EF", "FM", "ZN", "IM", "KK", "AS", "VW", 
        "SR", "EN", "ZK", "YC", "XF", "XT", "LS", "GY", "PS", 
        "FA", "DP", "OO", "EF", "XZ", "BC", "OE", "JU", "VP", 
        "VA", "BO", "YG", "PO", "EY", "LF", "PB", "NP", "LJ", 
        "VR", "VI", "PY", "AM", "YE", "HW", "QN", "QR", "QP", 
        "MX", "UJ", "JL", "OO", "VA", "OW", "UX", "WH", "MS", 
        "NC", "BX", "CO", "KS", "FZ", "KV", "AT", "XD", "KN", 
        "LY"
        };
    aleatorio(vet);
    printf("\nDesordenado:\n");
    int i;
    for (i = 0; i < 100; i++) {
        printf("%s, ",vet[i].letras);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n\nOrdenado:\n");
    quickSortMain(str, 100);

    for (i = 0; i < 100; i++)
  {
    printf("%s, ", str[i]);
    if ((i + 1) % 10 == 0) {
            printf("\n");
        }
  }
  return 0;
}
void quickSortMain(char items[][100], int count)
{
  quickSort(items, 0, count - 1);
}

void quickSort(char items[][100], int left, int right)
{
  int i, j;
  char *x;
  char temp[100];

  i = left;
  j = right;
  x = items[(left + right) / 2];

  do
  {
    while ((strcmp(items[i], x) < 0) && (i < right))
    {
      i++;
    }
    while ((strcmp(items[j], x) > 0) && (j > left))
    {
      j--;
    }
    if (i <= j)
    {
      strcpy(temp, items[i]);
      strcpy(items[i], items[j]);
      strcpy(items[j], temp);
      i++;
      j--;
    }
  } while (i <= j);

  if (left < j)
  {
    quickSort(items, left, j);
  }
  if (i < right)
  {
    quickSort(items, i, right);
  }
}
