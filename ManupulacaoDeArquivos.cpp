#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

class Pessoa
{
	private:
		string nome;
		int anoDeNascimento;
		char genero;
	public:
		void setNome(string nome)
		{
			this->nome = nome;
		}
		string getNome()
		{
			return this->nome;
		}
		void setAnnoDeNascimento(int anDnscmnt)
		{
			this->anoDeNascimento = anDnscmnt;
		}
		int getAnoDeNascimento()
		{
			return this->anoDeNascimento;
		}
		void setGenero(char genero)
		{
			this->genero = genero;
		}
		char getGenero()
		{
			return this->genero;
		}
};



class Estudante: public Pessoa
{
	private:
		string disciplinas[3], curso;
		int nivel;	
	public:
		void setDisciplinas(string dscplns[])
		{
			for(int i = 0; i < 3; i++){
				this->disciplinas[i] = dscplns[i];
			}
		}
		string *getDisciplinas()
		{
			return this->disciplinas;
		}
		void setCurso(string crs)
		{
			this->curso = crs;
		}
		string getCurso()
		{
			return this->curso;
		}
		void setNivel(int nvl)
		{
			this->nivel = nvl;
		}
		int getNivel()
		{
			return this->nivel;
		}
};

class ControladorDeEstudante
{
	public:
		Estudante estudante;
		ControladorDeEstudante()
		{
			this->menu();
		}

		void menuFinal(){
			cout<<"\n\nDIGITE 1 PARA CONTINUAR OU DIGITE 0 PARA SAIR...\n";
		}
		
		void error(){
			system("cls");
			cout<<"ESCOLHA INVALIDA!";
		}
		
		void menu()
		{
			int opcao, continuar = 1;
			
			do{
				system("cls");
				cout<<"MENU INICIAL\n";
				cout<<"==============\n\n";
				cout<<"[1]. CADASTRAR\n[2]. LISTAR\n[3]. PESQUISAR\n";
				cout<<"ESCOLHA A OPCAO: ";
				cin>>opcao;

				switch(opcao){
					case 1:
						this->cadastrar();
					break;

					case 2:
						this->listar();
					break;

					case 3:
						this->pesquisar();
					break;
					
					default:
						this->error();
					break;
				}
				this->menuFinal();
				cin>>continuar;

			}while(continuar);
			system("cls");
			cout<<"SAIU....";
		}

		void cadastrar()
		{
			ofstream entrada;
			string nome, curso, disciplinas[3];
			char genero;
			int anoDeNascimento, nivel;
			system("cls");
			entrada.open("Estudantes.txt", ios::app | ios::binary);
			if(!entrada){
				cout<<"FALHA NA OPERACAO\n";
			}else{
					cout<<"===============\n\n";
					cout<<"Nome ----------------- : ";
					cin>>nome;
					cout<<"Ano De Nascimento ---- : ";
					cin>>anoDeNascimento;
					cout<<"Genero --------------- : ";
					cin>>genero;
					cout<<"Curso ---------------- : ";
					cin>>curso;
					cout<<"Nivel ---------------- : ";
					cin>>nivel;
					cout<<"Disciplinas ---------- :\n";
					for(int j = 0; j < 3; j++)
					{
						cout<<"Disciplina - "<<j+1<<": ";
						cin>>disciplinas[j];
					}
					estudante.setNome(nome);
					estudante.setAnnoDeNascimento(anoDeNascimento);
					estudante.setGenero(genero);
					estudante.setCurso(curso);
					estudante.setNivel(nivel);
					estudante.setDisciplinas(disciplinas);	
					entrada.write((char*)&estudante, sizeof(estudante));
			}
			entrada.close();
		}

		void listar()
		{
			ifstream saida;
			system("cls");
			
			saida.open("Estudantes.txt", ios::in | ios::binary);
			cout<<"LISTA DE ESTUDANTES\n";
			cout<<"===================\n\n";
			if(!saida){
				cout<<"ARQUIVO INEXISTENTE\n";
			}else{
				saida.read((char*)&estudante, sizeof(estudante));	
				while(!saida.eof()){
					cout<<"===============\n\n";
					cout<<"Nome ----------------- : "<<estudante.getNome()<<endl;
					cout<<"Ano De Nascimento ---- : "<<estudante.getAnoDeNascimento()<<endl;
					cout<<"Genero --------------- : "<<estudante.getGenero()<<endl;
					cout<<"Curso ---------------- : "<<estudante.getCurso()<<endl;
					cout<<"Nivel ---------------- : "<<estudante.getNivel()<<endl;
					cout<<"\nDisciplinas ---------- :\n";
					for(int j = 0; j < 3; j++)
					{
						cout<<"Disciplina - "<<j+1<<": "<<estudante.getDisciplinas()[j]<<endl;
					}
					cout<<"\n";
					saida.read((char*)&estudante, sizeof(estudante));	
				}
			}
			saida.close();

		}
		void pesquisar()
		{	
			ifstream saida;
			int idDoEstudante;
			bool resultadoEncontrado = false;
			string nome;
			system("cls");
			
			cout<<"PESQUISAR ESTUDANTE\n";
			cout<<"===================\n\n";
			
			saida.open("Estudantes.txt", ios::in | ios::binary);
			if(!saida){
				cout<<"ARQUIVO INEXISTENTE\n";
			}else{
				cout<<"Digite o nome do estudante: ";
				cin>>nome;
				saida.read((char*)&estudante, sizeof(estudante));
				while(!saida.eof()){
					if(estudante.getNome() == nome){
						cout<<"DADOS DO ESTUDANTE\n";
						cout<<"===============\n\n";
						cout<<"Nome ----------------- : "<<estudante.getNome()<<endl;
						cout<<"Ano De Nascimento ---- : "<<estudante.getAnoDeNascimento()<<endl;
						cout<<"Genero --------------- : "<<estudante.getGenero()<<endl;
						cout<<"Curso ---------------- : "<<estudante.getCurso()<<endl;
						cout<<"Nivel ---------------- : "<<estudante.getNivel()<<endl;
						cout<<"Disciplinas ---------- :\n";
						for(int j = 0; j < 3; j++)
							cout<<"Disciplina - "<<j+1<<": "<<estudante.getDisciplinas()[j]<<endl;
							
						resultadoEncontrado = true;
						break;
					}
					saida.read((char*)&estudante, sizeof(estudante));
				}
			}
			saida.close();
			if(!resultadoEncontrado){
				cout<<"OPS :( NENHUM RESULTADO ENCONTRADO\n";	
			}
		}
};

int main()
{
	ControladorDeEstudante cntrldrDEstdnt;
	return 0;
}