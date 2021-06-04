#include <stdio.h>
#include <stdlib.h>
#include <Privado.h>
#include <mysql.h>
#include <time.h>

struct switches
{
    int a;
    int b;
};

struct login
{
    char username[20];
    char password[32];
};

struct registo
{
    char username[20];
    char password[32];
};

struct mysqlvalues
{
    char query1[200];
    char query2[200];
    char query3[200];
    char query4[200];
    char query5[200];
    char query6[200];
};

struct randomnum
{
    int lower;
    int upper;
};

struct randomnum randomnum;
struct login login;
struct registo registo;
struct mysqlvalues mysqlvalues;
struct switches switches;

////////////////////////////////////////

void finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

////////////////////////////////////////

int main()
{
    ////////////////////////////////////////
    MYSQL *con;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *server = "192.168.56.1";
    char *user = "root";
    char *pass = "5603";
    char *database = "psi";
    con = mysql_init(NULL);
    if(!mysql_real_connect(con, server, user, pass, database, 0, NULL, 0))
    {
        fprintf(stderr, "%s\n", mysql_error(con));
    }
    ////////////////////////////////////////
    idioma();
    fullscreen();
    loadingfunc();
    cls();
    title("Waterbank");
    printf("+-------------------------+\n");
    printf("| Bem-vindo ao WaterBank. |\n");
    printf("+-------------------------+\n");
    sleep(5);
principal:
    cls();
    printf("+-------------------------------------+\n");
    printf("| Escolha umas das opções abaixo.     |\n");
    printf("+-------------------------------------+\n");
    printf("| 1 - Login                           |\n");
    printf("| 2 - Registro                        |\n");
    printf("| 3 - Créditos                        |\n");
    printf("| 4 - Sair                            |\n");
    printf("+-------------------------------------+\n");
    printf("| Resposta: ");
    scanf("%i",&switches.a);
    switch(switches.a)
    {
    case 1:
login:
        cls();
        printf("+---------------+\n");
        printf("| Menu do Login |\n");
        printf("+---------------+\n");
        printf("| Username: ");
        scanf("%s",&login.username);
        printf("| Password: ");
        scanf("%s",&login.password);
        sprintf(mysqlvalues.query1, "SELECT * FROM contas WHERE username = '%s' AND password = '%s'", login.username, login.password);
        if(mysql_query(con, mysqlvalues.query1))
        {
            printf("Query failed: %s\n", mysql_error(con));
            exit(0);
        }
        res = mysql_use_result(con);
        if(mysql_fetch_row(res) == NULL)
        {
            printf("Username ou Password incorreto.\n");
            sleep(3);
            goto login;
        }
        mysql_free_result(res);
menu:
        cls();
        printf("+-------------------------------------------+\n");
        printf("| Bem-vindo, escolha uma das opções abaixo. |\n");
        printf("+-------------------------------------------+\n");
        printf("| 1 - Solicitar cartão                      |\n");
        printf("| 2 - Verificar dados/saldo conta bancária  |\n");
        printf("| 3 - Verificar dados cartão                |\n");
        printf("| 4 - Transferir dinheiro                   |\n");
        printf("+-------------------------------------------+\n");
        printf("| Resposta: ");
        scanf("%i",&switches.b);
        switch(switches.b)
        {
        case 1:
            sprintf(mysqlvalues.query2, "SELECT * FROM `contas` WHERE `username` = '%s' AND `Cartao_solicitado` = 0;", login.username);
            if(mysql_query(con, mysqlvalues.query2))
            {
                printf("Query failed: %s\n", mysql_error(con));
                exit(0);
            }
            res = mysql_use_result(con);
            if(mysql_fetch_row(res) == NULL)
            {
                printf("O seu cartão já foi solicitado.\n");
                sleep(3);
                goto menu;
            }
            mysql_free_result(res);
            printf("A solicitação foi feita com sucesso. Aguarde alguns segundos...\n");
            srand(time(NULL));
            int cartao1 = (rand() % (9999 + 1 - 1000)) + 1000;
            sleep(5);
            int cartao2 = (rand() % (9999 + 1 - 1000)) + 1000;
            sleep(5);
            int cartao3 = (rand() % (9999 + 1 - 1000)) + 1000;
            sleep(5);
            int cartao4 = (rand() % (9999 + 1 - 1000)) + 1000;
            sleep(5);
            int cvv = (rand() % (999 + 1 - 100)) + 100;
            char cvvchar[5];
            sprintf(cvvchar, "%i", cvv);
            char cartao[16];
            sprintf(cartao, "%i%i%i%i", cartao1, cartao2, cartao3, cartao4);
            printf("+----------------------------------+\n");
            printf("| Titular                          |\n");
            printf("| %s\n", login.username);
            printf("|                                  |\n");
            printf("| Nº Cartão %s       |\n", cartao);
            printf("|                                  |\n");
            printf("| CVC %s          Validade 2025   |\n", cvvchar);
            printf("+----------------------------------+\n");
            ///////////////////////////////////////////////////////////////////
            int entidade1 = (rand() % (999 + 1 - 100)) + 100;
            sleep(5);
            int entidade2 = (rand() % (99 + 1 - 10)) + 10;
            char entidade[20];
            sprintf(entidade, "%i%i", entidade1, entidade2);
            ////////////////////////////////////////////////////////////////////
            int referencia1 = (rand() % (99999 + 1 - 10000)) + 10000;
            sleep(5);
            int referencia2 = (rand() % (9999 + 1 - 1000)) + 1000;
            char referencia1char[20];
            char referencia2char[20];
            itoa(referencia1, referencia1char, 10);
            itoa(referencia2, referencia2char, 10);
            strcat(referencia1char, referencia2char);
            ////////////////////////////////////////////////////////////////////
            int codigocartao = (rand() % (9999 + 1 - 1000)) + 1000;
            char codigocartaochar[5];
            sprintf(codigocartaochar, "%i", codigocartao);
            printf("\n");
            printf("+----------------------------------+\n");
            printf("| Entidade                         |\n");
            printf("| %s                            |\n", entidade);
            printf("|                                  |\n");
            printf("| Referência %s             |\n", referencia1char);
            printf("|                                  |\n");
            printf("| Código %s                      |\n", codigocartaochar);
            printf("+----------------------------------+\n");
            sprintf(mysqlvalues.query3, "UPDATE `contas` SET Cartao_solicitado = 1, Cartao_codigo = '%s', Cartao_entidade = '%s' WHERE Username = '%s';", codigocartaochar, entidade, login.username);
            if(mysql_query(con, mysqlvalues.query3))
            {
                printf("Query failed: %s\n", mysql_error(con));
                exit(0);
            }
            sprintf(mysqlvalues.query4, "UPDATE `contas` SET Cartao_referencia = '%s', Cartao_numero = '%s', Cartao_ccv = '%s' WHERE Username = '%s';", referencia1char, cartao, cvvchar, login.username);
            if(mysql_query(con, mysqlvalues.query4))
            {
                printf("Query failed: %s\n", mysql_error(con));
                exit(0);
            }
            printf("O seu cartão foi gerado com sucesso. A voltar ao menu...");
            sleep(3);
            goto menu;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 2:
            cls();
            sprintf(mysqlvalues.query5, "SELECT * FROM `contas` WHERE Username = '%s';", login.username);
            if(mysql_query(con, mysqlvalues.query5))
            {
                printf("Query failed: %s\n", mysql_error(con));
                exit(0);
            }
            res = mysql_fetch_row(con);
            if(mysql_fetch_row(res) == NULL)
            {
                erroexit();
            }
            printf("+---------------------------+\n");
            printf("|           IBAN            |\n");
            printf("+---------------------------+\n");
            printf("| %s |\n", row[0]);
            printf("+---------------------------+\n");
        }
        break;
    case 2:
        cls();
        printf("+-----------------+\n");
        printf("| Menu do Registo |\n");
        printf("+-----------------+\n");
        printf("| Username: ");
        scanf("%s",&registo.username);
        printf("| Password: ");
        scanf("%s",&registo.password);
        sprintf(mysqlvalues.query6, "INSERT INTO contas (username, password) VALUES ('%s', '%s');", registo.username, registo.password);
        if(mysql_query(con, mysqlvalues.query6))
        {
            printf("Query failed: %s\n", mysql_error(con));
            exit(0);
        }
        break;
    case 3:
        printf("+---------------+\n");
        printf("|  Programador  |\n");
        printf("+---------------+\n");
        printf("| António Matos |\n");
        printf("+---------------+\n");
        pressanykey();
        goto principal;
        break;
    case 4:
        cls();
        printf("A sair do programa...");
        SetConsoleTitle("A sair do programa...");
        sleep(3);
        exit(0);
        break;
    default:
        erroexit();
    }
}

