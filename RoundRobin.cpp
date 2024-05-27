#include <iostream>
#include <list>
#include <windows.h>
#include <cctype>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
using namespace std;


void gotoxy(int x, int y)
{
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);
}

struct Marcos 
{
    int ID_Proceso = 0;
    bool Disponible = false;
    string Estado = "";
    int Memoria = 0;
};

class Proceso
{
    public:
        Proceso():operador("none"),num1("none"),num2("none"),tiempo_estimado(0),ID(0),lote_perteneciente(0),
                    resultado(0), no_proceso(0),tiempo_transcurrido(0),flag_error(0),flag_respuesta(0),tiempo_bloqueado(0),tiempo_respuesta(0),
                    tiempo_finalizacion(0),tiempo_llegada(0),tiempo_espera(0),tiempo_retorno(0),espacio_memoria(0){};

        Proceso(string op,string n1,string n2,int tiempo,int IDE,int lote, float res, int proc, int TT, int FE, int FR, int TB, int TR, int TF, int TLL, int TE, int TRT, int EM):operador(op),
                    num1(n1),num2(n2),tiempo_estimado(tiempo),ID(IDE),lote_perteneciente(lote),resultado(res),no_proceso(proc), 
                    tiempo_transcurrido(TT),flag_error(FE),flag_respuesta(FR),tiempo_bloqueado(TB),tiempo_respuesta(TR),tiempo_finalizacion(TF),
                    tiempo_llegada(TLL), tiempo_espera(TE),tiempo_retorno(TRT),espacio_memoria(EM){};

        void set_operador(string op);
        void set_num1(string n1);
        void set_num2(string n2);
        void set_tiempo(int tiempo);
        void set_ID(int IDE);
        void set_lote(int lote);
        void set_resultado(float res);
        void set_NumProceso(int proc);
        void set_TT(int TT);
        void set_FlagError(int FE);
        void set_FlagRespuesta(int FR);
        void set_TmpBloqueado(int TB);
        void set_TmpRespuesta(int TR);
        void set_TmpFinalizacion(int TF);
        void set_TmpLlegada(int TLL);
        void set_TmpEspera(int TE);
        void set_TmpRetorno(int TRT);
        void set_EspacioMemoria(int EM);

        string get_operador(void);
        string get_n1(void);
        string get_n2(void);
        int get_tiempo(void);
        int get_ID(void);
        int get_lote(void);
        float get_resultado(void);
        int get_NumProceso(void);
        int get_TT(void);
        int get_FlagError(void);
        int get_FlagRespuesta(void);
        int get_TmpBloqueado(void);
        int get_TmpRespuesta(void);
        int get_TmpFinalizacion(void);
        int get_TmpLlegada(void);
        int get_TmpEspera(void);
        int get_TmpRetorno(void);
        int get_EspacioMemoria(void);


    private:
    
        string operador, num1, num2;
        int tiempo_estimado;
        int ID;
        int lote_perteneciente;
        int resultado;
        int no_proceso;
        int tiempo_transcurrido;
        int flag_error;
        int flag_respuesta;
        int tiempo_bloqueado;
        int tiempo_respuesta;
        int tiempo_finalizacion;
        int tiempo_llegada;
        int tiempo_espera;
        int tiempo_retorno;
        int espacio_memoria;
};

//////////////////////////////////////MÉTODOS SETS//////////////////////////////////////////////

void Proceso::set_operador(string op)
{
    operador = op;
}

void Proceso::set_num1(string n1)
{
    num1 = n1;
}

void Proceso::set_num2(string n2)
{
    num2 = n2;
}

void Proceso::set_tiempo(int tiempo)
{
    tiempo_estimado = tiempo;
}

void Proceso::set_ID(int IDE)
{
    ID = IDE;
}

void Proceso::set_lote(int lote)
{
    lote_perteneciente = lote;
}

void Proceso::set_resultado(float res)
{   
    resultado = res;
}

void Proceso::set_NumProceso(int proc)
{   
    no_proceso = proc;
}

void Proceso::set_TT(int TT)
{   
    tiempo_transcurrido = TT;
}

void Proceso::set_FlagError(int FE)
{   
    flag_error = FE;
}

void Proceso::set_FlagRespuesta(int FR)
{   
    flag_respuesta = FR;
}

void Proceso::set_TmpBloqueado(int TB)
{   
    tiempo_bloqueado = TB;
}

void Proceso::set_TmpRespuesta(int TR)
{   
    tiempo_respuesta = TR;
}

void Proceso::set_TmpFinalizacion(int TF)
{   
    tiempo_finalizacion = TF;
}

void Proceso::set_TmpLlegada(int TLL)
{   
    tiempo_llegada = TLL;
}

void Proceso::set_TmpEspera(int TE)
{   
    tiempo_espera = TE;
}

void Proceso::set_TmpRetorno(int TRT)
{   
    tiempo_retorno = TRT;
}

void Proceso::set_EspacioMemoria(int EM)
{   
    espacio_memoria = EM;
}

/////////////////////////////////MÉTODOS GETS////////////////////////////////////////////

string Proceso::get_operador()
{
    return operador;
}

string Proceso::get_n1()
{
    return num1;
}

string Proceso::get_n2()
{
    return num2;
}

int Proceso::get_tiempo()
{
    return tiempo_estimado;
}

int Proceso::get_ID()
{
    return ID;
}

int Proceso::get_lote()
{
    return lote_perteneciente;
}

float Proceso::get_resultado()
{
    return resultado;
}

int Proceso::get_NumProceso()
{
    return no_proceso;
}

int Proceso::get_TT()
{
    return tiempo_transcurrido;
}

int Proceso::get_FlagError()
{   
    return flag_error;
}

int Proceso::get_FlagRespuesta()
{   
    return flag_respuesta;
}

int Proceso::get_TmpBloqueado()
{   
    return tiempo_bloqueado;
}

int Proceso::get_TmpRespuesta()
{   
    return tiempo_respuesta;
}

int Proceso::get_TmpFinalizacion()
{   
    return tiempo_finalizacion;
}

int Proceso::get_TmpLlegada()
{   
    return tiempo_llegada;
}

int Proceso::get_TmpEspera()
{   
    return tiempo_espera;
}

int Proceso::get_TmpRetorno()
{   
    return tiempo_retorno;
}

int Proceso::get_EspacioMemoria()
{   
    return espacio_memoria;
}


float res_operacion(string num1, string num2, string operador)
{
    int numero1 = stoi(num1);
    int numero2 = stoi(num2); 
    float resultado;
    if(operador == "+"){
        resultado = numero1 + numero2;
    }else if(operador == "-"){
        resultado = numero1 - numero2;
    }else if(operador == "*"){
        resultado = numero1 * numero2;
    }else if(operador == "/"){
        resultado = numero1 / numero2;
    }else if(operador == "r"){
        resultado = numero1 % numero2;
    }else{
        resultado = (static_cast<double>(numero1) / numero2) * 100.0;
    } 
    return resultado;
};

int rand_time()
{
    int random = 6 + (rand() % 13);
    return random;
};

string numeros_random()
{
    int random = 1 + (rand() % 99);
    string num = to_string(random);
    return num;
}

string operador_random()
{
    int random = 1 + (rand() % 6);
    string operador;
    switch(random)
    {
        case 1:
            operador = "+";
            break;
        case 2:
            operador = "-";
            break;
        case 3:
            operador = "*";
            break;
        case 4:
            operador = "/";
            break;
        case 5:
            operador = "r";
            break;
        case 6:
            operador = "%";
            break;
    }
    return operador;
}

int memoria_random()
{
    int random = 6 + (rand() % 21);
    return random;
}

void inicializarSemilla() {
    srand(static_cast<unsigned>(time(NULL)));
}

void Bloqueados(list<Proceso>& cola_bloqueados, list<Proceso>& lote_ejecucion, Marcos *Marco)
{
    int incremento_bloqueados = 0;
    for(Proceso& proceso : cola_bloqueados)
    {
        proceso.set_TmpEspera(proceso.get_TmpEspera()+1);
        proceso.set_TmpBloqueado(proceso.get_TmpBloqueado()-1);
        gotoxy(8,23+incremento_bloqueados);cout<<proceso.get_ID();
        gotoxy(24,23+incremento_bloqueados);cout<<proceso.get_TmpBloqueado();
        incremento_bloqueados++;
    }
    Proceso& proceso = cola_bloqueados.front();
    if(proceso.get_TmpBloqueado() <= 0)
    {
        for(int i=0; i<40; i++){
            if(Marco[i].ID_Proceso == proceso.get_ID())
                Marco[i].Estado = "L";
        }
        lote_ejecucion.splice(lote_ejecucion.end(), cola_bloqueados,cola_bloqueados.begin());
    }
}

void Terminados(list<Proceso>& cola_terminados)
{
    int incremento = 0;
    for(Proceso& proceso : cola_terminados)
    {
        gotoxy(84,6+incremento);cout<<proceso.get_ID();
        gotoxy(96,6+incremento);cout<<proceso.get_n1()<<proceso.get_operador()<<proceso.get_n2();
        if(proceso.get_FlagError() == 1)
        {
            gotoxy(108,6+incremento);cout<<"ERROR";
        }else{
            gotoxy(108,6+incremento);cout<<proceso.get_resultado();
        } 
        incremento = incremento + 1;
    }
}

void BCP(list<Proceso>& cola_terminados,list<Proceso>& listaProcesos,list<Proceso>& cola_bloqueados,list<Proceso>& lote_ejecucion,list<Proceso>& en_ejecucion, int bandera_visualizar, list<Proceso>& suspendidos)
{
    system("cls");
    int incremento_terminados = 0;
    gotoxy(2,0);cout<<"#";gotoxy(49,0);cout<<"    Tabla BCP";gotoxy(119,0);cout<<"#";
    gotoxy(2,1);cout<<"######################################################################################################################";   
    gotoxy(2,2);cout<<"#";gotoxy(2,3);cout<<"#";gotoxy(2,4);cout<<"#";gotoxy(2,5);cout<<"#";gotoxy(2,6);cout<<"#";gotoxy(2,7);cout<<"#";gotoxy(2,8);cout<<"#";
    gotoxy(119,2);cout<<"#";gotoxy(119,3);cout<<"#";gotoxy(119,4);cout<<"#";gotoxy(119,5);cout<<"#";gotoxy(119,6);cout<<"#";gotoxy(119,7);cout<<"#";gotoxy(119,8);cout<<"#";
    gotoxy(5,2);cout<<"ID   Operacion   Resultado   T.Llegada   T.Fin   T.Retorno  T.Res  T.Espera   T.Servicio    TME       Estado";
    ///TERMINADOS
    for(Proceso& proceso: cola_terminados)
    {
        proceso.set_TmpRetorno(proceso.get_TmpEspera()+proceso.get_TT());
        gotoxy(5,3+incremento_terminados);cout<<proceso.get_ID();
        gotoxy(12,3+incremento_terminados);cout<<proceso.get_n1()<<proceso.get_operador()<<proceso.get_n2();
        if(proceso.get_FlagError() == 1)
        {
            gotoxy(24,3+incremento_terminados);cout<<"ERROR";
        }else{
            gotoxy(24,3+incremento_terminados);cout<<proceso.get_resultado();
        }
        gotoxy(38,3+incremento_terminados);cout<<proceso.get_TmpLlegada();
        gotoxy(48,3+incremento_terminados);cout<<proceso.get_TmpFinalizacion();
        gotoxy(58,3+incremento_terminados);cout<<proceso.get_TmpRetorno();
        gotoxy(67,3+incremento_terminados);cout<<proceso.get_TmpRespuesta();
        gotoxy(75,3+incremento_terminados);cout<<proceso.get_TmpEspera();
        gotoxy(87,3+incremento_terminados);cout<<proceso.get_TT();
        gotoxy(98,3+incremento_terminados);cout<<proceso.get_tiempo();
        gotoxy(107,3+incremento_terminados);cout<<"Finalizado";
        incremento_terminados++;
    }
    ///EN_EJECUCION
    for(Proceso& proceso: en_ejecucion)
    {
        proceso.set_TmpRetorno(proceso.get_TmpEspera()+proceso.get_TT());
        gotoxy(5,3+incremento_terminados);cout<<proceso.get_ID();
        gotoxy(12,3+incremento_terminados);cout<<proceso.get_n1()<<proceso.get_operador()<<proceso.get_n2();
        gotoxy(23,3+incremento_terminados);cout<<"- - - -";
        gotoxy(38,3+incremento_terminados);cout<<proceso.get_TmpLlegada();
        gotoxy(45,3+incremento_terminados);cout<<"- - - -";
        gotoxy(55,3+incremento_terminados);cout<<"- - - -";
        gotoxy(67,3+incremento_terminados);cout<<proceso.get_TmpRespuesta();
        gotoxy(75,3+incremento_terminados);cout<<proceso.get_TmpEspera();
        gotoxy(87,3+incremento_terminados);cout<<proceso.get_TT();
        gotoxy(98,3+incremento_terminados);cout<<proceso.get_tiempo();
        gotoxy(107,3+incremento_terminados);cout<<"En Ejecucion";
        incremento_terminados++;
    }
    ///LISTOS
    for(Proceso& proceso: lote_ejecucion)
    {
        proceso.set_TmpRetorno(proceso.get_TmpEspera()+proceso.get_TT());
        gotoxy(5,3+incremento_terminados);cout<<proceso.get_ID();
        gotoxy(12,3+incremento_terminados);cout<<proceso.get_n1()<<proceso.get_operador()<<proceso.get_n2();
        gotoxy(23,3+incremento_terminados);cout<<"- - - -";
        gotoxy(38,3+incremento_terminados);cout<<proceso.get_TmpLlegada();
        gotoxy(45,3+incremento_terminados);cout<<"- - - -";
        gotoxy(55,3+incremento_terminados);cout<<"- - - -";
        gotoxy(67,3+incremento_terminados);cout<<proceso.get_TmpRespuesta();
        gotoxy(75,3+incremento_terminados);cout<<proceso.get_TmpEspera();
        gotoxy(87,3+incremento_terminados);cout<<proceso.get_TT();
        gotoxy(98,3+incremento_terminados);cout<<proceso.get_tiempo();
        gotoxy(107,3+incremento_terminados);cout<<"Listo";
        incremento_terminados++;
    }
    ///BLOQUEADOS
    for(Proceso& proceso: cola_bloqueados)
    {
        proceso.set_TmpRetorno(proceso.get_TmpEspera()+proceso.get_TT());
        gotoxy(5,3+incremento_terminados);cout<<proceso.get_ID();
        gotoxy(12,3+incremento_terminados);cout<<proceso.get_n1()<<proceso.get_operador()<<proceso.get_n2();
        gotoxy(23,3+incremento_terminados);cout<<"- - - -";
        gotoxy(38,3+incremento_terminados);cout<<proceso.get_TmpLlegada();
        gotoxy(45,3+incremento_terminados);cout<<"- - - -";
        gotoxy(55,3+incremento_terminados);cout<<"- - - -";
        gotoxy(67,3+incremento_terminados);cout<<proceso.get_TmpRespuesta();
        gotoxy(75,3+incremento_terminados);cout<<proceso.get_TmpEspera();
        gotoxy(87,3+incremento_terminados);cout<<proceso.get_TT();
        gotoxy(98,3+incremento_terminados);cout<<proceso.get_tiempo();
        gotoxy(107,3+incremento_terminados);cout<<"Bloqueado-"<<proceso.get_TmpBloqueado();
        incremento_terminados++;
    }
    ///SUSPENDIDOS
    for(Proceso& proceso: suspendidos)
    {
        proceso.set_TmpRetorno(proceso.get_TmpEspera()+proceso.get_TT());
        gotoxy(5,3+incremento_terminados);cout<<proceso.get_ID();
        gotoxy(12,3+incremento_terminados);cout<<proceso.get_n1()<<proceso.get_operador()<<proceso.get_n2();
        gotoxy(23,3+incremento_terminados);cout<<"- - - -";
        gotoxy(38,3+incremento_terminados);cout<<proceso.get_TmpLlegada();
        gotoxy(45,3+incremento_terminados);cout<<"- - - -";
        gotoxy(55,3+incremento_terminados);cout<<"- - - -";
        gotoxy(67,3+incremento_terminados);cout<<proceso.get_TmpRespuesta();
        gotoxy(75,3+incremento_terminados);cout<<proceso.get_TmpEspera();
        gotoxy(87,3+incremento_terminados);cout<<proceso.get_TT();
        gotoxy(98,3+incremento_terminados);cout<<proceso.get_tiempo();
        gotoxy(107,3+incremento_terminados);cout<<"Suspendido";
        incremento_terminados++;
    }
    ///NUEVOS
    for(Proceso& proceso: listaProcesos)
    {
        proceso.set_TmpRetorno(proceso.get_TmpEspera()+proceso.get_TT());
        gotoxy(5,3+incremento_terminados);cout<<proceso.get_ID();
        gotoxy(12,3+incremento_terminados);cout<<proceso.get_n1()<<proceso.get_operador()<<proceso.get_n2();
        gotoxy(23,3+incremento_terminados);cout<<"- - - -";
        gotoxy(35,3+incremento_terminados);cout<<"- - - -";
        gotoxy(45,3+incremento_terminados);cout<<"- - - -";
        gotoxy(55,3+incremento_terminados);cout<<"- - - -";
        gotoxy(64,3+incremento_terminados);cout<<"- - - -";
        gotoxy(73,3+incremento_terminados);cout<<"- - - -";
        gotoxy(84,3+incremento_terminados);cout<<"- - - -";
        gotoxy(98,3+incremento_terminados);cout<<proceso.get_tiempo();
        gotoxy(107,3+incremento_terminados);cout<<"Nuevo";
        incremento_terminados++;
    }
    if(bandera_visualizar == 1)
    {
        gotoxy(38,6+incremento_terminados);cout<<"MODO VISUALIZACION";
        while(true)
        {
            if(kbhit())
            {
                char tecla = getch();
                if(tecla == 'c' || tecla == 'C'){
                    system("cls");
                    break;
                }            
            }
        }
    }
}

void Nuevos_Procesos(list<Proceso>& listaProcesos, int ID_actual)
{
    Proceso NuevoProceso;
    NuevoProceso.set_num1(numeros_random());
    NuevoProceso.set_num2(numeros_random());
    NuevoProceso.set_operador(operador_random());
    NuevoProceso.set_resultado(res_operacion(NuevoProceso.get_n1(),NuevoProceso.get_n2(),NuevoProceso.get_operador()));
    NuevoProceso.set_tiempo(rand_time());
    NuevoProceso.set_TT(0);
    NuevoProceso.set_ID(ID_actual);
    NuevoProceso.set_EspacioMemoria(memoria_random());
    listaProcesos.push_back(NuevoProceso);
}

void interfaz_ejecucion(list<Proceso>& listaProcesos, int quantum_global)
{
    gotoxy(4,0);cout<<"--No.Procesos Pendientes:    ";gotoxy(30,0);cout<<listaProcesos.size();
    gotoxy(2,1);cout<<"######################################################################################################################";
    gotoxy(2,3);cout<<"######################################################################################################################";
    gotoxy(2,0);cout<<"#";gotoxy(34,0);cout<<"#";gotoxy(61,0);cout<<"#";
    gotoxy(2,2);cout<<"#";gotoxy(2,3);cout<<"#";gotoxy(2,4);cout<<"#";gotoxy(2,5);cout<<"#";gotoxy(2,6);cout<<"#";
    gotoxy(37,2);cout<<"#";gotoxy(37,3);cout<<"#";gotoxy(37,4);cout<<"#";gotoxy(37,5);cout<<"#";gotoxy(37,6);cout<<"#";
    gotoxy(76,2);cout<<"#";gotoxy(76,3);cout<<"#";gotoxy(76,4);cout<<"#";gotoxy(76,5);cout<<"#";gotoxy(76,6);cout<<"#";
    gotoxy(119,2);cout<<"#";gotoxy(119,3);cout<<"#";gotoxy(119,4);cout<<"#";gotoxy(119,5);cout<<"#";gotoxy(119,6);cout<<"#";
    gotoxy(8,2);cout<<"Procesos Listos";
    gotoxy(6,4);cout<<"'ID'";
    gotoxy(14,4);cout<<"'TME'";
    gotoxy(23,4);cout<<"'TT'";
    gotoxy(29,4);cout<<"'MEM'";
    gotoxy(8,20);cout<<"Cola Bloqueados";
    gotoxy(6,22);cout<<"'ID'";
    gotoxy(18,22);cout<<"'T.Bloqueado'";
    gotoxy(48,2);cout<<"Proceso en Ejecucion";
    gotoxy(88,2);cout<<"Procesos  Terminado";
    gotoxy(83,4);cout<<"'ID'";
    gotoxy(96,4);cout<<"'OP'"; 
    gotoxy(108,4);cout<<"'RES'"; 
    gotoxy(45,16);cout<<"Pausa [P]";
    gotoxy(45,17);cout<<"Continuar [C]";
    gotoxy(45,18);cout<<"Error [E]";
    gotoxy(45,19);cout<<"Interrupcion [I]";
    gotoxy(45,20);cout<<"BCP [B]";
    gotoxy(45,21);cout<<"Nuevo Proceso [N]";
    gotoxy(45,22);cout<<"Tabla de Paginacion [T]";
    gotoxy(45,23);cout<<"Suspendido [S]";
    gotoxy(45,24);cout<<"Regresa [R]";
    gotoxy(45,27);cout<<"Procesos Suspendidos:       ";
    gotoxy(45,28);cout<<"ID            MEM";
    gotoxy(37,0);cout<<"--Contador Global:     ";
    gotoxy(63,0);cout<<"--Quantum asignado: "<<quantum_global;
}

void tabla_paginacion(Marcos *Marco, int tamano, int flag)
{
    if(flag == 1)
        system("cls");
    int incremento_marcos = 0;
    int posicion_x = (flag == 0) ? 140 : 88;
    for(int i=0; i<tamano; i++)
    {
        gotoxy(posicion_x+3,2+incremento_marcos);
        if(Marco[i].Disponible == true)
        {    
            cout<<i<<"     "<<Marco[i].ID_Proceso<<"    "<<Marco[i].Memoria<<"/5    "<<Marco[i].Estado;
        }else{
            cout<<i<<"                                           ";
        }
        incremento_marcos++;
    }
    gotoxy(posicion_x,1);cout<<"No. M   ID    MEM   EST";
    gotoxy(posicion_x+3,0);cout<<"Tabla de Paginacion";
    gotoxy(posicion_x+3,42);cout<<"40 SISTEMA OPERATIVO";
    gotoxy(posicion_x+3,43);cout<<"41 SISTEMA OPERATIVO";
    gotoxy(posicion_x+3,44);cout<<"42 SISTEMA OPERATIVO";
    gotoxy(posicion_x+3,45);cout<<"43 SISTEMA OPERATIVO";
    if(flag == 1)
    {
        gotoxy(92,6+incremento_marcos);cout<<"MODO VISUALIZACION";
        while(true)
        {
            if(kbhit())
            {
                char tecla = getch();
                if(tecla == 'c' || tecla == 'C'){
                    system("cls");
                    break;
                }            
            }
        }
    }

}

void agregar_procesos(Marcos *Marco, int tamano, list<Proceso>& lista_destino, list<Proceso>& lista_origen, int contador_global, int flag)
{
    while(true)
    {
        if(lista_origen.empty())
            break;
        ///HACER UN IF DE MODOD QUE SI ES UN PROCESO PROVENIENTE
        ///DE SUSPENDIDOS O LISTAPROCESOS    
        Proceso& proceso = lista_origen.front();
        int marco, modulo, marcos_libres = 0;
        marco = proceso.get_EspacioMemoria()/5;
        modulo = proceso.get_EspacioMemoria()%5;
        if(modulo!=0)
            marco++;
        
        ///VALIDAR SI HAY ESPACIOS DISPONIBLES
        for(int i=0; i<tamano; i++)
        {
            if(Marco[i].Disponible == false)
                marcos_libres++;
        }
        
        if(marcos_libres >= marco)
        {
            if(flag == 0)
                proceso.set_TmpLlegada(contador_global);
            lista_destino.splice(lista_destino.end(),lista_origen,lista_origen.begin());
            int Memoria = proceso.get_EspacioMemoria();
            for(int i=0; i<tamano; i++)
            {
                if((Marco[i].Disponible == false) and (Memoria != 0))
                {
                    Marco[i].ID_Proceso = proceso.get_ID();
                    Marco[i].Disponible = true;
                    Marco[i].Estado = (flag==0) ? "L" : "B";
                    if(Memoria >= 5)
                    {
                        Marco[i].Memoria = 5;
                        Memoria = Memoria - 5;
                    }else{
                        Marco[i].Memoria = Memoria;
                        break;
                    }
                }
            }
            if(flag == 1){
                proceso.set_TmpBloqueado(9);
                break;
            }
        }else{
            break;
        }

    }
}

void suspender_proceso(list<Proceso>& cola_bloqueados, list<Proceso>& suspendidos, Marcos* Marco, list<Proceso>& lote_ejecucion, list<Proceso>& listaProcesos, int contador_global)
{
    Proceso proceso = cola_bloqueados.front();
    suspendidos.splice(suspendidos.end(), cola_bloqueados, cola_bloqueados.begin());
    for(int i=0; i<40; i++){
        if(Marco[i].ID_Proceso == proceso.get_ID())
            Marco[i].Disponible = false;
    }
    agregar_procesos(Marco, 40, lote_ejecucion, listaProcesos, contador_global, 0);
}

void Mostrar_suspendidos(list<Proceso>& suspendidos)
{
    ofstream archivo("suspendidos.txt", ofstream::out);
    int incremento_suspendido = 0;
    for(Proceso& proceso : suspendidos)
    {
        archivo<<"ID: "<<proceso.get_ID()<<", Espacio Memoria: "<<proceso.get_EspacioMemoria()<<"\n";
        proceso.set_TmpEspera(proceso.get_TmpEspera() + 1);
        gotoxy(45,29+incremento_suspendido);cout<<proceso.get_ID();
        gotoxy(59,29+incremento_suspendido);cout<<proceso.get_EspacioMemoria();
        incremento_suspendido++;
    }
    archivo.close();
}

void Limpieza_datos()
{
    gotoxy(7,23);cout<<"                        ";
    gotoxy(7,24);cout<<"                        ";
    gotoxy(7,25);cout<<"                        ";
    gotoxy(7,26);cout<<"                        ";
    gotoxy(7,27);cout<<"                        ";
    gotoxy(7,28);cout<<"                        ";
    gotoxy(7,29);cout<<"                        ";
    gotoxy(7,30);cout<<"                        ";
    gotoxy(7,31);cout<<"                        ";
    gotoxy(7,32);cout<<"                        ";
    gotoxy(7,33);cout<<"                        ";
    gotoxy(7,34);cout<<"                        ";

    gotoxy(44,29);cout<<"                        ";
    gotoxy(44,30);cout<<"                        ";
    gotoxy(44,31);cout<<"                        ";
    gotoxy(44,32);cout<<"                        ";
    gotoxy(44,33);cout<<"                        ";
    gotoxy(44,34);cout<<"                        ";
    gotoxy(44,35);cout<<"                        ";
    gotoxy(44,36);cout<<"                        ";
    gotoxy(44,37);cout<<"                        ";
    gotoxy(44,38);cout<<"                        ";
    gotoxy(44,39);cout<<"                        ";
    gotoxy(44,40);cout<<"                        ";
}

int main()
{
    Marcos Marco[40]{};
    list<Proceso> listaProcesos;
    int quantum_global, procesos, contador_global = 0, ID_actual=1;
    gotoxy(35,4);cout<<"###############################################"<<endl;
    gotoxy(35,5);cout<<"# --------- SIMULACION DE PROCESOS ---------- #"<<endl;
    gotoxy(35,6);cout<<"###############################################"<<endl;
    gotoxy(35,12);cout<<"###############################################"<<endl;
    gotoxy(35,7);cout<<"#"<<endl;gotoxy(35,8);cout<<"#"<<endl;gotoxy(35,9);cout<<"#"<<endl;gotoxy(35,10);cout<<"#"<<endl;gotoxy(35,11);cout<<"#"<<endl;
    gotoxy(81,7);cout<<"#"<<endl;gotoxy(81,8);cout<<"#"<<endl;gotoxy(81,9);cout<<"#"<<endl;gotoxy(81,10);cout<<"#"<<endl;gotoxy(81,11);cout<<"#"<<endl;
    gotoxy(45,8);cout<<"Procesos a Emplearse [    ]";
    gotoxy(68,8);cin>>procesos;
    gotoxy(45,9);cout<<"Quantum asignado [    ]";
    gotoxy(64,9);cin>>quantum_global;
    inicializarSemilla();
    for(int i=1; i<=procesos; i++)
    {
        Nuevos_Procesos(listaProcesos, i);
        ID_actual++;
    }
    system("cls");

    ///EJECUCIÓN DE PROCESOS
    int procesos_guardados = 0, quantum_proceso = 0;
    list<Proceso> en_ejecucion, lote_ejecucion, cola_bloqueados, cola_terminados, suspendidos;
    agregar_procesos(Marco, 40, lote_ejecucion, listaProcesos, contador_global, 0);
    en_ejecucion.splice(en_ejecucion.begin(),lote_ejecucion,lote_ejecucion.begin());
    while(procesos_guardados < procesos)
    {
        int ban_error = 0, ban_interrupcion = 0, ban_nuevo = 0, ban_quantum = 0;
        interfaz_ejecucion(listaProcesos, quantum_global);      ///INTERFAZ DE PROCESOS
        Terminados(cola_terminados);                            ///COLUMNA PROCESOS TERMINADOS
        for(Proceso& proceso : en_ejecucion)                    ///COLUMNA PROCESOS EN EJECUCIÓN
        {
            if(proceso.get_FlagRespuesta() == 0){
                proceso.set_TmpRespuesta(contador_global-proceso.get_TmpLlegada());
                proceso.set_FlagRespuesta(1);
            }
            ///CAMBIAR EL ESTADO DE MARCOS A EJECUCION
            for(int i=0;i<40;i++)
            {
                if(Marco[i].ID_Proceso == proceso.get_ID())
                    Marco[i].Estado = "E";
            }
            
            ///DATOS DE PROCESO EN EJECUCIÓN
            gotoxy(40,4);cout<<"                                    ";
            gotoxy(40,5);cout<<"                                    ";
            gotoxy(40,6);cout<<"                                    ";
            gotoxy(40,7);cout<<"                                    ";
            gotoxy(40,8);cout<<"                                    ";
            gotoxy(40,9);cout<<"                                    ";
            int TT = proceso.get_TT();
            int TR = proceso.get_tiempo() - proceso.get_TT();
            while(TR > 0)
            {
                gotoxy(30,0);cout<<listaProcesos.size();
                quantum_proceso++;
                if(lote_ejecucion.empty())
                    quantum_proceso = 0;
                    
                contador_global++;
                int incremento_ejecucion=0;
                gotoxy(40,4);cout <<"ID: " << proceso.get_ID() << endl;
                gotoxy(40,5);cout <<"Operacion: " <<proceso.get_n1()<<proceso.get_operador()<<proceso.get_n2()<<endl;
                gotoxy(40,6);cout <<"Tiempo Estimado: " << proceso.get_tiempo() << endl <<endl;
                gotoxy(50,14);cout<<"                ";
                gotoxy(40,7);cout<<"Tiempo Transcurrido: ";
                gotoxy(61,7);cout<<"      ";gotoxy(61,7);cout<<TT;
                gotoxy(40,8);cout<<"Tiempo Restante: ";
                gotoxy(57,8);cout<<"      ";gotoxy(57,8);cout<<TR;
                gotoxy(40,10);cout<<"Memoria: ";
                gotoxy(50,10);cout<<"      ";gotoxy(50,10);cout<<proceso.get_EspacioMemoria();
                gotoxy(67,27);cout<<suspendidos.size();
                if(!lote_ejecucion.empty())
                {
                    gotoxy(40,9);cout<<"Quantum Restante: ";
                    gotoxy(58,9);cout<<"      ";gotoxy(58,9);cout<<quantum_proceso;
                }
                gotoxy(56,0);cout<<contador_global;
                if(!listaProcesos.empty())
                {
                    Proceso& SigProceso = listaProcesos.front();
                    gotoxy(85,0);cout<<"--Sig. Proceso: "<<SigProceso.get_ID();
                    gotoxy(105,0);cout<<"--Tam. Memoria: "<<SigProceso.get_EspacioMemoria();
                }
                    /// COLUMNA PROCESOS EN ESPERA
                for(Proceso& proceso : lote_ejecucion)
                {
                    proceso.set_TmpEspera(proceso.get_TmpEspera()+1);
                    gotoxy(7,6+incremento_ejecucion);cout<<proceso.get_ID();
                    gotoxy(15,6+incremento_ejecucion);cout<<proceso.get_tiempo();
                    gotoxy(24,6+incremento_ejecucion);cout<<proceso.get_TT();
                    gotoxy(30,6+incremento_ejecucion);cout<<proceso.get_EspacioMemoria();
                    incremento_ejecucion = incremento_ejecucion + 1;
                }   

                /// MOSTRAR MARCOS DE PROCESOS
                tabla_paginacion(Marco, 40, 0);
                
                ///LIMPIEZA PROCESOS BLOQUEADOS
                Limpieza_datos();
                Mostrar_suspendidos(suspendidos);
                Bloqueados(cola_bloqueados, lote_ejecucion, Marco);
                Sleep(1000);
                TT++;
                TR--;  
                if(kbhit()){
                    char tecla = getch();
                    if(tecla == 'p' || tecla == 'P')
                    {
                        gotoxy(50,14);cout<<"Pausa";
                        while(true){
                            char tecla = getch();
                            if(tecla == 'c' || tecla == 'C'){
                                break;
                            }
                        }
                    }
                    if(tecla == 'e' || tecla == 'E'){
                        quantum_proceso = 0;
                        proceso.set_FlagError(1);
                        proceso.set_TT(TT);
                        ban_error++;
                        break;
                    }
                    if(tecla == 'i' || tecla == 'I'){
                        quantum_proceso = 0;
                        ban_interrupcion++;
                        proceso.set_TT(TT);
                        break;
                    }
                    if(tecla == 'n' || tecla == 'N'){
                        ban_nuevo++;
                        proceso.set_TT(TT);
                        Nuevos_Procesos(listaProcesos,ID_actual);
                        ID_actual++;
                        procesos++;
                        break;
                    }
                    if(tecla == 'b' || tecla == 'B'){
                        proceso.set_TT(TT);
                        BCP(cola_terminados,listaProcesos,cola_bloqueados,lote_ejecucion,en_ejecucion,1,suspendidos);
                        tabla_paginacion(Marco, 40, 0);
                        interfaz_ejecucion(listaProcesos, quantum_global);
                        Terminados(cola_terminados);
                    }
                    if(tecla == 't' || tecla == 'T'){
                        proceso.set_TT(TT);
                        tabla_paginacion(Marco, 40, 1);
                        tabla_paginacion(Marco, 40, 0);
                        interfaz_ejecucion(listaProcesos, quantum_global);
                        Terminados(cola_terminados);
                    }
                    if(tecla == 's' || tecla == 'S'){
                        if(!cola_bloqueados.empty())
                            suspender_proceso(cola_bloqueados, suspendidos, Marco, lote_ejecucion, listaProcesos, contador_global);
                    }
                    if(tecla == 'r' || tecla == 'R'){
                        if(!suspendidos.empty())
                            agregar_procesos(Marco, 40, cola_bloqueados, suspendidos, contador_global, 1);
                    }
                }
                if(quantum_proceso >= quantum_global)
                {
                    quantum_proceso = 0;
                    proceso.set_TT(TT);
                    ban_quantum++;
                    break;
                }
            }
        }

        Proceso& proceso = en_ejecucion.front();
        if(ban_quantum == 1)
        {
            for(int i=0; i<40; i++)
            {
                if(Marco[i].ID_Proceso == proceso.get_ID())
                    Marco[i].Estado = "L";
            }
            lote_ejecucion.splice(lote_ejecucion.end(), en_ejecucion, en_ejecucion.begin());
            if(!lote_ejecucion.empty())
                en_ejecucion.splice(en_ejecucion.begin(),lote_ejecucion,lote_ejecucion.begin());
        }else{
            if(ban_interrupcion == 0)
            {
                if(ban_nuevo == 1){
                    agregar_procesos(Marco, 40, lote_ejecucion, listaProcesos, contador_global, 0);
                }else{
                    quantum_proceso = 0;
                    for(int i=0; i<40; i++)
                    {
                        if(Marco[i].ID_Proceso == proceso.get_ID())
                        {
                            Marco[i].Disponible = false;
                        }
                    }
                    proceso.set_TmpFinalizacion(contador_global);
                    if(proceso.get_FlagError() == 0)
                    {
                        proceso.set_TT(proceso.get_tiempo());
                    }
                    cola_terminados.splice(cola_terminados.end(), en_ejecucion, en_ejecucion.begin());
                    procesos_guardados++;
                    if(!listaProcesos.empty())
                    {
                        agregar_procesos(Marco, 40, lote_ejecucion, listaProcesos, contador_global, 0);
                    }
                    if(!lote_ejecucion.empty())
                        en_ejecucion.splice(en_ejecucion.begin(),lote_ejecucion,lote_ejecucion.begin());
                }
            }else{
                proceso.set_TmpBloqueado(9);
                for(int i=0; i<40; i++){
                    if(Marco[i].ID_Proceso == proceso.get_ID())
                        Marco[i].Estado = "B";
                }
                cola_bloqueados.splice(cola_bloqueados.end(),en_ejecucion,en_ejecucion.begin());
                if(!lote_ejecucion.empty())
                    en_ejecucion.splice(en_ejecucion.begin(),lote_ejecucion,lote_ejecucion.begin());
            }
        }

        ///LIMPIAR PROCESOS EN ESPERA
        gotoxy(85,0);cout<<"                                        ";
        gotoxy(5,6);cout<<"                            ";
        gotoxy(5,7);cout<<"                            ";
        gotoxy(5,8);cout<<"                            ";
        gotoxy(5,9);cout<<"                            ";
        gotoxy(5,10);cout<<"                           ";
        gotoxy(5,11);cout<<"                           ";
        gotoxy(5,12);cout<<"                           ";
        gotoxy(5,13);cout<<"                           ";
        gotoxy(5,14);cout<<"                           ";
        gotoxy(5,15);cout<<"                           ";
        gotoxy(5,16);cout<<"                           ";
        gotoxy(5,17);cout<<"                           ";
        
        if(!cola_bloqueados.empty() || !suspendidos.empty()) /// OR !SUSPENDIDOS.EMPTY()
        {
            if(lote_ejecucion.empty() && en_ejecucion.empty())
            {
                tabla_paginacion(Marco, 40, 0);
                Terminados(cola_terminados);
                /// LIMPIA PROCESO EN EJECUCION
                gotoxy(40,4);cout<<"                                    ";
                gotoxy(40,5);cout<<"                                    ";
                gotoxy(40,6);cout<<"                                    ";
                gotoxy(40,7);cout<<"                                    ";
                gotoxy(40,8);cout<<"                           ";
                gotoxy(40,9);cout<<"                           ";
                gotoxy(40,10);cout<<"                          ";
                while(true)
                {
                    tabla_paginacion(Marco, 40, 0);
                    Limpieza_datos();
                    contador_global++;
                    gotoxy(30,0);cout<<listaProcesos.size();
                    gotoxy(56,0);cout<<contador_global;
                    Mostrar_suspendidos(suspendidos);
                    gotoxy(67,27);cout<<suspendidos.size();
                    Bloqueados(cola_bloqueados, lote_ejecucion, Marco);
                    Sleep(1000);
                    if(kbhit())
                    {
                        char tecla = getch();
                        if(tecla == 'n' || tecla == 'N')
                        {
                            Nuevos_Procesos(listaProcesos,ID_actual);
                            ID_actual++;
                            procesos++;
                            agregar_procesos(Marco, 40, lote_ejecucion, listaProcesos, contador_global, 0);
                        }
                        if(tecla == 'b' || tecla == 'B')
                        {
                            BCP(cola_terminados,listaProcesos,cola_bloqueados,lote_ejecucion,en_ejecucion,1,suspendidos);
                            tabla_paginacion(Marco, 40, 0);
                            interfaz_ejecucion(listaProcesos, quantum_global);
                            Terminados(cola_terminados);
                        }
                        if(tecla == 't' || tecla == 'T')
                        {
                            tabla_paginacion(Marco, 40, 1);
                            tabla_paginacion(Marco, 40, 0);
                            interfaz_ejecucion(listaProcesos, quantum_global);
                            Terminados(cola_terminados);
                        }
                        if(tecla == 's' || tecla == 'S'){
                            if(!cola_bloqueados.empty())
                                suspender_proceso(cola_bloqueados, suspendidos, Marco, lote_ejecucion, listaProcesos, contador_global);
                        }
                        if(tecla == 'r' || tecla == 'R'){
                            if(!suspendidos.empty())
                                agregar_procesos(Marco, 40, cola_bloqueados, suspendidos, contador_global, 1);
                        }
                    }
                    if(!lote_ejecucion.empty()){
                        en_ejecucion.splice(en_ejecucion.begin(),lote_ejecucion,lote_ejecucion.begin());
                        quantum_proceso = 0;
                        break; 
                    } 
                }
            }
        }
    }
    BCP(cola_terminados,listaProcesos,cola_bloqueados,lote_ejecucion,en_ejecucion,0,suspendidos);
    return 0;
}   
