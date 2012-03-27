//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef DataH
#define DataH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <ComCtrls.hpp>
#include <Clipbrd.hpp>
//---------------------------------------------------------------------------
class TfrmDataModule : public TDataModule
{
__published:	// IDE-managed Components
	TADOQuery *Query;
	TADOConnection *adoDB;
	void __fastcall adoDBBeforeConnect(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmDataModule(TComponent* Owner);

	//Выполнить присланный отчет
	void ExecuteQuery(AnsiString strQuery);
	//Выводим данные в буфер обмена
	void DataToClipboard(TDataSet* DataSet);
	//Опред. последний номер
	int LastID(AnsiString Table);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDataModule *frmDataModule;
//---------------------------------------------------------------------------
#endif
