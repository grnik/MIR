//$$---- EXE CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Main.cpp", frmMain);
USEFORM("Data.cpp", frmDataModule); /* TDataModule: File Type */
USEFORM("Reporter.cpp", frmReporter);
USEFORM("Operator.cpp", frmOperator);
USEFORM("SubjectType.cpp", frmSubjectType);
USEFORM("PrintReport.cpp", frmPrintReport);
USEFORM("Branch.cpp", frmBranch);
USEFORM("Subject.cpp", frmSubject);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TfrmMain), &frmMain);
		Application->CreateForm(__classid(TfrmDataModule), &frmDataModule);
		Application->CreateForm(__classid(TfrmReporter), &frmReporter);
		Application->CreateForm(__classid(TfrmOperator), &frmOperator);
		Application->CreateForm(__classid(TfrmSubjectType), &frmSubjectType);
		Application->CreateForm(__classid(TfrmPrintReport), &frmPrintReport);
		Application->CreateForm(__classid(TfrmBranch), &frmBranch);
		Application->CreateForm(__classid(TfrmSubject), &frmSubject);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
