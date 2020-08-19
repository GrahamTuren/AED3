#include <iostream>
#include <locale.h>

using namespace std;

class celula
{
private:
	string nome, sexo, bebe;
	int idade;
	celula * proxima;
public:
	celula()
	{
		proxima = NULL;
	}
	celula(string n)
	{
		nome = n;
	}
celula(string n, celula *p)
	{
		nome = n;
		proxima = p;
	}
	celula(string n, string s, int i, string b, celula *p){
		nome = n;
		sexo = s;
		idade = i;
		bebe = b;
		proxima = p;
	}
	string getNome()
	{
		return nome;
	}
	void setNome(string n)
	{
		nome = n;
	}
	
	string getSexo()
	{
		return sexo;
	}
	void setSexo(string s)
	{
		sexo = s;
	}
	
	int getIdade()
	{
		return idade;
	}
	void setIdade(int i)
	{
		idade = i;
	}
	
	string getBebe()
	{
		return bebe;
	}
	void setBebe(string b)
	{
		bebe = b;
	}

	celula * getProxima()
	{
		return proxima;
	}

	void setProxima(celula * l)
	{
		proxima = l;
	}
};


class lista
{
private:
	celula * inicio;

public:
	lista()
	{
		inicio = NULL;
	}
	~lista(){
		esvaziar();
	}
	lista(celula *i)
	{
		inicio = i;
	}
	celula * getInicio()
	{
		return inicio;
	}

	void inserirInicio(string n, string s, int i, string b)
	{
		celula *nova = new celula;
		nova->setNome(n);
		nova->setSexo(s);
		nova->setIdade(i);
		nova->setBebe(b);
		nova->setProxima(inicio);
		inicio = nova;
	}

	void inserirFim(string n, string s, int i, string b)
	{
		if(inicio == NULL)
		{
			inserirInicio(n, s, i, b);
		}
		else
		{
			celula *aux = inicio;
			while(aux->getProxima() != NULL)
			{
				aux = aux->getProxima();
			}
			celula *nova = new celula(n, s, i, b, NULL);
			aux->setProxima(nova); 
		}
	}


	void imprimir()
	{
		if(inicio == NULL)
		{
			cout << "Lista vazia.\n";
		}
		else
		{
			celula *aux = inicio;
			cout << "Lista do Churrasco de Domingo\n\n";
			while(aux != NULL)
			{
				cout << "Nome: " <<aux->getNome() << "\n" << "Sexo: " << aux->getSexo() << " \n" << "Idade: " << aux->getIdade() << "\n" << "Bebe: " << aux->getBebe() << "\n" << "----------------------------------------" <<endl;
				aux = aux->getProxima();
			}
		}
	}
	
	void esvaziar(){
		celula *aux = inicio;
		while(aux != NULL){
			inicio = inicio->getProxima();
			delete aux;
			aux = inicio;
		}
		cout << "\n----Memoria liberada----\n";
	}
};

int main()
{
	setlocale(LC_ALL, "portuguese");
	
	lista listaConvidados;
	listaConvidados.inserirInicio("Esteban", "Masculino", 28, "Não");
	listaConvidados.inserirFim("Henrico",  "Masculino", 28, "Sim");
	listaConvidados.inserirFim("Lola", "Feminino", 28, "Sim");
	listaConvidados.inserirFim("Rubi", "Feminino", 28, "Não");
	listaConvidados.imprimir();	
	/*i=i*2*5/i-7;*/
	
	return 0;
}