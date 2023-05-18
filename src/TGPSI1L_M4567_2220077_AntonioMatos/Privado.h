//Início dos Imports

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stddef.h>
#include <stdbool.h>
#include <mysql.h>

//Fim dos Imports

//Início do Código

#define Reset  "\x1B[0m"
#define Vermelho  "\x1B[31m"
#define Verde  "\x1B[32m"
#define Amarelo  "\x1B[33m"
#define Azul  "\x1B[34m"
#define Magenta  "\x1B[35m"
#define Ciano  "\x1B[36m"
#define Branco  "\x1B[37m"

bool startsWith(const char *haystack, const char *needle)
{
    for (size_t i = 0; needle[i] != '\0'; i++)
    {
        if (haystack[i] != needle[i])
        {
            return false;
        }
    }
    return true;
}

void fullscreen()
{
    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
}

void vtlfunc()
{
    system("start Powershell.exe New-ItemProperty -Path HKCU:\\Console -Name VirtualTerminalLevel -Value 1");
}

void idioma()
{
    setlocale(LC_ALL, "portuguese");
}

void pressanykey()
{
    printf("Pressione alguma tecla para continuar...\n");
    getch();
}

void erro()
{
    printf("Ocorreu um erro ao executar a tarefa requesitada.\n");
    sleep(5);
}

void erroexit()
{
    printf("Ocorreu um erro ao executar a tarefa requesitada.\n");
    sleep(5);
    exit(1);
}

void cls()
{
    system("cls");
}

void title(nometitle)
{
    char msg[60];
    sprintf(msg, "Executando o programa %s...", nometitle);
    SetConsoleTitle(msg);
}

void loadingfunc()
{
    printf("A carregar, por favor aguarde");
    SetConsoleTitle("Loading - [!]");
    printf(".");
    sleep(1);
    SetConsoleTitle("Loading - [/]");
    printf(".");
    sleep(1);
    SetConsoleTitle("Loading - [-]");
    printf(".");
    sleep(1);
    SetConsoleTitle("Loading - [\\]");
    sleep(1);
}

//Fim do Código

#endif
