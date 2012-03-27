//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Subject.h"
#include "Data.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSubject *frmSubject;
//---------------------------------------------------------------------------
__fastcall TfrmSubject::TfrmSubject(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmSubject::btAddOperatorClick(TObject *Sender)
{
	if(tblSubject->Modified)
		tblSubject->Post();
	frmDataModule->ExecuteQuery("insert into dbo.SubjectOperator(Subject_ID,Operator_ID) \
		VALUES(" + tblSubject->FieldByName("ID")->AsString + ","
		+ tblOperators->FieldByName("ID")->AsString + ");");
	Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TfrmSubject::btDelOperatorClick(TObject *Sender)
{
	if(tblSubject->Modified)
		tblSubject->Post();
	frmDataModule->ExecuteQuery("delete from dbo.SubjectOperator \
		where Subject_ID = " + tblSubject->FieldByName("ID")->AsString
		+ " and Operator_ID = " + qrSubjectOperator->FieldByName("Operator_ID")->AsString + ";");
	Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfrmSubject::btAddReporterClick(TObject *Sender)
{
	if(tblSubject->Modified)
		tblSubject->Post();
	frmDataModule->ExecuteQuery("insert into dbo.SubjectReporter(Subject_ID,Reporter_ID) \
		VALUES(" + tblSubject->FieldByName("ID")->AsString + ","
		+ tblReporters->FieldByName("ID")->AsString + ");");
	Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfrmSubject::btDelReporterClick(TObject *Sender)
{
	if(tblSubject->Modified)
		tblSubject->Post();

	AnsiString SubID = tblSubject->FieldByName("ID")->AsString;
	AnsiString RepID = qrSubjectReporter->FieldByName("Reporter_ID")->AsString;

	frmDataModule->ExecuteQuery("delete from dbo.SubjectReporter \
		where Subject_ID = " + SubID
		+ " and Reporter_ID = " + RepID + ";");
	Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TfrmSubject::FormShow(TObject *Sender)
{
	Refresh();	
}
//---------------------------------------------------------------------------
void TfrmSubject::Refresh()
{
	if(tblSubject->Modified)
		tblSubject->Post();

	tblSubject->Filtered = false;
	qrSubjectReporter->Close();
	tblReporters->Close();
	qrSubjectOperator->Close();
	tblOperators->Close();
	tblSubjectType->Close();
//	tblSubject->Close();

	if (SubjectID != 0) {
		tblSubject->Filter = "ID = " + (AnsiString)SubjectID;
		tblSubject->Filtered = true;
	}

	tblSubject->Open();
	tblSubjectType->Open();
	tblOperators->Open();
	qrSubjectOperator->Open();
	tblReporters->Open();
	qrSubjectReporter->Open();
}
//---------------------------------------------------------------------------
//Редактируем запись
void TfrmSubject::Edit(int SubjectID, int BranchID, AnsiString BranchName)
{
	this->SubjectID = SubjectID;
	this->BranchID = BranchID;
	this->BranchName = BranchName;
	lblBranchName->Caption = BranchName;
	
	ShowModal();
};
//---------------------------------------------------------------------------
//Вставляем репортаж
int TfrmSubject::Insert(int BranchID, AnsiString BranchName)
{
	tblSubject->Close();
	tblSubject->Filtered = false;
	tblSubject->Open();
	tblSubject->Insert();
	tblSubjectType->Open();
//	tblSubject->FieldByName("ID")->Value = frmDataModule->LastID("Subjectes")+1;
	tblSubject->FieldByName("Name")->Value = "Новый сюжет";
	tblSubject->FieldByName("Branche_ID")->Value = BranchID;
	tblSubject->FieldByName("SubjectType_ID")->Value
		=	tblSubjectType->FieldByName("ID")->AsInteger;
	tblSubject->FieldByName("DateSubject")->Value
		=	TDateTime::CurrentDate();
	tblSubject->Post();
	this->SubjectID = tblSubject->FieldByName("ID")->AsInteger;

	this->BranchID = BranchID;
	this->BranchName = BranchName;
	lblBranchName->Caption = BranchName;

	if(ShowModal() == mrOk)
		return SubjectID;
	else {
		return -1;
	}
};
//---------------------------------------------------------------------------
//Удаляем репортаж
void TfrmSubject::Delete(int SubjectID)
{
	frmDataModule->ExecuteQuery("delete from dbo.SubjectOperator \
		where Subject_ID = " + (AnsiString)SubjectID + ";");
	frmDataModule->ExecuteQuery("delete from dbo.SubjectReporter \
		where Subject_ID = " + (AnsiString)SubjectID + ";");
	frmDataModule->ExecuteQuery("delete from dbo.Subjectes \
		where ID = " + (AnsiString)SubjectID + ";");
};
//---------------------------------------------------------------------------

void __fastcall TfrmSubject::btOkClick(TObject *Sender)
{
	if(tblSubject->Modified)
		tblSubject->Post();
	ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TfrmSubject::btCancelClick(TObject *Sender)
{
	if(tblSubject->Modified)
		tblSubject->Cancel();
	TfrmSubject::Delete(SubjectID);
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

void __fastcall TfrmSubject::FormClose(TObject *Sender, TCloseAction &Action)
{
	qrSubjectReporter->Close();
	tblReporters->Close();
	qrSubjectOperator->Close();
	tblOperators->Close();
	tblSubjectType->Close();
	tblSubject->Close();
}
//---------------------------------------------------------------------------

