//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PrintReport.h"
#include "Data.h"
#include "Operator.h"
#include "Reporter.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RpCon"
#pragma link "RpConDS"
#pragma link "RpDefine"
#pragma link "RpRave"
#pragma resource "*.dfm"
TfrmPrintReport *frmPrintReport;
//---------------------------------------------------------------------------
__fastcall TfrmPrintReport::TfrmPrintReport(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrintReport::btPrintClick(TObject *Sender)
{
int IndexReport = lstPrintReport->ItemIndex;

//В принципе должно быть как-то как, но лень разбираться
//AnsiString SelReport = lstPrintReport->Items[InexReport].Text;
AnsiString SelReport = lstPrintReport->Items->ValueFromIndex[IndexReport];
	SelReport = lstPrintReport->Items->Values[IndexReport];

	switch (IndexReport) {
		case 0 : SelReport = "Операторы"; break;
		case 1 : SelReport = "Корреспонденты"; break;
		case 2 : SelReport = "Сюжеты оператора"; break;
		case 3 : SelReport = "Сюжеты корреспондента"; break;
	default:
		SelReport = "";
	}

	if (SelReport == "Операторы"){
			qrOperators->Close();
			qrOperators->Parameters->ParamByName("DateStart")->Value
				= txtDateStart->Text;
			qrOperators->Parameters->ParamByName("DateFinish")->Value
				= txtDateFinish->Text;
			qrOperators->Open();
	}else if (SelReport == "Корреспонденты"){
			qrReporters->Close();
			qrReporters->Parameters->ParamByName("DateStart")->Value
				= txtDateStart->Text;
			qrReporters->Parameters->ParamByName("DateFinish")->Value
				= txtDateFinish->Text;
			qrReporters->Open();
	}else if (SelReport == "Сюжеты оператора"){
			qrOperatorSub->Close();
			if(frmOperator->ShowModal() == mrOk)
			{
				qrOperatorSub->Parameters->ParamByName("Operator_ID")->Value
					= frmOperator->ChOperator_ID;
				qrOperatorSub->Parameters->ParamByName("DateStart")->Value
					= txtDateStart->Text;
				qrOperatorSub->Parameters->ParamByName("DateFinish")->Value
					= txtDateFinish->Text;
				qrOperatorSub->Open();
			}else{
				return;
			}
	}else if (SelReport == "Сюжеты корреспондента"){
			qrReporterSub->Close();
			if(frmReporter->ShowModal() == mrOk)
			{
				qrReporterSub->Parameters->ParamByName("Reporter_ID")->Value
					= frmReporter->ChReporter_ID;
				qrReporterSub->Parameters->ParamByName("DateStart")->Value
					= txtDateStart->Text;
				qrReporterSub->Parameters->ParamByName("DateFinish")->Value
					= txtDateFinish->Text;
				qrReporterSub->Open();
			}else
				return;
	}

	rvpPrintReport->SelectReport(SelReport,true);
	rvpPrintReport->ReportDescToMemo(mmPrintReport);

//	rvpPrintReport->Design();
	rvpPrintReport->Execute();
//	rvpPrintReport->ExecuteReport(lstPrintReport->Items[lstPrintReport->ItemIndex].Text);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrintReport::FormShow(TObject *Sender)
{
	rvpPrintReport->Open();
	rvpPrintReport->GetReportList(lstPrintReport->Items,TRUE);

	txtDateStart->Text = (TDateTime::CurrentDate() - 30);
	txtDateFinish->Text = TDateTime::CurrentDate();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrintReport::FormClose(TObject *Sender,
			TCloseAction &Action)
{
	rvpPrintReport->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrintReport::lstPrintReportDblClick(TObject *Sender)
{
	btPrintClick(Sender);
}
//---------------------------------------------------------------------------

