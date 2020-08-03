#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>

using namespace std;


int main()
{
	setlocale(LC_ALL, "portuguese");
	/*Cor das letras*/
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    
    int Valor=0, num=0;
    int FOR, DES, CON, INT, CAR, WIS;
    int op, CA, INI, vida, ATKM, ARCO, CAm, vidam, dano=0, roll, cura, roll2, roll3, shot, INIP, INIM;

	cout << "BATALHA V.S.\n\n";
	cout << "Agora sera feita a rolagem dos status:\n";
	system("pause");
    for(int i=0;i<6; i++)
   { 
   	for(int j=0;j<3; j++)
   	{
   		num= rand() % 6 + 1;
   		
   		Valor=Valor+num;
   		if(j==2)
   		{
		   cout<< num <<"= ";
		}
		else
   		cout<< num << "+";
   	}
  	cout<<Valor<< "\n";
   	num=0;
   	Valor=0;
   }
   
	cout << "\nPosicione seus status:\n";
   do{
	cout << "Força (FOR): ";
	cin >> FOR;
   
	cout << "Destreza (DES): ";
	cin >> DES;
    
	cout << "Constituição(CON): ";
    cin >> CON;
    
    cout << "Inteligência (INT): ";
    cin >> INT;
    
    cout << "Carisma (CAR): ";
    cin >> CAR;
    
    cout << "Sabedoria (WIS): ";
    cin >> WIS;
    
    cout << "Você está certo disso?\n1)Sim\n2)Não\n";
    cin >> op;
	} while(op==2);
	
	system("CLS");
	
	cout << "Seu equipamento inicial é:\n1) Armadura de Couro Batido (CA: 12+DES)\n2) Arco curto (Dano: 1d6+DES)\n\n";
	cout << "Suas magias são:\n1) Escudo Arcano: Adiciona +5 a sua CA.\n2) Raio do Caos: Causa 2d8 de dano Aleatório.\n3) Vitalidade Falsa: Aumenta sua vida em 1d4+4.\n";
    /*Player*/
    FOR = (FOR-10)/2;
    DES = (DES-10)/2;
    CON = (CON-10)/2;
    INT = (INT-10)/2;
    CAR = (CAR-10)/2;
    WIS = (WIS-10)/2;
    
    CA = 12+DES;
    
    INI = DES;
    
    vida = (3*CON)+22;
    
    ATKM = 2+INT;
    
    ARCO = 2+DES;
    /*-----------------------*/
    
	/*Banshee*/
    CAm = 12;
    vidam = 58;
    /*-----------------------*/
    system("pause");
    system("CLS");
   cout << "Iniciando combate com Banshee.\n";
   
   system("pause");
   system("CLS");
   
   cout << "Iniciativa: \n";
   
   INIP= rand() % 20 + 1;
   INIM= rand() % 20 + 1;
   
   INIP = INIP+INI;
   INIM = INIM+2;
   cout << "Jogador: " << INIP;
   cout << "\nBanshee: " << INIM << "\n"; 
   system("pause");
   system("CLS");
   
   if(INIP>INIM)
   {
	cout << "Você começa.\n";
	system("pause");
   	while((vida>=0)&&(vidam>=0))
	{
		cout << "Selecione uma opção:\n1) Arco Curto(dano 1d6).\n2) Raio do Caos(dano 2d8).\n3) Escudo Arcano(CA+5).\n4) Vitalidade Falsa(recupera ou adiciona 1d4+4).\n";
   		cin >> op;
   		
   		switch(op)
		   {
		   case 1:
			shot= rand() % 20 + 1;
		   	shot = shot+ATKM;
		   	if(shot>CAm)
			   {
		   		dano= rand() % 6 + 1;
		   		dano = dano + DES;
		   		cout << "Dano = " << dano << "\n";
		   		vidam = vidam-dano;
		   		cout << "\nBanshee(PV): " << vidam << "\n";
		   		system("pause");
		   		system("CLS");
			   }
			    else
			   {
				   cout << "Você errou!\n";
				   system("pause");
				   system("CLS");
			   }
			   break;
		   case 2:
		   	shot= rand() % 20 + 1;
		   	shot = shot+ATKM;
		   	if(shot>CAm)
			   {
		   	roll= rand() % 8 + 1;
		   	roll2= rand() % 8 + 1;
			dano=roll+roll2;
			cout << "Dano = " << dano << "\n";
			vidam = vidam-dano;
		   	cout << "\nBanshee(PV): " << vidam << "\n";
		   	system("pause");
		   	system("CLS");
			   }
			   else
			   {
				   cout << "Você errou!\n";
				   system("pause");
				   system("CLS");
			   }
			   break;
		   case 3:
		   	CA = CA+5;
		   	cout << "\nSua CA é de: " << CA;
		   	system("pause");
		   	system("CLS");
			   break;
		   default:
		   	cura= rand() % 4 + 1;
		   	vida = vida + cura;
		   	cout << "\nSua vida atual é de: " << vida;
		   	system("pause");
		   	system("CLS");
			   break;
		   }
		   //Ataque Banshee
		   shot= rand() % 20 + 1;
		   shot = shot+4;
		   if(shot>CA)
		   {
		   for(int i = 0; i<3; i++)
		   {
		   	dano=0;
		   	roll= rand() % 6 + 1;
		   	dano = dano+roll; 
		   }
		   dano = dano+4;
		   cout << "Dano = " << dano;
		   vida = vida-dano;
		   cout << "\nSua vida é: " << vida << "\n";
		   system("pause");
		   system("CLS");
		   }	else
			      {
					  cout << "Banshee errou.\n";
					  system("pause");
					  system("CLS");
				  }
	}
   }
   /*-------------------------------------*/
   	else
  	   {
  	   	cout << "Banshee vai primeiro.\n";
		 	system("pause");
		 while((vida>0)&&(vidam>0))
		 {
			  //Ataque Banshee
		   shot= rand() % 20 + 1;
		   shot = shot+4;
		   if(shot>CA)
		   {
			roll= rand() % 6 + 1;
			roll2= rand() % 6 + 1;
			roll3= rand() % 6 + 1;
			dano=roll+roll2+roll3;
		   dano = dano+4;
		   cout << "Dano = " << dano << "\n";
		   vida = vida-dano;
		   cout << "\nSua vida é: " << vida << "\n";
		   system("pause");
		   system("CLS");
		   }	else
			      {
					  cout << "Banshee errou.\n";
					  system("pause");
					  system("CLS");
				  }
			cout << "Selecione uma opção:\n1) Arco Curto(dano 1d6).\n2) Raio do Caos(dano 2d8).\n3) Escudo Arcano(CA+5).\n4) Vitalidade Falsa(recupera ou adiciona 1d4+4).\n";
   		   	cin >> op;
   		
   		   	switch(op)
		   {
		   case 1:
			shot= rand() % 20 + 1;
		   	shot = shot+ATKM;
		   	if(shot>CAm)
			   {
		   		dano= rand() % 6 + 1;
		   		dano = dano + DES;
		   		cout << "Dano = " << dano;
		   		vidam = vidam-dano;
		   		cout << "\nBanshee(PV): " << vidam << "\n";
		   		system("pause");
		   		system("CLS");
			   }
			    else
			   {
				   cout << "Você errou!\n";
				   system("pause");
				   system("CLS");
			   }
			   break;
		   case 2:
		   	shot= rand() % 20 + 1;
		   	shot = shot+ATKM;
		   	if(shot>CAm)
			   {
			roll= rand() % 8 + 1;
		   	roll2= rand() % 8 + 1;
			dano=roll+roll2;
			cout << "Dano = " << dano;
			vidam = vidam-dano;
		   	cout << "\nBanshee(PV): " << vidam << "\n";
		   	system("pause");
		   	system("CLS");
			   }
			   else
			   {
				   cout << "Você errou!\n";
				   system("pause");
				   system("CLS");
			   }
			   break;
		   case 3:
		   	CA = CA+5;
		   	cout << "\nSua CA é de: " << CA << "\n";
		   	system("pause");
		   	system("CLS");
			   break;
		   default:
		   	cura= rand() % 4 + 1;
		   	vida = vida + cura;
		   	cout << "\nSua vida atual é de: " << vida << "\n";
		   	system("pause");
		   	system("CLS");
			   break;
		   }
		 }
		 
		 if(vida<=0)
		 {
		 	cout << "Você Perdeu!";
		 }
		 else
		 {
			 cout << "Você Venceu!";
		 }
	   
 	   }
   return 0;
}