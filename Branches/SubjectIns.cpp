//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SubjectIns.h"
#include "Data.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSubjectIns *frmSubjectIns;
//---------------------------------------------------------------------------
__fastcall TfrmSubjectIns::TfrmSubjectIns(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//Вставляем репортаж
int TfrmSubjectIns::Insert(int BranchID, AnsiString BranchName)
{
	tblSubject->Open();
	tblSubject->Insert();
//	tblSubjectType->Open();
//	tblSubject->FieldByName("ID")->Value = frmDataModule->LastID("Subjectes")+1;
	tblSubject->FieldByName("Name")->Value = "Новый сюжет";
	tblSubject->FieldByName("Branche_ID")->Value = BranchID;
	tblSubject->FieldByName("SubjectType_ID")->Value = 10;
//		=	tblSubjectType->FieldByName("ID")->AsInteger;
	tblSubject->FieldByName("DateSubject")->Value
		=	TDateTime::CurrentDate();
	tblSubject->Post();
	SubjectID = tblSubject->FieldByName("ID")->Value;

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
void __fastcall TfrmSubjectIns::Button1Click(TObject *Sender)
{
	ADOTable1->Open();
	ADOTable1->Insert();
	ADOTable1->FieldByName("Name")->Value = "Test";
	ADOTable1->FieldByName("SubjectType_ID")->Value = 10;
	ADOTable1->FieldByName("Branche_ID")->Value = 1;
	ADOTable1->FieldByName("DateSubject")->Value = TDateTime::CurrentDate();
	ADOTable1->Post();
	ShowMessage(ADOTable1->FieldByName("ID")->Value);
}
//---------------------------------------------------------------------------

