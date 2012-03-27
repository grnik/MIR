//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef BranchH
#define BranchH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <DBCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmBranch : public TForm
{
__published:	// IDE-managed Components
	TADOTable *tblBranch;
	TDataSource *dtsBranch;
	TDBGrid *DBGrid1;
	TPanel *Panel1;
	TBitBtn *btOk;
	TBitBtn *btCancel;
	TDBNavigator *DBNavigator1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btOkClick(TObject *Sender);
	void __fastcall btCancelClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmBranch(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmBranch *frmBranch;
//---------------------------------------------------------------------------
#endif
