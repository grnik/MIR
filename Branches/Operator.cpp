//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Operator.h"
#include "Data.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmOperator *frmOperator;
//---------------------------------------------------------------------------
__fastcall TfrmOperator::TfrmOperator(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmOperator::BitBtn1Click(TObject *Sender)
{
	if(tblOperator->Modified)
		tblOperator->Post();
	Close();
	ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TfrmOperator::BitBtn2Click(TObject *Sender)
{
	if(tblOperator->Modified)
		tblOperator->Cancel();
	Close();
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TfrmOperator::FormShow(TObject *Sender)
{
	tblBranch->Open();
	tblOperator->Open();
	qrSubject->Open();
}
//---------------------------------------------------------------------------
void __fastcall TfrmOperator::FormClose(TObject *Sender, TCloseAction &Action)
{
	ChOperator_ID = tblOperator->FieldByName("ID")->AsInteger;

	tblBranch->Close();
	tblOperator->Close();
	qrSubject->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmOperator::N1Click(TObject *Sender)
{
	frmDataModule->DataToClipboard(tblOperator);
}
//---------------------------------------------------------------------------

void __fastcall TfrmOperator::N2Click(TObject *Sender)
{
	frmDataModule->DataToClipboard(qrSubject);
}
//---------------------------------------------------------------------------

