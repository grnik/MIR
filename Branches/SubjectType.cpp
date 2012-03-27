//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SubjectType.h"
#include "Data.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSubjectType *frmSubjectType;
//---------------------------------------------------------------------------
__fastcall TfrmSubjectType::TfrmSubjectType(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmSubjectType::FormShow(TObject *Sender)
{
	tblBranch->Open();	
}
//---------------------------------------------------------------------------
void __fastcall TfrmSubjectType::btOkClick(TObject *Sender)
{
	if(tblBranch->Modified)
		tblBranch->Post();
	ModalResult = mrOk;
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmSubjectType::btCancelClick(TObject *Sender)
{
	if(tblBranch->Modified)
		tblBranch->Cancel();
	ModalResult = mrCancel;
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmSubjectType::FormClose(TObject *Sender, TCloseAction &Action)
{
	tblBranch->Close();
}
//---------------------------------------------------------------------------

