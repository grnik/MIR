//---------------------------------------------------------------------------

#ifndef PrintReportH
#define PrintReportH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "RpCon.hpp"
#include "RpConDS.hpp"
#include "RpDefine.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
#include "RpRave.hpp"
//---------------------------------------------------------------------------
class TfrmPrintReport : public TForm
{
__published:	// IDE-managed Components
	TADOQuery *qrOperators;
	TRvDataSetConnection *rvcOperators;
	TLabel *Label1;
	TEdit *txtDateStart;
	TLabel *Label2;
	TEdit *txtDateFinish;
	TButton *btPrint;
	TRvProject *rvpPrintReport;
	TListBox *lstPrintReport;
	TLabel *Label3;
	TMemo *mmPrintReport;
	TADOQuery *qrReporters;
	TRvDataSetConnection *rvcReporters;
	TADOQuery *qrOperatorSub;
	TRvDataSetConnection *rvcOperatorSub;
	TADOQuery *qrReporterSub;
	TRvDataSetConnection *rvcReporterSub;
	void __fastcall btPrintClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall lstPrintReportDblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmPrintReport(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPrintReport *frmPrintReport;
//---------------------------------------------------------------------------
#endif
