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
TDocument * doc;
doc = new TDocument(PageControl1);
doc->RichEdit->OnChange = Update ;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Otwrz1Click(TObject *Sender)
{
	if(OpenDialog1->Execute()){
		TDocument * doc;
		doc = new TDocument(PageControl1);
		doc -> LoadFromFile(OpenDialog1->FileName);
		doc->RichEdit->OnChange = Update;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zapisz1Click(TObject *Sender)
{
	if(SaveDialog1->Execute()){
		TTabSheet * az;
		az = PageControl1 -> ActivePage;
		TDocument*doc;
		doc = dynamic_cast<TDocument*>(az);
		//String text = doc->RichEdit->Text;
		if(doc)
			doc->SaveToFile(SaveDialog1->FileName);
	}
}
void __fastcall TForm1::DodajZakladke(TPageControl *APageControl)
{
		TDocument * doc;
		doc = new TDocument(PageControl1);
		doc->RichEdit->OnChange = Update;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Action2Execute(TObject *Sender)
{
	DodajZakladke(PageControl1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::WyodrebnijString()
{

		TTabSheet * az;
		az = PageControl1 -> ActivePage;
		TDocument*doc;
		doc = dynamic_cast<TDocument*>(az);
		String text = doc->RichEdit->Text;


		TStringList* ls = Tokenize(text, " ");
		TStringList* lz = Tokenize(text, ".");
		TStringList* la = Tokenize(text, "\n");
		int ls2 = ls->Count;
		int lz2 = lz->Count;
		int la2 = la->Count;
		int iloscznakow = text.Length() - la2 +1;
		StatusBar1->Panels->Items[0]->Text = "Znaków: "+ IntToStr(iloscznakow);
		StatusBar1->Panels->Items[1]->Text = "S³ów: "+ IntToStr(ls2 + la2 -2);
		StatusBar1->Panels->Items[2]->Text = "Zdañ: "+IntToStr(lz2 - 1);
		StatusBar1->Panels->Items[3]->Text = "Akapitów: "+IntToStr(la2);


	TTablica tabSlow;
	LiczZnaki(ls , tabSlow);

	StatusBar2->Panels->Items[0]->Text = "L. w wyrazie/ ile razy:" ;

	for(int i = 1; i<11; i++)
	{

		StatusBar2->Panels->Items[i]->Text = IntToStr(i) + " liter: " + IntToStr(tabSlow[i]);
	}

	for(int i = 11; i<20; i++)
	{
		StatusBar3->Panels->Items[i-10]->Text = IntToStr(i) + " liter: " + IntToStr(tabSlow[i]);
	}

	StatusBar3->Panels->Items[9]->Text = "20 i wiêcej liter: " + IntToStr(tabSlow[20]);
}
 TStringList *TForm1::Tokenize (String s,String delimiter)
{
 TStringList *StringList;
 int l; //length of s
 int start,delimp;
 String sub;
 StringList = new TStringList();
 start=0;
 if (s.Pos(delimiter)>0)
 {
 delimp = s.Pos(delimiter);
 do
 {
 l=s.Length();
 sub=s.SubString(start,delimp-1);
 if (sub != "") StringList->Add(sub);
 s=s.SubString(delimp+1,l-delimp);
 delimp = s.Pos(delimiter);
 } while (delimp != 0);
 StringList->Add(s); // dodanie tego co zosta³o na koñcu
 }
 else StringList->Add(s);
 return StringList;  }


//---------------------------------------------------------------------------


void __fastcall TForm1::Action4Execute(TObject *Sender)
{
   TTabSheet * az;
   az = PageControl1 -> ActivePage;
   delete az;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Action5Execute(TObject *Sender)
{
	WyodrebnijString();
}
//---------------------------------------------------------------------------


void TForm1::LiczZnaki(TStringList *slowa , TTablica &TablicaWynikowa )
{
 int i, dl;
 // najpierw zainicjujmy tablicê wyników
 for (i = 1; i< max_n_znakow; i++)
 TablicaWynikowa[i] = 0;
 // nastêpnie policzmy odpowiednie s³owa
 for (i=0; i<slowa->Count; i++)
 {
 dl = (*slowa)[i].Length();
 if (dl > max_n_znakow)
 TablicaWynikowa[max_n_znakow -1] = TablicaWynikowa[max_n_znakow -1] + 1;
 else if (dl > 0)
 TablicaWynikowa[dl] = TablicaWynikowa[dl] + 1;
 }
}

void __fastcall TForm1::statystExecute(TObject *Sender)
{
	 TTabSheet* az;
	 az = PageControl1 -> ActivePage;
	 TDocument*doc;
	 doc = dynamic_cast<TDocument*>(az);
	 String text = doc->RichEdit->Text;




}
//---------------------------------------------------------------------------

 void __fastcall TForm1::Update(TObject *Sender)
{
	 WyodrebnijString();
}


