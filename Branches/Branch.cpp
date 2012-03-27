//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Branch.h"
#include "Data.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmBranch *frmBranch;
//---------------------------------------------------------------------------
__fastcall TfrmBranch::TfrmBranch(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmBranch::FormShow(TObject *Sender)
{
	tblBranch->Open();	
}
//---------------------------------------------------------------------------
void __fastcall TfrmBranch::btOkClick(TObject *Sender)
{
	if(tblBranch->Modified)
		tblBranch->Post();
	ModalResult = mrOk;
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmBranch::btCancelClick(TObject *Sender)
{
	if(tblBranch->Modified)
		tblBranch->Cancel();
	ModalResult = mrCancel;
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmBranch::FormClose(TObject *Sender, TCloseAction &Action)
{
	tblBranch->Close();
}
//---------------------------------------------------------------------------

