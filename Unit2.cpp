//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TDocument::TDocument(TPageControl *APageControl): TTabSheet(APageControl)
{
 PageControl = APageControl;
 Caption = "Nowy dokument";
 /* s³ówko this oznacza odwo³anie siê do konkretnej instancji obiektu
klasy TDocument*/
 RichEdit = new TRichEdit(this);
 RichEdit->Parent = this;
 RichEdit->Align = alClient;
 RichEdit->WordWrap = false;
 RichEdit->ScrollBars = ssBoth;
}

void TDocument::LoadFromFile(String AFileName)
{
 FileName = AFileName;
 RichEdit->Lines->LoadFromFile(FileName);
 /*Procedura ExtractFileName pozwala na wyci¹gniecie samej nazwy pliku z
pe³nej œcie¿ki dostêpu. Nazwa zak³adki bêdzie nazw¹ pliku.*/
 Caption = ExtractFileName(FileName);
}

void TDocument::SaveToFile(String AFileName)
{
 FileName = AFileName;
 RichEdit->Lines->SaveToFile(FileName);
}

