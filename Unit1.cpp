//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Form1->Caption = "Servidor Controle Remoto";
        bConnected     = false;
        szCom = "COM3";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AbrirCOMM1Click(TObject *Sender)
{
        String parametros;
        memset(&dcb,0,sizeof(dcb));
        parametros = "baud=9600 parity=N data=8 stop=2";
        dcb.DCBlength = sizeof(dcb);

        if((hSerial = CreateFile(szCom.c_str(), GENERIC_READ | GENERIC_WRITE,
                0,0,OPEN_EXISTING,NULL,0)) == INVALID_HANDLE_VALUE)
        {
          Memo1->Lines->Add(DateToStr(Now())+" "+TimeToStr(Now())+
            ":Falhou ao Iniciar "+szCom+"!");
          return;
        }
        if(!GetCommState(hSerial,&dcb))
	{
          Memo1->Lines->Add(DateToStr(Now())+" "+TimeToStr(Now())+
            ":Falhou ao Iniciar "
            +szCom+"!(GetCommState)");
          return;
        }
        if(!BuildCommDCB(parametros.c_str(),&dcb))
	{
          Memo1->Lines->Add(DateToStr(Now())+" "+TimeToStr(Now())
          +":Falhou ao Iniciar "
          +szCom+"(BuildCommDCB)");
          return;
	}
        if(!SetCommState(hSerial,&dcb))
	{
          Memo1->Lines->Add(DateToStr(Now())+" "+TimeToStr(Now())
          +":Falhou ao Iniciar "
          +szCom+"!SetCommState");
	}

        Memo1->Lines->Add(DateToStr(Now())+" "+TimeToStr(Now())+": Connectado "
        +szCom);
        bConnected = true;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket1ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
  String S;
  S = Socket->ReceiveText();
  int i = S.Pos("act=On");

  if( i > 0  )
  {
    nRetBytesWritten = 0;
    if (bConnected)
    {
      Memo1->Lines->Add(DateToStr(Now())+" "+TimeToStr(Now())+
        " :Enviando comando para abrir portão!");
        WriteFile( hSerial,"Act",sizeof("Act"),&nRetBytesWritten,NULL );
        WriteFile( hSerial,"\n",1,&nRetBytesWritten,NULL );
    }
    else
    {
      Memo1->Lines->Add(DateToStr(Now())+" "+TimeToStr(Now())+
        " :Não connectado a "+szCom+"!");
    }
  }
  Memo1->Lines->Add(DateToStr(Now())+" "+TimeToStr(Now())+" :"+S);
  Socket->SendText("Teste\n\n");
  Memo1->Lines->SaveToFile("res.txt");
  Socket->Close();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  if(bConnected)
  {
    String S;
    S = "Hour"+TimeToStr(Now());
    nRetBytesWritten = 0;
    if (bConnected)
    {
      WriteFile( hSerial,S.c_str(),S.Length(),&nRetBytesWritten,NULL );
      WriteFile( hSerial,"\n",1,&nRetBytesWritten,NULL );
    }
  }
}
//---------------------------------------------------------------------------
