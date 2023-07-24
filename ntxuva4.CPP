#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

class Pessoa{
	private:
		char nome[32];
		char sexo[2];
	protected:
		int codigo;
		Pessoa(char *nm, char *sx);
		void _setId(int);
		int _getId();
		void _setNome(char *nm);
		char *_getNome();
		void _setSexo(char *sx);
		char *_getSexo();
	public:
		static int id;
		static int qtdPessoas;
};
int Pessoa::id = 0;
int Pessoa::qtdPessoas = 0;
Pessoa::Pessoa(char *nm, char *sx){
	this->_setNome(nm);
	this->_setSexo(sx);
}
void Pessoa::_setId(int id){
	this->id = id;
}
int Pessoa::_getId(){
	return this->id;
}
void Pessoa::_setNome(char *nm){
	strcpy(this->nome, nm);
}
char *Pessoa::_getNome(){
	return this->nome;
}
void Pessoa::_setSexo(char *sx){
	strcpy(this->sexo, sx);
}
char *Pessoa::_getSexo(){
	return this->sexo;
}

//segunda Classe Jogador
class Jogador: public Pessoa{
	private:
		int pontos, totalDeJogos, jogadorId;
	public:
		Jogador(char *nm, char *sx): Pessoa(nm, sx){
			this->setPontos(0);
			this->setTotalDeJogos(0);
		}
		void setCodigo();
		int getCodigo();
		void setId(int);
		int getId();
		void setNome(char *nm);
		char *getNome();
		void setSexo(char *sx);
		char *getSexo();
		void setPontos(int);
		int getPontos();
		void setTotalDeJogos(int);
		int getTotalDeJogos();
		void setJogadorId(int);
		int getJogadorId();
};
void Jogador::setCodigo(){
	this->codigo = 11111;
}
int Jogador::getCodigo(){
	return this->codigo;
}
void Jogador::setId(int id){
	this->_setId(id);
}
int Jogador::getId(){
	return this->_getId();
}
void Jogador::setPontos(int pts){
	this->pontos+=pts;
}
void Jogador::setNome(char *nm){
	this->_setNome(nm);
}
char *Jogador::getNome(){
	return this->getNome();
}
void Jogador::setSexo(char *sx){
	this->_setSexo(sx);
}
char *Jogador::getSexo(){
	return this->_getSexo();
}
int Jogador::getPontos(){
	return this->pontos;
}
void Jogador::setTotalDeJogos(int ttlJgs){
	this->totalDeJogos+=ttlJgs;
}
int Jogador::getTotalDeJogos(){
	return this->totalDeJogos;
}
void Jogador::setJogadorId(int jgdrId){
	this->jogadorId = jgdrId;
}
int Jogador::getJogadorId(){
	return this->jogadorId;
}

//terceira classe Admin
class Admin: public Jogador{
	private:
		char nomeDoUsuario[32];
		int  senha;
		static int totAdmin;
	public:
		Admin(char *nm, char *sx): Jogador(nm, sx){
			this->setNomeDoUsuario(this->operator+("usuario"));
			this->setSenha(totAdmin+1234);
		}
		void setNomeDoUsuario(char *nmUsr);
		char *getNomeDoUsuario();
		void setSenha(int);
		int getSenha();
		char *operator+(char *txt);
};
int Admin::totAdmin = 0;
void Admin::setNomeDoUsuario(char *nmUsr){
	strcpy(this->nomeDoUsuario, nmUsr);
}
char *Admin::getNomeDoUsuario(){
	return this->nomeDoUsuario;
}
void Admin::setSenha(int sn){
	this->senha = sn;
}
int Admin::getSenha(){
	return this->senha;
}
char *Admin::operator+(char *txt){
	strcpy(txt, strcat(this->getNome(),txt));
	return txt;
}

//Quarta classe Jogo
class Jogo{
	private:
		Jogador jogador[2];
		int vencedor, cancelado;
	public:
		Jogo(int);
		void setJogador(Jogador *jgdr);
		Jogador *getJogador();
		void setVencedor(int);
		int getVencedor();
		void setCancelado(int);
		int getCancelado();
};
/*Jogo::Jogo(int cncld){
	this->setCancelado(cncld);
	jogador[0] = Jogador("jogador1", "M");
	jogador[1] = Jogador("jogador2", "M");
}*/

void Jogo::setJogador(Jogador *jgdr){
	for(int i = 0; i < 2; i++){
		this->jogador[i].setNome(jgdr[i].getNome());
		this->jogador[i].setSexo(jgdr[i].getSexo());
	}
}
Jogador *Jogo::getJogador(){
	return this->jogador;
}
void Jogo::setVencedor(int vncdr){
	this->vencedor = vncdr;
}
int Jogo::getVencedor(){
	return this->vencedor;
}
void Jogo::setCancelado(int cncld){
	this->cancelado = cncld;
}
int Jogo::getCancelado(){
	return this->cancelado;
}

//Quinta classe tabuliro
class Tabuleiro{
	private:
		int comprimento, *dadosDoPrimeiroJogador, *dadosDoSegundoJogador, primeiroJogador, segundoJogador;
	public:
		Tabuleiro();
		void setComprimento(int);
		int getComprimento();
		void desenharTabuleiro(Jogador *jgdr);
		int desenharTabuleiro();
		void jogar();
};
Tabuleiro::Tabuleiro(){
	this->setComprimento(12);
	primeiroJogador = 0;
	segundoJogador = 0;
}
void Tabuleiro::setComprimento(int cprmt){
	this->comprimento = cprmt;
}
int Tabuleiro::getComprimento(){
	return this->comprimento;
}
int Tabuleiro::desenharTabuleiro(){
	int opcao;
	clrscr();
	for(int i = 0; i < this->getComprimento()*2; i++){
		dadosDoPrimeiroJogador[i] = 2;
		dadosDoSegundoJogador[i] = 2;
		primeiroJogador += dadosDoPrimeiroJogador[i];
		segundoJogador += dadosDoSegundoJogador[i];
	}
	cout<<endl<<"\t\t\t\tTABULEIRO 4"<<"X"<<this->getComprimento()<<endl<<endl;
	for(i = 0; i < 4; i++){
		if(this->getComprimento() < 10) cout<<"\t\t\t";
		else cout<<"\t\t";
		for(int k = 0; k <= this->getComprimento()*4; k++)
			cout<<"-";
		cout<<endl;
		if(this->getComprimento() < 10) cout<<"\t\t\t";
		else cout<<"\t\t";
		for(int j = 0; j < this->getComprimento(); j++){
			if(i < 2){
				if(j == this->getComprimento()-1)
					cout<<"| "<<dadosDoPrimeiroJogador[j]<<" |";
				else
					cout<<"| "<<dadosDoPrimeiroJogador[j]<<" ";
			}else{
				if(j == this->getComprimento()-1)
					cout<<"| "<<dadosDoSegundoJogador[j]<<" |";
				else
					cout<<"| "<<dadosDoSegundoJogador[j]<<" ";
			}
		}
		cout<<endl;
		if(i == 3){
			if(this->getComprimento() < 10) cout<<"\t\t\t";
			else cout<<"\t\t";
			for(int k = 0; k <= this->getComprimento()*4; k++)
				cout<<"-";
		}
	}
	cout<<endl<<endl;
	cout<<"[1]. CONFIRMAR"<<endl;
	cout<<"[0]. ESCOLHER OUTRO"<<endl;
	cout<<"ESCOLHA A OPCAO: ";
	cin>>opcao;
	clrscr();
	return opcao;
}
void Tabuleiro::desenharTabuleiro(Jogador *jgdr){
	int casa, terminado = 0, dadosDaCasa, *auxVectorDeDados;
	char jogadores[2][30] = {"Ozorio Nhaca", "Aldo Nhaca"}, auxJogador[30];
	strcpy(auxJogador, jogadores[0]);
	// for(int k = 0; k < this->getComprimento(); k++){
	// 	auxVectorDeDados[k] = dadosDoPrimeiroJogador[k];
	// }
	do{
		cout<<endl<<"\t\t\t\t"<<auxJogador<<" joga agora"<<endl<<endl;
		cout<<"\t\t\t\tDados de "<<jogadores[0]<<": "<<primeiroJogador<<endl;
		for(int i = 1; i <= 4; i++){
			if(this->getComprimento() < 10) cout<<"\t\t\t";
			else cout<<"\t\t";
			for(int k = 0; k <= this->getComprimento()*4; k++)
				cout<<"-";
			cout<<endl;
			if(this->getComprimento() < 10) cout<<"\t\t\t";
			else cout<<"\t\t";
			if(i%2 == 1){
				for(int j = (this->getComprimento()-1)*2 + 1; j >= this->getComprimento(); j--){
					if(i < 3){
						if(j == this->getComprimento())
							cout<<"| "<<dadosDoPrimeiroJogador[j]<<" |";
						else
							cout<<"| "<<dadosDoPrimeiroJogador[j]<<" ";
					}else{
						if(j == this->getComprimento())
							cout<<"| "<<dadosDoSegundoJogador[j]<<" |";
						else
							cout<<"| "<<dadosDoSegundoJogador[j]<<" ";
					}
				}
			}else{
				for(int j = 0; j < this->getComprimento(); j++){
					if(i < 3){
						if(j == this->getComprimento()-1)
							cout<<"| "<<dadosDoPrimeiroJogador[j]<<" |";
						else
							cout<<"| "<<dadosDoPrimeiroJogador[j]<<" ";
					}else{
						if(j == this->getComprimento()-1)
							cout<<"| "<<dadosDoSegundoJogador[j]<<" |";
						else
							cout<<"| "<<dadosDoSegundoJogador[j]<<" ";
					}
				}
			}
			cout<<endl;
			if(i == 4){
				if(this->getComprimento() < 10) cout<<"\t\t\t";
				else cout<<"\t\t";
				for(int k = 0; k <= this->getComprimento()*4; k++)
					cout<<"-";
			}
		}
		cout<<endl<<endl;
		cout<<"\t\t\t\tDados de "<<jogadores[1]<<": "<<segundoJogador<<endl<<endl;
		cout<<"\t\t\t\t\tEscolha a casa: ";
		cin>>casa;
		dadosDaCasa = dadosDoPrimeiroJogador[casa-1];
		//Depois devera se colocar a instrucao que verifica se ainda existe uma casa com mais de um dado ainda ou nao.
		while(dadosDaCasa > 1){
			dadosDoPrimeiroJogador[casa-1] = 0;
			for(int k = 1; k <= dadosDaCasa; k++){
				if(casa == this->getComprimento()*2)
					casa = 0;
				dadosDoPrimeiroJogador[casa] = dadosDoPrimeiroJogador[casa] + 1;
				casa++;
			}
			dadosDaCasa = dadosDoPrimeiroJogador[casa-1];
		}
		if(casa-1 >= this->getComprimento() && casa-1 < this->getComprimento()*2){
			if(dadosDoSegundoJogador[casa-1-(this->getComprimento() - 1)] > 0){
				dadosDoSegundoJogador[casa-1] = 0;
				dadosDoSegundoJogador[casa-1-(this->getComprimento() - 1)] = 0;
			}
	    }
		cout<<"1. sair\n0. continuar\n";
		cin>>terminado;
		clrscr();
	}while(!terminado);

}

//Sexta classe JogoController
class ControladorDoJogo{
	private:
		Jogo *jogo;
		Tabuleiro tabuleiro;
	public:
		static int totJogos;
		ControladorDoJogo();
		void nomeDoJogo();
		int menuInicial();
		int menuFinal();
		void iniciar();
		void iniciarJogo();
		int menuDeEscolhaDoTabuleiro();
		void escolherTabuleiro();
		void cadastrarJogadores();
		void verEstatisticas();
		void continuarJogo();
		void sair();
		void error();
		void cancelar();
};
int ControladorDoJogo::totJogos = 0;
ControladorDoJogo::ControladorDoJogo(){
	this->iniciar();
}
void ControladorDoJogo::nomeDoJogo(){
	clrscr();
	cout<<"\t\t\t======== JOGO NTXUVA ========"<<endl<<endl;
}
int ControladorDoJogo::menuInicial(){
	int opcao;
	this->nomeDoJogo();
	cout<<"MENU INICIAL"<<endl;
	cout<<"============"<<endl<<endl;
	cout<<"[1]. INICIAR NOVO JOGO"<<endl;
	cout<<"[2]. VER ESTATISTICAS"<<endl;
	cout<<"[3]. CONTINUAR UM JOGO"<<endl;
	cout<<"[0]. SAIR DO JOGO"<<endl<<endl;
	cout<<"ESCOLHA A OPCAO: ";
	cin>>opcao;
	return opcao;
}
int ControladorDoJogo::menuFinal(){
	int opcao;
	cout<<"[1]. CONTINUAR"<<endl;
	cout<<"[0]. SAIR"<<endl<<endl;
	cout<<"ESCOLHA A OPCAO: ";
	cin>>opcao;
	clrscr();
	return opcao;
}
void ControladorDoJogo::iniciar(){
	do{
		switch(this->menuInicial()){
			case 1: this->iniciarJogo(); break;
			case 2: this->verEstatisticas(); break;
			case 3: this->continuarJogo(); break;
			case 0: break; break;
			default: this->error(); break;
		}
	}while(this->menuFinal());
	this->sair();
}
void ControladorDoJogo::iniciarJogo(){
	this->nomeDoJogo();
	this->cadastrarJogadores();
	this->escolherTabuleiro();
	this->tabuleiro.desenharTabuleiro(this->jogo[totJogos].getJogador());
	cout<<"Jogo Iniciado"<<endl<<endl;
}
int ControladorDoJogo::menuDeEscolhaDoTabuleiro(){
	int modelo;
	this->nomeDoJogo();
	cout<<"ESCOLHA O TABULEIRO"<<endl;
	cout<<"==================="<<endl<<endl;
	cout<<"[1]. [4] X [6]"<<endl;
	cout<<"[2]. [4] X [8]"<<endl;
	cout<<"[3]. [4] X [12]"<<endl;
	cout<<"[4]. DEFAULT"<<endl;
	cout<<"ESCOLHA A OPCAO: ";
	cin>>modelo;
	return modelo;
}
void ControladorDoJogo::escolherTabuleiro(){
	int confirmar, modelo, escolha;
	do{
		escolha = this->menuDeEscolhaDoTabuleiro();
		if(escolha == 1 || escolha == 4)
			modelo = 6;
		else if(escolha == 2)
			modelo = 8;
		else if(escolha == 3)
			modelo = 12;
		else
			modelo = 4;
		this->tabuleiro.setComprimento(modelo);
		if(tabuleiro.desenharTabuleiro()){
			confirmar = 1;
		}else
			confirmar = 0;
	}while(!confirmar);
}
void ControladorDoJogo::cadastrarJogadores(){
	char nome[32], sexo[2];
	cout<<"CADASTRO DE JOGADORES"<<endl;
	cout<<"====================="<<endl;
	for(int i = 0; i < 2; i++){
		cout<<endl<<"JOGADOR - "<<(i+1)<<endl;
		cout<<"==========="<<endl;
		cout<<"NOME....: ";
		cin>>nome;
		cout<<"GENERO..: ";
		cin>>sexo;
		this->jogo[totJogos].getJogador()[i].setId(++Pessoa::id);
		this->jogo[totJogos].getJogador()[i].setJogadorId(i+1);
		this->jogo[totJogos].getJogador()[i].setNome(nome);
		this->jogo[totJogos].getJogador()[i].setSexo(sexo);
	}
	//cout<<"Nome: "<<this->jogo[0].getJogador()[1].getNome()<<endl;
	clrscr();
}
void ControladorDoJogo::verEstatisticas(){
	this->nomeDoJogo();
	cout<<"Estatisticas"<<endl<<endl;
}
void ControladorDoJogo::continuarJogo(){
	this->nomeDoJogo();
	cout<<"Continuar jogo"<<endl<<endl;
}
void ControladorDoJogo::sair(){
	this->nomeDoJogo();
	cout<<"SAIU DO JOGO! VOLTE SEMPRE..."<<endl<<endl;
}
void ControladorDoJogo::error(){
	this->nomeDoJogo();
	cout<<"ERRO AO EXECUTAR O PEDIDO..."<<endl<<endl;
}


void main(){
	clrscr();
	ControladorDoJogo ctrldrDjg;
	getch();
}
