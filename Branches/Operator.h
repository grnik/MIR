//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef OperatorH
#define OperatorH
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
class TfrmOperator : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TADOTable *tblOperator;
	TDataSource *dtsOperator;
	TPanel *Panel1;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TDBGrid *DBGrid2;
	TADOTable *tblBranch;
	TDataSource *dtsBranch;
	TPanel *Panel2;
	TADOQuery *qrSubject;
	TDataSource *dtsSubject;
	TDBGrid *DBGrid3;
	TSplitter *Splitter1;
	TSplitter *Splitter2;
	TDBNavigator *DBNavigator1;
	TPopupMenu *PopupMenu1;
	TPopupMenu *PopupMenu2;
	TMenuItem *N1;
	TMenuItem *N2;
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	//Номер выбранного оператора
	int ChOperator_ID;

	__fastcall TfrmOperator(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmOperator *frmOperator;
//---------------------------------------------------------------------------
#endif
