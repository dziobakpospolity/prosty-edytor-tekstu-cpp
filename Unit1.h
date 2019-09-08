//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include "Unit2.h"
#define max_n_znakow 21
typedef int TTablica[max_n_znakow];
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TPageControl *PageControl1;
	TPanel *Panel3;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TActionList *ActionList1;
	TAction *Action1;
	TAction *Action2;
	TAction *Action3;
	TStatusBar *StatusBar1;
	TAction *Action4;
	TMenuItem *zamknij1;
	TMenuItem *Plik1;
	TMenuItem *Nowy1;
	TMenuItem *Action21;
	TMenuItem *Zapisz1;
	TAction *Action5;
	TAction *statyst;
	TStatusBar *StatusBar2;
	TStatusBar *StatusBar3;
	TPanel *Panel1;
	TMenuItem *Nowy2;
	TMenuItem *statyst1;
	void __fastcall Otwrz1Click(TObject *Sender);
	void __fastcall Zapisz1Click(TObject *Sender);
	void __fastcall Action2Execute(TObject *Sender);
	void __fastcall Action4Execute(TObject *Sender);
	void __fastcall Action5Execute(TObject *Sender);
	void __fastcall statystExecute(TObject *Sender);
	void __fastcall Update(TObject *Sender);



private:	// User declarations
public:		// User declarations


	__fastcall TForm1(TComponent* Owner);
	void __fastcall DodajZakladke(TPageControl *APageControl);
	TStringList *Tokenize (String s,String delimiter);
	void __fastcall WyodrebnijString();
	void LiczZnaki(TStringList *slowa , TTablica &TablicaWynikowa );


};


//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
