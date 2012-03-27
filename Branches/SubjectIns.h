//---------------------------------------------------------------------------

#ifndef SubjectInsH
#define SubjectInsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TfrmSubjectIns : public TForm
{
__published:	// IDE-managed Components
	TADOTable *tblSubject;
	TDataSource *dtsSubject;
	TLabel *Label8;
	TLabel *lblBranchName;
	TLabel *Label1;
	TLabel *Label3;
	TLabel *Label4;
	TDBEdit *DBEdit2;
	TLabel *Label9;
	TDBEdit *DBEdit3;
	TADOTable *tblSubjectType;
	TDataSource *dtsSubjectType;
	TDBLookupComboBox *DBLookupComboBox3;
	TButton *Button1;
	TDataSource *DataSource1;
	TDBGrid *DBGrid1;
	TDBNavigator *DBNavigator1;
	TADOTable *ADOTable1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
	int SubjectID;
	int BranchID;
	AnsiString BranchName;
public:		// User declarations
	__fastcall TfrmSubjectIns(TComponent* Owner);

	//Вставляем репортаж
	int Insert(int BranchID, AnsiString BranchName);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSubjectIns *frmSubjectIns;
//---------------------------------------------------------------------------
#endif
