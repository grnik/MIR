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

	//��������� ���������� �����
	void ExecuteQuery(AnsiString strQuery);
	//������� ������ � ����� ������
	void DataToClipboard(TDataSet* DataSet);
	//�����. ��������� �����
	int LastID(AnsiString Table);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDataModule *frmDataModule;
//---------------------------------------------------------------------------
#endif
