//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef ReporterH
#define ReporterH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <Buttons.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TfrmReporter : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TPanel *Panel1;
	TBitBtn *btOk;
	TBitBtn *btCancel;
	TDataSource *dtsReporter;
	TADOTable *tblReporter;
	TADOTable *tblBranch;
	TDataSource *dtsBranch;
	TDBGrid *DBGrid2;
	TDBGrid *DBGrid3;
	TADOQuery *qrSubject;
	TDataSource *dtsSubject;
	TDBNavigator *DBNavigator1;
	TSplitter *Splitter1;
	TSplitter *Splitter2;
	TPopupMenu *PopupMenu1;
	TPopupMenu *PopupMenu2;
	TMenuItem *N1;
	TMenuItem *N2;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btOkClick(TObject *Sender);
	void __fastcall btCancelClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	//Выбранный корреспондент
	int ChReporter_ID;
	
	__fastcall TfrmReporter(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmReporter *frmReporter;
//---------------------------------------------------------------------------
#endif
