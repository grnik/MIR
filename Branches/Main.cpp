//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Branch.h"
#include "Operator.h"
#include "Reporter.h"
#include "Data.h"
#include "PrintReport.h"
#include "SubjectType.h"
#include "Subject.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
	SortedColumn = '1';
	SetFilterSubjectType = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::mnExitClick(TObject *Sender)
{
	Close();	
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::mnBrachClick(TObject *Sender)
{
	frmBranch->ShowModal();
	Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::mnReporterClick(TObject *Sender)
{
	frmReporter->ShowModal();
	Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::mnOperatorClick(TObject *Sender)
{
	frmOperator->ShowModal();
	Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::Button1Click(TObject *Sender)
{
	Refresh();
}
//---------------------------------------------------------------------------
void TfrmMain::Refresh()
{
AnsiString SbTypeCh="";
int CurrentFilial = 1;
int CurrentSubject = 1;

	if (tblSubjectTypeCh->Active) {
		SbTypeCh = tblSubjectTypeCh->FieldByName("ID")->Value;
	}

	if(qrBranche->Active)
		CurrentFilial = qrBranche->RecNo;
	if(qrSubjectList->Active)
		CurrentSubject = qrSubjectList->RecNo;

	qrOperators->Close();
	qrReporters->Close();
	qrSubjectList->Close();
	qrBranche->Close();
//	tblSubjectTypeCh->Close();

	qrSubjectList->SQL->Clear();

	qrSubjectList->SQL->Add("\
select dbo.Subjectes.Name, dbo.Subjectes.SubjectType_ID, dbo.Subjectes.Description, dbo.Subjectes.DateSubject\
	, dbo.Subjectes.TimeKeeping                                                                                \
	, dbo.SubjectType.Name SubjectTypeName                                                                     \
	, (select top 1 dbo.Operators.Name                                                                         \
		 from dbo.Operators inner join dbo.SubjectOperator on dbo.Operators.ID = dbo.SubjectOperator.Operator_ID \
	 where dbo.SubjectOperator.Subject_ID = dbo.Subjectes.ID) OperatorName                                     \
	, (select top 1 dbo.Reporters.Name                                                                         \
		 from dbo.Reporters inner join dbo.SubjectReporter on dbo.Reporters.ID = dbo.SubjectReporter.Reporter_ID \
	 where dbo.SubjectReporter.Subject_ID = dbo.Subjectes.ID) ReporterName                                     \
from dbo.Subjectes inner join dbo.SubjectType on dbo.Subjectes.SubjectType_ID = dbo.SubjectType.ID           \
where dbo.Subjectes.Branche_ID = " + (AnsiString)CurrentFilial + "\
	");

AnsiString ListField = dblSubjectTypeCh->ListField;

	if (SetFilterSubjectType) {
		qrSubjectList->SQL->Add("\
and dbo.Subjectes.SubjectType_ID = " + tblSubjectTypeCh->FieldByName("ID")->Value);
	}

	qrSubjectList->SQL->Add("\
order by " + SortedColumn);

	qrBranche->Parameters->ParamByName("DateStart")->Value = txtDateStart->Text;

	if (!tblSubjectTypeCh->Active) {
				tblSubjectTypeCh->Open();
			}
	qrBranche->Open();
// Отрабатывает в Scroll qrBranch	
//	qrSubjectList->Open();
	qrReporters->Open();
	qrOperators->Open();
	if (CurrentFilial !=1) {
		qrBranche->RecNo = CurrentFilial;
	}
	if (CurrentSubject > 1) {
		qrSubjectList->RecNo = CurrentSubject;
	}
};
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormShow(TObject *Sender)
{
	txtDateStart->Text = TDateTime::CurrentDate()-30;
	Refresh();
}
//---------------------------------------------------------------------------



void __fastcall TfrmMain::N4Click(TObject *Sender)
{
	frmPrintReport->Show();
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::N5Click(TObject *Sender)
{
	frmSubjectType->ShowModal();
	Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::dblSubjectTypeChClick(TObject *Sender)
{
	SetFilterSubjectType = true;
	Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::qrBrancheAfterScroll(TDataSet *DataSet)
{
/*
	qrSubjectList->Close();
//	qrSubjectList->Parameters->ParamByName("SubjectType_ID")->Value
//		= tblSubjectTypeCh->FieldByName("ID")->Value;
	qrSubjectList->Parameters->ParamByName("Branche_ID")->Value
		= qrBranche->FieldByName("ID")->Value;
	qrSubjectList->Open();
*/
	qrSubjectList->Close();

	qrSubjectList->SQL->Clear();
	qrSubjectList->SQL->Add("\
select dbo.Subjectes.*                                                                                       \
	, dbo.SubjectType.Name SubjectTypeName                                                                     \
	, (select top 1 dbo.Operators.Name                                                                         \
		 from dbo.Operators inner join dbo.SubjectOperator on dbo.Operators.ID = dbo.SubjectOperator.Operator_ID \
	 where dbo.SubjectOperator.Subject_ID = dbo.Subjectes.ID) OperatorName                                     \
	, (select top 1 dbo.Reporters.Name                                                                         \
		 from dbo.Reporters inner join dbo.SubjectReporter on dbo.Reporters.ID = dbo.SubjectReporter.Reporter_ID \
	 where dbo.SubjectReporter.Subject_ID = dbo.Subjectes.ID) ReporterName                                     \
from dbo.Subjectes inner join dbo.SubjectType on dbo.Subjectes.SubjectType_ID = dbo.SubjectType.ID           \
where dbo.Subjectes.Branche_ID = " + qrBranche->FieldByName("ID")->Value + "\
	");

	if (SetFilterSubjectType) {
		qrSubjectList->SQL->Add("\
and dbo.Subjectes.SubjectType_ID = " + tblSubjectTypeCh->FieldByName("ID")->Value);
	}

	if (!txtTextFind->Text.IsEmpty()) {
		qrSubjectList->SQL->Add("\
and dbo.Subjectes.Name like '%" + txtTextFind->Text + "%'");
	}

	qrSubjectList->SQL->Add("\
order by " + SortedColumn);

	qrSubjectList->Open();
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::qrSubjectListNewRecord(TDataSet *DataSet)
{
	qrSubjectList->FieldByName("DateSubject")->AsDateTime = TDateTime::CurrentDate();
	qrSubjectList->FieldByName("Branche_ID")->AsInteger
		= qrBranche->FieldByName("ID")->Value;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btSubjectEditClick(TObject *Sender)
{
	frmSubject->Edit(qrSubjectList->FieldByName("ID")->AsInteger
		, qrBranche->FieldByName("ID")->AsInteger, qrBranche->FieldByName("Name")->AsString);
	Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btSubjectInsertClick(TObject *Sender)
{
	frmSubject->Insert(qrBranche->FieldByName("ID")->AsInteger, qrBranche->FieldByName("Name")->AsString);
	Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Button2Click(TObject *Sender)
{
	if (MessageDlg("Вы действительно хотите удалить выбранную запись?", mtConfirmation, mbYesNo, 0)
				== mbNo) {
  	return;
	}
	frmSubject->Delete(qrSubjectList->FieldByName("ID")->AsInteger);
	Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::N6Click(TObject *Sender)
{
	frmDataModule->DataToClipboard(qrSubjectList);
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::dbgSubjectListTitleClick(TColumn *Column)
{
//	SortedColumn = (AnsiString)(Column->Index+1);
	SortedColumn = "dbo.Subjectes." + Column->FieldName;
	Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::txtTextFindExit(TObject *Sender)
{
	Refresh();
}
//---------------------------------------------------------------------------


