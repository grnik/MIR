//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Data.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Excel_XP_srvr"
#pragma link "Excel_XP_srvr"
#pragma resource "*.dfm"
TfrmDataModule *frmDataModule;
//---------------------------------------------------------------------------
__fastcall TfrmDataModule::TfrmDataModule(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmDataModule::adoDBBeforeConnect(TObject *Sender)
{
//AnsiString Path = Application->ExeName;

//	frmDataModule->adoDB->ConnectionString = "FILE NAME=./Branches.udl";
}
//---------------------------------------------------------------------------
//Выполнить присланный отчет
void TfrmDataModule::ExecuteQuery(AnsiString strQuery)
{
	Query->Close();
	Query->SQL->Clear();
	Query->SQL->Add(strQuery);
	Query->ExecSQL();
}
//---------------------------------------------------------------------------
//Выводим данные в Excel
void TfrmDataModule::DataToClipboard(TDataSet* DataSet)
{
	TClipboard* Clp = new TClipboard;
	AnsiString CopyText;

	Clp->Open();
	int FieldCount = DataSet->FieldCount;

	//Заголовки таблиц
	for(int i =0; i<DataSet->FieldCount; i++){
		CopyText +=	DataSet->Fields->Fields[i]->FieldName;
		CopyText += '\t';
	}
	CopyText += '\r';

	//Копируем данные
	DataSet->First();
	while(!DataSet->Eof){
		for(int i =0; i<DataSet->FieldCount; i++){
			CopyText +=	DataSet->Fields->Fields[i]->AsString;
			CopyText += '\t';
		}
		CopyText += '\r';
		DataSet->Next();
	}
	Clp->AsText = CopyText;
	Clp->Close();
};
//---------------------------------------------------------------------------
//Опред. последний номер
int TfrmDataModule::LastID(AnsiString Table)
{
	Query->Close();
	Query->SQL->Clear();
	Query->SQL->Add("select max(ID) from " + Table);
	Query->Open();
	int ID = Query->Fields->Fields[0]->AsInteger;
	Query->Close();
	return ID;
};
//---------------------------------------------------------------------------

