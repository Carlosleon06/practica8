

int main(void)
{

    int option;
    int corre_programa=1;

    while(corre_programa)
    {

        system("cls"); //WINDOWS    
        printf("\n\r [0] CAMBIAR PRIORIDAD");
        printf("\n\r [1] MOSTRAR COLA DE IMPRESION");
        printf("\n\r [2] AGREGAR ARCHIVO");
        printf("\n\r [3] ELIMINAR ARCHIVO");
        printf("\n\r [4] ELIMINAR TODOS LOS ARCHIVOS");
        printf("\n\r [5] PROCESAR/IMPRIMIR ARCHIVO");
        printf("\n\r [6] TERMINAR PROGRAMA");
        
        printf("\n\r Escoge opcion: ");
        scanf("%d",&option);
        switch(option)
        {
        case 0:
                //MOSTRAR CONTENIDO DE LA CAJA
                system("pause");
                break;
        case 1:

                system("pause");
                break;

        case 2:

                break;

        case 3:
                corre_programa=0;
                break;
        case 4:

                break;

        case 5:

                break;
        case 6:
                corre_programa=0;
                break;

        default:
                break;
        }
        printf("\n\n\r");
        //WINDOWS
    }
    printf("\n\n\r");
    return 0;
}

