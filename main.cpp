#include <iostream>

using namespace std;

class celula
{
private:
	string nome;
	celula *proxima;//*refere-se ao ponteiro , salvando endereço da próxima celula.
	
public:
	celula()//celula() é um metodo
	{
		proxima = NULL;
	}
	celula(string n)
	{
		nome = n;
	}
	string getNome(){
		return nome;
	}
	void setNome(string n){
		nome = n;
	}
	celula * getProxima(){
		return proxima;
	}
	/*~celula(){
		cout << "Passou no metodo destrutor";
	}*/
	
};

class lista
{
private:
	celula * inicio;
	
public:
	lista(){
		inicio = NULL;
	}
	celula * getInicio(){
		return inicio;
	}
	void inserirInicio(string n)
	{
		celula *nova = new celula;
		nova->setNome(n);
		inicio = nova;
	}
	void inserirFim (string n){
		celula *nova = new celula(n);
		nova->getProxima(NULL);
		if(inicio != NULL){
			celula *aux = inicio;
			while(aux->getProxima()!=NULL)
			{
				cout << aux->getProxima() << endl;
				aux = aux->getProxima();
			}
		}
		
	}
	void imprimir(){
		if(inicio == NULL){
			cout << "Lista vazia.\n";
		}	else{
			celula *aux = inicio;
			while(aux != NULL)
			{
				cout << aux->getNome() << "\n";
				aux = aux->getProxima;
			}
		}
	}
	
};

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "portuguese");
	lista listaAlunos;
	listaAlunos.inserirInicio("Mailson");
	listaAlunos.inserirInicio("João");
	listaAlunos.inserirInicio("Maria");
	listaAlunos.imprimir();
	
	return 0;
}