//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ScktComp.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo1;
        TTimer *Timer1;
        TServerSocket *ServerSocket1;
        TMainMenu *MainMenu1;
        TMenuItem *Controle1;
        TMenuItem *AbrirCOMM1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall AbrirCOMM1Click(TObject *Sender);
        void __fastcall ServerSocket1ClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        DCB dcb;
        HANDLE hSerial;
        unsigned long nRetBytesWritten ;
        bool bConnected;
        String szCom;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
