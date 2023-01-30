#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "functions.c"

int main()
{

    int octal_value;
    int binary_value;
    int decimal_value;
    char hexa_value[100];

    int option = -1;    // opção do menu principal do programa (inicializada com -1 para entrar no while)
    while (option != 0) // enquanto a opção for diferente de 0
    {
        printf("Choose your option: \n");
        printf("1 - Binary to Decimal\n");
        printf("2 - Binary to Octal\n");
        printf("3 - Decimal to Binary\n");
        printf("4 - Decimal to Octal\n");
        printf("5 - Decimal to Hexa\n");
        printf("6 - Octal to Decimal\n");
        printf("7 - Hexa to Decimal\n");
        printf("0 - Leave\n");
        scanf("%d", &option);
        getchar(); // realizar a entrada de um único caractere pode ser utilizado esta função

        switch (option)
        {
        case 0:
            printf("Leaving.....\n");
            return 0;

        case 1:
            printf("Enter a binary number: \n");
            scanf("%d", &binary_value);
            printf("[%d] in binary = [%d] in decimal\n", binary_value, converterBinToDec(binary_value));

            break;
        case 2:
            printf("Enter a binary number: \n");
            scanf("%d", &binary_value);
            printf("[%d] in binary = [%d] in octal\n", binary_value, converterBinToOctal(binary_value));

            break;
        case 3:
            printf("Enter a decimal number: \n");
            scanf("%d", &decimal_value);
            printf("[%d] in decimal = [%d] in binary\n", decimal_value, converterDecToBin(decimal_value));

            break;
        case 4:
            printf("Enter a decimal number: \n");
            scanf("%d", &decimal_value);
            printf("[%d] in decimal = [%d] in octal\n", decimal_value, converterDecToOct(decimal_value));

            break;
        case 5:
            printf("Enter a decimal number: \n");
            scanf("%d", &decimal_value);
            converterDecToHex(decimal_value, hexa_value);
            printf("[%d] in decimal = [%s] in hexa\n", decimal_value, hexa_value);

            break;
        case 6:
            printf("Enter a octal number: \n");
            scanf("%d", &octal_value);
            printf("[%d] in octal = [%d] in decimal\n", octal_value, converterOctToDec(octal_value));

            break;
        case 7:
            printf("Enter a hexa number: \n");
            fflush(stdin);                 // utilizado para limpar o fluxo/buffer do teclado
            fgets(hexa_value, 100, stdin); // 3 argumentos, no qual a string, o tamanho e o fluxo de entrada
            printf("[%s] in hexa = [%d] in decimal\n", hexa_value, converterHexToDec(hexa_value));

            break;
        }
    }
    return 0;
}
