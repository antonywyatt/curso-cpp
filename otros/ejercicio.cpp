#include<iostream>
#define MAX 40
using namespace std;

int n;

struct sPersona {
	string nombre;
	char genero;
	int codigo;
	float examenF;
	float examenP;
	float promediop;
	float notas;
};

sPersona RegistrarPersona();
void mostrarPersona(sPersona Per);

void genero(sPersona per);


int main()
{
	int op;
	sPersona per;
	sPersona alumnos[MAX];
	
		cout<<"Ingrese la cantidad de alumnos:\t";
		cin>>n;
	do
	{
	
		system("cls");
		
		cout<<"============CASO 1============="<<endl;
		cout<<"1.Registrar"<<endl;
		cout<<"2.Mostrar todos"<<endl;
		cout<<"3.Mostrar aprobados por Genero M"<<endl;
		cout<<"4.Mostrar aprobados por Genero F"<<endl;
		cout<<"0.Salir"<<endl;
		cout<<"Ingrese opcion:\t";
		cin>>op;
		
		switch(op)
		{
			case 1:
			{
				system("cls");
			
				for(int i=0;i<n;i++)
				{
					alumnos[i]=RegistrarPersona();
				
				}	
				
				break;
			}
			
			case 2:
			{	
					system("cls");
					
					for(int i=0;i<n;i++)
					{
						mostrarPersona(alumnos[i]);
						
					}
					
					system("pause");
				
				break;
			}
			case 3:
			{
				cout<<endl<<"GENERO M"<<endl;
				for(int i=0;i<n;i++)
					{
						genero(alumnos[i]);
					}
					
				system("pause");
				break;
			}	
			
			
		}
		
	}while(op!=0);
	


	return 0;
}

sPersona RegistrarPersona()
{
	sPersona per;
	
	cout<<"=============Registrar Persona=============="<<endl;
	cout<<"Ingrese el Nombre: ";cin>>per.nombre;
	
	do
	{
		cout<<"Ingrese el genero(M/F): ";cin>>per.genero;
		
		if(per.genero!='M'&&per.genero!='m'&&per.genero!='F'&&per.genero!='f')
		{
			cout<<endl<<"ERROR VUELVA A INGRESAR...."<<endl;	
		}
		
	}while(per.genero!='M'&&per.genero!='m'&&per.genero!='F'&&per.genero!='f');
	
	switch(per.genero)
	{
		case 'm':
		case 'M':
		{
			per.genero='M';
			break;
		}
		
		case 'f':
		case 'F':
		{
			per.genero='F';
			break;
		}
	}
	
	cout<<"Ingrese el codigo: ";cin>>per.codigo;
	cout<<"Ingrese el promedio de practicas: ";cin>>per.promediop;
	cout<<"Ingrese la nota Examen parcial: ";cin>>per.examenP;
	cout<<"Ingrese la nota del Examen Final: ";cin>>per.examenF;
	cout<<"============================================"<<endl;
	per.notas=(per.promediop*2+per.examenP*2+per.examenF*3)/7;
	
	return per;	
	
	
}

void mostrarPersona(sPersona per)
{
	cout<<"*************Mostrar Nombre**************"<<endl;
	cout<<" el Nombre: "<<per.nombre<<endl;
	cout<<" De codigo: "<<per.codigo<<endl;
	cout<<" De Genero : "<<per.genero<<endl;
	cout<<" con nota: "<<per.notas<<endl;
	cout<<"*****************************************"<<endl;
	
	
	
	
}
void genero(sPersona per)
{
	if(per.notas>=11)
	{
		
		if(per.genero=='M')
		{
			cout<<"*************Mostrar Nombre**************"<<endl;
			cout<<" el Nombre: "<<per.nombre<<endl;
			cout<<" De codigo: "<<per.codigo<<endl;
			cout<<" De Genero : "<<per.genero<<endl;
			cout<<" con nota: "<<per.notas<<endl;
			cout<<"*****************************************"<<endl;
		}
	}
	
	
}
