//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Reporter.h"
#include "Data.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmReporter *frmReporter;
//---------------------------------------------------------------------------
__fastcall TfrmReporter::TfrmReporter(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmReporter::FormShow(TObject *Sender)
{
	tblBranch->Open();
	tblReporter->Open();
	qrSubject->Open();
}
//---------------------------------------------------------------------------
void __fastcall TfrmReporter::btOkClick(TObject *Sender)
{
	if(tblReporter->Modified)
		tblReporter->Post();
	Close();
	ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TfrmReporter::btCancelClick(TObject *Sender)
{
	if(tblReporter->Modified)
		tblReporter->Cancel();
	Close();
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

void __fastcall TfrmReporter::FormClose(TObject *Sender, TCloseAction &Action)
{
	ChReporter_ID = tblReporter->FieldByName("ID")->AsInteger;

	tblBranch->Open();
	tblReporter->Open();
	qrSubject->Open();
}
//---------------------------------------------------------------------------

void __fastcall TfrmReporter::N1Click(TObject *Sender)
{
	frmDataModule->DataToClipboard(tblReporter);
}
//---------------------------------------------------------------------------

void __fastcall TfrmReporter::N2Click(TObject *Sender)
{
	frmDataModule->DataToClipboard(qrSubject);
}
//---------------------------------------------------------------------------

