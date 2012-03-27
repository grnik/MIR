//---------------------------------------------------------------------------

#ifndef SubjectH
#define SubjectH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TfrmSubject : public TForm
{
__published:	// IDE-managed Components
	TDataSource *dtsSubject;
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label3;
	TLabel *Label4;
	TADOTable *tblSubjectType;
	TDataSource *dtsSubjectType;
	TDBLookupComboBox *DBLookupComboBox3;
	TDBEdit *DBEdit1;
	TDBEdit *DBEdit2;
	TDBMemo *DBMemo1;
	TPanel *Panel2;
	TDataSource *dtsSubjectOperator;
	TPanel *Panel4;
	TLabel *Label2;
	TPanel *Panel5;
	TLabel *Label5;
	TPanel *Panel6;
	TPanel *Panel7;
	TLabel *Label6;
	TPanel *Panel8;
	TLabel *Label7;
	TDBGrid *DBGrid1;
	TADOQuery *qrSubjectOperator;
	TADOQuery *qrSubjectReporter;
	TDataSource *dtsSubjectReporter;
	TDBGrid *DBGrid2;
	TADOTable *tblOperators;
	TDataSource *dtsOperators;
	TDBGrid *DBGrid3;
	TADOTable *tblReporters;
	TDataSource *dtsReporters;
	TDBGrid *DBGrid4;
	TLabel *Label8;
	TLabel *lblBranchName;
	TPanel *Panel9;
	TButton *btAddReporter;
	TButton *btDelReporter;
	TPanel *Panel3;
	TButton *btAddOperator;
	TButton *btDelOperator;
	TButton *btOk;
	TButton *btCancel;
	TDBEdit *DBEdit3;
	TLabel *Label9;
	TADOTable *tblSubject;
	TDBEdit *DBEdit4;
	TDBEdit *DBEdit5;
	TDBEdit *DBEdit6;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	void __fastcall btAddOperatorClick(TObject *Sender);
	void __fastcall btDelOperatorClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btAddReporterClick(TObject *Sender);
	void __fastcall btDelReporterClick(TObject *Sender);
	void __fastcall btOkClick(TObject *Sender);
	void __fastcall btCancelClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
	int SubjectID;
	int BranchID;
	AnsiString BranchName;

	//Мои функции
	void Refresh();
public:		// User declarations
	__fastcall TfrmSubject(TComponent* Owner);

	//Редактируем репортаж
	void Edit(int SubjectID, int BranchID, AnsiString BranchName);
	//Вставляем репортаж
	int Insert(int BranchID, AnsiString BranchName);
	//Удаляем репортаж
	void static Delete(int SubjectID);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSubject *frmSubject;
//---------------------------------------------------------------------------
#endif
