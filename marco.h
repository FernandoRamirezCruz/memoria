#include<fstream>
#include<windows.h>
#include<iostream>
#include<conio.h>
#include<ctime>
#include<string>
#include <cstring>
#include<sstream> 

using namespace std;


//void matriz( int, int,int,int );
string mayusculasstring(string texto);		
string minusculasstring(string texto);
void posxy(int,int);
void delay(int);
void marco(int,int,int,int);
void menu();
void color(int );
void centraStr(string,int );
string substr(string, int, int);
void mayor0entero(int&);
void datosMatriz(int&,int&);
void marcomatriz( int , int ,int,int );
void pedirdatos_marco_matriz_int(int A[][15] ,int filas, int ,int ,int);
void matriz_pedirdatos_double_sn( double A[][15],int , int ,int,int );
void matriz_imprimirdatos_double( double A[][15] ,int filas , int columnas ,int iniciox ,int inicioy);

void matriz(  int filas , int columnas, int iniciox, int inicioy){
			char a;
	//margenes horizontales
	for(int j=inicioy;j<=(filas*5+inicioy); j=j+5){
	for(int i=iniciox; i<=(columnas*11+iniciox); i++){
		a=196;
	posxy(i,j);cout<<a;

 }
	}		
	//margenes verticales
	for(int j=inicioy;j<=(filas*5+inicioy); j++){
	for(int i=iniciox; i<=(columnas*11+iniciox); i=i+11){
		a=179;
	posxy(i,j);cout<<a;

 }
	}
		
			a=218;//esquina superior izquierda
			posxy(iniciox,inicioy);cout<<a;
			a=192;//esquina inferior izquierda
			posxy(iniciox,inicioy+(filas*5));cout<<a;
			a=191;//esquina superior derecha
			posxy(columnas*11+iniciox,inicioy);cout<<a;
			a=217;//esquina inferior derecha
			posxy(columnas*11+iniciox, filas*5+inicioy);cout<<a;
				
	for(int j=1;j<filas; j++){
	for(int i=1; i<columnas; i++){
		//esquina superior
		a=194;
		posxy(i*11+iniciox, inicioy );cout<<a;
		//esquina inferior
		a=193;
		posxy(i*11+iniciox, filas*5+inicioy );cout<<a;	
		//Intersecciones
		a=197;
		posxy(i*11+iniciox, j*5+inicioy );cout<<a;
		//Esquinas izquierda
		a=195;
		posxy(iniciox,j*5+inicioy);cout<<a;
//		Esquina derecha
		a=180;
		posxy(columnas*11+iniciox, j*5+inicioy );cout<<a;
		}	
		}
		
	
	}		
	
	
	
string substr(string texto, int npos, int num){
    string result="";
    
    int nlen=texto.length();
    
    const char* cad=texto.c_str();
    
    for (int i=npos-1;i<(npos-1+num);i++){
        if (i<nlen) result+=cad[i];
    }
    
    return result;
}

void centraStr(string texto,int y){
	int nlen=texto.length();
	posxy(39-(nlen/2),y);cout<<texto;
}

void color(int x){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}

void delay(int secs){
	for(int i = (time(NULL)+secs); time(NULL) != i ;time(NULL));
}
void posxy(int x,int y){
	COORD coordenada;
	coordenada.X=x;
	coordenada.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordenada);
}
void marco(int x, int y, int a, int b){
	char c;
	c=201;//esquina superior izquierda
	posxy(a,b);cout<<c;
	c=200;//Esquina inferior izquierda
	posxy(a,y+b);cout<<c;
	c=187;//esquina superior derecha
	posxy(x+a,b);cout<<c;
	c=188;//Esquina inferior derecha
	posxy(x+a,y+b);cout<<c;
	c=205;
	for(int i=a+1;i<x+a;i++){
			posxy(i,b);cout<<c;
			posxy(i,y+b);cout<<c;
		
	}
	c=186;
	for(int i=b+1;i<y+b;i++){
		
			posxy(a,i);cout<<c;
			posxy(x+a,i);cout<<c;
			
	}
}
void menu(){
	int x,y,a,b;
	cout<<"Digita en x: ";cin>>x;
	cout<<"Digita en y: ";cin>>y;
	cout<<"Digita donde quieras que inice en horizontal: ";cin>>a;
	cout<<"Digita donde quieras que inice en vertical: ";cin>>a;
	system("cls");
	marco( x,  y,  a, b);
}
string mayusculasstring(string texto) {
    int b=texto.length();
    for (int i=0; i<b; i++) {
        if (texto[i]>=97 && texto[i]<=122) { 
            texto[i]-=32;
        }
    }
    return texto;
}

string minusculasstring(string texto) {
    int b=texto.length();
    for (int i=0; i<b; i++) {
        if (texto[i]>=65 && texto[i]<=90) { 
            texto[i]+=32;
        }
    }
    return texto;
}
void mayor0entero(int& a){
	while( a < 0 ){
		cout<<"ESTE NUMERO DEBE DE SER MAYOR A 0"<<endl;
		cout<<"DIGITA NUEVAMENTE TU NUMERO: "; 
		cin>>a;
	}
}
void datosMatriz(int& filas ,int& columnas){
	
	marco(80,5 ,1 ,1 );
	centraStr("Indica la cantidad de filas que quieres que tenga: ",2);
	centraStr("Indica la cantidad de columnas que quieres que tenga: ",4);
	posxy(65, 2); cin>>filas;
	mayor0entero(filas);
	posxy(65, 4); cin>>columnas;
	mayor0entero(columnas);
}
void datosMatrizCuadrada(int& filas){
	marco(80,5 ,1 ,1 );
	centraStr("Indica la cantidad de filas y columnas que quieres que tenga: ",3);
	posxy(70, 3); cin>>filas;
	mayor0entero(filas);
}
void marcomatriz( int filas , int columnas ,int iniciox ,int inicioy){
	marco(columnas*11+2,filas*5+2 ,iniciox ,inicioy );
	matriz(filas, columnas, iniciox+1 ,inicioy+1);
}

void pedirdatos_marco_matriz_int(int A[][15] ,int filas , int columnas ,int iniciox ,int inicioy){
	marco(columnas*11+2,filas*5+2 ,iniciox ,inicioy );
	matriz(filas, columnas, iniciox+1 ,inicioy+1);
	for(int i=0; i<filas; i++){
		for(int j=0; j<columnas; j++){
	posxy(columnas+j*10+3,filas+i*5+3);cin>>A[i][j];
		}
	}
}
void matriz_pedirdatos_double_sn( double A[][15] ,int filas , int columnas ,int iniciox ,int inicioy){
	for(int i=0; i<filas; i++){
		for(int j=0; j<columnas; j++){
	posxy(j*11+4+iniciox,i*5+3+inicioy);
	cin>>A[i][j];
		}
	}
}
void matriz_imprimirdatos_double( double A[][15] ,int filas , int columnas ,int iniciox ,int inicioy){
	matriz(filas, columnas, iniciox+1 ,inicioy+1);
	for(int i=0; i<filas; i++){
		for(int j=0; j<columnas; j++){
	posxy(j*11+3+iniciox,i*5+3+inicioy);
	cout<<A[i][j];
		}
	}
}
float  strTofloat(string cadena){
    float valor;
       stringstream paso(cadena);
       paso >> valor;

    if (!paso.fail()) {
        return valor;
    } else {
        cout << "La conversión ha fallado." << endl;
        return 0;
    }
       return valor;
} 


string floatTostr(float valor) {
    char buffer[50];
    sprintf(buffer, "%.6f", valor);
    string cadena(buffer);
    return cadena;
}

 
 

int entero(float valor){

 

    int nEntero = static_cast<int>(valor);
    return nEntero;
}

 

float decimal(float valor){
 
    int nEntero=entero(valor);
    float nDecimal=valor-nEntero;
    return nDecimal;
}


int waitEnterInt(int x, int y){
	int entrada;
	string strEntrada;
	posxy(x,y); 
	while(true){
		getline(cin,strEntrada);
		stringstream ss(strEntrada);
		if(ss >> entrada && ss.eof() ){
			break;
		}
		posxy(x,y);
	}
	return entrada;
}
float waitEnterFloat(int x, int y){
	float entrada;
	string strEntrada;
	posxy(x,y); 
	while(true){
		getline(cin,strEntrada);
		stringstream ss(strEntrada);
		if(ss >> entrada && ss.eof() ){
			break;
		}
		posxy(x,y);
	}
	return entrada;
}
double waitEnterDouble(int x, int y){
	double entrada;
	string strEntrada;
	posxy(x,y); 
	while(true){
		getline(cin,strEntrada);
		stringstream ss(strEntrada);
		if(ss >> entrada && ss.eof() ){
			break;
		}
		posxy(x,y);
	}
	return entrada;
}
string waitEnterStr(int x, int y){
	string entrada;
	string strEntrada;
	posxy(x,y); 
	while(true){
		getline(cin,strEntrada);
		stringstream ss(strEntrada);
		if(ss >> entrada && ss.eof() ){
			break;
		}
		posxy(x,y);
	}
	return entrada;
}

string rPad(string texto,char chr,int n){

    string result=texto;
    int nlen=texto.length();
    for (int i=0;i<(n-nlen);i++) result+=chr;
    return result;
   
}