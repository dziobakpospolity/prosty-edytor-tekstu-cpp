//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TDocument::TDocument(TPageControl *APageControl): TTabSheet(APageControl)
{
 PageControl = APageControl;
 Caption = "Nowy dokument";
 /* słówko this oznacza odwołanie się do konkretnej instancji obiektu
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
 /*Procedura ExtractFileName pozwala na wyciągniecie samej nazwy pliku z
pełnej ścieżki dostępu. Nazwa zakładki będzie nazwą pliku.*/
 Caption = ExtractFileName(FileName);
}

void TDocument::SaveToFile(String AFileName)
{
 FileName = AFileName;
 RichEdit->Lines->SaveToFile(FileName);
}

