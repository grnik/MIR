//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <DBCtrls.hpp>
#include <DBCGrids.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *mnmMain;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *mnExit;
	TMenuItem *mnBrach;
	TMenuItem *mnReporter;
	TMenuItem *mnOperator;
	TPanel *Panel1;
	TLabel *Label1;
	TMaskEdit *txtDateStart;
	TDBGrid *DBGrid1;
	TADOQuery *qrBranche;
	TDataSource *dtsBranch;
	TSplitter *Splitter1;
	TButton *Button1;
	TPanel *Panel2;
	TSplitter *Splitter2;
	TMenuItem *N3;
	TMenuItem *N4;
	TPanel *Panel3;
	TDBGrid *dbgSubjectList;
	TMenuItem *N5;
	TLabel *Label5;
	TDBLookupComboBox *dblSubjectTypeCh;
	TADOTable *tblSubjectTypeCh;
	TDataSource *dtsSubjectTypeCh;
	TADOQuery *qrSubjectList;
	TDataSource *dtsSubjectList;
	TPanel *Panel4;
	TButton *btSubjectEdit;
	TButton *btSubjectInsert;
	TButton *Button2;
	TADOQuery *qrOperators;
	TADOQuery *qrReporters;
	TDataSource *dtsOperators;
	TDataSource *dtsReporters;
	TDBGrid *DBGrid3;
	TDBGrid *DBGrid4;
	TPopupMenu *ppmSubjectList;
	TMenuItem *N6;
	TLabel *Label2;
	TEdit *txtTextFind;
	void __fastcall mnExitClick(TObject *Sender);
	void __fastcall mnBrachClick(TObject *Sender);
	void __fastcall mnReporterClick(TObject *Sender);
	void __fastcall mnOperatorClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall dblSubjectTypeChClick(TObject *Sender);
	void __fastcall qrBrancheAfterScroll(TDataSet *DataSet);
	void __fastcall qrSubjectListNewRecord(TDataSet *DataSet);
	void __fastcall btSubjectEditClick(TObject *Sender);
	void __fastcall btSubjectInsertClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall dbgSubjectListTitleClick(TColumn *Column);
	void __fastcall txtTextFindExit(TObject *Sender);
private:	// User declarations
	void Refresh();

	AnsiString SortedColumn;
	bool SetFilterSubjectType;
public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
