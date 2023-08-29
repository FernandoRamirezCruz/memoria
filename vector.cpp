#include<iostream>
#include"marco.h"
#include <map>

using namespace std;

struct PARTICION{
	
	int tamanio, num, espacio_libre;
	
	int inicio, ifinal;

}X[100];


int espacio_usado=400;
int contador=0;

int ultima_particion=0;
void ordenar_particiones();
void particion(int espacio_memoria);
void intercambiar(int &, int&);//intercambia dos valores

void saber_datos(int memoria[], int espacio_memoria, int, int );
void saber_datos_particiones(int memoria[], int espacio_memoria);

void llenar_datos(int  memoria[],int espacio_memoria,int,int);

void mostrar_memoria(int memoria[], int espacio_memoria);

void remplazar(int memoria[], int espacio_memoria, int ,int);

void MENU(int memoria[], int espacio_memoria);

void eliminar(int memoria[], int espacio_memoria, int,int,int,int );

void regularizar(int memoria[],int espacio_memoria,int,int);//funcion dedicada a quitar los 0 de entre los valores

bool espacio_suficiente(int memoria[],int espacio_memoria,int);//Ingresa una serie de valores 
bool espacio_suficiente_particion(int memoria[],int espacio_memoria, int );
void formatear(int memoria[],int espacio_memoria);

int main(){
	
	int n;
	cout<<"Cuantos GB de memoria tienes ? "; 
	cin>>n;
	n= n*1024;
	int memoria[n];
	for(int i=0; i<n ;i++){
		memoria[i]=0;
	}
	for(int i=0; i<400; i++){
		memoria[i]=1;
	}
	getch();
	particion(n);
	MENU(memoria, n);
	return 0;
}

void particion( int espacio_memoria){
	int espacio_particion;
			system("cls");
	
//	int espacio_usado=400;
//	contador=0;
	cout<<"De cuanto quieres que sea tu particion ?  ";
	 
	cin>>espacio_particion;
	while(espacio_particion <=0){
		cout<<"NO PUEDES TENER PARTICION CON NUMEROS NEGATIVOS"<<endl;
		getch();
		particion(espacio_memoria);
	}
	
	if((espacio_usado+espacio_particion) <= espacio_memoria ){
		if(contador == 0){
		
				X[contador].inicio = 400 ;
				X[contador].ifinal = 400+espacio_particion;
				X[contador].tamanio = espacio_particion;
				X[contador].num = contador;	
				X[contador].espacio_libre = espacio_particion;
		}	
		else{
				X[contador].inicio = X[contador-1].ifinal + 1 ;
				X[contador].ifinal = X[contador].inicio + espacio_particion;	
				X[contador].tamanio = espacio_particion;
				X[contador].num = contador;	
				X[contador].espacio_libre = espacio_particion;
		}

		contador++;
		espacio_usado+=espacio_particion;
	}
	else {
		cout<<"\nEspacio insuficiente de memoria"<<endl;
	}	
	getch();
	system("cls");
	
	if(espacio_usado<espacio_memoria){
			string cc;
			cout<<"Quieres añadir otra particion (ponga 'si')"; 
			cin>>cc;
			if(cc == "si"){
				particion(espacio_memoria);
			}
		}	
	cout<<"Has creado "<< contador<< " particiones "<<endl;	
	ordenar_particiones();
}

void intercambiar(int &x, int &y ){
	int aux;
	aux = x; 
	x=y;
	y=aux;
}

void MENU(int memoria[], int espacio_memoria){
	system("cls");

	int VALORMENU=0,VALOR;
	while(VALORMENU==0){
	    posxy(29,2);cout<<"MENU DE OPCIONES";
		posxy(29,3);cout<<"----------------";
		posxy(29,5);cout<<"1._ LLENAR DATOS "<<endl;
		posxy(29,7);cout<<"2._ ELIMINAR DATOS "<<endl;
		posxy(29,9);cout<<"3._ MOSTRAR DATOS "<<endl;
		posxy(29,11);cout<<"4._ FORMETEAR"<<endl;
//		posxy(29,12);cout<<"5._ ORDENAR"<<endl;
		posxy(29,13);cout<<"6._ SALIR "<<endl;
		posxy(29,15);cout<<"Introduzca la opcion deseada [ ]" <<endl;
		posxy(59,15);cin>>VALOR;
	system("cls");		

		switch(VALOR){
			
		case 1:{
			int num_particion;
			int dato;
			int cantidad;
			string cc;
		do{

		cout<<"COMO SE LLAMA EL EL ARCHIVO QUE QUIERES INGRESAR(INGRESA NUMEROS): ";cin>>dato;
		cout<<"\nINGRESA EL TAMAÑO DEL ARCHIVOS EN MB: "; cin>>cantidad;
		
		if(dato==1 || dato==0){	
			cout<<"\nNUMERO RESERVADO "<<endl;
		}
		else{
		llenar_datos(memoria, espacio_memoria, cantidad, dato);
		}
	
		
		cout<<endl<<endl;
				
		cout<<"\n\nQuieres ingresar un nuevo dato? (escribe si): "; cin>>cc;
		system("cls");	
		}while(cc=="si");

		
		
		break;
		}
		case 2:{
			int dato;
			string cc;
			
		cout<<"	DATOS QUE SE PUEDEN ELIMINAR "<<endl;
			saber_datos( memoria, espacio_memoria,0, espacio_memoria);

		cout<<"\nINGRESA EL ARCHIVO A ELIMINAR"; cin>>dato;
		eliminar(memoria, espacio_memoria, dato, 0, espacio_memoria,-1 );
		cout<<"\n\nQuieres eliminar otro dato? (escribe si): "; cin>>cc;
		
		while(cc=="si"){
					system("cls");
		cout<<"	DATOS DE MEMORIA "<<endl;
			saber_datos( memoria, espacio_memoria,0, espacio_memoria);

		cout<<"\nINGRESA EL ARCHIVO A ELIMINAR"; cin>>dato;
	eliminar(memoria, espacio_memoria, dato, 0, espacio_memoria,-1 );
		cout<<"\n\nQuieres eliminar otro dato? (escribe si): "; cin>>cc;
		}

			
			
			getch();
		system("cls");
		
		break;
		}
		case 3:{
			saber_datos( memoria, espacio_memoria,0, espacio_memoria);
			mostrar_memoria( memoria, espacio_memoria);
			getch();
		system("cls");
		
			break;
		}
		case 4:{
			system("cls");
			formatear(memoria, espacio_memoria);
			cout<<"MEMORIA FORMATEADA"<<endl;
			getch();
			break;
		}/*
		case 5:{
			ordenar_particiones(memoria);
			system("cls");
			break;
		}*/
		case 6:{
			
			system("cls");
			
			exit(1);
			break;
		}
		MENU(memoria, espacio_memoria);
		getch();
		}

		
	}
}

void formatear(int memoria[],int espacio_memoria){

	for(int i=0; i<espacio_memoria; i++){
		if(memoria[i]!=1 ){
		memoria[i]=0;		
		}
	
	
	}
	contador=0;
	
}

void llenar_datos(int memoria[],int espacio_memoria ,int uso_memoria, int dato){	
int guia=0;
int ultima_particion_sim=0;
ultima_particion_sim= ultima_particion;

for(int i=ultima_particion_sim; i<contador; i++){
	if(espacio_suficiente_particion(memoria,uso_memoria, i)){
	cout<<X[i].num<<endl;
	cout<<X[i].espacio_libre<<endl;
	cout<<X[i].tamanio<<endl;
	cout<<X[i].inicio<<endl;
	cout<<X[i].ifinal<<endl;
	getch();
		for(int j=(X[i].inicio+X[i].tamanio-X[i].espacio_libre); j<(X[i].inicio+X[i].tamanio-X[i].espacio_libre+uso_memoria); j++){
			memoria[j] = dato;
			}

	 
	X[i].espacio_libre = X[i].espacio_libre - uso_memoria;
	ultima_particion = i;	
	ultima_particion_sim = i;
	guia=1;
	
	i=contador;
	}
}

if(guia==0){
	
	ultima_particion_sim = 0;	
	for(int i=ultima_particion_sim; i<contador; i++){
		
	if(espacio_suficiente_particion(memoria,uso_memoria, i)){
	
		for(int j=(X[i].inicio+X[i].tamanio-X[i].espacio_libre); j<(X[i].inicio+X[i].tamanio-X[i].espacio_libre+uso_memoria); j++){
			memoria[j] = dato;
		}
	
	X[i].espacio_libre = X[i].espacio_libre-uso_memoria;


	ultima_particion_sim = i;
	
	guia=1;
	
	i=contador;
	}
}


	}
	
	if(guia==0){
	string s;
	cout<<"\n EL DATO NO PUDO SER INGRESADO"<<endl;
	cout<<"\nQUIERES REEMPLAZARLO?(si)"; cin>>s;
	if(s=="si"){
//		remplazar(int memoria[], int espacio_memoria, int uso_memoria,int dato )
		remplazar(memoria, espacio_memoria, uso_memoria, dato);
	}
}
else{
	cout<<"\n DATO INGRESADO"<<endl;
}
	getch();
}
///Esta funcion sabra si hay espacio suficiente en una particion 
bool espacio_suficiente_particion(int memoria[],int uso_memoria, int num_de_particion){
	int contador1=0;
	
	
	for(int i=X[num_de_particion].inicio ; i<X[num_de_particion].ifinal; i++ ){
		if(memoria[i] == 0) {
		contador1++;	
		}
	}
	
	if(contador1 >= uso_memoria ) {
		return true;
	}
	else  {
	return false;	
	}
}
bool espacio_suficiente(int memoria[],int espacio_memoria, int uso_memoria){
	
	int contador1=0;

	for(int i=0; i<espacio_memoria; i++){
		if(memoria[i] == 0 && memoria[i]!=1) {
		contador1++;	
		}
	}
	
	if(contador1 >= uso_memoria) {
		return true;
	}
	else {
	return false;	
	}
	
}

void regularizar(int memoria[],int espacio_memoria,int inicio, int fin){
for(int j=inicio; j<fin;j++){
for(int i=inicio; i<fin; i++){
if(memoria[i]<memoria[i+1]){
	intercambiar(memoria[i], memoria[i+1] );
}
}
}

}

void eliminar(int memoria[], int espacio_memoria, int dato,int  inicio,int  fin,int particion ){
	int c=0;
	if(dato!= 1){
		
		for(int i=inicio; i<fin; i++){
	if(memoria[i]== dato ) {
		memoria[i] = 0;	
		c++;
	}
	}
	regularizar(memoria, espacio_memoria,inicio, fin);
	
	}
	else{
		system("cls");
		cout<<"EL SISTEMA OPERATIVO NO PUEDE SER ELIMINADO"<<endl;
		getch();
		system("cls");
	}
	if(particion != -1){
		X[particion].espacio_libre+=c;
	}
}

void saber_datos(int memoria[], int espacio_memoria,int inicio, int final){

	map<int, int> countMap; 
	
	   for (int i = inicio; i < final; ++i) {
        countMap[memoria[i]]++;
    }
    
    cout << "EXISTEN  " << countMap.size() <<" TIPOS DE DATOS DISTINTOS" <<endl;
    cout << "CANTIDAD DE MEMORIA USADAS:" << endl;
int libre=0;
    for (const auto &entry : countMap) {
    	
    		if( entry.first == 0){
    	libre = entry.second;
    	cout <<endl<< "ESPACIO LIBRE DE MEMORIA"<< ": " << entry.second << " MB" << endl;
	}
	else if(entry.first == 1){
		cout <<endl<< "EL SISTEMA OPERATIVO "<< ": " << entry.second << " MB" << endl;
	}
	else{
		cout <<endl<< "USO DE " << entry.first << ": ESPACIO DEL ARCHIVO " << entry.second << " MB	: Espacio si es liberado = "<<libre +entry.second<< endl;
	}
		}

if(inicio==0 && final==espacio_memoria) saber_datos_particiones(memoria,espacio_memoria);
		}
void saber_datos_particiones(int memoria[],int espacio_memoria){
		cout<<"\n--------------------------------------------------";	
	cout<<"\nTAMANIO DE PARTICIONES CREADOS" ;
			cout<<"\n--------------------------------------------------"<<endl;	
	for(int i=0; i<contador;i++){
	if(i!=0)			cout<<"\n--------------------------------------------------"<<endl;	
	cout<<"Nom. Partcion = "<<X[i].num<<endl;
	
	cout<<"		USO EN MEMORIA: "<<X[i].tamanio<<"MB"<<endl;
	cout<<"	ESPACIO LIBRE: "<<X[i].espacio_libre<<"MB"<<endl;
	}
	string x;
	cout<<"QUIERES SABER LOS DATOS DE LA PARTICION? (si)"; cin>>x;
	if(x=="si"){
		int z;
		"QUE DATOS DE PARTICIONES QUIERES SABER?"; cin>>z;
		saber_datos(memoria, espacio_memoria,X[z].inicio, X[z].ifinal);
		getch();
	}
} 
void remplazar(int memoria[], int espacio_memoria, int uso_memoria,int dato ){
	
	int particion, reemplazar;
	system("cls");
	
	cout<<"\nDATOS DEL SISTEMA\n";
	
	saber_datos_particiones(memoria, espacio_memoria);		
	
	cout<<"\n\nEN QUE PARTICION QUIERES REEMPLAZAR SUS DATOS POR TU NUEVO ARCHIVO "; cin>>particion;
	cout<<"\nQUE DATO QUIERES REEMPLAZAR?";cin>>reemplazar;
	eliminar(memoria, espacio_memoria, reemplazar ,X[particion].inicio, X[particion].ifinal, particion);
//	espacio_suficiente_particion(int memoria[],int uso_memoria, int num_de_particion)
	
	if(espacio_suficiente_particion(memoria, uso_memoria, particion)){
	llenar_datos(memoria, espacio_memoria,uso_memoria,dato);	
	}
	else{
	remplazar(memoria, espacio_memoria, uso_memoria,dato);
	}
	
	
}

void mostrar_memoria(int memoria[], int espacio_memoria){
cout<<"\nLa memoria tiene una capacidad de "<<espacio_memoria<<" MB ("<<espacio_memoria/1024<<"GB)"<<endl;
cout<<"Datos de memoria"<<endl;
for(int i=0; i<espacio_memoria; i++){
	cout<<memoria[i]<<" | ";
}

}
void ordenar_particiones(){

for (int i = 0; i < contador - 1; ++i) {
        for (int j = 0; j < contador - i - 1; ++j) {
            
			if (X[j].tamanio > X[j+1].tamanio) {
         
				
				X[j].ifinal = X[j].inicio + X[j+1].tamanio;
				X[j+1].inicio = X[j].ifinal +1;			
				
				intercambiar(X[j].tamanio,X[j+1].tamanio);
				intercambiar(X[j].espacio_libre,X[j+1].espacio_libre);
				
				
			}
        }
    }
	}
	
