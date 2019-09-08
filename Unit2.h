//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
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


class TDocument : public TTabSheet
{
public:
 TDocument(TPageControl *APageControl);
 __fastcall ~TDocument(){};
 void LoadFromFile(String AFileName);
 void SaveToFile(String AFileName);
 TRichEdit *RichEdit;
 String FileName;
};
#endif
